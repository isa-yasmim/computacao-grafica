//---------------------------------------------------------------------------

#pragma hdrstop

#include "Upoligono.h"
#include "Uponto.h"
#include "Ujanela.h"
#include <vector>
#include <Vcl.Forms.hpp>
#include <cstdlib>
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Poligono::desenha(TCanvas *Canvas, Janela mundo, Janela vp, int tipoReta){

	if (tipo == 'C' || tipo == 'G') {
		desenhaC(Canvas, mundo, vp);
        return;
	}

	//LineTo
	if (tipoReta == 0) {
		desenhaLine(Canvas, mundo, vp);
	}
	//DDA
	if (tipoReta == 1) {
		desenhaDDA(Canvas, mundo, vp);
	}
	//BRESENHAM
	if (tipoReta == 2) {
		desenhaBre(Canvas, mundo, vp);
	}
}

void Poligono::desenhaLine(TCanvas *Canvas, Janela mundo, Janela vp){
	int xvp, yvp;

		for (int i = 0; i < pontos.size(); i++) {

			//converte cordenada de mundo para vp
			xvp = pontos[i].xWVp(mundo, vp);
			yvp = pontos[i].yWVp(mundo, vp);

			if (i == 0) {
				Canvas->MoveTo(xvp, yvp);
			}
			else {
				Canvas->LineTo(xvp, yvp);
			}
		}
}

void Poligono::desenhaDDA(TCanvas *Canvas, Janela mundo, Janela vp){
	Ponto p1, p2;
	double dx, dy, length, x, y;

	for (int i = 0; i < pontos.size() - 1; i++) {
		p1 = pontos[i];
		p2 = pontos[i + 1];

		p1.x = pontos[i].xWVp(mundo, vp);
		p1.y = pontos[i].yWVp(mundo, vp);
		p2.x = pontos[i + 1].xWVp(mundo, vp);
		p2.y = pontos[i + 1].yWVp(mundo, vp);

		dx = p2.x - p1.x;
		dy = p2.y - p1.y;

		if (abs(dx) >= abs(dy)) {
			length = abs(dx);
		}
		if (abs(dx) < abs(dy)) {
			length = abs(dy);
		}

		dx /= length;
		dy /= length;

		x = p1.x;
        y = p1.y;

		for (int i = 0; i < length; i++) {
            if (tipo == 'H') {
				Canvas->Pixels[round(x)][round(y)] = clYellow;
			}
			else
			Canvas->Pixels[round(x)][round(y)] = clBlack;
			x += dx;
			y += dy;
		}
	}

}

void Poligono::desenhaBre(TCanvas *Canvas, Janela mundo, Janela vp){

	Ponto p1, p2;
	double dx, dy, sx, sy, x, y, erro = 0;
	Util util;

	for (int i = 0; i < pontos.size() - 1; i++) {

		bool troca = false;

		p1 = pontos[i];
		p2 = pontos[i + 1];

		p1.x = pontos[i].xWVp(mundo, vp);
		p1.y = pontos[i].yWVp(mundo, vp);
		p2.x = pontos[i + 1].xWVp(mundo, vp);
		p2.y = pontos[i + 1].yWVp(mundo, vp);

        x = p1.x;
		y = p1.y;

		dx = abs(p2.x - p1.x);
		dy = abs(p2.y - p1.y);

		sx = util.sign(p2.x - p1.x);
		sy = util.sign(p2.y - p1.y);

		if (sx < 0) {
			x -= 1;
		}
		if (sy < 0) {
			y -= 1;
		}

		if (dy > dx) {
			double aux = dx;
			dx = dy;
			dy = aux;
			troca = true;
		}

		erro = 2 * dy - dx;

		for (int j = 0; j < dx; j++) {

			if (tipo == 'H') {
				Canvas->Pixels[round(x)][round(y)] = clYellow;
			}
			else
			Canvas->Pixels[round(x)][round(y)] = clWhite;

            while (erro >= 0){
				if (troca) {
					x = x + sx;
				}
				else{
					y = y + sy;
				}

				erro = erro - 2 * dx;
			}

			if (troca) {
				y = y + sy;
			}
			else{
				x = x + sx;
			}

			erro = erro + 2 * dy;
		}

	}

}

void Poligono::desenhaC(TCanvas *Canvas, Janela mundo, Janela vp){
	int xvp, yvp;

	for (int i = 0; i < pontos.size(); i++) {
		//converte cordenada de mundo para vp
		xvp = pontos[i].xWVp(mundo, vp);
		yvp = pontos[i].yWVp(mundo, vp);

		if (tipo == 'C') {
			Canvas->Pixels[round(xvp)][round(yvp)] = clWhite;
		}
		if (tipo == 'G') {
			Canvas->Pixels[round(xvp)][round(yvp)] = clYellow;
		}

	}
}

void Poligono::criarCircunferencia(double xc, double yc, double r){
	double x, y, p;

	x = 0;
	y = r;

	quadrantes(xc, yc, x, y);

	p = 1 - r;

	while (x < y){
		if (p < 0) {
			x++;
		}
		else{
			x++;
			y--;
		}

		if (p < 0) {
			p += 2 * x + 1;
		}
		else{
			p += 2 * (x - y) + 1;
		}

		quadrantes(xc, yc, x, y);

	}


}

Poligono Poligono::CohenSutherland(Janela c){

	Poligono aux;
	std::vector<Ponto> clippedPoints;
	double m = 0;
	Util util;

	  for (int i = 0; i < pontos.size() - 1; i++) {
		Ponto p1 = pontos[i];
		Ponto p2 = pontos[i + 1];

		int code1 = p1.getRegionCode(c);
		int code2 = p2.getRegionCode(c);

		// Totalmente visivel
		if (code1 == 0 && code2 == 0) {

		  clippedPoints.push_back(p1);


		  if (p1.x != p2.x && p1.y != p2.y) {
			clippedPoints.push_back(p2);
		  }


		  continue;
		}

		// Parcialmente visivel
		else if ((code1 & code2) == 0) {
			m = util.media(p1, p2);

			  if (code1 != 0) {
				p1.clipLine(c, m, code1);
			  }

			  if (code2 != 0) {
				p2.clipLine(c, m, code2);
			  }

			  clippedPoints.push_back(p1);

			  if (p1.x != p2.x && p1.y != p2.y) {
				clippedPoints.push_back(p2);
			  }
		}
	  }

	  aux.pontos = clippedPoints;
      return aux;
}

Poligono Poligono::clipCircunferencia(Janela c){

	Poligono aux;
	std::vector<Ponto> clippedPoints;

	for (int i = 0; i < pontos.size(); i++) {
		if (pontos[i].getRegionCode(c) == 0) {
			clippedPoints.push_back(pontos[i]);
		}
	}

    aux.pontos = clippedPoints;
	return aux;
}

void Poligono::mostra(TListBox *listbox){
	listbox->Items->Add(IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()));
}

void Poligono::mostraPontos(TListBox *listbox){

	listbox->Items->Clear();

	for (int i = 0; i < pontos.size(); i++) {
		listbox->Items->Add(pontos[i].mostraPonto());
	}
}

void Poligono::translacao(double dx, double dy){
	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].translacao(dx, dy);
	}
}

bool Poligono::isEqual(Poligono pol){

	int cont = 0;

	if (tipo == pol.tipo && id == pol.id) {
        return true;
	}

    return false;
}

void Poligono::quadrantes(double xc, double yc, double x, double y){
    pontos.push_back(Ponto(xc + x, yc + y));
	pontos.push_back(Ponto(xc - x, yc + y));
	pontos.push_back(Ponto(xc - y, yc + x));
	pontos.push_back(Ponto(xc - y, yc - x));
	pontos.push_back(Ponto(xc - x, yc - y));
	pontos.push_back(Ponto(xc + x, yc - y));
	pontos.push_back(Ponto(xc + y, yc - x));
	pontos.push_back(Ponto(xc + y, yc + x));
}

/*void pontoCentral(){
	Ponto pc;

	for (int i = 0; i < pontos.size(); i++){
		pc.x += pontos[i].x;
		pc.y += pontos[i].y;
	}

	pc.x = pc.x / pontos.size();
	pc.y = pc.y / pontos.size();
}
*/

/*
	for (int l = 1; l<= m; l++)
		for (int c = 1; c <= k; c++)
			C(l,c) = 0;

*/

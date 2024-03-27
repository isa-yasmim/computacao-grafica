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

	//LineTo
	if (tipoReta == 0) {
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
	//DDA
	if (tipoReta == 1) {
		desenhaDDA(Canvas, mundo, vp);
	}
	//BRESENHAM
	if (tipo == 2) {
		desenhaBre(Canvas, mundo, vp);
	}
}

void Poligono::desenhaDDA(TCanvas *Canvas, Janela mundo, Janela vp){
	Ponto p1, p2;
	float dx, dy, length, x, y;

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
			Canvas->Pixels[round(x)][round(y)] = clBlack;
			x += dx;
			y += dy;
		}
	}

}

void Poligono::desenhaBre(TCanvas *Canvas, Janela mundo, Janela vp){
	Ponto p1, p2;
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

/*Ponto central
	Ponto pc;

	for (int i = 0; i < pontos.size(); i++){
		pc.x += pontos[i].x;
		pc.y += pontos[i].y;
	}

	pc.x = pc.x / pontos.size();
	pc.y = pc.y / pontos.size();
*/

/*
	for (int l = 1; l<= m; l++)
		for (int c = 1; c <= k; c++)
			C(l,c) = 0;

*/

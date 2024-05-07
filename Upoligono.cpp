//---------------------------------------------------------------------------

#pragma hdrstop

#include "Upoligono.h"
#include "Uponto.h"
#include "Ujanela.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Poligono::desenha(TCanvas *Canvas, Janela mundo, Janela vp, int tipoReta){

	if (tipo == 'C' || tipo == 'G') {
		desenhaC(Canvas, mundo, vp);
        return;
	}
	if (tipo == 'D') {
        desenhaLine(Canvas, mundo, vp);
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

		if (pontos.size() > 0) {
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

		if (pontosD.size() > 0) {
			for (int i = 0; i < pontosD.size(); i++) {

				//converte cordenada de mundo para vp
				xvp = pontosD[i].xWVp(mundo, vp);
				yvp = pontosD[i].yWVp(mundo, vp);

				if (i == 0) {
					Canvas->MoveTo(xvp, yvp);
				}
				else {
					Canvas->LineTo(xvp, yvp);
				}
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

			  if (p1.getRegionCode(c) == 0) {
				clippedPoints.push_back(p1);
			  }

			  if (p1.x != p2.x && p1.y != p2.y) {
				if (p2.getRegionCode(c) == 0) {
					clippedPoints.push_back(p2);
				}
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
	if (pontos.size() > 0) {
		listbox->Items->Add(IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()));
	}

	if (pontosD.size() > 0) {
		listbox->Items->Add(IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontosD.size()));
	}
}

void Poligono::mostraPontos(TListBox *listbox){

	listbox->Items->Clear();

	for (int i = 0; i < pontos.size(); i++) {
		listbox->Items->Add(pontos[i].mostraPonto());
	}

}

void Poligono::mostraPontosD(TListBox *listbox){

	listbox->Items->Clear();

	for (int i = 0; i < pontosD.size(); i++) {
		listbox->Items->Add(pontosD[i].mostraPontoD());
	}

}

void Poligono::translacao(double dx, double dy){
	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].translacao(dx, dy);
	}
}

void Poligono::escalonamento(double dx, double dy){
    for (int i = 0; i < pontos.size(); i++) {
		pontos[i].escalonamento(dx, dy);
	}
}

void Poligono::rotacao(double angulo){
    for (int i = 0; i < pontos.size(); i++) {
		pontos[i].rotacao(angulo);
	}
}

void Poligono::rotacaoH(double angulo){

	Ponto pc;

    pc = pontoCentral(pc);

    for (int i = 0; i < pontos.size(); i++) {
		pontos[i].rotacaoH(angulo, pc);
	}
}

void Poligono::reflexao(TRadioGroup *Eixo){

	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].reflexao(Eixo);
	}

}

void Poligono::translacaoD(double dx, double dy, double dz){
	for (int i = 0; i < pontosD.size(); i++) {
		pontosD[i].translacaoD(dx, dy, dz);
	}
}

void Poligono::escalonamentoD(double dx, double dy, double dz){
	for (int i = 0; i < pontosD.size(); i++) {
		pontosD[i].escalonamentoD(dx, dy, dz);
	}
}

void Poligono::rotacaoD(double angulo, char eixo){
	for (int i = 0; i < pontosD.size(); i++) {
		pontosD[i].rotacaoD(angulo, eixo);
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

Ponto Poligono::pontoCentral(Ponto pc){
	for (int i = 0; i < pontos.size(); i++){
		pc.x += pontos[i].x;
		pc.y += pontos[i].y;
	}

	pc.x = pc.x / pontos.size();
	pc.y = pc.y / pontos.size();

    return pc;
}

Poligono Poligono::curva(int tipoCurva){

	Poligono pol;

	if (tipoCurva == 0) {
		if (pontos.size() == 4) {
			pol = bSpline();
			return pol;
		}
	}
	if (tipoCurva == 1) {
		if (pontos.size() == 4) {
			pol = hermite();
			return pol;
		}
	}
	if (tipoCurva == 2) {
		if (pontos.size() == 4) {
			pol = bezier();
            return pol;
		}
	}
	if (tipoCurva == 3) {
		if (pontos.size() == 3) {
			pol = casteljau();
		}
		return pol;
	}
	if (tipoCurva == 4) {
		if (pontos.size() == 4) {
			pol = fowardD();
		}
		return pol;
	}

    return pol;
}

Poligono Poligono::bSpline(){

	Ponto aux;
	Poligono res;

	for(double t = 0; t < 1; t+= 0.01){

		double t2 = t*t;
		double t3 = t2*t;

		aux.x = pontos[0].x + 4 * pontos[1].x + pontos[2].x -  pontos[0].x * t3 + 3 * pontos[1].x * t3 - 3 * pontos[2].x * t3 + pontos[3].x * t3 + 3 * pontos[0].x * t2 - 6 * pontos[1].x * t2 + 3 * pontos[2].x * t2 - 3 * pontos[0].x * t+ 3 * pontos[2].x * t;
		aux.y = pontos[0].y + 4 * pontos[1].y + pontos[2].y -  pontos[0].y * t3 + 3 * pontos[1].y * t3 - 3 * pontos[2].y * t3 + pontos[3].y * t3 + 3 * pontos[0].y * t2 - 6 * pontos[1].y * t2 + 3 * pontos[2].y * t2 - 3 * pontos[0].y * t+ 3 * pontos[2].y * t;
		aux.x /= 6;
		aux.y /= 6;

		res.pontos.push_back(aux);
	}

	return res;

}

Poligono Poligono::hermite(){

	Ponto aux, r1, r4;
	Poligono res;

	r1.x = pontos[1].x - pontos[0].x;
	r1.y = pontos[1].y - pontos[0].y;
	r4.x = pontos[3].x - pontos[2].x;
	r4.y = pontos[3].y - pontos[2].y;

	for(double t = 0; t < 1; t+= 0.01){

		double t2 = t*t;
		double t3 = t2*t;

		aux.x = pontos[0].x * (2 * t3 - 3 * t2* t+1) + pontos[3].x * (-2 * t3 + 3 * t2) + r1.x * (t3 -2 * t2 + t) + r4.x * (t3 - t2);
		aux.y = pontos[0].y * (2 * t3 - 3 * t2* t+1) + pontos[3].y * (-2 * t3 + 3 * t2) + r1.y * (t3 -2 * t2 + t) + r4.y * (t3 - t2);

		res.pontos.push_back(aux);
	}

	return res;

}

Poligono Poligono::bezier(){

	Ponto aux;
	Poligono res;

	for(double t = 0; t < 1; t+= 0.01){

		double t2 = t*t;
		double t3 = t2*t;
		double u = 1-t;
		double u2 = u*u;
		double u3 = u2*u;

		aux.x = u3 * pontos[0].x + 3 * u2 * t * pontos[1].x + 3 * u * t2 * pontos[2].x + t3 * pontos[3].x;
		aux.y = u3 * pontos[0].y + 3 * u2 * t * pontos[1].y + 3 * u * t2 * pontos[2].y + t3 * pontos[3].y;

		res.pontos.push_back(aux);
	}

	return res;

}

Poligono Poligono::casteljau() {

	Ponto P1, P2, P3;

	P1 = pontos[0];
	P2 = pontos[1];
	P3 = pontos[2];

	Poligono aux;

	aux.pontos.push_back(P1);

	casteljauB(P1, P2, P3, &aux);

    return aux;

}

void Poligono::casteljauB(Ponto P1, Ponto P2, Ponto P3, Poligono *aux){

	double dist = sqrt(pow(P3.x - P1.x, 2) + pow(P3.y - P1.y, 2));

	if (dist < 3) {
		aux->pontos.push_back(P3);
	}
	else{
		Ponto A, B, C;

		A.medio(P1, P2);
		B.medio(P2, P3);
		C.medio(A, B);

		/*
		A.x = floor((P2.x + P1.x) / 2);
		A.y = floor((P2.y + P1.y) / 2);

		B.x = floor((P3.x + P2.x) / 2);
		B.y = floor((P3.y + P2.y) / 2);

		C.x = floor((B.x + A.x) / 2);
		C.y = floor((B.y + A.y) / 2);
        */

		casteljauB(P1, A, C, aux);
		casteljauB(C, B, P3, aux);

		aux->pontos.push_back(P3);
    }

}

Poligono Poligono::fowardD(){
	Ponto aux;
	Poligono res;

    double h = 0.0001;

    for(double t = 0; t < 1; t+= 0.01){

        double t2 = t*t;
        double t3 = t2*t;
        double u = 1-t;
        double u2 = u*u;
        double u3 = u2*u;

        aux.x = u3 * pontos[0].x + 3 * u2 * t * pontos[1].x + 3 * u * t2 * pontos[2].x + t3 * pontos[3].x;
        aux.y = u3 * pontos[0].y + 3 * u2 * t * pontos[1].y + 3 * u * t2 * pontos[2].y + t3 * pontos[3].y;

        double t_plus_h = t + h;
        double t2_plus_h = t_plus_h * t_plus_h;
        double t3_plus_h = t2_plus_h * t_plus_h;
        double u_plus_h = 1 - t_plus_h;
        double u2_plus_h = u_plus_h * u_plus_h;
        double u3_plus_h = u2_plus_h * u_plus_h;

        Ponto aux_plus_h;
		aux_plus_h.x = u3_plus_h * pontos[0].x + 3 * u2_plus_h * (t_plus_h) * pontos[1].x + 3 * u_plus_h * (t2_plus_h) * pontos[2].x + (t3_plus_h) * pontos[3].x;
        aux_plus_h.y = u3_plus_h * pontos[0].y + 3 * u2_plus_h * (t_plus_h) * pontos[1].y + 3 * u_plus_h * (t2_plus_h) * pontos[2].y + (t3_plus_h) * pontos[3].y;

        Ponto derivative;
        derivative.x = (aux_plus_h.x - aux.x) / h;
        derivative.y = (aux_plus_h.y - aux.y) / h;

        res.pontos.push_back(derivative);
    }

	return res;
}

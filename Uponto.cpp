//---------------------------------------------------------------------------

#pragma hdrstop

#include "Uponto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

double pi = M_PI;

Ponto::Ponto(){
	x = y = 0;
}

Ponto::Ponto(double nx, double ny){
	x = nx;
	y = ny;
}

int Ponto::xWVp(Janela mundo, Janela vp){
	return ((x - mundo.xMin) / (mundo.xMax - mundo.xMin)) * (vp.xMax - vp.xMin);
}
int Ponto::yWVp(Janela mundo, Janela vp){
	return (1 - ((y - mundo.yMin) / (mundo.yMax - mundo.yMin))) * (vp.yMax - vp.yMin);
}

AnsiString Ponto::mostraPonto(){
    return "(" + FloatToStr(x) + "," + FloatToStr(y) + ")";
}

void Ponto::translacao(double dx, double dy){
	x += dx;
	y += dy;
}

void Ponto::escalonamento(double dx, double dy){
	x = x * dx;
	y = y * dy;
}

void Ponto::rotacao(double angulo){

	angulo = angulo * (pi / 180);

	double xvelho = x;

	x = (x * cos(angulo)) - (y * sin(angulo));
	y = (xvelho * sin(angulo)) + (y * cos(angulo));
}

void Ponto::rotacaoH(double angulo, Ponto pc){

	angulo = angulo * (pi / 180);

    double xaux = x, yaux = y;

	double res[3][3];
	double res2[3][3];
    double res3[1][3];

	double ponto[1][3] = {
		{xaux, yaux, 1}
	};

	double m1[3][3] =  {
		{1, 0, 0},
		{0, 1, 0},
		{-pc.x, -pc.y, 1}
	};

	double m2[3][3] =  {
		{cos(angulo), -sin(angulo), 0},
		{sin(angulo), cos(angulo), 0},
		{0, 0, 1}
	};

	double m3[3][3] =  {
		{1, 0, 0},
		{0, 1, 0},
		{pc.x, pc.y, 1}
	};

	//m1 * m2 somada ao ponto
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
		res[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	//ponto * m2
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
		res2[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				res2[i][j] += res[i][k] * m3[k][j];
			}
		}
	}


	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 3; j++) {
		res3[i][j] = 1;
			for (int k = 0; k < 3; k++) {
				res3[i][j] += ponto[i][k] * res2[k][j];
			}
		}
	}

	x = res3[0][0];
	y = res3[0][1];


	/*
	FUNCIONA
	- nao e necessario matriz res3 e ponto
	- nao e necessario xaux, yaux
	- nao e necessario multiplicar res2 por ponto

	double xvelho = x;

	x = x * res2[0][0] + y * res2[1][0] + res2[2][0];
	y = xvelho * res2[0][1] + y * res2[1][1] + res2[2][1];
	*/

}

void Ponto::reflexao(){
	x *= (-1);
    y *= (-1);
}

int Ponto::getRegionCode(Janela c){
	int res = 0;

	if (x < c.xMin)
		res +=1;
		else
			if (x > c.xMax)
			res += 2;
	if (y < c.yMin)
		res += 4;
		else
			if (y > c.yMax)
			res += 8;

	return res;
}

void Ponto::clipLine(Janela c, double m, int rcode){

	Ponto aux;
    Boolean calculado = false;


	//left - 9 - 1 - 5
	if (rcode == 9 || rcode == 1 || rcode == 5) {
		if (m != 0) {
			aux.y = m * (c.xMin - x) + y;
			aux.x = c.xMin;
            calculado = true;
		}
	}

	//right -  10 - 2 - 6
	if (rcode == 10 || rcode == 2 || rcode == 6) {
		aux.y = m * (c.xMax - x) + y;
		aux.x = c.xMax;
		calculado = true;
	}

	//se esta dentro da janela ja achou o ponto ajustado e pode retornar
	if (aux.getRegionCode(c) == 0 && calculado) {
		x = aux.x;
		y = aux.y;
		return;
	}


	//above - 9 - 8 - 10
	if (rcode == 9 || rcode == 8 || rcode == 10) {
		aux.x = x + (1/m) * (c.yMax - y);
		aux.y = c.yMax;
		calculado = true;
	}

	//below - 5 - 4 - 6
	if (rcode == 5 || rcode == 4 || rcode == 6) {
		aux.x = x + (1/m) * (c.yMin - y);
		aux.y = c.yMin;
		calculado = true;
	}

	//se esta dentro da janela ja achou o ponto ajustado e pode retornar
	if (aux.getRegionCode(c) == 0 && calculado) {
		x = aux.x;
		y = aux.y;
        return;
	}
}


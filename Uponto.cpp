//---------------------------------------------------------------------------

#pragma hdrstop

#include "Uponto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

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


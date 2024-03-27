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
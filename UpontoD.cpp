//---------------------------------------------------------------------------

#pragma hdrstop

#include "UpontoD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


PontoD::PontoD(){
    x = y = 0;
}

PontoD::PontoD(double nx, double ny, double nz){
	x = nx;
	y = ny;
    z = nz;
}

void PontoD::translacaoD(double dx, double dy){
    x += dx;
	y += dy;
}

void PontoD::escalonamentoD(double dx, double dy){
	x = x * dx;
	y = y * dy;
}

void PontoD::rotacaoD(double angulo){
}

AnsiString PontoD::mostraPontoD(){
    return "(" + FloatToStr(x) + "," + FloatToStr(y) + "," + FloatToStr(z) + ")";
}

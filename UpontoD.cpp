//---------------------------------------------------------------------------

#pragma hdrstop

#include "UpontoD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

double pi = M_PI;

PontoD::PontoD(){
    x = y = 0;
}

PontoD::PontoD(double nx, double ny, double nz){
	x = nx;
	y = ny;
    z = nz;
}

void PontoD::translacaoD(double dx, double dy, double dz){
    x += dx;
	y += dy;
    z += dz;
}

void PontoD::escalonamentoD(double dx, double dy, double dz){
	x = x * dx;
	y = y * dy;
    z = z * dz;
}

void PontoD::rotacaoD(double angulo, char eixo){
	angulo = angulo * (pi / 180);

	PontoD aux;

	double xaux = x, yaux = y, zaux = z;

	double res[1][4];

	double ponto[1][4] = {
		{xaux, yaux, zaux, 1}
	};

	double mx[4][4] = {
		{1, 0, 0, 0}  ,
		{0, cos(angulo), sin(angulo), 0}  ,
		{0, -sin(angulo), cos(angulo), 0}  ,
		{0, 0, 0, 1}
	};

	double my[4][4] = {
		{cos(angulo), 0, -sin(angulo), 0}  ,
		{0, 1, 0, 0}  ,
		{sin(angulo), 0, cos(angulo), 0}  ,
		{0, 0, 0, 1}
	};

	double mz[4][4] = {
		{cos(angulo), sin(angulo), 0, 0}  ,
		{-sin(angulo), cos(angulo), 0, 0}  ,
		{0, 0, 1, 0}  ,
		{0, 0, 0, 1}
	};

	if (eixo == 'X') {

		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 4; j++) {
				res[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					res[i][j] += ponto[i][k] * mx[k][j];
				}
			}
		}

	}

	if (eixo == 'Y') {
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 4; j++) {
				res[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					res[i][j] += ponto[i][k] * my[k][j];
				}
			}
		}
	}

	if (eixo == 'Z') {
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 4; j++) {
				res[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					res[i][j] += ponto[i][k] * mz[k][j];
				}
			}
		}

	}

	x = res[0][0];
	y = res[0][1];
	z = res[0][2];
}

AnsiString PontoD::mostraPontoD(){
    return "(" + FloatToStr(x) + "," + FloatToStr(y) + "," + FloatToStr(z) + ")";
}

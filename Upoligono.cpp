//---------------------------------------------------------------------------

#pragma hdrstop

#include "Upoligono.h"
#include "Uponto.h"
#include "Ujanela.h"
#include <vector>
#include <Vcl.Forms.hpp>
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


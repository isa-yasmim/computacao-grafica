//---------------------------------------------------------------------------

#pragma hdrstop

#include "Upoligono.h"
#include "Ujanela.h"
#include <vector>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Poligono::desenha(TCanvas *Canvas, Janela mundo, Janela vp){

	int xvp, yvp;

	for (int i = 0; i < pontos.size(); i++) {

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

void Poligono::mostra(TListBox *listbox){
	listbox->Items->Add(IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()));
}

void Poligono::mostraPontos(TListBox *listbox){

	listbox->Items->Clear();

	for (int i = 0; i < pontos.size(); i++) {
		listbox->Items->Add(pontos[i].mostraPonto());
	}
}

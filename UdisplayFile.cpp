//---------------------------------------------------------------------------

#pragma hdrstop

#include "UdisplayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void DisplayFile::desenha(TCanvas *Canvas, Janela mundo, Janela vp, int tipoReta){
	//configura a caneta pra se escrever
	Canvas->Brush->Color = clRed;
	Canvas->FillRect(Rect(0,0,500,500));

    Canvas->Pen->Color = clBlack;
	Canvas->Pen->Width = 3;

	for (int i = 0; i < poligonos.size(); i++) {
		if (poligonos[i].tipo == 'N') {
			Canvas->Pen->Color = clBlack;
			Canvas->Pen->Width = 1;
		}
		if (poligonos[i].tipo == 'H') {
			Canvas->Pen->Color = clYellow;
			Canvas->Pen->Width = 3;
		}

		poligonos[i].desenha(Canvas, mundo, vp, tipoReta);
	}
}

void DisplayFile::mostra(TListBox *listbox){

	listbox->Clear();

	for (int i = 0; i < poligonos.size(); i++) {
		poligonos[i].mostra(listbox);
	}
}

void DisplayFile::clipping(TCanvas *canvas, Janela mundo, Janela vp, Janela c){

	Poligono aux;
	std::vector<Poligono> poligonosAux;
	int contId = 100;
    bool existe = false;

	canvas->Pen->Color = clYellow;
	canvas->Pen->Width = 3;

	//define os poligonos a serem desenhados
	for (int i = 2; i < poligonos.size(); i++) {
		if (poligonos[i].tipo != 'H') {

			aux = poligonos[i].CohenSutherland(c);

			if (aux.pontos.size() > 0) {
				poligonosAux.push_back(aux);
			}
		}
	}

    for (int i = 0; i < poligonosAux.size(); i++) {

		//desenha o poligono que vai popular
		poligonosAux[i].desenha(canvas, mundo, vp, 0);

		poligonosAux[i].id = contId++;
		poligonosAux[i].tipo = 'H';
		adicionarPol(poligonosAux[i]);  //da push_back se nao existe o poligono

	}

	poligonosAux.clear();

}

void DisplayFile::adicionarPol(Poligono pol){

	bool existe = false;

	for (int i = 0; i < poligonos.size(); i++) {
		if (poligonos[i].isEqual(pol)) {
            existe = true;
			break;
		}
	}

	if (!existe) {
		poligonos.push_back(pol);
	}
}

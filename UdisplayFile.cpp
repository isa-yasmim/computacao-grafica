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
	for (int i = 3; i < poligonos.size(); i++) {
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

void DisplayFile::eixo(TCanvas *canvas, Janela mundo, Janela vp, Janela c){

	Poligono pol;
	int contId = 0;

	//coloca os pontos no poligono pol para desenhar o eixo y
	pol.id = contId++;
	pol.tipo = 'E';
	pol.pontos.push_back(Ponto(0, mundo.yMax));
	pol.pontos.push_back(Ponto(0, mundo.yMin));

	poligonos.push_back(pol);
	pol.pontos.clear();

	pol.id = contId++;
	pol.tipo = 'E';
	pol.pontos.push_back(Ponto(mundo.xMax, 0));
	pol.pontos.push_back(Ponto(mundo.xMin, 0));

	poligonos.push_back(pol);
	pol.pontos.clear();

	//LIMITE DO CLIPPING
	pol.id = contId++;
	pol.tipo = 'P';
	pol.pontos.push_back(Ponto(c.xMin, c.yMax));
	pol.pontos.push_back(Ponto(c.xMax, c.yMax));

	pol.pontos.push_back(Ponto(c.xMax, c.yMin));
	pol.pontos.push_back(Ponto(c.xMin, c.yMin));
	pol.pontos.push_back(Ponto(c.xMin, c.yMax));

	poligonos.push_back(pol);
	pol.pontos.clear();
}

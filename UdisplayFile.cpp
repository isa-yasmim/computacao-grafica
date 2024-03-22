//---------------------------------------------------------------------------

#pragma hdrstop

#include "UdisplayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void DisplayFile::desenha(TCanvas *Canvas, Janela mundo, Janela vp){
	//configura a caneta pra se escrever
	Canvas->Brush->Color = clRed;
	Canvas->FillRect(Rect(0,0,500,500));

	Canvas->Pen->Color = clBlack;
	Canvas->Pen->Width = 3;

	for (int i = 0; i < poligonos.size(); i++) {
		poligonos[i].desenha(Canvas, mundo, vp);
	}
}

void DisplayFile::mostra(TListBox *listbox){

	listbox->Clear();

	for (int i = 0; i < poligonos.size(); i++) {
		poligonos[i].mostra(listbox);
	}
}

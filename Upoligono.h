//---------------------------------------------------------------------------

#ifndef UpoligonoH
#define UpoligonoH

#include "Uponto.h"
#include <vector>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Poligono{
	public:
	int id;
	char tipo;
	std::vector<Ponto> pontos;

	void desenha(TCanvas *Canvas, Janela mundo, Janela vp);

	void mostra(TListBox *listbox);

    void mostraPontos(TListBox *listbox);
};
#endif

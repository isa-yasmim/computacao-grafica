//---------------------------------------------------------------------------

#ifndef UpoligonoH
#define UpoligonoH

#include "Uponto.h"
#include "Util.h"
#include <vector>
#include <Vcl.ExtCtrls.hpp>

/*
DIFERENTES TIPOS
E = EIXO
N = POLIGONO NORMAL
C = CIRCUNFERENCIA
H = POLIGONO CLIPPADO
P = PARAMETROS
*/

//---------------------------------------------------------------------------
class Poligono{
	public:
		int id;
		char tipo;
		std::vector<Ponto> pontos;

		void desenha(TCanvas *Canvas, Janela mundo, Janela vp, int tipoReta);

		void desenhaLine(TCanvas *Canvas, Janela mundo, Janela vp);

		void desenhaDDA(TCanvas *Canvas, Janela mundo, Janela vp);

		void desenhaBre(TCanvas *Canvas, Janela mundo, Janela vp);

		Poligono CohenSutherland(Janela c);

		void mostra(TListBox *listbox);

		void mostraPontos(TListBox *listbox);

		void translacao(double dx, double dy);

		bool isEqual(Poligono pol);

};
#endif

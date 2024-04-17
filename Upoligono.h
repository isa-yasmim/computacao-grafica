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
G = CIRCUNFERENCIA CLIPADA
H = POLIGONO CLIPADO
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

		void desenhaC(TCanvas *Canvas, Janela mundo, Janela vp);

		void criarCircunferencia(double xc, double yc, double r);

		Poligono CohenSutherland(Janela c);

        Poligono clipCircunferencia(Janela c);

		void mostra(TListBox *listbox);

		void mostraPontos(TListBox *listbox);

		void translacao(double dx, double dy);

		bool isEqual(Poligono pol);

        void quadrantes(double xc, double yc, double x, double y);

};
#endif

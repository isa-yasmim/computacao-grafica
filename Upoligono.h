//---------------------------------------------------------------------------

#ifndef UpoligonoH
#define UpoligonoH

#include "Uponto.h"
#include "Util.h"
#include <vector>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <cstdlib>
#include <cmath>

/*
DIFERENTES TIPOS
E = EIXO
N = POLIGONO NORMAL
C = CIRCUNFERENCIA
G = CIRCUNFERENCIA CLIPADA
H = POLIGONO CLIPADO
P = PARAMETROS
V = CURVE
*/

//---------------------------------------------------------------------------
class Poligono{
	public:
		int id;
		char tipo;
		std::vector<Ponto> pontos;

        //DESENHA
		void desenha(TCanvas *Canvas, Janela mundo, Janela vp, int tipoReta);

		void desenhaLine(TCanvas *Canvas, Janela mundo, Janela vp);

		void desenhaDDA(TCanvas *Canvas, Janela mundo, Janela vp);

		void desenhaBre(TCanvas *Canvas, Janela mundo, Janela vp);

		void desenhaC(TCanvas *Canvas, Janela mundo, Janela vp);

		//CIRCUNFERENCIA
		void criarCircunferencia(double xc, double yc, double r);

		//CLIPPING
		Poligono CohenSutherland(Janela c);

        Poligono clipCircunferencia(Janela c);

		//SHOW
		void mostra(TListBox *listbox);

		void mostraPontos(TListBox *listbox);

		//TRANSFORMACOES
		void translacao(double dx, double dy);

		void escalonamento(double dx, double dy);

		void rotacao(double angulo);

		void rotacaoH(double angulo);

		void reflexao(TRadioGroup *Eixo);

        //GERAIS
		bool isEqual(Poligono pol);

		void quadrantes(double xc, double yc, double x, double y);

		Ponto pontoCentral(Ponto pc);

		//CURVA

		Poligono curva(int tipoCurva);

		Poligono bSpline();

		Poligono hermite();

		Poligono bezier();

		Poligono casteljau();
		void casteljauB(Ponto P1, Ponto P2, Ponto P3, Poligono *aux);

};
#endif

//---------------------------------------------------------------------------

#ifndef UpontoH
#define UpontoH
//---------------------------------------------------------------------------
#include "Ujanela.h"
#include <Vcl.Controls.hpp> //AnsiString
#include <cmath> //Pi
#include <Vcl.ExtCtrls.hpp>
class Ponto{
	public:
		double x, y;

		Ponto();
		Ponto(double nx, double ny);

		int xWVp(Janela mundo, Janela vp);
		int yWVp(Janela mundo, Janela vp);

		AnsiString mostraPonto();

		void translacao(double dx, double dy);

		void escalonamento(double dx, double dy);

		void rotacao(double angulo);

		void rotacaoH(double angulo, Ponto pc);

        void reflexao(TRadioGroup *Eixo);

		int getRegionCode(Janela clipping);

		void clipLine(Janela c, double m, int rcode);
};

#endif

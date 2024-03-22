//---------------------------------------------------------------------------

#ifndef UpontoH
#define UpontoH
//---------------------------------------------------------------------------
#include "Ujanela.h"
#include <Vcl.Controls.hpp> //AnsiString
class Ponto{
	public:
		double x, y;

		Ponto();
		Ponto(double nx, double ny);

		int xWVp(Janela mundo, Janela vp);
		int yWVp(Janela mundo, Janela vp);

		AnsiString mostraPonto();
};

#endif

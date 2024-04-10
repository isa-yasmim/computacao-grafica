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

		void translacao(double dx, double dy);

		int getRegionCode(Janela clipping);

		void clipLine(Janela c, double m, int rcode);
};

#endif

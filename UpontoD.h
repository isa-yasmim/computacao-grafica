//---------------------------------------------------------------------------

#ifndef UpontoDH
#define UpontoDH
//---------------------------------------------------------------------------
#include "Uponto.h"
#include <Vcl.Controls.hpp>
class PontoD : public Ponto {
	public:
		double z;

		//CONSTRUCTORS
		PontoD();
		PontoD(double nx, double ny, double nz);

		//GERAL
		AnsiString mostraPontoD();

		//GEOMETRIC FUNCTIONS
		void translacaoD(double dx, double dy);

		void escalonamentoD(double dx, double dy);

		void rotacaoD(double angulo);
};
#endif

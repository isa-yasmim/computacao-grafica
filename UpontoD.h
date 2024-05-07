//---------------------------------------------------------------------------

#ifndef UpontoDH
#define UpontoDH
//---------------------------------------------------------------------------
#include "Uponto.h"
#include <Vcl.Controls.hpp>
#include <cmath>
class PontoD : public Ponto {
	public:
		double z;

		//CONSTRUCTORS
		PontoD();
		PontoD(double nx, double ny, double nz);

		//GERAL
		AnsiString mostraPontoD();

		//GEOMETRIC FUNCTIONS
		void translacaoD(double dx, double dy, double dz);

		void escalonamentoD(double dx, double dy, double dz);

		void rotacaoD(double angulo, char eixo);
};
#endif

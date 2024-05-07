//---------------------------------------------------------------------------

#ifndef UtilH
#define UtilH
#include "Uponto.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.h>
//---------------------------------------------------------------------------
#endif

class Util {
	public:

		static int polId;

		double media(Ponto p1, Ponto p2);

		double sign(double a);

		bool validate(TListBox *listbox, TEdit *Edit, double x);

};
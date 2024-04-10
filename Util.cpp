//---------------------------------------------------------------------------

#pragma hdrstop

#include "Util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

float Util::media(Ponto p1, Ponto p2){

	float res = 1;

	if (p2.x - p1.x == 0 ) {
		return res;
	}

	res = ((p2.y - p1.y) / (p2.x - p1.x));

	return res;
}


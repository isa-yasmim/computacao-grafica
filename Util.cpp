//---------------------------------------------------------------------------

#pragma hdrstop

#include "Util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

double Util::media(Ponto p1, Ponto p2){

	double res = 1;

	if (p2.x - p1.x == 0 ) {
		return res;
	}

	res = ((p1.y - p2.y) / (p1.x - p2.x));

	return res;
}

double Util::sign(double a){
	if (a < 0) {
		return -1;
	}
	else
        return 1;
}

bool Util::validate(TListBox *listbox, TEdit *Edit, double x){
	try {
		x = StrToFloat(Edit->Text);
	} catch (...) {
		ShowMessage("Erro ao converter para float");
		return false;
	}

    if (listbox->ItemIndex == -1) {
		ShowMessage("Nenhum Poligono selecionado");
        return false;
	}

    return true;
}

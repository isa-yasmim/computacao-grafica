//---------------------------------------------------------------------------

#ifndef UdisplayFileH
#define UdisplayFileH
#include "Upoligono.h"
#include "Ujanela.h"
#include <vector>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class DisplayFile{
	public:
		std::vector<Poligono> poligonos;

		void desenha(TCanvas *canvas, Janela mundo, Janela vp);

		void mostra(TListBox *listbox);
};
#endif

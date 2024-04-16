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

		void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta);

		void mostra(TListBox *listbox);

		void clipping(TCanvas *canvas, Janela mundo, Janela vp, Janela c);

		void adicionarPol(Poligono pol);

		void eixo(TCanvas *canvas, Janela mundo, Janela vp, Janela c);

};
#endif

//---------------------------------------------------------------------------

#ifndef TestH
#define TestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "Uponto.h"
#include "Ujanela.h"
#include "Upoligono.h"
#include "UdisplayFile.h"
#include <Vcl.ComCtrls.hpp>
#include <iostream>
#include <fstream>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TLabel *Mundo;
	TLabel *Viewport;
	TButton *Button1;
	TListBox *ListBox_Poligonos;
	TListBox *ListBox_Pontos;
	TLabel *Label_Poligonos;
	TLabel *Label_Pontos;
	TButton *Inicia;
	TEdit *xMin;
	TEdit *xMax;
	TEdit *yMin;
	TEdit *yMax;
	TLabel *Coordenadas_Viewport;
	TLabel *Coordenadas_Mundo;
	TButton *up;
	TButton *left;
	TButton *down;
	TButton *right;
	TButton *Zoom_in;
	TButton *Zoom_out;
	TRadioGroup *RadioGroup_TipoReta;
	TEdit *edx;
	TEdit *edy;
	TButton *Translacao;
	TLabel *Operacoes_pol;
	TButton *Clipping;
	TButton *Clear;
	TButton *Circunferência;
	TButton *Escalonamento;
	TButton *Rotação;
	TEdit *angulo;
	TButton *Reflexao;
	TEdit *dx;
	TEdit *dy;
	TEdit *dz;
	TButton *Escalonamentod;
	TButton *rotacaoHomo;
	TRadioGroup *Eixo;
	TPageControl *PageControl;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TRadioGroup *RadioGroup_TipoCurva;
	TButton *Curva;
	TButton *Translacaod;
	TButton *Cubo;
	TButton *Piramide;
	TButton *Button4;
	TEdit *anguloD;
	void __fastcall FormDblClick(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ListBox_PoligonosClick(TObject *Sender);
	void __fastcall IniciaClick(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall upClick(TObject *Sender);
	void __fastcall leftClick(TObject *Sender);
	void __fastcall rightClick(TObject *Sender);
	void __fastcall downClick(TObject *Sender);
	void __fastcall Zoom_inClick(TObject *Sender);
	void __fastcall Zoom_outClick(TObject *Sender);
	void __fastcall TranslacaoClick(TObject *Sender);
	void __fastcall ClippingClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall CircunferênciaClick(TObject *Sender);
	void __fastcall RotaçãoClick(TObject *Sender);
	void __fastcall EscalonamentoClick(TObject *Sender);
	void __fastcall rotacaoHomoClick(TObject *Sender);
	void __fastcall ReflexaoClick(TObject *Sender);
	void __fastcall CurvaClick(TObject *Sender);
	void __fastcall TranslacaodClick(TObject *Sender);
	void __fastcall EscalonamentodClick(TObject *Sender);
	void __fastcall PiramideClick(TObject *Sender);
	void __fastcall CuboClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void atualizaMundo(Janela mundo);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

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
#include "Ujanela.h"
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
	TLabel *Label1;
	void __fastcall FormDblClick(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
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

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void atualizaMundo(Janela mundo);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

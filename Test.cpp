//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Test.h"

Ponto aux;
Poligono pol;
DisplayFile display;

Janela mundo(-250,-250,250,250);
Janela vp(0,0,500,500);
Janela clipping(-100, -100, 100, 100);

bool inicia = false;

double xVp_Mundo(int xVp, Janela mundo, Janela vp){
	return ((xVp - vp.xMin) / (vp.xMax - vp.xMin)) * (mundo.xMax - mundo.xMin) + mundo.xMin;
}

double yVp_Mundo(int yVp, Janela mundo, Janela vp){
	return (1 - ((yVp - vp.yMin) / (vp.yMax - vp.yMin))) * (mundo.yMax - mundo.yMin) + mundo.yMin;
}

int contId = 0;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	/*
	Form1->Image1->Canvas->Brush->Color = clRed;
	Form1->Image1->Canvas->FillRect(Rect(0,0,500,500));

	//configura a caneta pra se escrever
	Form1->Image1->Canvas->Pen->Color = clBlack;
	Form1->Image1->Canvas->Pen->Width = 3;
	//movimenta a caneta pra posicao inicial para pintar
	Form1->Image1->Canvas->MoveTo(250,0);
    //escreve uma linha da posicao atual ate a posicao desejada
	Form1->Image1->Canvas->LineTo(250,500);

    //desenha o eixo x
	Form1->Image1->Canvas->MoveTo(0,250);
	Form1->Image1->Canvas->LineTo(500,250);
	*/

	/*transformando cordenada de vp para mundo e populando um ponto aux
	aux.x = xVp_Mundo(250, mundo, vp);
	aux.y = yVp_Mundo(0, mundo, vp);

	ou

	aux.x = 0;
	aux.y = mundo.yMax;*/

	//coloca os pontos no poligono pol para desenhar o eixo y
	pol.id = contId++;
    pol.tipo = 'E';
	pol.pontos.push_back(Ponto(0, mundo.yMax));
	pol.pontos.push_back(Ponto(0, mundo.yMin));

	display.poligonos.push_back(pol);
	pol.pontos.clear();

	pol.id = contId++;
	pol.tipo = 'E';
	pol.pontos.push_back(Ponto(mundo.xMax, 0));
	pol.pontos.push_back(Ponto(mundo.xMin, 0));

	display.poligonos.push_back(pol);
	pol.pontos.clear();

	//LIMITE DO CLIPPING
	pol.id = contId++;
	pol.tipo = 'P';
	pol.pontos.push_back(Ponto(clipping.xMin, clipping.yMax));
	pol.pontos.push_back(Ponto(clipping.xMax, clipping.yMax));

	pol.pontos.push_back(Ponto(clipping.xMax, clipping.yMin));
	pol.pontos.push_back(Ponto(clipping.xMin, clipping.yMin));
	pol.pontos.push_back(Ponto(clipping.xMin, clipping.yMax));

    display.poligonos.push_back(pol);
	pol.pontos.clear();

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);

    display.mostra(Form1->ListBox_Poligonos);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDblClick(TObject *Sender)
{
    if(Form1->Color == clRed)
		Form1->Color = clGreen;
	else
		Form1->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
			  Viewport->Caption = "(" + IntToStr(X) + "," + IntToStr(Y) + ")";

			  double xW, yW;
			  xW = xVp_Mundo(X, mundo, vp);
			  yW = yVp_Mundo(Y, mundo, vp);

			  Mundo->Caption = "(" + FloatToStr(xW) + "," + FloatToStr(yW) + ")";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	/*int x, y;
	Ponto a(0,0);
	x = a.xWVp(mundo, vp);
	y = a.yWVp(mundo, vp);


	ShowMessage(IntToStr(x) + "," + IntToStr(y));

    ListBox_Poligonos->Items->Clear();
	ListBox_Poligonos->Items->Add(Ponto(10,10).mostraPonto());*/

	//atualiza o tamanho do mundo
	mundo.xMin = StrToFloat(xMin->Text);
	mundo.yMin = StrToFloat(yMin->Text);
	mundo.xMax = StrToFloat(xMax->Text);
	mundo.yMax = StrToFloat(yMax->Text);

	//atualiza o eixo
	display.poligonos[0].pontos[0].y = mundo.yMax;
	display.poligonos[0].pontos[1].y = mundo.yMin;
	display.poligonos[1].pontos[0].x = mundo.xMin;
	display.poligonos[1].pontos[1].x = mundo.xMax;

	display.mostra(Form1->ListBox_Poligonos);
    display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox_PoligonosClick(TObject *Sender)
{
	display.poligonos[ListBox_Poligonos->ItemIndex].mostraPontos(ListBox_Pontos);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::IniciaClick(TObject *Sender)
{
	inicia = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	double xW, yW;

	if (inicia) {
        //clicar com o botao da esquerda vai criar um ponto novo no poligono auxiliar
		if (Button == mbLeft) {
			xW = xVp_Mundo(X, mundo, vp);
			yW = yVp_Mundo(Y, mundo, vp);

			pol.pontos.push_back(Ponto(xW, yW));
			pol.desenha(Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
		}
		else {
            //clicar com o botao da direita vai armazenar os pontos no poligono e desenhar no canvas
			if (Button == mbRight) {
				pol.id = contId++;
				pol.tipo = 'N';
				display.poligonos.push_back(pol);
				pol.pontos.clear();
				inicia = false;
				display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
				display.mostra(Form1->ListBox_Poligonos);
			}
        }
	}
}
//---------------------------------------------------------------------------

void TForm1::atualizaMundo(Janela mundo){
    //atualiza o tamanho do mundo
	xMin->Text = FloatToStr(mundo.xMin);
	yMin->Text = FloatToStr(mundo.yMin);
	xMax->Text = FloatToStr(mundo.xMax);
	yMax->Text = FloatToStr(mundo.yMax);

	//atualiza o eixo
	display.poligonos[0].pontos[0].y = mundo.yMax;
	display.poligonos[0].pontos[1].y = mundo.yMin;
	display.poligonos[1].pontos[0].x = mundo.xMin;
	display.poligonos[1].pontos[1].x = mundo.xMax;

	display.mostra(ListBox_Poligonos);
}

void __fastcall TForm1::upClick(TObject *Sender)
{
	//set coordinates up
	mundo.yMin -= 10;
	mundo.yMax -= 10;

	atualizaMundo(mundo);

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::leftClick(TObject *Sender)
{
	//set coordinates left
	mundo.xMin += 10;
	mundo.xMax += 10;

	atualizaMundo(mundo);

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightClick(TObject *Sender)
{
	//set coordinates right
	mundo.xMin -= 10;
	mundo.xMax -= 10;

	atualizaMundo(mundo);

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::downClick(TObject *Sender)
{
	//set coordinates down
	mundo.yMin += 10;
	mundo.yMax += 10;

	atualizaMundo(mundo);

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zoom_inClick(TObject *Sender)
{
	//zoom in
	mundo.xMin += 10;
	mundo.yMin += 10;
	mundo.xMax -= 10;
	mundo.yMax -= 10;

    atualizaMundo(mundo);

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zoom_outClick(TObject *Sender)
{
	//zoom out
	mundo.xMin -= 10;
	mundo.yMin -= 10;
	mundo.xMax += 10;
	mundo.yMax += 10;

    atualizaMundo(mundo);

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TranslacaoClick(TObject *Sender)
{
	double dx, dy;

	try {
		dx = StrToFloat(edx->Text);
		dy = StrToFloat(edy->Text);
	} catch (...) {
		ShowMessage("Erro ao converter para float");
		return;
	}

	if (ListBox_Poligonos->ItemIndex == -1) {
		ShowMessage("Nenhum Poligono selecionado");
        return;
	}

	display.poligonos[ListBox_Poligonos->ItemIndex].translacao(dx, dy);

	display.desenha(Form1->Image1->Canvas, mundo, vp, RadioGroup_TipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClippingClick(TObject *Sender)
{
	display.clipping(Form1->Image1->Canvas, mundo, vp, clipping);
    display.mostra(ListBox_Poligonos);

}
//---------------------------------------------------------------------------


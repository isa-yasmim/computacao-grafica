object Form1: TForm1
  Left = 0
  Top = 0
  Caption = '-'
  ClientHeight = 955
  ClientWidth = 1068
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  Scaled = False
  OnDblClick = FormDblClick
  TextHeight = 15
  object Mundo: TLabel
    Left = 72
    Top = 33
    Width = 3
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
  end
  object Viewport: TLabel
    Left = 72
    Top = 63
    Width = 3
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
  end
  object Label_Poligonos: TLabel
    Left = 866
    Top = 36
    Width = 53
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Poligonos'
  end
  object Label_Pontos: TLabel
    Left = 866
    Top = 296
    Width = 37
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Pontos'
  end
  object Coordenadas_Viewport: TLabel
    Left = 480
    Top = 569
    Width = 70
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Y MIN - MAX'
  end
  object Coordenadas_Mundo: TLabel
    Left = 272
    Top = 567
    Width = 70
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'X MIN - MAX'
  end
  object Label1: TLabel
    Left = 60
    Top = 724
    Width = 961
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 
      'Operacoes de poligono ------------------------------------------' +
      '----------------------------------------------------------------' +
      '-------------------------------------------------------------'
  end
  object Panel1: TPanel
    Left = 272
    Top = 39
    Width = 502
    Height = 502
    BevelWidth = 502
    TabOrder = 0
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 505
      Height = 505
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
    end
  end
  object Button1: TButton
    Left = 80
    Top = 613
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Atualiza mundo'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ListBox_Poligonos: TListBox
    Left = 866
    Top = 63
    Width = 150
    Height = 200
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ItemHeight = 15
    TabOrder = 2
    OnClick = ListBox_PoligonosClick
  end
  object ListBox_Pontos: TListBox
    Left = 866
    Top = 323
    Width = 150
    Height = 200
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ItemHeight = 15
    TabOrder = 3
  end
  object Inicia: TButton
    Left = 80
    Top = 391
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Inicia'
    DisabledImageName = 'Inicia'
    TabOrder = 4
    OnClick = IniciaClick
  end
  object xMin: TEdit
    Left = 272
    Top = 590
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'Japanese'
    TabOrder = 5
    Text = '-250'
  end
  object xMax: TEdit
    Left = 272
    Top = 640
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'xMax'
    TabOrder = 6
    Text = '250'
  end
  object yMin: TEdit
    Left = 480
    Top = 592
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'yMin'
    TabOrder = 7
    Text = '-250'
  end
  object yMax: TEdit
    Left = 480
    Top = 640
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    BevelOuter = bvNone
    ImeName = 'Japanese'
    TabOrder = 8
    Text = '250'
  end
  object up: TButton
    Left = 922
    Top = 551
    Width = 37
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #652
    DisabledImageName = 'up'
    TabOrder = 9
    OnClick = upClick
  end
  object left: TButton
    Left = 877
    Top = 592
    Width = 37
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '<'
    DisabledImageName = 'left'
    TabOrder = 10
    OnClick = leftClick
  end
  object down: TButton
    Left = 922
    Top = 633
    Width = 37
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'v'
    DisabledImageName = 'down'
    TabOrder = 11
    OnClick = downClick
  end
  object right: TButton
    Left = 967
    Top = 592
    Width = 37
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '>'
    DisabledImageName = 'right'
    TabOrder = 12
    OnClick = rightClick
  end
  object Zoom_in: TButton
    Left = 690
    Top = 580
    Width = 37
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '+'
    DisabledImageName = 'Zoom_in'
    TabOrder = 13
    OnClick = Zoom_inClick
  end
  object Zoom_out: TButton
    Left = 690
    Top = 633
    Width = 37
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '-'
    DisabledImageName = 'Zoom_out'
    TabOrder = 14
    OnClick = Zoom_outClick
  end
  object RadioGroup_TipoReta: TRadioGroup
    Left = 72
    Top = 148
    Width = 121
    Height = 197
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Line type'
    ItemIndex = 0
    Items.Strings = (
      'LineTo'
      'DDA'
      'Bresenham')
    TabOrder = 15
  end
  object edx: TEdit
    Left = 60
    Top = 778
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'Japanese'
    TabOrder = 16
    Text = 'edx'
  end
  object edy: TEdit
    Left = 60
    Top = 826
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'edy'
    TabOrder = 17
    Text = 'edy'
  end
  object Translacao: TButton
    Left = 80
    Top = 865
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Translacao'
    DisabledImageName = 'Translacao'
    TabOrder = 18
    OnClick = TranslacaoClick
  end
end

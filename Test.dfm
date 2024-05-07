object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'angulo'
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
    Left = 854
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
    Left = 854
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
  object Operacoes_pol: TLabel
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
    Left = 854
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
    Left = 854
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
    Top = 367
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
    Left = 914
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
    Left = 869
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
    Left = 914
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
    Left = 959
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
  object edx: TEdit
    Left = 60
    Top = 762
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'Japanese'
    TabOrder = 15
    Text = 'edx'
  end
  object edy: TEdit
    Left = 60
    Top = 801
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'edy'
    TabOrder = 16
    Text = 'edy'
  end
  object Translacao: TButton
    Left = 80
    Top = 847
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Translacao'
    DisabledImageName = 'Translacao'
    TabOrder = 17
    OnClick = TranslacaoClick
  end
  object Clipping: TButton
    Left = 80
    Top = 529
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Clipping'
    DisabledImageName = 'Clipping'
    TabOrder = 18
    OnClick = ClippingClick
  end
  object Clear: TButton
    Left = 208
    Top = 39
    Width = 41
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'X'
    DisabledImageName = 'Clear'
    TabOrder = 19
    OnClick = ClearClick
  end
  object Circunferência: TButton
    Left = 80
    Top = 422
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Circunfer'#234'ncia'
    DisabledImageName = 'Circunfer'#234'ncia'
    TabOrder = 20
    OnClick = CircunferênciaClick
  end
  object Escalonamento: TButton
    Left = 80
    Top = 894
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Escalonamento'
    DisabledImageName = 'Escalonamento'
    TabOrder = 21
    OnClick = EscalonamentoClick
  end
  object Rotação: TButton
    Left = 272
    Top = 801
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rota'#231#227'o'
    DisabledImageName = 'Rota'#231#227'o'
    TabOrder = 22
    OnClick = RotaçãoClick
  end
  object angulo: TEdit
    Left = 252
    Top = 762
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'angulo'
    TabOrder = 23
    Text = 'angulo'
  end
  object Reflexao: TButton
    Left = 272
    Top = 894
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Reflexao'
    DisabledImageName = 'Reflexao'
    TabOrder = 24
    OnClick = ReflexaoClick
  end
  object dx: TEdit
    Left = 626
    Top = 762
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'dx'
    TabOrder = 25
    Text = 'dx'
  end
  object dy: TEdit
    Left = 626
    Top = 805
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'dy'
    TabOrder = 26
    Text = 'dy'
  end
  object dz: TEdit
    Left = 626
    Top = 851
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'dz'
    TabOrder = 27
    Text = 'dz'
  end
  object Escalonamentod: TButton
    Left = 813
    Top = 821
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Escalonamento'
    DisabledImageName = 'Escalonamento'
    TabOrder = 28
    OnClick = EscalonamentodClick
  end
  object rotacaoHomo: TButton
    Left = 272
    Top = 848
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rota'#231#227'o Homo'
    DisabledImageName = 'rotacaoHomo'
    TabOrder = 29
    OnClick = rotacaoHomoClick
  end
  object Eixo: TRadioGroup
    Left = 453
    Top = 762
    Width = 121
    Height = 156
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Eixo'
    ItemIndex = 0
    Items.Strings = (
      'X'
      'Y'
      'XY')
    TabOrder = 30
  end
  object PageControl: TPageControl
    Left = 32
    Top = 101
    Width = 201
    Height = 241
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = TabSheet2
    TabOrder = 31
    object TabSheet1: TTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'Line type'
      object RadioGroup_TipoReta: TRadioGroup
        Left = 5
        Top = 5
        Width = 183
        Height = 201
        Margins.Left = 5
        Margins.Top = 5
        Margins.Right = 5
        Margins.Bottom = 5
        Caption = 'Line type'
        ItemIndex = 0
        Items.Strings = (
          'LineTo'
          'DDA'
          'Bresenham')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'Curve type'
      ImageIndex = 1
      object RadioGroup_TipoCurva: TRadioGroup
        Left = 6
        Top = 6
        Width = 181
        Height = 199
        Margins.Left = 6
        Margins.Top = 6
        Margins.Right = 6
        Margins.Bottom = 6
        Caption = 'Curve type'
        ItemIndex = 0
        Items.Strings = (
          'B-Spline'
          'Hermite'
          'Brezier'
          'Casteljau'
          'Foward')
        TabOrder = 0
      end
    end
  end
  object Curva: TButton
    Left = 80
    Top = 474
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Curva'
    DisabledImageName = 'Curva'
    TabOrder = 32
    OnClick = CurvaClick
  end
  object Translacaod: TButton
    Left = 812
    Top = 767
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Translacao'
    DisabledImageName = 'Translacaod'
    TabOrder = 33
    OnClick = TranslacaodClick
  end
  object Cubo: TButton
    Left = 927
    Top = 847
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Cubo'
    DisabledImageName = 'Cubo'
    TabOrder = 34
    OnClick = CuboClick
  end
  object Piramide: TButton
    Left = 927
    Top = 804
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Piramide'
    DisabledImageName = 'Piramide'
    TabOrder = 35
    OnClick = PiramideClick
  end
  object Button4: TButton
    Left = 813
    Top = 878
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rotacao'
    DisabledImageName = 'Translacaod'
    TabOrder = 36
    OnClick = Button4Click
  end
  object anguloD: TEdit
    Left = 626
    Top = 898
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ImeName = 'Japanese'
    TabOrder = 37
    Text = 'angulo'
  end
end

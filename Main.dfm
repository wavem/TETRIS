object FormMain: TFormMain
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Tetris'
  ClientHeight = 739
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object __Main: TPanel
    Left = 0
    Top = 0
    Width = 1018
    Height = 739
    Align = alClient
    BevelOuter = bvNone
    Color = clGray
    ParentBackground = False
    TabOrder = 0
    object Notebook_Main: TNotebook
      Left = 0
      Top = 0
      Width = 1018
      Height = 739
      Align = alClient
      PageIndex = 2
      TabOrder = 0
      object TPage
        Left = 0
        Top = 0
        Caption = 'Default'
        object __MainPage_00_Default: TPanel
          Left = 0
          Top = 0
          Width = 1018
          Height = 739
          Align = alClient
          BevelOuter = bvNone
          Color = clGray
          ParentBackground = False
          TabOrder = 0
        end
      end
      object TPage
        Left = 0
        Top = 0
        HelpContext = 1
        Caption = 'Login'
        object __MainPage_01_Login: TPanel
          Left = 0
          Top = 0
          Width = 1018
          Height = 739
          Align = alClient
          BevelOuter = bvNone
          Color = clCream
          ParentBackground = False
          TabOrder = 0
          object btn_GO: TAdvGlassButton
            Left = 464
            Top = 440
            Width = 100
            Height = 32
            BackColor = clBlack
            Caption = 'GO'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ForeColor = clWhite
            GlowColor = 16760205
            InnerBorderColor = clBlack
            OuterBorderColor = clWhite
            ParentFont = False
            ShineColor = clWhite
            TabOrder = 0
            Version = '1.3.0.2'
            OnClick = btn_GOClick
          end
        end
      end
      object TPage
        Left = 0
        Top = 0
        HelpContext = 2
        Caption = 'Main_Tetris'
        object __MainPage_02_Main: TPanel
          Left = 0
          Top = 0
          Width = 1018
          Height = 739
          Align = alClient
          BevelOuter = bvNone
          Color = clSilver
          DoubleBuffered = True
          ParentBackground = False
          ParentDoubleBuffered = False
          TabOrder = 0
          object btn_LogOut: TcxButton
            Left = 928
            Top = 704
            Width = 75
            Height = 25
            Caption = 'Back'
            TabOrder = 0
            OnClick = btn_LogOutClick
          end
          object grid_Mine: TAdvStringGrid
            Left = 320
            Top = 86
            Width = 324
            Height = 644
            Cursor = crDefault
            TabStop = False
            BevelInner = bvNone
            BevelOuter = bvNone
            Color = clBlack
            ColCount = 10
            DefaultColWidth = 32
            DefaultRowHeight = 32
            DrawingStyle = gdsClassic
            FixedCols = 0
            RowCount = 20
            FixedRows = 0
            Options = [goVertLine, goHorzLine]
            ScrollBars = ssNone
            TabOrder = 1
            OnKeyDown = grid_MineKeyDown
            HoverRowCells = [hcNormal, hcSelected]
            ActiveCellFont.Charset = DEFAULT_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Tahoma'
            ActiveCellFont.Style = [fsBold]
            ControlLook.FixedGradientHoverFrom = clGray
            ControlLook.FixedGradientHoverTo = clWhite
            ControlLook.FixedGradientDownFrom = clGray
            ControlLook.FixedGradientDownTo = clSilver
            ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownHeader.Font.Color = clWindowText
            ControlLook.DropDownHeader.Font.Height = -11
            ControlLook.DropDownHeader.Font.Name = 'Tahoma'
            ControlLook.DropDownHeader.Font.Style = []
            ControlLook.DropDownHeader.Visible = True
            ControlLook.DropDownHeader.Buttons = <>
            ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownFooter.Font.Color = clWindowText
            ControlLook.DropDownFooter.Font.Height = -11
            ControlLook.DropDownFooter.Font.Name = 'Tahoma'
            ControlLook.DropDownFooter.Font.Style = []
            ControlLook.DropDownFooter.Visible = True
            ControlLook.DropDownFooter.Buttons = <>
            EnableHTML = False
            EnableWheel = False
            EnhRowColMove = False
            Filter = <>
            FilterDropDown.Font.Charset = DEFAULT_CHARSET
            FilterDropDown.Font.Color = clWindowText
            FilterDropDown.Font.Height = -11
            FilterDropDown.Font.Name = 'Tahoma'
            FilterDropDown.Font.Style = []
            FilterDropDown.TextChecked = 'Checked'
            FilterDropDown.TextUnChecked = 'Unchecked'
            FilterDropDownMultiCol = False
            FilterDropDownClear = '(All)'
            FilterEdit.TypeNames.Strings = (
              'Starts with'
              'Ends with'
              'Contains'
              'Not contains'
              'Equal'
              'Not equal'
              'Larger than'
              'Smaller than'
              'Clear')
            FixedColWidth = 32
            FixedRowHeight = 32
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -11
            FixedFont.Name = 'Tahoma'
            FixedFont.Style = [fsBold]
            FloatFormat = '%.2f'
            HoverButtons.Buttons = <>
            HoverButtons.Position = hbLeftFromColumnLeft
            HTMLSettings.ImageFolder = 'images'
            HTMLSettings.ImageBaseName = 'img'
            IntelliZoom = False
            Look = glSoft
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'Tahoma'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'Tahoma'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'Tahoma'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'Tahoma'
            PrintSettings.FooterFont.Style = []
            PrintSettings.PageNumSep = '/'
            SearchFooter.Color = clBtnFace
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'Tahoma'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurrence'
            SearchFooter.HintFindPrev = 'Find previous occurrence'
            SearchFooter.HintHighlight = 'Highlight occurrences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SelectionColor = clHighlight
            SelectionTextColor = clHighlightText
            ShowSelection = False
            SortSettings.DefaultFormat = ssAutomatic
            Version = '7.8.0.1'
          end
          object memo: TMemo
            Left = 818
            Top = 120
            Width = 185
            Height = 578
            ScrollBars = ssVertical
            TabOrder = 2
          end
          object btn_START: TButton
            Left = 712
            Top = 112
            Width = 75
            Height = 25
            Caption = 'START'
            TabOrder = 3
            OnClick = btn_STARTClick
          end
          object Edit1: TEdit
            Left = 704
            Top = 85
            Width = 121
            Height = 21
            TabOrder = 4
            Text = 'Edit1'
          end
        end
      end
    end
  end
end

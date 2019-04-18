//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Define.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGlassButton"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCreate(TObject *Sender)
{
    InitTetris();
	RefreshMyGameView();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::InitTetris() {
	Notebook_Main->PageIndex = 1; // Login
	m_row = 0;
	m_col = 0;
	grid_Mine->Colors[m_col][m_row] = clBlue;

	for(int i = 0 ; i < 10 ; i++) {
		for(int j = 0 ; j < 20 ; j++) {
			m_MyView[i][j] = 0;
        }
	}

	m_Current_X = 0;
	m_Current_Y = 0;


}
//---------------------------------------------------------------------------


void __fastcall TFormMain::btn_GOClick(TObject *Sender)
{
	Notebook_Main->PageIndex = 2;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_LogOutClick(TObject *Sender)
{
	Notebook_Main->PageIndex = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::grid_MineKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{

	if(!m_CB) return;

	bool t_ret = false;
	if(Key == VK_RIGHT) t_ret = m_CB->MoveRight();
	if(Key == VK_LEFT) t_ret = m_CB->MoveLeft();
	if(Key == VK_UP) t_ret = m_CB->RotateRight();
	if(Key == VK_DOWN) t_ret = m_CB->MoveDown();
	if(Key == VK_SPACE) t_ret = m_CB->Drop();

	if(t_ret) DrawCurrentBlock(m_CB->Point);
	return;


	// Set Start Point (Temp)
	int t_Current_X = m_Current_X;
	int t_Current_Y = m_Current_Y;
	int t_Current_X_Old = t_Current_X;
	int t_Current_Y_Old = t_Current_Y;
	int t_Current_X_New = 0;
	int t_Current_Y_New = 0;


	if(Key == VK_RIGHT) {
		if(t_Current_Y < 9) {
			t_Current_Y++;
		}
	}

	if(Key == VK_LEFT) {
		if(t_Current_Y > 0) {
			t_Current_Y--;
		}
	}

	if(Key == VK_UP) {
		if(t_Current_X > 0) {
			t_Current_X--;
		}
	}

	if(Key == VK_DOWN) {
		if(t_Current_X < 19) {
			t_Current_X++;
		}
	}

	if(Key == VK_SPACE) {
        t_Current_X = 19;
    }

	t_Current_X_New = t_Current_X;
	t_Current_Y_New = t_Current_Y;

	m_Current_X = t_Current_X_New;
	m_Current_Y = t_Current_Y_New;

	m_MyView[t_Current_Y_Old][t_Current_X_Old] = 0;
	m_MyView[t_Current_Y_New][t_Current_X_New] = 1;

	RefreshMyGameView();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RefreshMyGameView() {

	BYTE t_Byte = 0;

	for(int i = 0 ; i < 10 ; i++) {
		for(int j = 0 ; j < 20 ; j++) {
			t_Byte = GetBlockStatus(m_MyView[i][j]);
			if(t_Byte == 1) {
				grid_Mine->Colors[i][j] = clBlue;
			} else {
				grid_Mine->Colors[i][j] = clBlack;
            }
        }
    }
}
//---------------------------------------------------------------------------

bool TFormMain::GetBitStatus(BYTE _src, int _bit) {
	if(_bit < 8 && _bit >= 0)	return (_src >> _bit) & 0x01;
	return false;
}
//---------------------------------------------------------------------------

BYTE TFormMain::GetBlockStatus(BYTE _src) {
	return (_src & 0x3F);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_STARTClick(TObject *Sender)
{
	int num = StrToInt(Edit1->Text);
	m_CB = new CCurrentBlock;
	if(m_CB->CreateNewBlock(num)) {
		DrawCurrentBlock(m_CB->Point);
    }
}
//---------------------------------------------------------------------------

bool TFormMain::DrawCurrentBlock(stPoint *_Point) {

	int t_X_Old = -1;
	int t_Y_Old = -1;
	int t_X_New = -1;
	int t_Y_New = -1;

	for(int i = 0 ; i < 4 ; i++) {
		t_X_Old = _Point[i].X_old;
		t_Y_Old = _Point[i].Y_old;

		if(t_X_Old != -1 && t_Y_Old != -1) m_MyView[t_X_Old][t_Y_Old] = 0x00;
	}

	for(int i = 0 ; i < 4 ; i++) {
	    t_X_New = _Point[i].X;
		t_Y_New = _Point[i].Y;

		m_MyView[t_X_New][t_Y_New] = 0x01;
    }
	RefreshMyGameView();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

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
	Notebook_Main->PageIndex = 1; // Login
	m_row = 0;
	m_col = 0;
	grid_Mine->Colors[m_col][m_row] = clBlue;
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
	if(Key == VK_RIGHT) {
		grid_Mine->Colors[m_col][m_row] = clBlack;
		m_col++;
		grid_Mine->Colors[m_col][m_row] = clBlue;
	}

	if(Key == VK_LEFT) {
		grid_Mine->Colors[m_col][m_row] = clBlack;
		m_col--;
		grid_Mine->Colors[m_col][m_row] = clBlue;
	}

	if(Key == VK_UP) {
		grid_Mine->Colors[m_col][m_row] = clBlack;
		m_row--;
		grid_Mine->Colors[m_col][m_row] = clBlue;
	}

	if(Key == VK_DOWN) {
		grid_Mine->Colors[m_col][m_row] = clBlack;
		m_row++;
		grid_Mine->Colors[m_col][m_row] = clBlue;
	}
}
//---------------------------------------------------------------------------


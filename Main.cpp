//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "common_func.h"
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

	for(int i = 0 ; i < 10 ; i++) {
		for(int j = 0 ; j < 20 ; j++) {
			m_MyView[i][j] = 0;
		}
	}
	m_Block = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_GOClick(TObject *Sender)
{
	Notebook_Main->PageIndex = 2; // MAIN GAME PAGE
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_LogOutClick(TObject *Sender)
{
	Notebook_Main->PageIndex = 1; // LOGIN PAGE
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::grid_MineKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{

	if(!m_Block) return;

	bool t_ret = false;
	if(Key == VK_RIGHT) t_ret = m_Block->MoveRight();
	if(Key == VK_LEFT)  t_ret = m_Block->MoveLeft();
	if(Key == VK_DOWN)  t_ret = m_Block->MoveDown();
	if(Key == VK_SPACE) t_ret = m_Block->Drop();
	if(Key == VK_UP)    t_ret = m_Block->RotateRight();
	if(Key == 0x43)    t_ret = m_Block->RotateRight(); // 0x43 : 'C'
	if(Key == 0x5A)    t_ret = m_Block->RotateLeft(); // 0x5A : 'Z'

	RefreshMyGameView();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RefreshMyGameView() {
	BYTE t_Byte = 0;
	for(int i = 0 ; i < 10 ; i++) {
		for(int j = 0 ; j < 20 ; j++) {
			t_Byte = GetBlockStatus(m_MyView[i][j]);
			if(t_Byte == 0x80) {
				grid_Mine->Colors[i][j] = clBlue;
			} else {
				grid_Mine->Colors[i][j] = clBlack;
            }
        }
    }
}
//---------------------------------------------------------------------------

BYTE TFormMain::GetBlockStatus(BYTE _src) {
	//return (_src & 0x3F);
	return (_src);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_STARTClick(TObject *Sender)
{
	memset(&(m_MyView[0][0]), 0, 200);
	int num = StrToInt(Edit1->Text);
	m_Block = new C_BLOCK(num, m_MyView);
	RefreshMyGameView();
	//delete m_Block;																							 `
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::PrintMessage(UnicodeString _str) {
	memo->Lines->Add(_str);
}
//---------------------------------------------------------------------------


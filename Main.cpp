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

	for(int i = 0 ; i < MAX_GRID_X ; i++) {
		for(int j = 0 ; j < MAX_GRID_Y ; j++) {
			m_MyView[i][j] = 0;
		}
	}
	m_Block = NULL;
	m_CreateSuccess = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RefreshMyGameView() {
	BYTE t_Byte = 0;
	for(int i = 0 ; i < MAX_GRID_X ; i++) {
		for(int j = 0 ; j < MAX_GRID_Y ; j++) {
			//t_Byte = GetBlockStatus(m_MyView[i][j]);
			t_Byte = GetBlockData(m_MyView[i][j]);

			switch(t_Byte) {
				case TYPE_BLOCK_O:
					grid_Mine->Colors[i][j] = clYellow;
					break;
				case TYPE_BLOCK_I:
					grid_Mine->Colors[i][j] = clBlue;
					break;
				case TYPE_BLOCK_T:
					grid_Mine->Colors[i][j] = clPurple;
					break;
				case TYPE_BLOCK_J:
					grid_Mine->Colors[i][j] = clGreen;
					break;
				case TYPE_BLOCK_L:
					grid_Mine->Colors[i][j] = clMenuHighlight;
					break;
				case TYPE_BLOCK_S:
					grid_Mine->Colors[i][j] = clRed;
					break;
				case TYPE_BLOCK_Z:
					grid_Mine->Colors[i][j] = clFuchsia;
					break;
				default:
					grid_Mine->Colors[i][j] = clBlack;
					break;
			}

#if 0
			if(t_Byte == 0x80) {
				grid_Mine->Colors[i][j] = clBlue;
			} else if(t_Byte == 0x30) {
				grid_Mine->Colors[i][j] = clYellow;
			} else {
				grid_Mine->Colors[i][j] = clBlack;
			}
#endif
        }
    }
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

void __fastcall TFormMain::PrintMessage(UnicodeString _str) {
	memo->Lines->Add(_str);
}
//---------------------------------------------------------------------------

BYTE TFormMain::GetBlockStatus(BYTE _src) {
	//return (_src & 0x3F);
	return (_src);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_STARTClick(TObject *Sender)
{
	memset(&(m_MyView[0][0]), 0, MAX_GRID_X * MAX_GRID_Y);
	int num = 0;
	srand((unsigned int)GetTickCount());
	num = rand() % 7;
	if(ed_BLOCK->Text != L"") num = StrToInt(ed_BLOCK->Text);
	m_Block = new C_BLOCK(num, m_MyView, &m_CreateSuccess);
	RefreshMyGameView();
	tm_Level->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::grid_MineKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	///***** PRE RETURN *****///
	if(!m_Block) return;
	bool t_ret = false;

	///***** COMMON INIT *****///
	srand((unsigned int)GetTickCount());
	int num = rand() % 7;

	///***** KEY MAP *****///
	if(Key == VK_RIGHT) t_ret = m_Block->MoveRight();
	if(Key == VK_LEFT)  t_ret = m_Block->MoveLeft();
	if(Key == VK_UP)    t_ret = m_Block->RotateRight();
	if(Key == 0x43)    t_ret = m_Block->RotateRight(); // 0x43 : 'C'
	if(Key == 0x5A)    t_ret = m_Block->RotateLeft(); // 0x5A : 'Z'

	if(Key == VK_DOWN) {
		t_ret = m_Block->MoveDown();
		if(t_ret) {
			delete m_Block;
			m_Block = NULL;
			m_Block = new C_BLOCK(num, m_MyView, &m_CreateSuccess);
		}
	}
	if(Key == VK_SPACE) {
		t_ret = m_Block->Drop();
		if(t_ret) {
			delete m_Block;
			m_Block = NULL;
			m_Block = new C_BLOCK(num, m_MyView, &m_CreateSuccess);
		}
	}

	RefreshMyGameView();

	if(!m_CreateSuccess) {
		delete m_Block;
		m_Block = NULL;
		ShowMessage(L"GAME OVER");
		tm_Level->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::tm_LevelTimer(TObject *Sender)
{
	if(!m_Block) return;

	///***** COMMON INIT *****///
	srand((unsigned int)GetTickCount());
	int num = rand() % 7;

	bool t_ret = m_Block->MoveDown();
	if(t_ret) {
		delete m_Block;
		m_Block = NULL;
		m_Block = new C_BLOCK(num, m_MyView, &m_CreateSuccess);
	}

	RefreshMyGameView();

	if(!m_CreateSuccess) {
		delete m_Block;
		m_Block = NULL;
		ShowMessage(L"GAME OVER");
		tm_Level->Enabled = false;
	}
}
//---------------------------------------------------------------------------


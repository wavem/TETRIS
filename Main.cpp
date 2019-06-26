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
#pragma link "PictureContainer"
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
	//RefreshMyGameView();
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
	m_Score = 0;

	///***** LOAD BITMAP IMAGE *****///
	LoadBMPFiles();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::LoadBMPFiles() {

	///***** BLOCKS *****///
	m_BmpList[BLOCK_O] = new TBitmap;
	m_BmpList[BLOCK_O]->LoadFromFile(L".\\IMG\\O.bmp");
	m_BmpList[BLOCK_I] = new TBitmap;
	m_BmpList[BLOCK_I]->LoadFromFile(L".\\IMG\\I.bmp");
	m_BmpList[BLOCK_T] = new TBitmap;
	m_BmpList[BLOCK_T]->LoadFromFile(L".\\IMG\\T.bmp");
	m_BmpList[BLOCK_J] = new TBitmap;
	m_BmpList[BLOCK_J]->LoadFromFile(L".\\IMG\\J.bmp");
	m_BmpList[BLOCK_L] = new TBitmap;
	m_BmpList[BLOCK_L]->LoadFromFile(L".\\IMG\\L.bmp");
	m_BmpList[BLOCK_S] = new TBitmap;
	m_BmpList[BLOCK_S]->LoadFromFile(L".\\IMG\\S.bmp");
	m_BmpList[BLOCK_Z] = new TBitmap;
	m_BmpList[BLOCK_Z]->LoadFromFile(L".\\IMG\\Z.bmp");
	m_BmpList[BLOCK_N] = new TBitmap;
	m_BmpList[BLOCK_N]->LoadFromFile(L".\\IMG\\N.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::grid_MineDrawCell(TObject *Sender, int ACol, int ARow,
		  TRect &Rect, TGridDrawState State)
{
	TAdvStringGrid *p_grid = (TAdvStringGrid*)Sender;

	BYTE t_Byte = 0;
	t_Byte = GetBlockData(m_MyView[ACol][ARow]);
	switch(t_Byte) {
		case TYPE_BLOCK_O:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_O];
			break;
		case TYPE_BLOCK_I:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_I];
			break;
		case TYPE_BLOCK_T:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_T];
			break;
		case TYPE_BLOCK_J:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_J];
			break;
		case TYPE_BLOCK_L:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_L];
			break;
		case TYPE_BLOCK_S:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_S];
			break;
		case TYPE_BLOCK_Z:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_Z];
			break;
		default:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_N];
			break;
	}
	p_grid->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::OnDrawCell_Players(TObject *Sender, int ACol, int ARow,
		  TRect &Rect, TGridDrawState State)
{
	TAdvStringGrid *p_grid = (TAdvStringGrid*)Sender;

	BYTE t_Byte = 0;
	t_Byte = GetBlockData(m_MyView[ACol][ARow + 3]);
	switch(t_Byte) {
		case TYPE_BLOCK_O:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_O];
			break;
		case TYPE_BLOCK_I:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_I];
			break;
		case TYPE_BLOCK_T:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_T];
			break;
		case TYPE_BLOCK_J:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_J];
			break;
		case TYPE_BLOCK_L:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_L];
			break;
		case TYPE_BLOCK_S:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_S];
			break;
		case TYPE_BLOCK_Z:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_Z];
			break;
		default:
			p_grid->Canvas->Brush->Bitmap = m_BmpList[BLOCK_N];
			break;
	}
	p_grid->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RefreshOthersGameView() {
	TAdvStringGrid *p_grid = NULL;
	UnicodeString tempStr = L"";

	for(int i = 1 ; i < 6 ; i++) {
		tempStr.sprintf(L"grid_P%d", i);
		p_grid = (TAdvStringGrid*)FindComponent(tempStr);
		if(!p_grid) continue;
		p_grid->Refresh();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RefreshMyGameView() {
	grid_Mine->Refresh();

#if 0
	BYTE t_Byte = 0;
	for(int i = 0 ; i < MAX_GRID_X ; i++) {
		for(int j = 0 ; j < MAX_GRID_Y ; j++) {
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
        }
	}
#endif
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

void __fastcall TFormMain::btn_STARTClick(TObject *Sender)
{
	m_Score = 0;
	AddScore(m_Score);
	memset(&(m_MyView[0][0]), 0, MAX_GRID_X * MAX_GRID_Y);
	RefreshOthersGameView(); // THIS FUNC MUST BE HERE (after memset 0)
	int num = 0;
	srand((unsigned int)GetTickCount());
	num = rand() % 7;
	if(ed_BLOCK->Text != L"") num = StrToInt(ed_BLOCK->Text);
	m_Block = new C_BLOCK(num, m_MyView, &m_CreateSuccess);
	RefreshMyGameView();
	tm_Level->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::AddScore(int _Value) {
	m_Score += _Value;
	lb_Score_Value->Caption = m_Score;
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
			RefreshOthersGameView();
			m_Block = new C_BLOCK(num, m_MyView, &m_CreateSuccess);
		}
	}
	if(Key == VK_SPACE) {
		t_ret = m_Block->Drop();
		if(t_ret) {
			delete m_Block;
			m_Block = NULL;
			RefreshOthersGameView();
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

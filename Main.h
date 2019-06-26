//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvGlassButton.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include <Vcl.Menus.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *__Main;
	TNotebook *Notebook_Main;
	TPanel *__MainPage_00_Default;
	TPanel *__MainPage_01_Login;
	TAdvGlassButton *btn_GO;
	TPanel *__MainPage_02_Main;
	TcxButton *btn_LogOut;
	TAdvStringGrid *grid_Mine;
	TMemo *memo;
	TButton *btn_START;
	TEdit *ed_BLOCK;
	TPanel *pn_Cover;
	TAdvStringGrid *grid_NEXT;
	TAdvStringGrid *grid_P1;
	TAdvStringGrid *grid_P2;
	TAdvStringGrid *grid_P3;
	TAdvStringGrid *grid_P4;
	TAdvStringGrid *grid_P5;
	TAdvStringGrid *grid_Items;
	TTimer *tm_Level;
	TLabel *lb_Score_Title;
	TLabel *lb_Score_Value;
	TLabel *lb_Combo_Title;
	TLabel *lb_Combo_Value;
	void __fastcall btn_GOClick(TObject *Sender);
	void __fastcall btn_LogOutClick(TObject *Sender);
	void __fastcall grid_MineKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall btn_STARTClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tm_LevelTimer(TObject *Sender);
	void __fastcall grid_MineDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall OnDrawCell_Players(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);

private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);


///***** START MJW *****///

///***** PROPERTY *****///
public:
	void __fastcall InitTetris();
	int m_row;
	int m_col;
	BYTE m_MyView[MAX_GRID_X][MAX_GRID_Y];
	C_BLOCK *m_Block;
	bool m_CreateSuccess;
	int m_Score;
	TBitmap *m_BmpList[64];
	void __fastcall LoadBMPFiles();


public: // Control Information
	void __fastcall AddScore(int _Value);

public: // Display
	void __fastcall RefreshMyGameView();
	void __fastcall RefreshOthersGameView();


///***** ETC *****///
public:
	void __fastcall PrintMessage(UnicodeString _str);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif

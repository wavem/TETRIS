//---------------------------------------------------------------------------

#pragma hdrstop

#include "Item.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall TFormMain::CreateRandomItem() {

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::USE_ITEM_PLUS() {

	int num = rand() % 9;
	int t_TopLine = MAX_GRID_Y - 1;
	bool t_bFindComplete = false;
	for(int y = 2 ; y <= MAX_GRID_Y - 1 ; y++) {
		for(int x = 0 ; x < 10 ; x++) {
			if(GetBlockData(m_MyView[x][y]) != 0 && !GetBitStatus(m_MyView[x][y], 7) && !GetBitStatus(m_MyView[x][y], 6)) {
				t_TopLine = y;
				t_bFindComplete = true;
				break;
			}
		}
		if(t_bFindComplete) break;
	}

	///***** CASE : THERE IS NOTHING *****///
	if(!t_bFindComplete) {
		for(int x = 0 ; x < 10 ; x++) {
			if(x == num) continue;
			m_MyView[x][t_TopLine] = TYPE_STATUS_ROCK;
		}
		return;
	}

	///***** CASE : FULL *****///
	if(t_TopLine == 2) {
		PrintMessage(L"GAME OVER");
	}


	///***** MOVE UP LINES *****///
	BYTE t_Byte = 0;
	bool t_b_IsMovedCurrentBlock = false;

	for(int y = t_TopLine ; y < MAX_GRID_Y ; y++) {
		for(int x = 0 ; x < 10 ; x++) {
			t_Byte = m_MyView[x][y];
			if(GetBitStatus(t_Byte, 7) || GetBitStatus(t_Byte, 6)) {
				continue;
			}

			if(GetBitStatus(m_MyView[x][y - 1], 7) && !t_b_IsMovedCurrentBlock) {
				m_Block->MoveUp();
				t_b_IsMovedCurrentBlock = true;
			}

			m_MyView[x][y - 1] = t_Byte;
			m_MyView[x][y] = 0;
		}
		if(y == MAX_GRID_Y - 1) {
			for(int x = 0 ; x < 10 ; x++) {
				if(x == num) continue;
				m_MyView[x][y] = TYPE_STATUS_ROCK;
			}
			return;
		}
	}
}
//---------------------------------------------------------------------------

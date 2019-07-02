//---------------------------------------------------------------------------

#pragma hdrstop

#include "Item.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall TFormMain::CreateRandomItem() {

	PrintMessage(L"CREATE RANDOM ITEM");

	///***** COMMON INIT *****///
	BYTE t_Byte = 0;
	int t_TopLine = MAX_GRID_Y - 1;
	bool t_bFindComplete = false;
	int total_block_cnt = 0;
	int check_cnt = 0;
	int randNum = 0;



	///***** FIND TOP LINE *****///
	for(int y = 0 ; y < MAX_GRID_Y ; y++) {
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
			if(GetBitStatus(m_MyView[x][y], 7) || GetBitStatus(m_MyView[x][y], 6)) continue;
			t_Byte = GetBlockData(m_MyView[x][y]);
			if(t_Byte != 0) {
				t_TopLine = y;
				t_bFindComplete = true;
				break;
			}
		}
		if(t_bFindComplete) break;
	}

	if(!t_bFindComplete) return; // YOU DO NOT DESERVED GET ITEM


	///***** GET TOTAL BLOCK NUMBER *****///
	for(int y = 0 ; y < MAX_GRID_Y ; y++) {
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
			if(GetBitStatus(m_MyView[x][y], 7) || GetBitStatus(m_MyView[x][y], 6)) continue;
			t_Byte = GetBlockData(m_MyView[x][y]);
			if(t_Byte != 0) total_block_cnt++;
		}
	}

	///***** GET RANDOM NUMBER *****///
	randNum = rand() % total_block_cnt;


	///***** GET ITEM *****///
	for(int y = 0 ; y < MAX_GRID_Y ; y++) {
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
			if(GetBitStatus(m_MyView[x][y], 7) || GetBitStatus(m_MyView[x][y], 6)) continue;
			t_Byte = GetBlockData(m_MyView[x][y]);
			if(t_Byte != 0) {
				if(check_cnt == randNum) {
                    m_MyView[x][y] = TYPE_ITEM_PLUS;
					return;
				}
				check_cnt++;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::USE_ITEM_PLUS() {

	int num = rand() % 9;
	int t_TopLine = MAX_GRID_Y - 1;
	bool t_bFindComplete = false;
	for(int y = 2 ; y <= MAX_GRID_Y - 1 ; y++) {
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
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
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
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
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
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
			for(int x = 0 ; x < MAX_GRID_X ; x++) {
				if(x == num) continue;
				m_MyView[x][y] = TYPE_STATUS_ROCK;
			}
			return;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::USE_ITEM_MINUS() {
	m_Block->ClearLine(MAX_GRID_Y - 1);
}
//---------------------------------------------------------------------------

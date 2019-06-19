//---------------------------------------------------------------------------

#pragma hdrstop

#include "Define.h"
#include "Main.h"
#include "common_func.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall CCurrentBlock::CCurrentBlock() {
	Init();
}
//---------------------------------------------------------------------------

void __fastcall CCurrentBlock::Init() {

	// Init Point
	for(int i = 0 ; i < 4 ; i++) {
		Point[i].RotateCenter = false;
		Point[i].X = -1;
		Point[i].Y = -1;
		Point[i].X_new = -1;
		Point[i].Y_new = -1;
		Point[i].X_old = -1;
		Point[i].Y_old = -1;
	}

	mp_MyView = FormMain->m_MyView;

	DropSpeed = 0;
	CanMoveFlag = false;
	bIsNew = false;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::CreateNewBlock(int _Type) {

	bIsNew = true;

	switch(_Type) {
		case BLOCK_O:
			Point[0].X = 4;
			Point[0].Y = 0;
			Point[0].RotateCenter = false;

			Point[1].X = 5;
			Point[1].Y = 0;
			Point[0].RotateCenter = false;

			Point[2].X = 4;
			Point[2].Y = 1;
			Point[0].RotateCenter = false;

			Point[3].X = 5;
			Point[3].Y = 1;
			Point[0].RotateCenter = false;
			break;

		case BLOCK_I:
			Point[0].X = 3;
			Point[0].Y = 0;
			Point[0].RotateCenter = false;

			Point[1].X = 4;
			Point[1].Y = 0;
			Point[0].RotateCenter = false;

			Point[2].X = 5;
			Point[2].Y = 0;
			Point[0].RotateCenter = true;

			Point[3].X = 6;
			Point[3].Y = 0;
			Point[0].RotateCenter = false;
			break;

		case BLOCK_T:
			Point[0].X = 5;
			Point[0].Y = 0;
			Point[0].RotateCenter = false;

			Point[1].X = 4;
			Point[1].Y = 1;
			Point[0].RotateCenter = false;

			Point[2].X = 5;
			Point[2].Y = 1;
			Point[0].RotateCenter = true;

			Point[3].X = 6;
			Point[3].Y = 1;
			Point[0].RotateCenter = false;
			break;

		case BLOCK_J:
			Point[0].X = 4;
			Point[0].Y = 0;
			Point[0].RotateCenter = false;

			Point[1].X = 4;
			Point[1].Y = 1;
			Point[0].RotateCenter = false;

			Point[2].X = 5;
			Point[2].Y = 1;
			Point[0].RotateCenter = true;

			Point[3].X = 6;
			Point[3].Y = 1;
			Point[0].RotateCenter = false;
			break;

		case BLOCK_L:
			Point[0].X = 6;
			Point[0].Y = 0;
			Point[0].RotateCenter = false;

			Point[1].X = 4;
			Point[1].Y = 1;
			Point[0].RotateCenter = false;

			Point[2].X = 5;
			Point[2].Y = 1;
			Point[0].RotateCenter = true;

			Point[3].X = 6;
			Point[3].Y = 1;
			Point[0].RotateCenter = false;
			break;

		case BLOCK_S:
			Point[0].X = 4;
			Point[0].Y = 0;
			Point[0].RotateCenter = false;

			Point[1].X = 5;
			Point[1].Y = 0;
			Point[0].RotateCenter = false;

			Point[2].X = 5;
			Point[2].Y = 1;
			Point[0].RotateCenter = true;

			Point[3].X = 6;
			Point[3].Y = 1;
			Point[0].RotateCenter = false;
			break;

		case BLOCK_Z:
			Point[0].X = 5;
			Point[0].Y = 0;
			Point[0].RotateCenter = false;

			Point[1].X = 6;
			Point[1].Y = 0;
			Point[0].RotateCenter = false;

			Point[2].X = 4;
			Point[2].Y = 1;
			Point[0].RotateCenter = true;

			Point[3].X = 5;
			Point[3].Y = 1;
			Point[0].RotateCenter = false;
			break;

		default:
			break;
	}

	// Check If Block Can Create, If not return false : means game over.
	for(int i = 0 ; i < 4 ; i++) {
		if(mp_MyView[Point[i].X][Point[i].Y] != 0x00) {
			ShowMessage(L"There is block");
			return false;
		}
	}

	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::MoveRight() {

	int t_point[4] = {0, };

	for(int i = 0 ; i < 4 ; i++) {
		t_point[i] = Point[i].X + 1;
		if(t_point[i] >= 10) return false;
		if(GetBitStatus(mp_MyView[Point[i].X + 1][Point[i].Y], 7)) continue;
		if(mp_MyView[Point[i].X + 1][Point[i].Y] != 0x00) return false;
	}

	for(int i = 0 ; i < 4 ; i++) {
		Point[i].X_old = Point[i].X;
		Point[i].Y_old = Point[i].Y;
		Point[i].X = t_point[i];
	}

	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::MoveLeft() {

	int t_point[4] = {0, };

	for(int i = 0 ; i < 4 ; i++) {
		t_point[i] = Point[i].X - 1;
		if(t_point[i] <= -1) return false;
	}

	for(int i = 0 ; i < 4 ; i++) {
		Point[i].X_old = Point[i].X;
		Point[i].Y_old = Point[i].Y;
		Point[i].X = t_point[i];
	}

	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::MoveDown() {

    int t_point[4] = {0, };

	for(int i = 0 ; i < 4 ; i++) {
		t_point[i] = Point[i].Y + 1;
		if(t_point[i] >= 20) return false;
	}

	for(int i = 0 ; i < 4 ; i++) {
		Point[i].Y_old = Point[i].Y;
		Point[i].X_old = Point[i].X;
		Point[i].Y = t_point[i];
	}

	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::Drop() {
	Complete();
	ShowMessage(L"Drop");
	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::RotateRight() {

	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::Complete() {
	BYTE t_Byte = 0;
	for(int i = 0 ; i < 4 ; i++) {
		t_Byte = mp_MyView[Point[i].X][Point[i].Y];
		mp_MyView[Point[i].X][Point[i].Y] = _BitSetting(t_Byte, 7, false);
    }
	return true;
}
//---------------------------------------------------------------------------







//__fastcall C_BLOCK::C_BLOCK(int _TYPE) {
__fastcall C_BLOCK::C_BLOCK(int _TYPE, unsigned char (*_p_My)[MAX_GRID_Y]) {

	///***** SAFE INIT MEMBER STRUCT *****///
	for(int i = 0 ; i < 4 ; i++) {
		POINT[i].X = 0;
		POINT[i].Y = 0;
		POINT[i].R = false;
	}


	///***** COMMON INIT *****///
	Direction = DIRECTION_U;
	Type = _TYPE;
	p_My = _p_My;


	///***** ALLOCATION *****///
	switch(_TYPE) {
		case BLOCK_O:
		{
			POINT[0].X = 4;
			POINT[0].Y = 0;
			POINT[1].X = 5;
			POINT[1].Y = 0;
			POINT[2].X = 4;
			POINT[2].Y = 1;
			POINT[3].X = 5;
			POINT[3].Y = 1;
			p_My[4][0] = 0x80;
			p_My[5][0] = 0x80;
			p_My[4][1] = 0x80;
			p_My[5][1] = 0x80;
			break;
		}

		case BLOCK_I:
		{
			POINT[0].X = 3;
			POINT[0].Y = 0;
			POINT[1].X = 4;
			POINT[1].Y = 0;
			POINT[2].X = 5;
			POINT[2].Y = 0;
			POINT[3].X = 6;
			POINT[3].Y = 0;
			p_My[3][0] = 0x80;
			p_My[4][0] = 0x80;
			p_My[5][0] = 0x80;
			p_My[6][0] = 0x80;

			POINT[2].R = true;
			break;
		}

		case BLOCK_T:
		{
			POINT[0].X = 5;
			POINT[0].Y = 0;
			POINT[1].X = 4;
			POINT[1].Y = 1;
			POINT[2].X = 5;
			POINT[2].Y = 1;
			POINT[3].X = 6;
			POINT[3].Y = 1;
			p_My[5][0] = 0x80;
			p_My[4][1] = 0x80;
			p_My[5][1] = 0x80;
			p_My[6][1] = 0x80;

			POINT[2].R = true;
			break;
		}

		case BLOCK_J:
		{
			POINT[0].X = 4;
			POINT[0].Y = 0;
			POINT[1].X = 5;
			POINT[1].Y = 0;
			POINT[2].X = 6;
			POINT[2].Y = 0;
			POINT[3].X = 6;
			POINT[3].Y = 1;
			p_My[4][0] = 0x80;
			p_My[5][0] = 0x80;
			p_My[6][0] = 0x80;
			p_My[6][1] = 0x80;

			POINT[1].R = true;
			break;
		}

		case BLOCK_L:
		{
			POINT[0].X = 4;
			POINT[0].Y = 0;
			POINT[1].X = 4;
			POINT[1].Y = 1;
			POINT[2].X = 5;
			POINT[2].Y = 1;
			POINT[3].X = 6;
			POINT[3].Y = 1;
			p_My[4][0] = 0x80;
			p_My[4][1] = 0x80;
			p_My[5][1] = 0x80;
			p_My[6][1] = 0x80;

			POINT[2].R = true;
			break;
		}

		case BLOCK_S:
		{
			POINT[0].X = 4;
			POINT[0].Y = 0;
			POINT[1].X = 5;
			POINT[1].Y = 0;
			POINT[2].X = 5;
			POINT[2].Y = 1;
			POINT[3].X = 6;
			POINT[3].Y = 1;
			p_My[4][0] = 0x80;
			p_My[5][0] = 0x80;
			p_My[5][1] = 0x80;
			p_My[6][1] = 0x80;

			POINT[2].R = true;
			break;
		}

		case BLOCK_Z:
		{
			POINT[0].X = 5;
			POINT[0].Y = 0;
			POINT[1].X = 6;
			POINT[1].Y = 0;
			POINT[2].X = 4;
			POINT[2].Y = 1;
			POINT[3].X = 5;
			POINT[3].Y = 1;
			p_My[5][0] = 0x80;
			p_My[6][0] = 0x80;
			p_My[4][1] = 0x80;
			p_My[5][1] = 0x80;

			POINT[3].R = true;
			break;
		}

		default:
		{
			break;
		}
	}
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::MoveRight() {
	///***** COMMON INIT *****///
	int t_CheckCnt = 0;

	///***** CHECK IS POSSIBLE MOVE *****///
	t_CheckCnt = 0;
	int x = 0;
	int y = 0;
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		if(x == 9) return false;

		if(GetBitStatus(p_My[x + 1][y], 7) || p_My[x + 1][y] == 0 || GetBitStatus(p_My[x + 1][y], 6)) {
			++t_CheckCnt;
		}
	}
	if(t_CheckCnt != 4) return false;

	///***** DELETE CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x][y] = 0;
	}

	///***** RESET CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x + 1][y] = 0x80;
		POINT[i].X = x + 1;
		POINT[i].Y = y;
	}

	FormMain->PrintMessage(L"MOVE RIGHT !");
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::MoveLeft() {
	///***** COMMON INIT *****///
	int t_CheckCnt = 0;

	///***** CHECK IS POSSIBLE MOVE *****///
	t_CheckCnt = 0;
	int x = 0;
	int y = 0;
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		if(x == 0) return false;

		if(GetBitStatus(p_My[x - 1][y], 7) || p_My[x - 1][y] == 0 || GetBitStatus(p_My[x - 1][y], 6)) {
			++t_CheckCnt;
		}
	}
	if(t_CheckCnt != 4) return false;

	///***** DELETE CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x][y] = 0;
	}

	///***** RESET CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x - 1][y] = 0x80;
		POINT[i].X = x - 1;
		POINT[i].Y = y;
	}

	FormMain->PrintMessage(L"MOVE LEFT !");
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::MoveDown() {
	///***** COMMON INIT *****///
	int t_CheckCnt = 0;

	///***** CHECK IS POSSIBLE MOVE *****///
	t_CheckCnt = 0;
	int x = 0;
	int y = 0;
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		if(y == 19) return false;

		if(GetBitStatus(p_My[x][y + 1], 7) || p_My[x][y + 1] == 0 || GetBitStatus(p_My[x][y + 1], 6)) {
			++t_CheckCnt;
		}
	}
	if(t_CheckCnt != 4) return false;

	///***** DELETE CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x][y] = 0;
	}

	///***** RESET CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x][y + 1] = 0x80;
		POINT[i].X = x;
		POINT[i].Y = y + 1;
	}

	FormMain->PrintMessage(L"MOVE DOWN !");
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::Drop() {
	///***** COMMON INIT *****///
	int t_CheckCnt = 0;
	st_POINT t_Point[4] = { };

	///***** FIND CURRENT BLOCK *****///
	for(int x = 0 ; x < 10 ; x++) {
		if(t_CheckCnt == 4) break;
		for(int y = 0 ; y < 20 ; y++) {
			if(GetBitStatus(p_My[x][y], 7)) {
				t_Point[t_CheckCnt].X = x;
				t_Point[t_CheckCnt].Y = y;
				++t_CheckCnt;
			}
			if(t_CheckCnt == 4) break;
		}
	}
	if(t_CheckCnt != 4) return false;

	FormMain->PrintMessage(L"DROP !");
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::RotateRight() {
	///***** PRE RETURN IF BLOCK IS O *****///
	if(Type == BLOCK_O) {
        FormMain->PrintMessage(L"BLOCK O !");
		return false;
	}

	///***** COMMON INIT *****///
	int t_CheckCnt = 0;
	st_POINT t_NewPoint[4] = { };

	///***** GET ROTATION POINT *****///
	int RX = 0; // R : Rotation Point
	int RY = 0;
	for(int i = 0 ; i < 4 ; i++) {
		if(POINT[i].R) {
			RX = POINT[i].X;
			RY = POINT[i].Y;
			break;
		}
	}

	///***** CHECK IS POSSIBLE ROTATE *****///
	t_CheckCnt = 0;
	int x = 0;
	int y = 0;
	int GX = 0; // G : Gap x between RX
	int GY = 0; // G : Gap y between RY
	int NX = 0; // N : New x coordinate
	int NY = 0; // N : New y coordinate
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		if(x == RX && y == RY) {
			t_NewPoint[t_CheckCnt].X = x;
			t_NewPoint[t_CheckCnt].Y = y;
			++t_CheckCnt;
			continue; // Rotation Point : No Neccessary Rotate
		}

		GX = RX - x;
		GY = RY - y;
		NX = RX + GY;
		NY = RY - GX;

		if(NX > 9 || NX < 0 || NY < 0 || NY > 19) return false;

		if(GetBitStatus(p_My[NX][NY], 7) || p_My[NX][NY] == 0 || GetBitStatus(p_My[NX][NY], 6)) {
			t_NewPoint[t_CheckCnt].X = NX;
			t_NewPoint[t_CheckCnt].Y = NY;
			++t_CheckCnt;
		}
	}
	if(t_CheckCnt != 4) return false;

	///***** DELETE CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x][y] = 0;
	}

	///***** RESET CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = t_NewPoint[i].X;
		y = t_NewPoint[i].Y;
		p_My[x][y] = 0x80;
		POINT[i].X = x;
		POINT[i].Y = y;
	}

	FormMain->PrintMessage(L"ROTATE RIGHT !");
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::RotateLeft() {
	///***** PRE RETURN IF BLOCK IS O *****///
	if(Type == BLOCK_O) {
        FormMain->PrintMessage(L"BLOCK O !");
		return false;
	}

	///***** COMMON INIT *****///
	int t_CheckCnt = 0;
	st_POINT t_NewPoint[4] = { };

	///***** GET ROTATION POINT *****///
	int RX = 0; // R : Rotation Point
	int RY = 0;
	for(int i = 0 ; i < 4 ; i++) {
		if(POINT[i].R) {
			RX = POINT[i].X;
			RY = POINT[i].Y;
			break;
		}
	}

	///***** CHECK IS POSSIBLE ROTATE *****///
	t_CheckCnt = 0;
	int x = 0;
	int y = 0;
	int GX = 0; // G : Gap x between RX
	int GY = 0; // G : Gap y between RY
	int NX = 0; // N : New x coordinate
	int NY = 0; // N : New y coordinate
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		if(x == RX && y == RY) {
			t_NewPoint[t_CheckCnt].X = x;
			t_NewPoint[t_CheckCnt].Y = y;
			++t_CheckCnt;
			continue; // Rotation Point : No Neccessary Rotate
		}

		GX = RX - x;
		GY = RY - y;
		NX = RX - GY;
		NY = RY + GX;

		if(NX > 9 || NX < 0 || NY < 0 || NY > 19) return false;

		if(GetBitStatus(p_My[NX][NY], 7) || p_My[NX][NY] == 0 || GetBitStatus(p_My[NX][NY], 6)) {
			t_NewPoint[t_CheckCnt].X = NX;
			t_NewPoint[t_CheckCnt].Y = NY;
			++t_CheckCnt;
		}
	}
	if(t_CheckCnt != 4) return false;

	///***** DELETE CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x][y] = 0;
	}

	///***** RESET CURRENT BLOCK *****///
	for(int i = 0 ; i < 4 ; i++) {
		x = t_NewPoint[i].X;
		y = t_NewPoint[i].Y;
		p_My[x][y] = 0x80;
		POINT[i].X = x;
		POINT[i].Y = y;
	}

	FormMain->PrintMessage(L"ROTATE RIGHT !");
}
//---------------------------------------------------------------------------

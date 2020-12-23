//---------------------------------------------------------------------------

#pragma hdrstop

#include "Define.h"
#include "Main.h"
#include "common_func.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall C_BLOCK::C_BLOCK(int _TYPE, unsigned char (*_p_My)[MAX_GRID_Y], bool* _p_rst) {

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
			POINT[0].Y = 2;
			POINT[1].X = 5;
			POINT[1].Y = 2;
			POINT[2].X = 4;
			POINT[2].Y = 3;
			POINT[3].X = 5;
			POINT[3].Y = 3;
			if(CheckCanCreate() == false) {
				*_p_rst = false;
				return;
			}
			p_My[4][2] = TYPE_BLOCK_O;
			p_My[5][2] = TYPE_BLOCK_O;
			p_My[4][3] = TYPE_BLOCK_O;
			p_My[5][3] = TYPE_BLOCK_O;
			p_My[4][2] = _BitSetting(p_My[4][2], 7, true);
			p_My[5][2] = _BitSetting(p_My[5][2], 7, true);
			p_My[4][3] = _BitSetting(p_My[4][3], 7, true);
			p_My[5][3] = _BitSetting(p_My[5][3], 7, true);
			break;
		}

		case BLOCK_I:
		{
			POINT[0].X = 3;
			POINT[0].Y = 2;
			POINT[1].X = 4;
			POINT[1].Y = 2;
			POINT[2].X = 5;
			POINT[2].Y = 2;
			POINT[3].X = 6;
			POINT[3].Y = 2;
			if(CheckCanCreate() == false) {
				*_p_rst = false;
				return;
			}
			p_My[3][2] = TYPE_BLOCK_I;
			p_My[4][2] = TYPE_BLOCK_I;
			p_My[5][2] = TYPE_BLOCK_I;
			p_My[6][2] = TYPE_BLOCK_I;
			p_My[3][2] = _BitSetting(p_My[3][2], 7, true);
			p_My[4][2] = _BitSetting(p_My[4][2], 7, true);
			p_My[5][2] = _BitSetting(p_My[5][2], 7, true);
			p_My[6][2] = _BitSetting(p_My[6][2], 7, true);

			POINT[2].R = true;
			break;
		}

		case BLOCK_T:
		{
			POINT[0].X = 5;
			POINT[0].Y = 2;
			POINT[1].X = 4;
			POINT[1].Y = 3;
			POINT[2].X = 5;
			POINT[2].Y = 3;
			POINT[3].X = 6;
			POINT[3].Y = 3;
			if(CheckCanCreate() == false) {
				*_p_rst = false;
				return;
			}
			p_My[5][2] = TYPE_BLOCK_T;
			p_My[4][3] = TYPE_BLOCK_T;
			p_My[5][3] = TYPE_BLOCK_T;
			p_My[6][3] = TYPE_BLOCK_T;
			p_My[5][2] = _BitSetting(p_My[5][2], 7, true);
			p_My[4][3] = _BitSetting(p_My[4][3], 7, true);
			p_My[5][3] = _BitSetting(p_My[5][3], 7, true);
			p_My[6][3] = _BitSetting(p_My[6][3], 7, true);

			POINT[2].R = true;
			break;
		}

		case BLOCK_J:
		{
			POINT[0].X = 4;
			POINT[0].Y = 2;
			POINT[1].X = 5;
			POINT[1].Y = 2;
			POINT[2].X = 6;
			POINT[2].Y = 2;
			POINT[3].X = 4;
			POINT[3].Y = 3;
			if(CheckCanCreate() == false) {
				*_p_rst = false;
				return;
			}
			p_My[4][2] = TYPE_BLOCK_J;
			p_My[5][2] = TYPE_BLOCK_J;
			p_My[6][2] = TYPE_BLOCK_J;
			p_My[4][3] = TYPE_BLOCK_J;
			p_My[4][2] = _BitSetting(p_My[4][2], 7, true);
			p_My[5][2] = _BitSetting(p_My[5][2], 7, true);
			p_My[6][2] = _BitSetting(p_My[6][2], 7, true);
			p_My[4][3] = _BitSetting(p_My[4][3], 7, true);

			POINT[1].R = true;
			break;
		}

		case BLOCK_L:
		{
			POINT[0].X = 4;
			POINT[0].Y = 2;
			POINT[1].X = 4;
			POINT[1].Y = 3;
			POINT[2].X = 5;
			POINT[2].Y = 3;
			POINT[3].X = 6;
			POINT[3].Y = 3;
			if(CheckCanCreate() == false) {
				*_p_rst = false;
				return;
			}
			p_My[4][2] = TYPE_BLOCK_L;
			p_My[4][3] = TYPE_BLOCK_L;
			p_My[5][3] = TYPE_BLOCK_L;
			p_My[6][3] = TYPE_BLOCK_L;
			p_My[4][2] = _BitSetting(p_My[4][2], 7, true);
			p_My[4][3] = _BitSetting(p_My[4][3], 7, true);
			p_My[5][3] = _BitSetting(p_My[5][3], 7, true);
			p_My[6][3] = _BitSetting(p_My[6][3], 7, true);

			POINT[2].R = true;
			break;
		}

		case BLOCK_S:
		{
			POINT[0].X = 4;
			POINT[0].Y = 2;
			POINT[1].X = 5;
			POINT[1].Y = 2;
			POINT[2].X = 5;
			POINT[2].Y = 3;
			POINT[3].X = 6;
			POINT[3].Y = 3;
			if(CheckCanCreate() == false) {
				*_p_rst = false;
				return;
			}
			p_My[4][2] = TYPE_BLOCK_S;
			p_My[5][2] = TYPE_BLOCK_S;
			p_My[5][3] = TYPE_BLOCK_S;
			p_My[6][3] = TYPE_BLOCK_S;
			p_My[4][2] = _BitSetting(p_My[4][2], 7, true);
			p_My[5][2] = _BitSetting(p_My[5][2], 7, true);
			p_My[5][3] = _BitSetting(p_My[5][3], 7, true);
			p_My[6][3] = _BitSetting(p_My[6][3], 7, true);

			POINT[2].R = true;
			break;
		}

		case BLOCK_Z:
		{
			POINT[0].X = 5;
			POINT[0].Y = 2;
			POINT[1].X = 6;
			POINT[1].Y = 2;
			POINT[2].X = 4;
			POINT[2].Y = 3;
			POINT[3].X = 5;
			POINT[3].Y = 3;
			if(CheckCanCreate() == false) {
				*_p_rst = false;
				return;
			}
			p_My[5][2] = TYPE_BLOCK_Z;
			p_My[6][2] = TYPE_BLOCK_Z;
			p_My[4][3] = TYPE_BLOCK_Z;
			p_My[5][3] = TYPE_BLOCK_Z;
			p_My[5][2] = _BitSetting(p_My[5][2], 7, true);
			p_My[6][2] = _BitSetting(p_My[6][2], 7, true);
			p_My[4][3] = _BitSetting(p_My[4][3], 7, true);
			p_My[5][3] = _BitSetting(p_My[5][3], 7, true);

			POINT[3].R = true;
			break;
		}

		default:
		{
			break;
		}
	}

	*_p_rst = true;
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::CheckCanCreate() {

	int x = 0;
	int y = 0;

	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		if(p_My[x][y]) {
			return false;
		}
	}
	return true;
}
//---------------------------------------------------------------------------

unsigned char __fastcall C_BLOCK::GetBlockType(int _TYPE) {
	unsigned char rst = 0;
	switch(_TYPE) {
		case BLOCK_O:
			rst = TYPE_BLOCK_O;
			break;
		case BLOCK_I:
			rst = TYPE_BLOCK_I;
			break;
		case BLOCK_J:
			rst = TYPE_BLOCK_J;
			break;
		case BLOCK_L:
			rst = TYPE_BLOCK_L;
			break;
		case BLOCK_S:
			rst = TYPE_BLOCK_S;
			break;
		case BLOCK_Z:
			rst = TYPE_BLOCK_Z;
			break;
		case BLOCK_T:
			rst = TYPE_BLOCK_T;
			break;
		default:
			break;
	}
	return rst;
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
		p_My[x + 1][y] = GetBlockType(Type);
		p_My[x + 1][y] = _BitSetting(p_My[x + 1][y], 7, true);
		POINT[i].X = x + 1;
		POINT[i].Y = y;
	}

	//FormMain->PringMsg(L"MOVE RIGHT !");
	return true;
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
		p_My[x - 1][y] = GetBlockType(Type);
		p_My[x - 1][y] = _BitSetting(p_My[x - 1][y], 7, true);
		POINT[i].X = x - 1;
		POINT[i].Y = y;
	}

	//FormMain->PringMsg(L"MOVE LEFT !");
	return true;
}
//---------------------------------------------------------------------------

void __fastcall C_BLOCK::MoveUp() {

	///***** COMMON INIT *****///
	int x = 0;
	int y = 0;

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
		p_My[x][y - 1] = GetBlockType(Type);
		p_My[x][y - 1] = _BitSetting(p_My[x][y - 1], 7, true);
		POINT[i].X = x;
		POINT[i].Y = y - 1;
	}
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
		if(y == MAX_GRID_Y - 1) {
			Complete();
			CheckLineClear();
			return true;
		}

		if(GetBitStatus(p_My[x][y + 1], 7) || p_My[x][y + 1] == 0 || GetBitStatus(p_My[x][y + 1], 6)) {
			++t_CheckCnt;
		}
	}
	if(t_CheckCnt != 4) {
		Complete();
		CheckLineClear();
		return true;
	}

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
		p_My[x][y + 1] = GetBlockType(Type);
		p_My[x][y + 1] = _BitSetting(p_My[x][y + 1], 7, true);
		POINT[i].X = x;
		POINT[i].Y = y + 1;
	}

	//FormMain->PringMsg(L"MOVE DOWN !");
	return false;
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::Drop() {

	for(int i = 0 ; i < MAX_GRID_Y ; i++) {
		if(MoveDown()) {
			//FormMain->PringMsg(L"DROP !");
			return true;
		}
	}
	return false;
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::RotateRight() {
	///***** PRE RETURN IF BLOCK IS O *****///
	if(Type == BLOCK_O) {
		//FormMain->PringMsg(L"BLOCK O !");
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
		p_My[x][y] = GetBlockType(Type);
		p_My[x][y] = _BitSetting(p_My[x][y], 7, true);
		POINT[i].X = x;
		POINT[i].Y = y;
	}

	//FormMain->PringMsg(L"ROTATE RIGHT !");
	return true;
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::RotateLeft() {
	///***** PRE RETURN IF BLOCK IS O *****///
	if(Type == BLOCK_O) {
		//FormMain->PringMsg(L"BLOCK O !");
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
		p_My[x][y] = GetBlockType(Type);
		p_My[x][y] = _BitSetting(p_My[x][y], 7, true);
		POINT[i].X = x;
		POINT[i].Y = y;
	}

	//FormMain->PringMsg(L"ROTATE RIGHT !");
	return true;
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::Complete() {
	int x = 0;
	int y = 0;
	for(int i = 0 ; i < 4 ; i++) {
		x = POINT[i].X;
		y = POINT[i].Y;
		p_My[x][y] = GetBlockType(Type);
	}
	return true;
}
//---------------------------------------------------------------------------

bool __fastcall C_BLOCK::CheckLineClear() {

	int t_ClearCnt = 0;
	int t_CheckCnt = 0;
	for(int y = 0 ; y < MAX_GRID_Y ; y++) {
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
			if(p_My[x][y]) t_CheckCnt++;
		}
		if(t_CheckCnt == 10) {
			ClearLine(y);
			t_ClearCnt++;
		}
		t_CheckCnt = 0;
	}
	FormMain->AddScore(t_ClearCnt);
	return true;
}
//---------------------------------------------------------------------------

void __fastcall C_BLOCK::ClearLine(int _Num) {
	for(int x = 0 ; x < MAX_GRID_X ; x++) {
		p_My[x][_Num] = 0;
	}

	for(int y = _Num - 1 ; y >= 0 ; y--) {
		for(int x = 0 ; x < MAX_GRID_X ; x++) {
			if(GetBitStatus(p_My[x][y], 7) || GetBitStatus(p_My[x][y], 6)) continue;
			if(GetBitStatus(p_My[x][y + 1], 7) || GetBitStatus(p_My[x][y + 1], 6)) continue;
			p_My[x][y + 1] = p_My[x][y];
		}
    }
}
//---------------------------------------------------------------------------

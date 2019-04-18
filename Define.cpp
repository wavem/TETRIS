//---------------------------------------------------------------------------

#pragma hdrstop

#include "Define.h"
#include "Main.h"
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
	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::MoveRight() {

	int t_point[4] = {0, };

	for(int i = 0 ; i < 4 ; i++) {
		t_point[i] = Point[i].X + 1;
		if(t_point[i] >= 10) return false;
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

	return true;
}
//---------------------------------------------------------------------------

bool __fastcall CCurrentBlock::RotateRight() {

	return true;
}
//---------------------------------------------------------------------------

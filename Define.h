//---------------------------------------------------------------------------

#ifndef DefineH
#define DefineH
//---------------------------------------------------------------------------
#endif

#define MAX_GRID_X 10
#define MAX_GRID_Y 20

#define BLOCK_O 0
#define BLOCK_I 1
#define BLOCK_T 2
#define BLOCK_J 3
#define BLOCK_L	4
#define BLOCK_S 5
#define BLOCK_Z	6

#define DIRECTION_U 1
#define DIRECTION_L 2
#define DIRECTION_R 3
#define DIRECTION_D 4



typedef struct St_Point {
	bool RotateCenter;
	int X;
	int Y;
	int X_new;
	int Y_new;
	int X_old;
	int Y_old;
} stPoint;
//---------------------------------------------------------------------------

class CCurrentBlock {
private:
	//stPoint Point[4];
	int DropSpeed;
	bool CanMoveFlag;

public:
	stPoint Point[4];
	bool bIsNew;
	unsigned char (*mp_MyView)[20];

	__fastcall CCurrentBlock();
	void __fastcall Init();
	bool __fastcall CreateNewBlock(int _Type);

	bool __fastcall MoveRight();
	bool __fastcall MoveLeft();
	bool __fastcall MoveDown();
	bool __fastcall Drop();
	bool __fastcall RotateRight();
	bool __fastcall RotateLeft();
	bool __fastcall Complete();

};
//---------------------------------------------------------------------------

typedef struct ST_POINT {
	int X;
	int Y;
	bool R;
} st_POINT;
//---------------------------------------------------------------------------

class C_BLOCK {
private:
	st_POINT POINT[4];
	unsigned char (*p_My)[MAX_GRID_Y];

public:
	__fastcall C_BLOCK(int _TYPE, unsigned char (*_p_My)[MAX_GRID_Y]);
	bool __fastcall CheckCreateSuccess();
	bool __fastcall CheckIsComplete();


	///***** PROPERTY *****///
	int Direction;
	int Type;


	///***** METHOD *****///
	bool __fastcall MoveRight();
	bool __fastcall MoveLeft();
	bool __fastcall MoveDown();
	bool __fastcall Drop();
	bool __fastcall RotateRight();
	bool __fastcall RotateLeft();
	bool __fastcall Complete();
};
//---------------------------------------------------------------------------

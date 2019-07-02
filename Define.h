//---------------------------------------------------------------------------

#ifndef DefineH
#define DefineH

#define MAX_GRID_X 10
#define MAX_GRID_Y 23

#define BLOCK_O 0
#define BLOCK_I 1
#define BLOCK_T 2
#define BLOCK_J 3
#define BLOCK_L	4
#define BLOCK_S 5
#define BLOCK_Z	6

#define BLOCK_N 7 // NOTHING
#define BLOCK_R 8 // ROCK
#define ITEM_P  9 // ITEM PLUS

#define DIRECTION_U 1
#define DIRECTION_L 2
#define DIRECTION_R 3
#define DIRECTION_D 4


///***** BLOCK INFORMATION TABLE *****///

#define TYPE_STATUS_NONE 	0
#define TYPE_BLOCK_O 		1
#define TYPE_BLOCK_I 		2
#define TYPE_BLOCK_T 		3
#define TYPE_BLOCK_J 		4
#define TYPE_BLOCK_L 		5
#define TYPE_BLOCK_S 		6
#define TYPE_BLOCK_Z 		7
#define TYPE_STATUS_ROCK	8
#define TYPE_ITEM_PLUS		9

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
	__fastcall C_BLOCK(int _TYPE, unsigned char (*_p_My)[MAX_GRID_Y], bool* _p_rst);

	///***** INNER ROUTINE *****///
	bool __fastcall Complete();
	bool __fastcall CheckCanCreate();
	bool __fastcall CheckLineClear();
	void __fastcall ClearLine(int _Num);
	unsigned char __fastcall GetBlockType(int _TYPE);


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


	///***** SPECIAL METHOD *****///
	void __fastcall MoveUp();
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif

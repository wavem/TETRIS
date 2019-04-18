//---------------------------------------------------------------------------

#ifndef DefineH
#define DefineH
//---------------------------------------------------------------------------
#endif

#define BLOCK_O 0
#define BLOCK_I 1
#define BLOCK_T 2
#define BLOCK_J 3
#define BLOCK_L	4
#define BLOCK_S 5
#define BLOCK_Z	6

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
	__fastcall CCurrentBlock();
	void __fastcall Init();
	bool __fastcall CreateNewBlock(int _Type);

	bool __fastcall MoveRight();
	bool __fastcall MoveLeft();
	bool __fastcall MoveDown();
	bool __fastcall Drop();
	bool __fastcall RotateRight();
	bool __fastcall RotateLeft();

};
//---------------------------------------------------------------------------

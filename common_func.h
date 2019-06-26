//---------------------------------------------------------------------------
#ifndef common_funcH
#define common_funcH

typedef unsigned char BYTE;

extern bool GetBitStatus(BYTE _src, int _bit);
extern BYTE GetBlockData(BYTE _src);
extern void SetBlockData(BYTE &_src);
extern BYTE _BitSetting(BYTE _src, int _bitIdx, bool _bool);
//---------------------------------------------------------------------------
#endif

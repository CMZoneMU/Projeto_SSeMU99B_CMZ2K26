#pragma once

void InitCommon();
void InitMemoryProtection();
void CalcFPS();
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int map);
void LoginTab();
void CheckTickCount();
void CheckMasterLevel();
void CompareGensMoveIndex();

extern int CustomAttack;
extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];
extern char WindowName[64];
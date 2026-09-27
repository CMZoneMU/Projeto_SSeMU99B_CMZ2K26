#pragma once

void InitCommon();
void CalcFPS();
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
char HelperMouseClick(char* This);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();

extern int CustomAttack;
extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];
extern char WindowName[64];
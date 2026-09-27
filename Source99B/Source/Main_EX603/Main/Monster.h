#pragma once

void InitMonster();
void LoadMonsterModel(int a,char* b,char* c,int d);
void LoadMonsterTexture(int a,char* b,int c,int d,int e);
DWORD RenderMonster(int a,int b,int c,int d);

DWORD CreateMonster(int index,int x,int y,int key);
DWORD SettingMonster(DWORD o,int index);
#include "stdafx.h"
#include "Monster.h"
#include "CustomMonster.h"
#include "CustomMonsterSkin.h"
#include "Item.h"
#include "Offset.h"
#include "Util.h"

void InitMonster() // OK
{
	SetByte(0x00559B85,0xFF); // Monster Kill
	
	SetByte(0x00559B86,0xFF); // Monster Kill
	
	//SetCompleteHook(0xE8,0x0058103A,&CreateMonster);

	//SetCompleteHook(0xE8,0x0058105B,&SettingMonster);

	SetCompleteHook(0xE8,0x0061FE3F,&LoadMonsterModel);

	SetCompleteHook(0xE8,0x0061FEEA,&LoadMonsterTexture);

	SetCompleteHook(0xE8,0x004E199D,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00587049,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00587049,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00590CCC,&RenderMonster);
	
	SetCompleteHook(0xE8,0x005BBEE6,&RenderMonster);
	
	SetCompleteHook(0xE8,0x0064229D,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00642D51,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00643229,&RenderMonster);
	
	SetCompleteHook(0xE8,0x0065EA86,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00911A53,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00911A6D,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00911A87,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00911AA1,&RenderMonster);
	
	SetCompleteHook(0xE8,0x00911ABB,&RenderMonster);
}

void LoadMonsterModel(int a,char* b,char* c,int d) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex((a-644));

	if(lpInfo != 0)
	{
		char path[MAX_PATH] = {0};

		wsprintf(path,"Data\\%s",lpInfo->FolderPath);

		pLoadItemModel(a,path,lpInfo->ModelPath,-1);
	}

	pLoadItemModel(a,b,c,d);
}

void LoadMonsterTexture(int a,char* b,int c,int d,int e) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex((a-644));

	if(lpInfo != 0)
	{
		pLoadItemTexture(a,lpInfo->FolderPath,GL_REPEAT,GL_NEAREST,GL_TRUE);
	}

	pLoadItemTexture(a,b,c,d,e);
}

DWORD RenderMonster(int index,int x,int y,int key) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex(index);

	if(lpInfo != 0)
	{
		((void(__cdecl*)(int))0x0061FDE0)(index); // OpenMonsterModel

		DWORD o = pCreateCharacter(key,(lpInfo->Type>2)?1163:(index+644),x,y,0);

		memcpy((DWORD*)(o + 56),lpInfo->Name,sizeof(lpInfo->Name));

		*(DWORD*)(o + 132) = (lpInfo->Type == 2) ? 43 : index;

		*(BYTE*)(o + 800) = (lpInfo->Type == 0 || lpInfo->Type == 3) ? 4 : 2;

		*(float*)(o + 872) = lpInfo->Size;

		if(lpInfo->Type > 2)
		{
			for(int n=0; n<MAX_CUSTOM_MONSTER_SKIN;n++)
			{
				CUSTOM_MONSTER_SKIN_INFO* lpInfo = &gCustomMonsterSkin.m_CustomMonsterSkinInfo[n];

				if(lpInfo->Index == -1 || lpInfo->MonsterIndex != index)
				{
					continue;
				}

				*(WORD*)(o + 268 + 36 * lpInfo->slot) = lpInfo->ItemIndex+ITEM_BASE_MODEL;
				*(BYTE*)(o + 270 + 36 * lpInfo->slot) = lpInfo->ItemLevel;
				*(BYTE*)(o + 271 + 36 * lpInfo->slot) = lpInfo->Option1;
				*(BYTE*)(o + 272 + 36 * lpInfo->slot) = lpInfo->Excellent;
			}

			pSetCharacterScale(o);
		}

		return pSettingMonster(o,index);
	}

	return ((DWORD(__cdecl*)(int,int,int,int))0x00580FC0)(index,x,y,key); // pRenderMonster
}

DWORD CreateMonster(int index,int x,int y,int key) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex(index);

	if(lpInfo != 0)
	{
		if(lpInfo->Type != 0 && lpInfo->Type != 3)
		{
			index += 644;
		}

		DWORD o = *(DWORD *)(*(DWORD*)(0x00E8C200) + 8) + 260 * index;

		if(o != 0 && *(WORD*)(o + 38) <= 0)
		{
			char path[MAX_PATH] = {0};

			wsprintf(path,"Data\\%s",lpInfo->FolderPath);

			pLoadItemModel(index,path,lpInfo->ModelPath,-1);

			if(lpInfo->Type == 0 || lpInfo->Type == 3)
			{
				for(int i=0;i < *(WORD*)(o + 38);++i)
				{
					*(float*)(*(DWORD*)(o + 48) + 16 * i + 4) = 0.25f;
				}
			}
			else
			{
				*(float*)(*(DWORD*)(o + 48) + 4) = 0.25f;
				*(float*)(*(DWORD*)(o + 48) + 20) = 0.2f;
				*(float*)(*(DWORD*)(o + 48) + 36) = 0.34f;
				*(float*)(*(DWORD*)(o + 48) + 52) = 0.33f;
				*(float*)(*(DWORD*)(o + 48) + 68) = 0.33f;
				*(float*)(*(DWORD*)(o + 48) + 84) = 0.5f;
				*(float*)(*(DWORD*)(o + 48) + 100) = 0.55f;
				*(BYTE*)(*(DWORD*)(o + 48) + 96) = 1;
			}
		}

		pLoadItemTexture(index,lpInfo->FolderPath,GL_REPEAT,GL_NEAREST,GL_TRUE);

		return pCreateCharacter(key,(lpInfo->Type>2)?1163:index,x,y,0);
	}

	return pCreateMonster(index,x,y,key);
}

DWORD SettingMonster(DWORD o,int index) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex(index);

	if(lpInfo != 0)
	{
		memcpy((DWORD*)(o + 56),lpInfo->Name,sizeof(lpInfo->Name));

		*(DWORD*)(o + 132) = (lpInfo->Type == 2) ? 43 : index;

		*(BYTE*)(o + 800) = (lpInfo->Type == 0 || lpInfo->Type == 3) ? 4 : 2;

		*(float*)(o + 872) = lpInfo->Size;

		if(lpInfo->Type > 2)
		{
			for(int n=0; n<MAX_CUSTOM_MONSTER_SKIN;n++)
			{
				CUSTOM_MONSTER_SKIN_INFO* lpInfo = &gCustomMonsterSkin.m_CustomMonsterSkinInfo[n];

				if(lpInfo->Index == -1 || lpInfo->MonsterIndex != index)
				{
					continue;
				}

				*(WORD*)(o + 268 + 36 * lpInfo->slot) = lpInfo->ItemIndex+ITEM_BASE_MODEL;
				*(BYTE*)(o + 270 + 36 * lpInfo->slot) = lpInfo->ItemLevel;
				*(BYTE*)(o + 271 + 36 * lpInfo->slot) = lpInfo->Option1;
				*(BYTE*)(o + 272 + 36 * lpInfo->slot) = lpInfo->Excellent;
			}

			pSetCharacterScale(o);
		}

		return o;
	}

	return pSettingMonster(o,index);
}
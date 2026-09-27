#include "stdafx.h"
#include "Monster.h"
#include "CustomMonster.h"
#include "CustomMonsterSkin.h"
#include "Item.h"
#include "Offset.h"
#include "Util.h"

void InitMonster() // OK
{
	SetByte(0x0055E421,0xFF); // Monster Kill
	
	SetByte(0x0055E422,0xFF); // Monster Kill
	
	SetCompleteHook(0xE8,0x0058A4EE,&CreateMonster);

	SetCompleteHook(0xE8,0x0058A50B,&SettingMonster);
}

DWORD CreateMonster(int index,int x,int y,int key) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex(index);

	if(lpInfo != 0)
	{
		if(lpInfo->Type != 0 && lpInfo->Type != 3)
		{
			index += 674;
		}

		DWORD o = *(DWORD *)(*(DWORD*)(0x011C3AFC) + 8) + 260 * index;

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

		return pCreateCharacter(key,(lpInfo->Type>2)?1202:index,x,y,0);
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

		*(BYTE*)(o + 844) = (lpInfo->Type == 0 || lpInfo->Type == 3) ? 4 : 2;

		*(float*)(o + 920) = lpInfo->Size;

		if(lpInfo->Type > 2)
		{
			for(int n=0; n<MAX_CUSTOM_MONSTER_SKIN;n++)
			{
				CUSTOM_MONSTER_SKIN_INFO* lpInfo = &gCustomMonsterSkin.m_CustomMonsterSkinInfo[n];

				if(lpInfo->Index == -1 || lpInfo->MonsterIndex != index)
				{
					continue;
				}

				*(WORD*)(o + 284 + 36 * lpInfo->slot) = lpInfo->ItemIndex+ITEM_BASE_MODEL;
				*(BYTE*)(o + 286 + 36 * lpInfo->slot) = lpInfo->ItemLevel;
				*(BYTE*)(o + 287 + 36 * lpInfo->slot) = lpInfo->Option1;
				*(BYTE*)(o + 288 + 36 * lpInfo->slot) = lpInfo->Excellent;
			}

			pSetCharacterScale(o);
		}

		return o;
	}

	return pSettingMonster(o,index);
}
#include "stdafx.h"
#include "Monster.h"
#include "CustomMonster.h"
#include "CustomMonsterSkin.h"
#include "Offset.h"
#include "Util.h"

void InitMonster() // OK
{
	SetByte(0x004F3EC9,0xD0); // Monster Kill
	
	SetByte(0x004F3ECA,0x07); // Monster Kill

	SetCompleteHook(0xE8,0x0050ACE6,&CreateMonster);

	SetCompleteHook(0xE8,0x0050ACFE,&SettingMonster);
}

DWORD CreateMonster(int index,int x,int y,int key) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex(index);

	if(lpInfo != 0)
	{
		if(lpInfo->Type != 0 && lpInfo->Type != 3)
		{
			index += 329;
		}

		DWORD o = 224 * index + *(DWORD*)0x05756AB8;

		if(*(BYTE*)0x006B8D84 == 0 || *(WORD*)(o + 38) <= 0)
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

		return pCreateCharacter(key,(lpInfo->Type>2)?507:index,x,y,0);
	}

	return pCreateMonster(index,x,y,key);
}

DWORD SettingMonster(DWORD o,int index) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex(index);

	if(lpInfo != 0)
	{
		*(float*)(o + 12) = lpInfo->Size;

		*(BYTE*)(o + 132) = (lpInfo->Type== 0||lpInfo->Type==3)?4:2;

		memcpy((DWORD*)(o + 457),lpInfo->Name,sizeof(lpInfo->Name));

		*(DWORD*)(o + 870) = (lpInfo->Type==2)?43:index;

		if(lpInfo->Type > 2)
		{
			for(int n=0; n<MAX_CUSTOM_MONSTER_SKIN;n++)
			{
				CUSTOM_MONSTER_SKIN_INFO* lpInfo = &gCustomMonsterSkin.m_CustomMonsterSkinInfo[n];

				if(lpInfo->Index == -1 || lpInfo->MonsterIndex != index)
				{
					continue;
				}
				
				*(WORD*)(o + 520 + 32 * lpInfo->slot) = lpInfo->ItemIndex+ITEM_BASE_MODEL;
				*(BYTE*)(o + 522 + 32 * lpInfo->slot) = lpInfo->ItemLevel;
				*(BYTE*)(o + 523 + 32 * lpInfo->slot) = lpInfo->Option1;
				*(BYTE*)(o + 524 + 32 * lpInfo->slot) = lpInfo->Excellent;
			}

			pSetCharacterScale(o);
		}

		/*int SOUND_MONSTER = 210;

		pLoadWaveFile(1000,"Data\\Sound\\mIceQueen1.wav",2,1);
		pLoadWaveFile(1001,"Data\\Sound\\mIceQueen2.wav" ,2,1);
		pLoadWaveFile(1002,"Data\\Sound\\mIceQueenAttack1.wav",2,1);
		pLoadWaveFile(1003,"Data\\Sound\\mIceQueenAttack2.wav",2,1);
		pLoadWaveFile(1004,"Data\\Sound\\mIceQueenDie.wav",2,1);

		pSetMonsterSound(329+index,1000-SOUND_MONSTER,1001-SOUND_MONSTER,1002-SOUND_MONSTER,1003-SOUND_MONSTER,1004-SOUND_MONSTER,-1,-1,-1,-1,-1);*/

		return o;
	}

	return pSettingMonster(o,index);
}
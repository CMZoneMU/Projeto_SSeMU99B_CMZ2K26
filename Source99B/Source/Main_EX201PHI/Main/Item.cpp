#include "stdafx.h"
#include "Item.h"
#include "CustomEffect.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomTooltip.h"
#include "CustomWing.h"
#include "Offset.h"
#include "Util.h"

void InitItem() // OK
{
	SetCompleteHook(0xE8,0x0069529F,&ItemModelLoad);

	SetCompleteHook(0xE8,0x006952B4,&ItemTextureLoad);

	SetCompleteHook(0xFF,0x0052F0A5,&GetItemColor);

	SetCompleteHook(0xFF,0x006786A6,&GetItemColor);

	SetCompleteHook(0xE8,0x0052590F,&GetItemEffect);

	SetCompleteHook(0xE8,0x0067C698,&GetItemEffect);

	SetCompleteHook(0xE9,0x00601068,&GetItemToolTip);

	SetCompleteHook(0xE8,0x00616999,&MoveItem);
}

void InitBundle() // OK
{
	SetCompleteHook(0xE9,0x004030A8,&BundleCheckIndex1);

	SetCompleteHook(0xE9,0x005FF36E,&BundleCheckIndex2);

	SetCompleteHook(0xE9,0x0063A032,&BundleCheckIndex3);

	SetCompleteHook(0xE9,0x00639350,&BundleCheckIndex4);

	SetCompleteHook(0xE9,0x00638F55,&BundleCheckIndex5);
}

void InitJewel() // OK
{
	SetCompleteHook(0xE9,0x00619191,&JewelCheckApplyItem1);

	SetCompleteHook(0xE9,0x0062F89E,&JewelCheckApplyItem2);

	SetCompleteHook(0xE9,0x004EB397,&JewelCheckIndex1);

	SetCompleteHook(0xE9,0x00672C72,&JewelCheckIndex2);

	SetCompleteHook(0xE9,0x0063075A,&JewelCheckIndex3);
}

void InitWing() // OK
{
	SetCompleteHook(0xE8,0x004B8F7E,&WingMakePreviewCharSet);

	SetCompleteHook(0xE8,0x004DB15D,&WingMakePreviewCharSet);
	
	SetCompleteHook(0xE8,0x004E1115,&WingMakePreviewCharSet);
	
	SetCompleteHook(0xE8,0x004E209A,&WingMakePreviewCharSet);
	
	SetCompleteHook(0xE8,0x004FD9A0,&WingMakePreviewCharSet);
	
	SetCompleteHook(0xE8,0x004FFFEF,&WingMakePreviewCharSet);
}

void ItemModelLoad() // OK
{
	((void(*)())0x0068215F)();

	LoadItemModel(GET_ITEM_MODEL(12,136),"Item\\","Jewel03");
	
	LoadItemModel(GET_ITEM_MODEL(12,137),"Item\\","jewel22");

	LoadItemModel(GET_ITEM_MODEL(12,138),"Item\\","suho");

	LoadItemModel(GET_ITEM_MODEL(12,139),"Item\\","rs");

	LoadItemModel(GET_ITEM_MODEL(12,140),"Item\\","jos");

	LoadItemModel(GET_ITEM_MODEL(12,141),"Item\\","Jewel15");

	LoadItemModel(GET_ITEM_MODEL(12,142),"Item\\","LowRefineStone");

	LoadItemModel(GET_ITEM_MODEL(12,143),"Item\\","HighRefineStone");

	for(int n=0;n<MAX_CUSTOM_JEWEL;n++)
	{
		if(gCustomJewel.m_CustomJewelInfo[n].Index != -1)
		{
			LoadItemModel((gCustomJewel.m_CustomJewelInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\",gCustomJewel.m_CustomJewelInfo[n].ModelName);
		}
	}

	for(int n=0;n<MAX_CUSTOM_WING;n++)
	{
		if(gCustomWing.m_CustomWingInfo[n].Index != -1)
		{
			LoadItemModel((gCustomWing.m_CustomWingInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\",gCustomWing.m_CustomWingInfo[n].ModelName);
		}
	}

	for(int n=0;n<MAX_CUSTOM_ITEM;n++)
	{
		if(gCustomItem.m_CustomItemInfo[n].Index != -1)
		{
			LoadItemModel((gCustomItem.m_CustomItemInfo[n].ItemIndex+ITEM_BASE_MODEL),((gCustomItem.m_CustomItemInfo[n].ItemIndex >= GET_ITEM(7,0) && gCustomItem.m_CustomItemInfo[n].ItemIndex<GET_ITEM(12,0)) ? "Player\\" : "Item\\"),gCustomItem.m_CustomItemInfo[n].ModelName);
		}
	}
}

void ItemTextureLoad() // OK
{
	((void(*)())0x006841D7)();

	LoadItemTexture(GET_ITEM_MODEL(12,136),"Item\\");

	LoadItemTexture(GET_ITEM_MODEL(12,137),"Item\\");

	LoadItemTexture(GET_ITEM_MODEL(12,138),"Item\\");

	LoadItemTexture(GET_ITEM_MODEL(12,139),"Item\\");

	LoadItemTexture(GET_ITEM_MODEL(12,140),"Item\\");

	LoadItemTexture(GET_ITEM_MODEL(12,141),"Item\\");

	LoadItemTexture(GET_ITEM_MODEL(12,142),"Item\\");

	LoadItemTexture(GET_ITEM_MODEL(12,143),"Item\\");

	for(int n=0;n<MAX_CUSTOM_JEWEL;n++)
	{
		if(gCustomJewel.m_CustomJewelInfo[n].Index != -1)
		{
			LoadItemTexture((gCustomJewel.m_CustomJewelInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\");
		}
	}

	for(int n=0;n<MAX_CUSTOM_WING;n++)
	{
		if(gCustomWing.m_CustomWingInfo[n].Index != -1)
		{
			LoadItemTexture((gCustomWing.m_CustomWingInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\");
		}
	}

	for(int n=0;n<MAX_CUSTOM_ITEM;n++)
	{
		if(gCustomItem.m_CustomItemInfo[n].Index != -1)
		{
			LoadItemTexture((gCustomItem.m_CustomItemInfo[n].ItemIndex+ITEM_BASE_MODEL),((gCustomItem.m_CustomItemInfo[n].ItemIndex >= GET_ITEM(7,0) && gCustomItem.m_CustomItemInfo[n].ItemIndex<GET_ITEM(12,0)) ? "Player\\" : "Item\\"));
		}
	}
}

void LoadItemModel(int index,char* folder,char* name)
{
	if(name[0] == 0)
	{
		return;
	}

	char path[MAX_PATH]={ 0 };

	wsprintf(path,"Data\\%s",folder);

	pLoadItemModel(index,path,name,-1);
}

void LoadItemTexture(int index,char* folder)
{
	pLoadItemTexture(index,folder,GL_REPEAT,GL_NEAREST,GL_TRUE);
}

void GetItemColor(DWORD a,DWORD b,DWORD c,DWORD d,DWORD e) // OK
{
	if(gCustomItem.GetCustomItemColor((a-ITEM_BASE_MODEL),(float*)d) == 0)
	{
		((void(*)(DWORD,DWORD,DWORD,DWORD,DWORD))0x00673B6C)(a,b,c,d,e);
	}
}

void GetItemEffect(DWORD a,int b,float* c,float d,int e,int f,int g,int h,int i) // OK
{
	for(int n=0;n < MAX_CUSTOM_EFFECT;n++)
	{
		if(gCustomEffect.m_CustomEffectInfo[n].Index != -1)
		{
			if(gCustomEffect.m_CustomEffectInfo[n].ItemIndex != (b-ITEM_BASE_MODEL))
			{
				continue;
			}

			if(gCustomEffect.m_CustomEffectInfo[n].MinItemLevel != -1 && gCustomEffect.m_CustomEffectInfo[n].MinItemLevel > GET_ITEM_OPT_LEVEL(e))
			{
				continue;
			}

			if(gCustomEffect.m_CustomEffectInfo[n].MaxItemLevel != -1 && gCustomEffect.m_CustomEffectInfo[n].MaxItemLevel < GET_ITEM_OPT_LEVEL(e))
			{
				continue;
			}

			if(gCustomEffect.m_CustomEffectInfo[n].MinNewOption != -1 && gCustomEffect.m_CustomEffectInfo[n].MinNewOption > GET_ITEM_OPT_EXC(f))
			{
				continue;
			}

			if(gCustomEffect.m_CustomEffectInfo[n].MaxNewOption != -1 && gCustomEffect.m_CustomEffectInfo[n].MaxNewOption < GET_ITEM_OPT_EXC(f))
			{
				continue;
			}

			DWORD o = 240 * b + *(DWORD*)0x05846038;

			float ItemColor[3];
			
			float Position[3] = {0.0f,0.0f,0.0f};

			float WorldPosition[3] = {0.0f,0.0f,0.0f};

			ItemColor[0] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorR/255.0f);
			
			ItemColor[1] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorG/255.0f);
			
			ItemColor[2] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorB/255.0f);

			pTransformPosition(o,0x00698DD7C+(48*gCustomEffect.m_CustomEffectInfo[n].EffectValue),Position,WorldPosition,true);

			switch(gCustomEffect.m_CustomEffectInfo[n].EffectType)
			{
				case 0:
					pCreateSprite(gCustomEffect.m_CustomEffectInfo[n].EffectIndex,WorldPosition,gCustomEffect.m_CustomEffectInfo[n].Scale,ItemColor,1,0,gCustomEffect.m_CustomEffectInfo[n].EffectLevel);
					break;
				case 1:
					pCreateParticle(gCustomEffect.m_CustomEffectInfo[n].EffectIndex,WorldPosition,a+28,ItemColor,gCustomEffect.m_CustomEffectInfo[n].EffectLevel,gCustomEffect.m_CustomEffectInfo[n].Scale,1);
					break;
				case 2:
					pCreateEffect(gCustomEffect.m_CustomEffectInfo[n].EffectIndex,WorldPosition,a+28,ItemColor,gCustomEffect.m_CustomEffectInfo[n].EffectLevel,a,0,0,0,0,0);
					break;
			}
		}
	}

	if((b >= GET_ITEM_MODEL(12,136) && b <= GET_ITEM_MODEL(12,143)) || gCustomJewel.CheckCustomJewelByItem((b-ITEM_BASE_MODEL)) != 0)
	{
		e = (8<<3);
	}

	pRenderPartObjectEffect(a,b,c,d,e,f,g,h,i);
}

void DrawItemToolTip(DWORD address) // OK
{
	for(int i=0;i<MAX_CUSTOM_TOOLTIP;i++)
	{
		if(gCustomTooltip.m_CustomTooltipInfo[i].Index != -1 && gCustomTooltip.m_CustomTooltipInfo[i].ItemIndex == *(WORD*)(address+0x00))
		{
			if (gCustomTooltip.m_CustomTooltipInfo[i].ItemLevel == -1 || gCustomTooltip.m_CustomTooltipInfo[i].ItemLevel == GET_ITEM_OPT_LEVEL(*(DWORD*)(address+0x04)))
			{
				*(&*(DWORD*)0x079C0BA4 + *(DWORD*)0x079F26F8) = gCustomTooltip.m_CustomTooltipInfo[i].FontValue;
				*(&*(DWORD*)0x079EFB98 + *(DWORD*)0x079F26F8) = gCustomTooltip.m_CustomTooltipInfo[i].FontColor;

				wsprintf((char*)(0x64 * *(DWORD*)0x079F26F8 + 0x079BFA08), gCustomTooltip.m_CustomTooltipInfo[i].Text);

				*(DWORD*)0x079F26F8 += 1;
			}
		}
	}
}

bool MoveItem(DWORD a,DWORD b,int c,int d,int e) // OK
{
	if (pCheckWindow(WINDOWS_TRADE) != 0)
	{
		return ((bool(*)(DWORD,DWORD,int,int,int))0x00618280)(0x113,0x10F,0x079EFC10,d,0x04);
	}
	else if (pCheckWindow(WINDOWS_CHAOS_MIX) != 0 || pCheckWindow(WINDOWS_SENIOR_MIX) != 0 || pCheckWindow(WINDOWS_REFINERY) != 0 || pCheckWindow(WINDOWS_CHAOS_CARD) != 0)
	{
		return ((bool(*)(DWORD,DWORD,int,int,int))0x00618280)(0x113,0x6E,0x07E74008,d,0x04);
	}
	else if (pCheckWindow(WINDOWS_WAREHOUSE) != 0)
	{
		return ((bool(*)(DWORD,DWORD,int,int,int))0x00618280)(a,b,c,d,e);
	}
	
	return 0;
}

void WingMakePreviewCharSet(int a,BYTE* b,int c,int d,int e,int f,int g) // OK
{
	((void(*)(int,BYTE*,int,int,int,int,int))0x00533303)(a,b,c,d,e,f,g);
	
	DWORD ViewportAddress = pViewportAddress+(a*0x478);

	if(*(BYTE*)(ViewportAddress) == 0)
	{
		return;
	}

	int Index = ((b[16]>>1)-1);

	if(gCustomWing.CheckCustomWing(Index) != 0)
	{
		int ItemIndex = gCustomWing.GetCustomWingItem(Index);

		if(ItemIndex != 0)
		{
			*(WORD*)(ViewportAddress+0x338) = (ItemIndex+ITEM_BASE_MODEL);
		}
	}
}

__declspec(naked) void GetItemToolTip() // OK
{
	static DWORD ItemApplyToolTipAddress1 = 0x0060106E;

	_asm
	{
		PushAd
		Push Ebp
		Call[DrawItemToolTip]
		Add Esp,0x04
		PopAd
		Cmp Word Ptr Ss:[Ebp],0x1C0D
		Jmp[ItemApplyToolTipAddress1]
	}
}

__declspec(naked) void BundleCheckIndex1() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x004030B4;
	static DWORD BundleCheckIndexAddress2 = 0x004030EB;

	_asm
	{
		Cmp Ecx,GET_ITEM(12,30)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,136)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,137)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,138)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,139)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,140)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,141)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,142)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,143)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Mov Al,2;
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex2() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005FF398;
	static DWORD BundleCheckIndexAddress2 = 0x005FF386;

	_asm
	{
		Cmp Cx,GET_ITEM(12,30)
		Jz Exit
		Cmp Cx,GET_ITEM(12,136)
		Jz Next1
		Cmp Cx,GET_ITEM(12,137)
		Jz Next2
		Cmp Cx,GET_ITEM(12,138)
		Jz Next3
		Cmp Cx,GET_ITEM(12,139)
		Jz Next4
		Cmp Cx,GET_ITEM(12,140)
		Jz Next5
		Cmp Cx,GET_ITEM(12,141)
		Jz Next6
		Cmp Cx,GET_ITEM(12,142)
		Jz Next7
		Cmp Cx,GET_ITEM(12,143)
		Jz Next8
		Jmp[BundleCheckIndexAddress1]
		Next1:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782EDDC]
		Jmp[BundleCheckIndexAddress2]
		Next2:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782EF08]
		Jmp[BundleCheckIndexAddress2]
		Next3:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782F034]
		Jmp[BundleCheckIndexAddress2]
		Next4:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782F160]
		Jmp[BundleCheckIndexAddress2]
		Next5:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782F28C]
		Jmp[BundleCheckIndexAddress2]
		Next6:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782F3B8]
		Jmp[BundleCheckIndexAddress2]
		Next7:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782F4E4]
		Jmp[BundleCheckIndexAddress2]
		Next8:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782F610]
		Jmp[BundleCheckIndexAddress2]
		Exit:
		Mov Edx,Dword Ptr Ss:[Esp+0x10]
		Lea Eax,[Eax*0x04+Eax]
		Inc Edx
		Lea Eax,[Eax*0x04+Eax]
		Push Edx
		Push [0x0782FE44]
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex3() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x0063A03E;
	static DWORD BundleCheckIndexAddress2 = 0x0063A10A;

	_asm
	{
		Cmp Esi,GET_ITEM(12,30)
		Jz Exit
		Cmp Esi,GET_ITEM(12,136)
		Jz Exit
		Cmp Esi,GET_ITEM(12,137)
		Jz Exit
		Cmp Esi,GET_ITEM(12,139)
		Jz Exit
		Cmp Esi,GET_ITEM(12,140)
		Jz Exit
		Cmp Esi,GET_ITEM(12,142)
		Jz Exit
		Cmp Esi,GET_ITEM(12,143)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex4() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x00639356;
	static DWORD BundleCheckIndexAddress2 = 0x00639776;

	_asm
	{
		Cmp Esi,GET_ITEM_MODEL(12,136)
		Je Next
		Cmp Esi,GET_ITEM_MODEL(12,137)
		Je Next
		Cmp Esi,GET_ITEM_MODEL(12,138)
		Je Next2
		Cmp Esi,GET_ITEM_MODEL(12,139)
		Je Next2
		Cmp Esi,GET_ITEM_MODEL(12,140)
		Je Next4
		Cmp Esi,GET_ITEM_MODEL(12,141)
		Je Next3
		Cmp Esi,GET_ITEM_MODEL(12,142)
		Je Next4
		Cmp Esi,GET_ITEM_MODEL(12,143)
		Je Next4
		Cmp Esi,GET_ITEM_MODEL(12,30)
		Jmp[BundleCheckIndexAddress1]
		Next:
		Mov Dword Ptr Ss:[Esp+0x10],993400000
		Jmp[BundleCheckIndexAddress2]
		Next2:
		Mov Dword Ptr Ss:[Esp+0x10],994500000
		Jmp[BundleCheckIndexAddress2]
		Next3:
		Mov Dword Ptr Ss:[Esp+0x10],990400000
		Jmp[BundleCheckIndexAddress2]
		Next4:
		Mov Dword Ptr Ss:[Esp+0x10],998900000
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex5() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x00638F61;
	static DWORD BundleCheckIndexAddress2 = 0x0063907E;

	_asm
	{
		Cmp Esi,GET_ITEM_MODEL(14,43)
		Jz Exit
		Cmp Esi,GET_ITEM_MODEL(12,142)
		Jz Exit
		Cmp Esi,GET_ITEM_MODEL(12,143)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckApplyItem1() // OK
{
	static DWORD JewelCheckApplyItemAddress1 = 0x00619198;
	static DWORD JewelCheckApplyItemAddress2 = 0x006191AF;

	_asm
	{
		PushAd
		Cmp Si,0x1C2C
		Jz Exit
		Push Esi
		Lea Ecx,gCustomJewel
		Call[CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		PopAd
		Jmp[JewelCheckApplyItemAddress1]
		Exit:
		PopAd
		Jmp[JewelCheckApplyItemAddress2]
	}
}

__declspec(naked) void JewelCheckApplyItem2() // OK
{
	static DWORD JewelCheckApplyItemAddress1 = 0x00630591;
	static DWORD JewelCheckApplyItemAddress2 = 0x0062F8A9;

	_asm
	{
		Cmp Dx,0x1C2C
		Jz Exit
		Push Edx
		Lea Ecx,gCustomJewel
		Call[CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		Jmp[JewelCheckApplyItemAddress1]
		Exit:
		Jmp[JewelCheckApplyItemAddress2]
	}
}

__declspec(naked) void JewelCheckIndex1() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x004EB3E9;
	static DWORD JewelCheckIndexAddress2 = 0x004EB39C;

	_asm
	{
		PushAd
		Push Eax
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Je EXIT
		Jmp [JewelCheckIndexAddress1]
		EXIT:
		PopAd
		Cmp Eax,0x1C0E
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckIndex2() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x00672CA8;
	static DWORD JewelCheckIndexAddress2 = 0x00672C79;

	_asm
	{
		Mov Eax,Dword Ptr Ss:[Ebp-0x04]
		Push Eax
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Je EXIT
		Jmp [JewelCheckIndexAddress1]
		EXIT:
		Cmp Dword Ptr Ss:[Ebp-0x04],0x1C0D
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckIndex3() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x00630764;
	static DWORD JewelCheckIndexAddress2 = 0x006307E5;

	_asm
	{
		PushAd
		Cmp Ax,0x1A1E
		Jz Exit
		Push Eax
		Lea Ecx,gCustomJewel
		Call[CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		PopAd
		Jmp[JewelCheckIndexAddress1]
		Exit:
		PopAd
		Jmp[JewelCheckIndexAddress2]
	}
}
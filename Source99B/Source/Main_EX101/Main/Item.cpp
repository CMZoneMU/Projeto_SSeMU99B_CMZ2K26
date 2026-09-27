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
	SetCompleteHook(0xE8,0x0060ABBB,&ItemModelLoad);

	SetCompleteHook(0xE8,0x0060ABC0,&ItemTextureLoad);

	SetCompleteHook(0xFF,0x005069A2,&GetItemColor);

	SetCompleteHook(0xFF,0x005F8445,&GetItemColor);

	SetCompleteHook(0xE8,0x0050074D,&GetItemEffect);

	SetCompleteHook(0xE8,0x005FA6BB,&GetItemEffect);

	SetCompleteHook(0xE9,0x005A5000,&GetItemToolTip);

	SetCompleteHook(0xE8,0x005B79B4,&MoveItem);
}

void InitBundle() // OK
{
	SetCompleteHook(0xE9,0x00402B39,&BundleCheckIndex1);

	SetCompleteHook(0xE9,0x005A3A4F,&BundleCheckIndex2);

	SetCompleteHook(0xE9,0x005D041C,&BundleCheckIndex3);

	SetCompleteHook(0xE9,0x005CF916,&BundleCheckIndex4);
}

void InitJewel() // OK
{
	SetCompleteHook(0xE9,0x005B8E7B,&JewelCheckApplyItem1);

	SetCompleteHook(0xE9,0x005C6CF9,&JewelCheckApplyItem2);

	SetCompleteHook(0xE9,0x004CA3D8,&JewelCheckIndex1);

	SetCompleteHook(0xE9,0x005CD714,&JewelCheckIndex2);

	SetCompleteHook(0xE9,0x005CDE3F,&JewelCheckIndex3);

	SetCompleteHook(0xE9,0x005F57EA,&JewelCheckIndex4);
}

void InitWing() // OK
{
	SetCompleteHook(0xE9,0x0050A674,&WingMakePreviewCharSet);

	SetCompleteHook(0xE9,0x005F871A,&WingDisableLevelGlow);

	SetCompleteHook(0xE9,0x005A5317,&WingSetIncDamage);

	SetCompleteHook(0xE9,0x005A5356,&WingSetDecDamage);

	SetCompleteHook(0xE9,0x00540EBD,&WingSetDefense);

	SetCompleteHook(0xE9,0x00540F0E,&WingSetExtraDefense);

	SetCompleteHook(0xE9,0x00541703,&WingSetOption);

	SetCompleteHook(0xE9,0x00541252,&WingSetNewOption);

	SetCompleteHook(0xE9,0x00540A98,&WingCheckIndex1);

	SetCompleteHook(0xE9,0x00540FA3,&WingCheckIndex2);

	SetCompleteHook(0xE9,0x005414B8,&WingCheckIndex3);

	SetCompleteHook(0xE9,0x0054222B,&WingCheckIndex4);

	SetCompleteHook(0xE9,0x00542292,&WingCheckIndex5);

	SetCompleteHook(0xE9,0x0054236B,&WingCheckIndex6);

	SetCompleteHook(0xE9,0x00542AF5,&WingCheckIndex7);

	SetCompleteHook(0xE9,0x00542B4F,&WingCheckIndex8);

	SetCompleteHook(0xE9,0x00542C00,&WingCheckIndex9);

	SetCompleteHook(0xE9,0x00542D95,&WingCheckIndex10);

	SetCompleteHook(0xE9,0x0058A06B,&WingCheckIndex11);

	SetCompleteHook(0xE9,0x005A1381,&WingCheckIndex12);

	SetCompleteHook(0xE9,0x005A1917,&WingCheckIndex13);

	SetCompleteHook(0xE9,0x005A2382,&WingCheckIndex14);

	SetCompleteHook(0xE9,0x005A3945,&WingCheckIndex15);

	SetCompleteHook(0xE9,0x005A5FF8,&WingCheckIndex16);

	SetCompleteHook(0xE9,0x005A7708,&WingCheckIndex17);

	SetCompleteHook(0xE9,0x005A7D77,&WingCheckIndex18);

	SetCompleteHook(0xE9,0x005AB4AA,&WingCheckIndex19);

	SetCompleteHook(0xE9,0x005B1843,&WingCheckIndex20);

	SetCompleteHook(0xE9,0x005B1880,&WingCheckIndex21);

	SetCompleteHook(0xE9,0x005C6D27,&WingCheckIndex22);

	SetCompleteHook(0xE9,0x005CD77D,&WingCheckIndex23);

	SetCompleteHook(0xE9,0x005CDE8A,&WingCheckIndex24);

	SetCompleteHook(0xE9,0x005EBDFC,&WingCheckIndex25);

	SetCompleteHook(0xE9,0x00540FC7,&WingCheckIndex26);

	SetCompleteHook(0xE9,0x00540FE7,&WingCheckIndex27);

	SetCompleteHook(0xE9,0x00541AA2,&WingCheckIndex28);

	SetCompleteHook(0xE9,0x005AA341,&WingCheckModelIndex1);

	SetCompleteHook(0xE9,0x005F9DE1,&WingCheckModelIndex2);

	SetCompleteHook(0xE9,0x005F874E,&WingCheckModelIndex3);
}

void ItemModelLoad() // OK
{
	((void(*)())0x005FD0E0)();

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

	LoadItemModel(GET_ITEM_MODEL(12,136),"Item\\","Jewel03"); // Bundle Life
	
	LoadItemModel(GET_ITEM_MODEL(12,137),"Item\\","jewel22"); // Bundle Creation
	
	LoadItemModel(GET_ITEM_MODEL(12,138),"Item\\","suho"); // Bundle Guardian
	
	LoadItemModel(GET_ITEM_MODEL(12,141),"Item\\","Jewel15"); // Bundle Chaos
}

void ItemTextureLoad() // OK
{
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

	LoadItemTexture(GET_ITEM_MODEL(12,136),"Item\\"); // Bundle Life
	
	LoadItemTexture(GET_ITEM_MODEL(12,137),"Item\\"); // Bundle Creation
	
	LoadItemTexture(GET_ITEM_MODEL(12,138),"Item\\"); // Bundle Guardian
	
	LoadItemTexture(GET_ITEM_MODEL(12,141),"Item\\"); // Bundle Chaos

	((void(*)())0x005FE910)();
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
		((void(*)(DWORD,DWORD,DWORD,DWORD,DWORD))0x005F6220)(a,b,c,d,e);
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

			DWORD o = 224 * b + *(DWORD*)0x05756AB8;

			float ItemColor[3];
			
			float Position[3] = {0.0f,0.0f,0.0f};

			float WorldPosition[3] = {0.0f,0.0f,0.0f};

			ItemColor[0] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorR/255.0f);
			
			ItemColor[1] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorG/255.0f);
			
			ItemColor[2] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorB/255.0f);

			pTransformPosition(o,0x00689E7FC+(48*gCustomEffect.m_CustomEffectInfo[n].EffectValue),Position,WorldPosition,true);

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

	if(b == GET_ITEM_MODEL(12,136) || b == GET_ITEM_MODEL(12,137) ||b == GET_ITEM_MODEL(12,138) ||b == GET_ITEM_MODEL(12,141) || gCustomJewel.CheckCustomJewelByItem((b-ITEM_BASE_MODEL)) != 0)
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
				*(&*(DWORD*)0x0785B2A8 + *(DWORD*)0x0788C850) = gCustomTooltip.m_CustomTooltipInfo[i].FontValue;
				*(&*(DWORD*)0x07889F60 + *(DWORD*)0x0788C850) = gCustomTooltip.m_CustomTooltipInfo[i].FontColor;

				wsprintf((char*)(0x64 * *(DWORD*)0x0788C850 + 0x0785A110), gCustomTooltip.m_CustomTooltipInfo[i].Text);

				*(DWORD*)0x0788C850 += 1;
			}
		}
	}
}

bool MoveItem(DWORD a,DWORD b,int c,int d,int e) // OK
{
	if (pCheckWindow(WINDOWS_TRADE) != 0)
	{
		return ((bool(*)(DWORD,DWORD,int,int,int))0x005B8890)(0x113,0x10F,0x07889FD8,d,4);
	}
	else if (pCheckWindow(WINDOWS_CHAOS_MIX) != 0 || pCheckWindow(WINDOWS_SENIOR_MIX) != 0)
	{
		return ((bool(*)(DWORD,DWORD,int,int,int))0x005B8890)(0x113,0x6E,0x07D0E088,d,4);
	}
	else if (pCheckWindow(WINDOWS_WAREHOUSE) != 0)
	{
		return ((bool(*)(DWORD,DWORD,int,int,int))0x005B8890)(a,b,c,d,e);
	}
	
	return 0;
}

__declspec(naked) void GetItemToolTip() // OK
{
	static DWORD ItemApplyToolTipAddress1 = 0x005A5005;

	_asm
	{
		PushAd
		Push Esi
		Call [DrawItemToolTip]
		Add Esp,0x04
		PopAd
		Cmp Word Ptr Ss:[Esi],0x1C0D
		Jmp [ItemApplyToolTipAddress1]
	}
}

__declspec(naked) void BundleCheckIndex1() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x00402B43;
	static DWORD BundleCheckIndexAddress2 = 0x00402B63;

	_asm
	{
		Cmp Ax,GET_ITEM(12,30)
		Jz Exit
		Cmp Ax,GET_ITEM(12,136)
		Jz Exit
		Cmp Ax,GET_ITEM(12,137)
		Jz Exit
		Cmp Ax,GET_ITEM(12,138)	
		Jz Exit
		Cmp Ax,GET_ITEM(12,141)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Mov Al,2;
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex2() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005A3A6C;
	static DWORD BundleCheckIndexAddress2 = 0x005A3A62;

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
		Cmp Cx,GET_ITEM(12,141)
		Jz Next4
		Jmp[BundleCheckIndexAddress1]
		Next1:
		Mov Edi,Dword Ptr Ss:[Ebp-0x10]
		Lea Ecx,[Edi+1]
		Push Ecx
		Push [0x077251A4]
		Jmp[BundleCheckIndexAddress2]
		Next2:
		Mov Edi,Dword Ptr Ss:[Ebp-0x10]
		Lea Ecx,[Edi+1]
		Push Ecx
		Push [0x077252D0]
		Jmp[BundleCheckIndexAddress2]
		Next3:
		Mov Edi,Dword Ptr Ss:[Ebp-0x10]
		Lea Ecx,[Edi+1]
		Push Ecx
		Push [0x077253FC]
		Jmp[BundleCheckIndexAddress2]
		Next4:
		Mov Edi,Dword Ptr Ss:[Ebp-0x10]
		Lea Ecx,[Edi+1]
		Push Ecx
		Push [0x07725780]
		Jmp[BundleCheckIndexAddress2]
		Exit:
		Mov Edi,Dword Ptr Ss:[Ebp-0x10]
		Lea Ecx,[Edi+1]
		Push Ecx
		Push [0x0772620C]
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex3() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005D0428;
	static DWORD BundleCheckIndexAddress2 = 0x005D04EA;

	_asm
	{
		Cmp Esi,GET_ITEM(12,30)
		Jz Exit
		Cmp Esi,GET_ITEM(12,136)
		Jz Exit
		Cmp Esi,GET_ITEM(12,137)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex4() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005CF91C;
	static DWORD BundleCheckIndexAddress2 = 0x005CFC58;

	_asm
	{
		Cmp Esi,GET_ITEM_MODEL(12,136)
		Je Next
		Cmp Esi,GET_ITEM_MODEL(12,137)
		Je Next
		Cmp Esi,GET_ITEM_MODEL(12,138)
		Je Next2
		Cmp Esi,GET_ITEM_MODEL(12,141)
		Je Next3
		Cmp Esi,GET_ITEM_MODEL(12,30)
		Jmp[BundleCheckIndexAddress1]
		Next:
		Mov Dword Ptr Ss:[Ebp+0x20],993400000
		Jmp[BundleCheckIndexAddress2]
		Next2:
		Mov Dword Ptr Ss:[Ebp+0x20],994500000
		Jmp[BundleCheckIndexAddress2]
		Next3:
		Mov Dword Ptr Ss:[Ebp+0x20],990400000
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckApplyItem1()
{
	static DWORD JewelCheckApplyItemAddress1 = 0x005B8E82;
	static DWORD JewelCheckApplyItemAddress2 = 0x005B8E92;

	_asm
	{
		PushAd
		Cmp Si,0x1C16
		Jz Exit
		Push Esi
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		PopAd
		Jmp [JewelCheckApplyItemAddress1]
		Exit:
		PopAd
		Jmp [JewelCheckApplyItemAddress2]
	}
}

__declspec(naked) void JewelCheckApplyItem2()
{
	static DWORD JewelCheckApplyItemAddress1 = 0x005C76D3;
	static DWORD JewelCheckApplyItemAddress2 = 0x005C6D04;

	_asm
	{
		Cmp Dx,0x1C10
		Jz Exit
		Push Edx
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		Jmp [JewelCheckApplyItemAddress1]
		Exit:
		Jmp [JewelCheckApplyItemAddress2]
	}
}

__declspec(naked) void JewelCheckIndex1() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x004CA416;
	static DWORD JewelCheckIndexAddress2 = 0x004CA3DD;

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

__declspec(naked) void JewelCheckIndex2()
{
	static DWORD JewelCheckIndexAddress1 = 0x005CDE0D;
	static DWORD JewelCheckIndexAddress2 = 0x005CD719;

	_asm
	{
		Mov Eax,Dword Ptr Ds:[0x0785ACC8]
		Push Eax
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Je EXIT
		Jmp [JewelCheckIndexAddress1]
		EXIT:
		Mov Eax,Dword Ptr Ds:[0x0785ACC8]
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckIndex3()
{
	static DWORD JewelCheckIndexAddress1 = 0x005CF0DE;
	static DWORD JewelCheckIndexAddress2 = 0x005CDE45;

	_asm
	{
		Mov Ecx,Dword Ptr Ds:[0x0785ACC8]
		Push Ecx
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Je EXIT
		Jmp [JewelCheckIndexAddress1]
		EXIT:
		Mov Ecx,Dword Ptr Ds:[0x0785ACC8]
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckIndex4() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x005F5824;
	static DWORD JewelCheckIndexAddress2 = 0x005F57F0;

	_asm
	{
		PushAd
		Push Ebx
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Je EXIT
		PopAd
		Jmp [JewelCheckIndexAddress1]
		EXIT:
		PopAd
		Cmp Ebx,0x1C0D
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void WingMakePreviewCharSet() // OK
{
	static DWORD WingMakePreviewCharSetAddress1 = 0x0050A6C5;
	static DWORD WingMakePreviewCharSetAddress2 = 0x0050A679;

	_asm
	{
		Pushad
		Movzx Edx,Byte Ptr Ds:[Edi+0x10]
		Sar Edx,0x01
		And Edx,0x0F
		Test Edx,Edx
		Je EXIT
		Movzx Ecx,Byte Ptr Ds:[Edi+0x10]
		Sar Ecx,0x01
		And Ecx,0x0F
		Sub Ecx,0x01
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWing]
		Test Eax,Eax
		Je EXIT
		Movzx Eax, Byte Ptr Ds:[Edi+0x10]
		Sar Eax,0x01
		And Eax,0x0F
		Sub Eax,0x01
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingItem]
		Add Eax,ITEM_BASE_MODEL
		Mov Word Ptr Ds:[Esi+0x2E8],Ax
		Popad
		Jmp[WingMakePreviewCharSetAddress1]
		EXIT:
		Popad
		Mov Al,Byte Ptr Ds:[Edi+0x08]
		And Al,0x07
		Jmp[WingMakePreviewCharSetAddress2]
	}
}

__declspec(naked) void WingDisableLevelGlow() // OK
{
	static DWORD WingDisableLevelGlowAddress1 = 0x005F87E0;
	static DWORD WingDisableLevelGlowAddress2 = 0x005F8720;
	
	_asm
	{
		PushAd
		Sub Ecx,ITEM_BASE_MODEL
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		PopAd
		Xor Ebx,Ebx
		Jmp [WingDisableLevelGlowAddress1]
		EXIT:
		PopAd
		Cmp Ecx,0x1E19
		Jmp [WingDisableLevelGlowAddress2]
	}
}

__declspec(naked) void WingSetIncDamage() // OK
{
	static DWORD WingSetIncDamageAddress1 = 0x005A5326;
	static DWORD WingSetIncDamageAddress2 = 0x005A531C;
	static DWORD Damage;

	_asm
	{
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Movsx Eax,Word Ptr Ds:[Esi]
		Mov Ecx,Dword Ptr Ds:[Esi+0x04]
		Sar Ecx,0x03
		And Ecx,0x0F
		Push Ecx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingIncDamage]
		Mov Damage,Eax
		Popad
		Push Damage
		Lea Eax,[Eax+Eax*4]
		Jmp [WingSetIncDamageAddress1]
		EXIT:
		Popad
		Cmp Cx,0x1806
		Jmp [WingSetIncDamageAddress2]
	}
}

__declspec(naked) void WingSetDecDamage() // OK
{
	static DWORD WingSetDecDamageAddress1 = 0x005A535C;
	static DWORD Damage;

	_asm
	{
		Pushad
		Movsx Ecx,Word Ptr Ds:[Esi]
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Movsx Eax,Word Ptr Ds:[Esi]
		Mov Ecx,Dword Ptr Ds:[Esi+0x04]
		Sar Ecx,0x03
		And Ecx,0x0F
		Push Ecx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingDecDamage]
		Mov Damage,Eax
		Popad
		Mov Ecx,Damage
		Push Ecx
		Mov Dword Ptr Ss:[0x00788C850],Eax
		Jmp [WingSetDecDamageAddress1]
		EXIT:
		Popad
		Push Ecx
		Mov Dword Ptr Ss:[0x00788C850],Eax
		Jmp [WingSetDecDamageAddress1]
	}
}

__declspec(naked) void WingSetDefense() // OK
{
	static DWORD WingSetDefenseAddress1 = 0x00540EDF;
	static DWORD WingSetDefenseAddress2 = 0x00540EC4;

	_asm
	{
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Mov Dx,[Esi]
		Movsx Ecx,Dx
		Push Ebx
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingDefense]
		Mov Dx,[Esi+0x12]
		Movsx Ecx,Dx
		Add Ecx,Eax
		Mov [Esi+0x12],Cx
		Jmp [WingSetDefenseAddress1]
		EXIT:
		Mov Ax,[Esi]
		Cmp Ax,0x1803
		Jmp [WingSetDefenseAddress2]
	}
}

__declspec(naked) void WingSetExtraDefense() // OK
{
	static DWORD WingSetExtraDefenseAddress1 = 0x00540F31;
	static DWORD WingSetExtraDefenseAddress2 = 0x00540F14;

	_asm
	{
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Lea Eax,[Ebx]
		Cmp Eax,0x0A
		Jnz NEXT1
		Mov Dx,[Esi+0x12]
		Movsx Ecx,Dx
		Add Ecx,0x01
		Mov [Esi+0x12],Cx
		Jmp [WingSetExtraDefenseAddress1]
		NEXT1:
		Lea Eax,[Ebx]
		Cmp Eax,0x0B
		Jnz NEXT2
		Mov Dx,[Esi+0x12]
		Movsx Ecx,Dx
		Add Ecx,0x03
		Mov [Esi+0x12],Cx
		Jmp [WingSetExtraDefenseAddress1]
		NEXT2:
		Lea Eax,[Ebx]
		Cmp Eax,0x0C
		Jnz NEXT3
		Mov Dx,[Esi+0x12]
		Movsx Ecx,Dx
		Add Ecx,0x06
		Mov [Esi+0x12],Cx
		Jmp [WingSetExtraDefenseAddress1]
		NEXT3:
		Lea Eax,[Ebx]
		Cmp Eax,0x0D
		Jnz NEXT4
		Mov Dx,[Esi+0x12]
		Movsx Ecx,Dx
		Add Ecx,0x0A
		Mov [Esi+0x12],Cx
		Jmp [WingSetExtraDefenseAddress1]
		NEXT4:
		Jmp [WingSetExtraDefenseAddress1]
		EXIT:
		Lea Eax,[Ebx-0x0A]
		Cmp Eax,0x03
		Jmp [WingSetExtraDefenseAddress2]
	}
}

__declspec(naked) void WingSetOption() // OK
{
	static DWORD WingSetOptionAddress1 = 0x00541745;
	static DWORD WingSetOptionAddress2 = 0x00541726;
	static DWORD WingSetOptionAddress3 = 0x00541709;

	_asm
	{
		Pushad
		Push Ecx
		Movsx Edx,Ax
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Test Byte Ptr[Ebp-0x0C],0x20
		Jz NEXT1
		Mov Ax,[Esi]
		Movsx Edx,Ax
		Push 0x02
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionValue]
		Pop Ecx
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Imul Eax,cl
		Mov Byte Ptr DS:[Edx+Esi+0x33],Al
		Mov Ax,[Esi]
		Movsx Edx,Ax
		Push 0x02
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionIndex]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Word Ptr DS:[Edx+Esi+0x2B],Ax
		Inc Dl
		Mov Byte Ptr[Esi+0x2A],Dl
		Popad
		Jmp [WingSetOptionAddress1]
		NEXT1:
		Test Byte Ptr[Ebp+0x10],0x10
		Jz NEXT2
		Mov Ax,[Esi]
		Movsx Edx,Ax
		Push 0x01
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionValue]
		Pop Ecx
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Imul Eax,cl
		Mov Byte Ptr DS:[Edx+Esi+0x33],Al
		Mov Ax,[Esi]
		Movsx Edx,Ax
		Push 0x01
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionIndex]
		Xor Edx,Edx
		Mov Dl, Byte Ptr[Esi+0x2A]
		Mov Word Ptr DS:[Edx+Esi+0x2B],Ax
		Inc Dl
		Mov Byte Ptr[Esi+0x2A],Dl
		Popad
		Jmp [WingSetOptionAddress1]
		NEXT2:
		Mov Ax,[Esi]
		Movsx Edx,Ax
		Push 0x00
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionValue]
		Pop Ecx
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Imul Eax,cl
		Mov Byte Ptr DS:[Edx+Esi+0x33],Al
		Mov Ax,[Esi]
		Movsx Edx,Ax
		Push 0x00
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionIndex]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Word Ptr DS:[Edx+Esi+0x2B],Ax
		Inc Dl
		Mov Byte Ptr[Esi+0x2A],Dl
		Popad
		Jmp [WingSetOptionAddress1]
		EXIT:
		Pop Ecx
		Popad
		Mov Ax,[Esi]
		Cmp Ax,0x1806
		Jnz EXIT2
		Jmp [WingSetOptionAddress3]
		EXIT2:
		Jmp [WingSetOptionAddress2]
	}
}

__declspec(naked) void WingSetNewOption() // OK
{
	static DWORD WingSetNewOptionAddress1 = 0x0054145A;
	static DWORD WingSetNewOptionAddress2 = 0x00541257;

	_asm
	{
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Test Byte Ptr[Ebp-0x0C],0x01
		Jz NEXT1
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x00
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Byte Ptr[Edx+Esi+0x33],Al
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x00
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Word Ptr DS:[Edx+Esi+0x2B],Ax
		Mov Dl,Byte Ptr[Esi+0x2A]
		Inc Dl
		Mov Byte Ptr[Esi+0x2A],Dl
		NEXT1:
		Test Byte Ptr[Ebp-0x0C],0x02
		Jz NEXT2
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x01
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Byte Ptr DS:[Edx+Esi+0x33],Al
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x01
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Word Ptr DS:[Edx+Esi+0x2B],Ax
		Mov Dl, Byte Ptr[Esi+0x2A]
		Inc Dl
		Mov Byte Ptr[Esi+0x2A],Dl
		NEXT2:
		Test Byte Ptr[Ebp-0x0C],0x04
		Jz NEXT3
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x02
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Byte Ptr DS:[Edx+Esi+0x33],Al
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x02
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Word Ptr DS:[Edx+Esi+0x2B],Ax
		Mov Dl,Byte Ptr[Esi+0x2A]
		Inc Dl
		Mov Byte Ptr[Esi+0x2A],Dl
		NEXT3:
		Test Byte Ptr[Ebp-0x0C],0x08
		Jz NEXT4
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x03
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Byte Ptr DS:[Edx+Esi+0x33],Al
		Mov Ax,[Esi]
		Movsx Ecx,Ax
		Push 0x03
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Xor Edx,Edx
		Mov Dl,Byte Ptr[Esi+0x2A]
		Mov Word Ptr DS:[Edx+Esi+0x2B],Ax
		Mov Dl,Byte Ptr[Esi+0x2A]
		Inc Dl
		Mov Byte Ptr[Esi+0x2A],Dl
		NEXT4:
		Popad
		Jmp [WingSetNewOptionAddress1]
		EXIT:
		Popad
		Cmp Cx,0x1806
		Jmp [WingSetNewOptionAddress2]
	}
}

__declspec(naked) void WingCheckIndex1() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00540ABC;
	static DWORD WingCheckIndexAddress2 = 0x00540A9E;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex2() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00540FAA;
	static DWORD WingCheckIndexAddress2 = 0x00540FAF;

	__asm
	{
		Cmp Dx,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Dx
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex3() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005414BE;
	static DWORD WingCheckIndexAddress2 = 0x005414CF;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex4() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x0054224A;
	static DWORD WingCheckIndexAddress2 = 0x0054244B;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex5() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005422A0;
	static DWORD WingCheckIndexAddress2 = 0x00542299;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex6() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00542373;
	static DWORD WingCheckIndexAddress2 = 0x0054239E;

	__asm
	{
		Mov Dx,Word Ptr Ss:[Ebp-0x14]
		Cmp Dx,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Dx
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex7() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00542B14;
	static DWORD WingCheckIndexAddress2 = 0x00542D1D;

	__asm
	{
		Cmp Di,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Di
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex8() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00542B56;
	static DWORD WingCheckIndexAddress2 = 0x00542B6B;

	__asm
	{
		Cmp Di,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Di
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex9() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00542C07;
	static DWORD WingCheckIndexAddress2 = 0x00542C72;

	__asm
	{
		Mov Ax,Word Ptr Ds:[Ebx]
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex10() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00542DFC;
	static DWORD WingCheckIndexAddress2 = 0x00542D9B;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex11() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x0058A0E1;
	static DWORD WingCheckIndexAddress2 = 0x0058A071;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex12() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005A13B3;
	static DWORD WingCheckIndexAddress2 = 0x005A1388;

	__asm
	{
		Cmp Dx,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Dx
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex13() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005A191E;
	static DWORD WingCheckIndexAddress2 = 0x005A1950;

	__asm
	{
		Cmp Eax,0x1806
		Jle NEXT
		Pushad
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex14() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005A2390;
	static DWORD WingCheckIndexAddress2 = 0x005A2389;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex15() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005A394C;
	static DWORD WingCheckIndexAddress2 = 0x005A3970;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex16() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005A5FFF;
	static DWORD WingCheckIndexAddress2 = 0x005A6006;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex17() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005A7714;
	static DWORD WingCheckIndexAddress2 = 0x005A770E;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex18() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005A7D85;
	static DWORD WingCheckIndexAddress2 = 0x005A7D7E;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex19() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005AB4D7;
	static DWORD WingCheckIndexAddress2 = 0x005AB4B0;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex20() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B184F;
	static DWORD WingCheckIndexAddress2 = 0x005B1849;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex21() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B2688;
	static DWORD WingCheckIndexAddress2 = 0x005B188B;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex22() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005C6D3C;
	static DWORD WingCheckIndexAddress2 = 0x005C6D2F;

	__asm
	{
		Cmp Esi,0x1806
		Jle NEXT
		Pushad
		Push Esi
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex23() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005CDE0D;
	static DWORD WingCheckIndexAddress2 = 0x005CD788;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex24() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005CF0DE;
	static DWORD WingCheckIndexAddress2 = 0x005CDE95;

	__asm
	{
		Cmp Cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex25() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005EBE02;
	static DWORD WingCheckIndexAddress2 = 0x005EBE0A;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex26() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00540FDB;
	static DWORD WingCheckIndexAddress2 = 0x00540FCE;

	__asm
	{
		Cmp Dx,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Dx
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex27() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00540FF5;
	static DWORD WingCheckIndexAddress2 = 0x00540FEE;

	__asm
	{
		Cmp Dx,0x1807
		Jle NEXT
		Pushad
		Movsx Ecx,Dx
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex28() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00541AA8;
	static DWORD WingCheckIndexAddress2 = 0x00541AB2;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckModelIndex1() // OK
{
	static DWORD WingCheckModelIndexAddress1 = 0x005AA361;
	static DWORD WingCheckModelIndexAddress2 = 0x005AA347;

	__asm
	{
		Cmp Ax,0x1A09
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Sub Ecx,ITEM_BASE_MODEL
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckModelIndexAddress2]
		NEXT:
		Jmp [WingCheckModelIndexAddress1]
	}
}

__declspec(naked) void WingCheckModelIndex2() // OK
{
	static DWORD WingCheckModelIndexAddress1 = 0x005F9E4A;
	static DWORD WingCheckModelIndexAddress2 = 0x005F9DE7;

	__asm
	{
		Cmp Ax,0x1A09
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Sub Ecx,ITEM_BASE_MODEL
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckModelIndexAddress2]
		NEXT:
		Jmp [WingCheckModelIndexAddress1]
	}
}

__declspec(naked) void WingCheckModelIndex3() // OK
{
	static DWORD WingCheckModelIndexAddress1 = 0x005F892C;
	static DWORD WingCheckModelIndexAddress2 = 0x005F8754;

	__asm
	{
		Pushad
		Sub Ecx,ITEM_BASE_MODEL
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp [WingCheckModelIndexAddress1]
		EXIT:
		Popad
		Cmp Ecx,0x1A09
		Jmp [WingCheckModelIndexAddress2]
	}
}
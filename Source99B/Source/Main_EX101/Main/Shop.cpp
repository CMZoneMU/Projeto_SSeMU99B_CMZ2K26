#include "stdafx.h"
#include "Shop.h"
#include "CustomJewel.h"
#include "ItemStack.h"
#include "ItemValue.h"
#include "Offset.h"
#include "Util.h"

void InitShop() // OK
{
	SetCompleteHook(0xE8,0x005A242A,&GetItemValue);

	SetCompleteHook(0xE8,0x005A24FB,&GetItemValue);

	SetCompleteHook(0xE8,0x005A2542,&GetItemValue);

	SetCompleteHook(0xE9,0x005A12F0,&GetItemDurability);
}

DWORD GetItemValue(DWORD item,int type) // OK
{
	WORD ItemIndex = *(WORD*)(item);

	DWORD ItemLevel = *(DWORD*)(item + 4);

	BYTE Durability = *(BYTE*)(item + 26);

	BYTE NewOption = *(BYTE*)(item + 27);

	if(gCustomJewel.CheckCustomJewelByItem(ItemIndex)!=0)
	{
		int value = gCustomJewel.GetCustomJewelSalePrice(ItemIndex);
		
		return ((type==0)?value:(value/3));
	}

	for(int n=0;n<MAX_ITEM_VALUE_INFO;n++)
	{
		ITEM_VALUE_INFO* lpInfo = gItemValue.GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->ItemIndex == ItemIndex)
		{
			if(lpInfo->Level == -1 || lpInfo->Level == ((ItemLevel/8) & 15))
			{
				if(lpInfo->Grade == -1 || lpInfo->Grade == (NewOption & 63))
				{
					int value = 0;

					if(gItemStack.GetItemMaxStack(lpInfo->ItemIndex,lpInfo->Level) == 0 || lpInfo->ItemIndex == GET_ITEM(4,7) || lpInfo->ItemIndex == GET_ITEM(4,15))
					{
						value = lpInfo->Value;
					}
					else
					{
						value = (int)(lpInfo->Value * Durability);
					}

					value = ((type==0)?value:(value/3));

					value = ((value>=100)?((value/10)*10):value);

					value = ((value>=1000)?((value/100)*100):value);

					return value;
				}
			}
		}
	}

	return ((int(*)(DWORD,int))0x00541BE0)(item,type);
}

WORD GetItemDurability(DWORD item,DWORD info,int level) // OK
{
	WORD ItemIndex = *(WORD*)(item);

	BYTE ItemSlot = *(BYTE*)(item + 8);

	BYTE NewOption = *(BYTE*)(item + 27);

	BYTE SetOption = *(BYTE*)(item + 28);

	BYTE Durability = *(BYTE*)(info + 43);

	if(ItemIndex == GET_ITEM(14,21) || ItemIndex == GET_ITEM(14,29)) // Rena, Symbol of Kundun
	{
		return 1;
	}

	if(ItemIndex == GET_ITEM(13,18) || ItemIndex == GET_ITEM(13,29) || ItemIndex == GET_ITEM(14,19)) // Invisibility Cloak, Armor of Guardsman, Devil's Invitation
	{
		return 1;
	}

	int dur = 0;

	if(level >= 5)
	{
		if(level == 10)
		{
			dur = Durability+((level*2)-3);
		}
		else if(level == 11)
		{
			dur = Durability+((level*2)-1);
		}
		else if(level == 12)
		{
			dur = Durability+((level*2)+2);
		}
		else if(level == 13)
		{
			dur = Durability+((level*2)+6);
		}
		else if(level == 14)
		{
			dur = Durability+((level*2)+11);
		}
		else if(level == 15)
		{
			dur = Durability+((level*2)+17);
		}
		else
		{
			dur = Durability+((level*2)-4);
		}
	}
	else
	{
		dur = Durability+level;
	}

	if(ItemIndex != GET_ITEM(0,19) && ItemIndex != GET_ITEM(2,13) && ItemIndex != GET_ITEM(4,18) && ItemIndex != GET_ITEM(5,10) && ItemSlot != 7) // Sword of Archangel,Scepter of Archangel,Crossbow of Archangel,Staff of Archangel
	{
		if((SetOption % 4) != 0) // Ancient
		{
			dur += 20;
		}
		else if((NewOption & 63) != 0) // Excellent
		{
			dur += 15;
		}
	}

	return ((dur>255)?255:dur);
}
#include "stdafx.h"
#include "PcPoint.h"
#include "Item.h"
#include "Util.h"

PC_POINT_INFO gPcPointPrice[MAX_ITEM_PRICE];

void InitPcPoint() // OK
{
	SetCompleteHook(0xE8,0x005863DA,&GetPricePcPoint);
}

int GetPricePcPoint(DWORD address)
{
	for(int n=0;n<MAX_ITEM_PRICE;n++)
	{
		if(gPcPointPrice[n].ItemIndex != -1)
		{
			if(gPcPointPrice[n].ItemIndex != *(WORD*)(address+0x00))
			{
				continue;
			}

			if(gPcPointPrice[n].ItemLevel != GET_ITEM_OPT_LEVEL(*(DWORD*)(address+0x02)))
			{
				continue;
			}

			if(gPcPointPrice[n].ItemDur != *(BYTE*)(address+0x16))
			{
				continue;
			}

			if(gPcPointPrice[n].ItemNewOption != GET_ITEM_OPT_EXC(*(BYTE*)(address+0x17)))
			{
				continue;
			}

			return gPcPointPrice[n].ItemPrice;
		}
	}

	return 0;
}

void ClearPriceList() // OK
{
	for(int n=0;n<MAX_ITEM_PRICE;n++)
	{
		gPcPointPrice[n].ItemIndex=-1;
		gPcPointPrice[n].ItemLevel=0;
		gPcPointPrice[n].ItemDur=0;
		gPcPointPrice[n].ItemNewOption=0;
		gPcPointPrice[n].ItemPrice=0;
	}
}

void InsertPrice(DWORD index,DWORD level,DWORD dur,DWORD exc,DWORD price) // OK
{
	for(int n=0;n<MAX_ITEM_PRICE;n++)
	{
		if(gPcPointPrice[n].ItemIndex == -1)
		{
			gPcPointPrice[n].ItemIndex=index;
			gPcPointPrice[n].ItemLevel=level;
			gPcPointPrice[n].ItemDur=dur;
			gPcPointPrice[n].ItemNewOption=exc;
			gPcPointPrice[n].ItemPrice=price;
			return;
		}
	}
}
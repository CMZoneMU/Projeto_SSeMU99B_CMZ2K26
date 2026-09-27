#pragma once

#define MAX_ITEM_PRICE 120

struct PC_POINT_INFO
{
	DWORD ItemIndex;
	DWORD ItemLevel;
	DWORD ItemDur;
	DWORD ItemNewOption;
	DWORD ItemPrice;
};

void InitPcPoint();
int GetPricePcPoint(DWORD address);
void ClearPriceList();
void InsertPrice(DWORD index,DWORD level,DWORD dur,DWORD exc,DWORD price);

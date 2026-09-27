#pragma once

#define ITEM_BASE_MODEL 1254
#define MAX_ITEM_TYPE 512

#define GET_ITEM(x,y) (((x)*MAX_ITEM_TYPE)+(y))
#define GET_ITEM_MODEL(x,y) ((((x)*MAX_ITEM_TYPE)+(y))+ITEM_BASE_MODEL)
#define GET_ITEM_OPT_LEVEL(x) ((x>>3)&0xF)
#define GET_ITEM_OPT_EXC(x) (x-(x&0x40))

void InitItem();
void InitJewel();
void InitWing();
void ItemModelLoad();
void ItemTextureLoad();
void LoadItemModel(int index,char* folder,char* name);
void LoadItemTexture(int index,char* folder);
void GetItemColor(DWORD a,DWORD b,DWORD c,DWORD d,DWORD e);
void GetItemEffect(DWORD a,int b,float* c,float d,int e,int f,int g,int h,int i);
BOOL CheckSocketItem(DWORD address);
void ItemSocketName1();
void ItemSocketName2();
void ItemExcellentSocket();
void JewelSetSalePrice();
void JewelCheckApplyItem();
void JewelCheckIndex1();
void JewelCheckIndex2();
void JewelCheckIndex3();
void JewelCheckModelIndex1();
void WingMakePreviewCharSet();
void WingDisableLevelGlow();
void WingSetIncDamage();
void WingSetDecDamage();
void WingSetOption();
void WingSetModelType();
void WingCheckIndex1();
void WingCheckModelIndex1();

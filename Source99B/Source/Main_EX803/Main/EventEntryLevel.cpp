#include "stdafx.h"
#include "EventEntryLevel.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"

void InitEventEntryLevel() // OK
{
	for(int n=0;n < 7;n++)
	{
		SetDword(0x00807C1A+(0x1A*n),gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon[n][0]);
		SetDword(0x00807C27+(0x1A*n),gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon[n][1]);
		SetDword(0x00807CE4+(0x1A*n),gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial[n][0]);
		SetDword(0x00807CF1+(0x1A*n),gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial[n][1]);
	}

	for(int n=0;n < 6;n++)
	{
		SetDword(0x0080B1AD+(0x1A*n),gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon[n][0]);
		SetDword(0x0080B1BA+(0x1A*n),gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon[n][1]);
		SetDword(0x0080B25D+(0x1A*n),gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial[n][0]);
		SetDword(0x0080B26A+(0x1A*n),gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial[n][1]);
	}

	MemoryCpy(0x0101D030,gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon));

	MemoryCpy(0x0101D060,gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial));

	MemoryCpy(0x01023948,gProtect.m_MainInfo.m_KalimaEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelCommon));

	MemoryCpy(0x01023980,gProtect.m_MainInfo.m_KalimaEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelSpecial));

	MemoryCpy(0x0101E184,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin,sizeof(gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin));

	MemoryCpy(0x0101E198,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax,sizeof(gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax));

	SetDword(0x008A69AA,0x270F); // Chaos Castle MaxLevel

	SetDword(0x007CFC5B,0x270F); // Kalima MaxLevel
}
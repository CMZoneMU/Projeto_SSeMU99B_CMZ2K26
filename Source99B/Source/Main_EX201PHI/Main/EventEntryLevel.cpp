#include "stdafx.h"
#include "EventEntryLevel.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"

void InitEventEntryLevel() // OK
{
	MemoryCpy(0x00783640,gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon));

	MemoryCpy(0x00783678,gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial));

	MemoryCpy(0x007835E0,gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon));

	MemoryCpy(0x00783610,gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial));

	MemoryCpy(0x007836B0,gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon));

	MemoryCpy(0x007836E0,gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial));

	MemoryCpy(0x00781BEC,gProtect.m_MainInfo.m_KalimaEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelCommon));

	MemoryCpy(0x00781C20,gProtect.m_MainInfo.m_KalimaEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelSpecial));

	SetDword(0x00602015,0x270F); // Chaos Castle MaxLevel

	SetDword(0x0044DD93,0x270F); // Kalima MaxLevel
}
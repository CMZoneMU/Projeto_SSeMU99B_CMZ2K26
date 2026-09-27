#include "stdafx.h"
#include "EventEntryLevel.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"

void InitEventEntryLevel() // OK
{
	MemoryCpy(0x006A94D0,gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon));

	MemoryCpy(0x006A9508,gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial));

	MemoryCpy(0x006A9470,gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon));

	MemoryCpy(0x006A94A0,gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial));

	MemoryCpy(0x006A9540,gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon));

	MemoryCpy(0x006A9570,gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial));

	MemoryCpy(0x006A7ACC,gProtect.m_MainInfo.m_KalimaEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelCommon));

	MemoryCpy(0x006A7B04,gProtect.m_MainInfo.m_KalimaEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelSpecial));

	SetDword(0x005A5E63,0x270F); // Chaos Castle MaxLevel

	SetDword(0x00433148,0x270F); // Kalima MaxLevel
}
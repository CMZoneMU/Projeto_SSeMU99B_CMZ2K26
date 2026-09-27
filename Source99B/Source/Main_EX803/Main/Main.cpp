#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "Camera.h"
#include "CCRC32.H"
#include "ChaosBox.h"
#include "Common.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomWing.h"
#include "EventEntryLevel.h"
#include "Fog.h"
#include "Font.h"
#include "HackCheck.h"
#include "Item.h"
#include "Lua.h"
#include "LuaLoader.h"
#include "Map.h"
#include "MiniMap.h"
#include "Monster.h"
#include "Offset.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "Shop.h"
#include "TrayMode.h"
#include "Util.h"
//ZUMBA
#include "Zumba\\Stack.h"
#include "Zumba\\ProtectionWarn.h"

DWORD state;
HINSTANCE hins;
HHOOK HookKB,HookMS;
KERNELGETSTARTUPINFO HookGetStartupInfo;
static DWORD ReloadScript = 0;

static const char* LogPath1 = "Logs\\stack_%s.txt";
static const char* LogPath2 = "Logs\\crash_%04d%02d%02d_%02d%02d.dmp";
static const char* LogPath3 = "Logs\\stack_%04d%02d%02d_%02d%02d.txt";
static const char* LogPath4 = "Logs\\CrashLog.txt";
static const char* LogPath5 = "Logs\\CrashLog_%d.txt";
static const char* LogPath6 = "Logs\\Error.log";
static const char* LogPath7 = "Logs\\Error_%d.log";

LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam) // OK
{
	if(nCode == HC_ACTION)
	{
		if(((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0 && GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			#if(LUA_SCRIPT == 1)
			
			if(wParam == VK_PAUSE)
			{
				if((++ReloadScript) >= 10)
				{
					ReloadScript = 0;

					gLuaLoader.Load("Script\\Main.lua");

					pDrawMessage("Reload Scripts",1);
				}
			}

			#endif

			if(gProtect.m_MainInfo.KeyCodeCamera3DSwitch != 0 && wParam == gProtect.m_MainInfo.KeyCodeCamera3DSwitch)
			{
				gCamera.Toggle();
			}
			else if(gProtect.m_MainInfo.KeyCodeCamera3DRestore != 0 && wParam == gProtect.m_MainInfo.KeyCodeCamera3DRestore)
			{
				gCamera.Restore();
			}
			else if(gProtect.m_MainInfo.KeyCodeTrayModeSwitch != 0 && wParam == gProtect.m_MainInfo.KeyCodeTrayModeSwitch)
			{
				gTrayMode.Toggle();
			}

			gLuaLoader.KeyboardEvent(wParam);
		}
	}

	return CallNextHookEx(HookKB,nCode,wParam,lParam);
}

LRESULT CALLBACK MouseProc(int nCode,WPARAM wParam,LPARAM lParam) // OK
{
	if(nCode == HC_ACTION)
	{
		MOUSEHOOKSTRUCTEX* HookStruct =(MOUSEHOOKSTRUCTEX*)lParam;

		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			switch(wParam)
			{
				case WM_MOUSEMOVE:
					gCamera.Move(HookStruct);
					break;
				case WM_MBUTTONDOWN:
					gCamera.SetIsMove(1);
					gCamera.SetCursorX(HookStruct->pt.x);
					gCamera.SetCursorY(HookStruct->pt.y);
					break;
				case WM_MBUTTONUP:
					gCamera.SetIsMove(0);
					break;
				case WM_MOUSEWHEEL:
					gCamera.Zoom(HookStruct);
					break;
			}
		}
	}

	return CallNextHookEx(HookMS,nCode,wParam,lParam);
}

SHORT WINAPI KeysProc(int nCode) // OK
{
	if(GetForegroundWindow() != *(HWND*)(MAIN_WINDOW))
	{
		return 0;
	}

	return GetAsyncKeyState(nCode);
}

HICON WINAPI IconProc(HINSTANCE hInstance,LPCSTR lpIconName) // OK
{
	FILE* file;

	if(fopen_s(&file,".\\main.ico","r") != 0)
	{
		gTrayMode.m_TrayIcon = (HICON)LoadImage(hins,MAKEINTRESOURCE(IDI_CLIENT),IMAGE_ICON,GetSystemMetrics(SM_CXICON),GetSystemMetrics(SM_CYICON),LR_DEFAULTCOLOR);
	}
	else
	{
		fclose(file);
		gTrayMode.m_TrayIcon = (HICON)LoadImage(hins,".\\main.ico",IMAGE_ICON,GetSystemMetrics(SM_CXICON),GetSystemMetrics(SM_CYICON),LR_LOADFROMFILE | LR_DEFAULTCOLOR);
	}

	return gTrayMode.m_TrayIcon;
}

void WINAPI ReduceConsumeProc() // OK
{
	while(true)
	{
		Sleep(5000);
		SetProcessWorkingSetSize(GetCurrentProcess(),0xFFFFFFFF,0xFFFFFFFF);
		SetThreadPriority(GetCurrentProcess(),THREAD_PRIORITY_LOWEST);
	}
}

void EntryProc() // OK
{
	if(gProtect.ReadMainFile("ServerInfo.sse") != 0)
	{
		SetByte(0x004D9556,0xE9); // Crack (GameGuard)
		SetByte(0x004D9557,0x8B); // Crack (GameGuard)
		SetByte(0x004D9558,0x00); // Crack (GameGuard)
		SetByte(0x004D9559,0x00); // Crack (GameGuard)
		SetByte(0x004D955A,0x00); // Crack (GameGuard)
		SetByte(0x004D9176,0xEB); // Crack (ResourceGuard)
		SetByte(0x004D9513,0x75); // Crack (ResourceGuard)
		SetByte(0x0043E510,0x50); // Login Screen
		SetByte(0x0043E519,0x50); // Login Screen
		SetByte(0x0043E521,0x18); // Login Screen
		SetByte(0x0043DFD9,0x00); // Login Screen
		SetByte(0x0043E098,0xEB); // Login Screen
		SetByte(0x0043EC4B,0xB0); // Web Check
		SetByte(0x0043EC4C,0x01); // Web Check
		SetByte(0x0043EC4D,0x90); // Web Check
		SetByte(0x009CDF5A,0x07); // Jewel of Life
		SetByte(0x0052AB21,0xEB); // Ctrl Fix
		SetByte(0x009D20DF,0x00); // Move Vulcanus
		SetByte(0x0118EF48,(gProtect.m_MainInfo.ClientVersion[0]+1)); // Version
		SetByte(0x0118EF49,(gProtect.m_MainInfo.ClientVersion[2]+2)); // Version
		SetByte(0x0118EF4A,(gProtect.m_MainInfo.ClientVersion[3]+3)); // Version
		SetByte(0x0118EF4B,(gProtect.m_MainInfo.ClientVersion[5]+4)); // Version
		SetByte(0x0118EF4C,(gProtect.m_MainInfo.ClientVersion[6]+5)); // Version
		SetWord(0x0118D31C,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
		SetDword(0x004D7FBF,(DWORD)gProtect.m_MainInfo.WindowName);
		SetDword(0x004E0F40,(DWORD)gProtect.m_MainInfo.ScreenShotPath);
		SetDword(0x00FFC82C,(DWORD)KeysProc);
		SetDword(0x00FFC858,(DWORD)IconProc);
		SetDword(0x009F3CDB,(DWORD)LogPath1);
		SetDword(0x009F3D25,(DWORD)LogPath2);
		SetDword(0x009F3D59,(DWORD)LogPath3);
		SetDword(0x009F6B95,(DWORD)LogPath4);
		SetDword(0x009F6BE2,(DWORD)LogPath5);
		SetDword(0x009F1668,(DWORD)LogPath6);
		SetDword(0x009F1758,(DWORD)LogPath7);

		MemorySet(0x005528B6,0x90,0x3D); // Remove Reflect Effect

		MemorySet(0x006CCCAA,0x90,0x02); // Remove Packet Twist

		MemorySet(0x0A6FBFD9,0x90,0x03); // Remove Packet Twist

		MemorySet(0x0A702AFA,0x90,0x03); // Remove Packet Twist

		MemoryCpy(0x0118DB1A,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddres

		MemoryCpy(0x0118EF50,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

		SetCompleteHook(0xFF,0x0065E94C,&ProtocolCoreEx);

		gCustomEffect.Load(gProtect.m_MainInfo.CustomEffectInfo);

		gCustomFog.Load(gProtect.m_MainInfo.CustomFogInfo);

		gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

		gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

		gCustomMap.Load(gProtect.m_MainInfo.CustomMapInfo);

		gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsterInfo);

		gCustomMonsterSkin.Load(gProtect.m_MainInfo.CustomMonsterSkinInfo);

		gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

		gItemStack.Load(gProtect.m_MainInfo.ItemStackInfo);

		gItemValue.Load(gProtect.m_MainInfo.ItemValueInfo);

		gLuaLoader.Load("Script\\Main.lua");

		InitChaosBox();

		InitCommon();

		InitEventEntryLevel();

		InitFog();

		InitFont();

		InitHackCheck();

		InitItem();

		InitJewel();

		InitLua();

		InitMap();

		InitMemoryProtection();

		//InitMiniMap();

		InitMonster();

		InitPrintPlayer();

		InitReconnect();

		InitResolution();

		InitShop();

		InitWing();

		gProtect.CheckLauncher();

		gProtect.CheckInstance();

		gProtect.CheckClientFile();

		gProtect.CheckPluginFile();

		HookKB = SetWindowsHookEx(WH_KEYBOARD,KeyboardProc,hins,GetCurrentThreadId());

		HookMS = SetWindowsHookEx(WH_MOUSE,MouseProc,hins,GetCurrentThreadId());

		CreateThread(0,0,(LPTHREAD_START_ROUTINE)ReduceConsumeProc,0,0,0);

		#if(DEBUG_CONSOLE == 1)

		if(GetPrivateProfileInt("Debug","Debug",0,".\\Config.ini") != 0)
		{
			if(AllocConsole() == 0)
			{
				ErrorMessageBox("Could not open AllocConsole()");
				return;
			}

			SetConsoleTitleA("SSeMU || Debugger");

			DeleteMenu(GetSystemMenu(GetConsoleWindow(),0),SC_CLOSE,MF_BYCOMMAND);
		}

		#endif

		CreateDirectory("Logs",0);

		StartStackLogging();

		ProtectionWarnStart();
	}
	else
	{
		ErrorMessageBox("Could not load ServerInfo.sse!");
		ExitProcess(0);
	}
}

void WINAPI MyGetStartupInfo(LPSTARTUPINFO lpStartupInfo) // OK
{
	if((state++) == 0)
	{
		EntryProc();
	}

	HookGetStartupInfo(lpStartupInfo);
}

void InitEntryProc() // OK
{
	state = 0;

	HookGetStartupInfo = (KERNELGETSTARTUPINFO)GetProcAddress(GetModuleHandle("Kernel32.dll"),"GetStartupInfoA");

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)HookGetStartupInfo,MyGetStartupInfo);
	DetourTransactionCommit();
}

BOOL APIENTRY DllMain(HANDLE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hins = (HINSTANCE)hModule;
			InitEntryProc();
			break;
	}

	return 1;
}

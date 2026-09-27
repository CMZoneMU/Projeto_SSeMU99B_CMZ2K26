// TrayMode.cpp: implementation of the CTrayMode class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"
#include "Offset.h"
#include "Protect.h"
#include "Reconnect.h"
#include "TrayMode.h"
#include "Util.h"

CTrayMode gTrayMode;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CTrayMode::Init() // OK
{
	SetDword(0x004B36EB,(DWORD)&TrayModeWndProc);
}

void CTrayMode::Toggle() // OK
{
	if(IsWindowVisible(*(HWND*)(MAIN_WINDOW)) == 0)
	{
		ShowWindow(*(HWND*)(MAIN_WINDOW),SW_SHOW);

		this->ShowNotify(0);
	}
	else
	{
		ShowWindow(*(HWND*)(MAIN_WINDOW),SW_HIDE);

		this->ShowNotify(1);
	}
}

void CTrayMode::ShowNotify(bool mode) // OK
{
	NOTIFYICONDATA nid;

	memset(&nid,0,sizeof(nid));

	nid.cbSize = sizeof(NOTIFYICONDATA);

	nid.hWnd = *(HWND*)(MAIN_WINDOW);

	nid.uID = WM_TRAY_MODE_ICON;

	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;

	nid.uCallbackMessage = WM_TRAY_MODE_MESSAGE;

	nid.hIcon = this->m_TrayIcon;

	if(*(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		STRUCT_DECRYPT

		wsprintf(nid.szTip,"SSeMU Client (%s)",(char*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x00));

		STRUCT_ENCRYPT
	}
	else
	{
		wsprintf(nid.szTip,"SSeMU Client");
	}

	Shell_NotifyIcon(((mode==0)?NIM_DELETE:NIM_ADD),&nid);
}

LRESULT CALLBACK CTrayMode::TrayModeWndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) // OK
{
	switch(message)
	{
		case WM_NCACTIVATE:
			return 0;
		break;
		case WM_TRAY_MODE_MESSAGE:
			switch(lParam)
			{
				case WM_LBUTTONDBLCLK:
					gTrayMode.Toggle();
					break;
				default:
					break;
			}
		default:
			break;
	}

	return CallWindowProc((WNDPROC)(0x004A9BD0),hWnd,message,wParam,lParam);
}
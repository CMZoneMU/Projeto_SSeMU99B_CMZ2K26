// LuaLoader.h: interface for the CLuaLoader class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "CriticalSection.h"

class CLuaLoader
{
public:
	CLuaLoader();
	virtual ~CLuaLoader();
	void Load(char* path);
	void MainLoader();
	void MainProcThread();
	void KeyboardEvent(int index);
private:
	#if(LUA_SCRIPT == 1)
	lua_State* m_luaState;
	#endif
	CCriticalSection m_critical;
};

extern CLuaLoader gLuaLoader;
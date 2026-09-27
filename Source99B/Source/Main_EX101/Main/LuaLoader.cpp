// LuaLoader.cpp: implementation of the CLuaLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LuaLoader.h"
#include "Lua.h"
#include "CriticalSection.h"
#include "Util.h"

CLuaLoader gLuaLoader;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLuaLoader::CLuaLoader() // OK
{

}

CLuaLoader::~CLuaLoader() // OK
{
	
}

void CLuaLoader::Load(char* path) // OK
{
	#if(LUA_SCRIPT == 1)

	this->m_critical.lock();

	HANDLE file = CreateFile(path,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

	if(file == INVALID_HANDLE_VALUE)
	{
		return;
	}

	this->m_luaState = 0;

	lua_State* lua = luaL_newstate();

	luaL_openlibs(lua);
	lua_pushcclosure(lua,LuaRequire,0);
	lua_setglobal(lua,"require");
	lua_gc(lua,LUA_GCCOLLECT,0);

	LuaFunction(lua);

	if(luaL_loadfile(lua,path) != 0)
    {
		Console(1,"Could not load '%s'. %s",path,lua_tostring(lua,-1));
		CloseHandle(file);
		this->m_critical.unlock();
        return;
    }

	if(lua_pcall(lua,0,0,0) != 0)
    {
		Console(1,"Error in Lua-file. %s",lua_tostring(lua,-1));
		CloseHandle(file);
		this->m_critical.unlock();
        return;
    }

	this->m_luaState = lua;

	CloseHandle(file);

	this->m_critical.unlock();

	#endif
}

void CLuaLoader::MainLoader() // OK
{
	#if(LUA_SCRIPT == 1)

	this->m_critical.lock();

	if(this->m_luaState == 0)
	{
		this->m_critical.unlock();
		return;
	}

	lua_getglobal(this->m_luaState,"MainLoader");

	if(lua_pcall(this->m_luaState,0,0,0) != 0)
	{
		Console(1,"%s",lua_tostring(this->m_luaState,-1));
		this->m_critical.unlock();
		return;
	}

	this->m_critical.unlock();

	#endif
}

void CLuaLoader::MainProcThread() // OK
{
	#if(LUA_SCRIPT == 1)

	this->m_critical.lock();

	if(this->m_luaState == 0)
	{
		this->m_critical.unlock();
		return;
	}

	lua_getglobal(this->m_luaState,"MainProcThread");

	if(lua_pcall(this->m_luaState,0,0,0) != 0)
	{
		Console(1,"%s",lua_tostring(this->m_luaState,-1));
		this->m_critical.unlock();
		return;
	}

	this->m_critical.unlock();

	#endif
}

void CLuaLoader::KeyboardEvent(int index) // OK
{
	#if(LUA_SCRIPT == 1)

	this->m_critical.lock();

	if(this->m_luaState == 0)
	{
		this->m_critical.unlock();
		return;
	}

	lua_getglobal(this->m_luaState,"KeyboardEvent");

	lua_pushinteger(this->m_luaState,index);

	if(lua_pcall(this->m_luaState,1,0,0) != 0)
	{
		Console(1,"%s",lua_tostring(this->m_luaState,-1));
		this->m_critical.unlock();
		return;
	}

	this->m_critical.unlock();

	#endif
}
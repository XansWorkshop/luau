#pragma once

#include "lstate.h"

LUALIB_API void xan_getLuauConfig(int* maxUserdataTags, int* maxLightUserdataTags, int* vectorComponentCount, int* isDoublePrecision, int* idSize)
{
    if (maxUserdataTags)
    {
        *maxUserdataTags = LUA_UTAG_LIMIT;
    }
    if (maxLightUserdataTags)
    {
        *maxLightUserdataTags = LUA_LUTAG_LIMIT;
    }
    if (vectorComponentCount)
    {
        *vectorComponentCount = LUA_VECTOR_SIZE;
    }
    if (isDoublePrecision)
    {
        *isDoublePrecision = LUA_VECTOR_DOUBLE == 1;
    }
    if (idSize)
    {
        *idSize = LUA_IDSIZE;
    }
}

LUALIB_API int xan_isRunningTopLevelFunction(lua_State* L)
{
    return L->ci == L->base_ci;
}

LUALIB_API void* xan_getLocal(lua_State* L, int localNumber)
{
// #define pcRel(pc, p) ((pc) && (pc) != (p)->code ? cast_to(int, (pc) - (p)->code) - 1 : 0)
// ^ ldebug.h
    CallInfo* ci = L->ci;
    Proto* p = ci->p;
    int pc = pcRel(ci->savedpc, p);
    for (int i = 0; i < p->sizelocvars; i++)
    {
        if (pc >= p->locvars[i].startpc && pc < p->locvars[i].endpc)
        { // is variable active?
            localNumber--;
            if (localNumber == 0)
                return &p->locvars[i];
        }
    }

    return NULL; // not found
}

LUALIB_API void* xan_findLocal(lua_State* L, int localReg)
{
    CallInfo* ci = L->ci;
    Proto* p = ci->p;
    int pc = pcRel(ci->savedpc, p);
    for (int i = 0; i < p->sizelocvars; i++)
        if (localReg == p->locvars[i].reg && pc >= p->locvars[i].startpc && pc < p->locvars[i].endpc)
            return &p->locvars[i];

    return NULL; // not found
}

void xan_getFunctionName(lua_State* L, int idx, char* result, signed int length); // In lapi.cpp

LUALIB_API int xan_getLineNumber(lua_State* L, int level)
{
    lua_Debug ar;
    if (lua_getinfo(L, level, "l", &ar) && ar.currentline > 0)
    {
        return ar.currentline;
    }
    return -1;
}

/*
#include "xanslua.h"
#include "lapi.h"
#include "ldebug.h"


LUALIB_API void xan_setOutputHandler(xan_WriteStringReceiver mtd)
{
    writeStringReceiver = mtd;
}

LUALIB_API void xan_getLuauConfig(int* maxUserdataTags, int* maxLightUserdataTags, int* vectorComponentCount, int* isDoublePrecision)
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
}

LUALIB_API const char* xan_getFunctionName(lua_State* L, int idx)
{
    StkId o = index2addr(L, idx);
    switch (ttype(o))
    {
    case LUA_TFUNCTION:
        return getfuncname(gco2cl(gcvalue(o)));
    default:
        return nullptr;
    }
}
*/

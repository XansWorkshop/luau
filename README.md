Luau ![CI](https://github.com/luau-lang/luau/actions/workflows/build.yml/badge.svg) [![codecov](https://codecov.io/gh/luau-lang/luau/branch/master/graph/badge.svg)](https://codecov.io/gh/luau-lang/luau)
====

This is a fork of the [Luau](https://github.com/luau-lang/luau) language by Xan's Workshop.

It is roughly the same as the base library, but contains tools and extensions meant for *Godot: Conservatory Edition* that make embedding certain features, especially those relating to C#, easier.

# Changes

## Supplemental API:

* `void xan_getLuauConfig(int* maxUserdataTags, int* maxLightUserdataTags, int* vectorComponentCount, int* isDoublePrecision, int* idSize)`
	* Returns various settings of Luau for analysis in C#.
* `void xan_getFunctionName(lua_State* L, int idx, char* result, signed int length);`
	* Stores the name of the function on the stack at index `idx` into `result`.
* `int xan_lessequal(lua_State* L, int idx1, int idx2)`
	* Addition to `lua_lessthan` to invoke `lessequal` instead.

## Behavioral Changes:

* New metatable field `__xan_metatable_hidden`. When defined (non-nil), `getmetatable` returns `nil` even if there is a metatable.
	* This is a stronger alternative to hiding the metatable by setting it to `false`, and is used to emulate class-like behavior from C# without having to declare a proper Luau class/object.
* Arithmetic operators are now defined on `integer` types.
	* To prevent accidental type conversion, operators are *not* defined between `number` and `integer`!
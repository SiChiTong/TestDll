#pragma once
#include <string>

#ifdef __ADD_DLL
#define _ADD_API __declspec(dllexport)
#else
#define _ADD_API __declspec(dllimport)
#endif

_ADD_API int add(const int, const int);
//_ADD_API std::string add(const std::string&, const std::string&);
_ADD_API size_t sum(const std::string&, const std::string&);
_ADD_API void add2(const std::string&, const std::string&, std::string& res);

#undef  _ADD_API
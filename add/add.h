#pragma once
#include <string>
#include <memory>
#include <vector>

#ifdef __ADD_DLL
#define _ADD_API __declspec(dllexport)
#else
#define _ADD_API __declspec(dllimport)
#endif

// ��Ϊ����
_ADD_API void helloValue(std::string name);                 // ��
_ADD_API void helloRef(const std::string& name);            // ��
_ADD_API void helloPointer(const std::string* const name);  // �� ���㹦�ܣ��Ƚϳ����
// ��Ϊ���
_ADD_API std::string  returnValue(void);                    // ��
_ADD_API std::string& returnRef(void);                      // �� ���ܲ����ƣ���Ҫ��֤����Դ��Ч
_ADD_API bool returnPointer(std::string* const out);              // ��
_ADD_API bool returnSmartPtr(std::shared_ptr<std::string> out);              // ��
_ADD_API bool returnSmartPtr2(std::shared_ptr<std::string>& out);            // ��
_ADD_API bool returnSmartPtr3(const std::shared_ptr<std::string>& out);      // ��

_ADD_API bool fillv(std::shared_ptr<std::vector<std::string>>& out);      // ��
_ADD_API std::shared_ptr<std::vector<std::string>> returnv();      // ��

#undef  _ADD_API
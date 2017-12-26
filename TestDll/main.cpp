#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
#include <string>
// 1. �ȿ��ǲ�ʹ�� def �ļ������ַ�ʽò���Ǻ���ֵ�
// 2. ��ʱҲ���������أ�c �� C++ �ڱ����ڼ�����������
// 3. �����ĵ��÷�ʽ���__cdecl / __stdcall / _fastcall ������ʽ�����η���Ҳ����ͬ

//typedef  int(_cdecl *ADD)(const int, const int);
typedef  int(*ADD)(const int, const int);
typedef std::string( *STRADD)(const std::string&, const std::string&);

CONST std::string _str_add_name = "?add@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABV12@0@Z";
int main(int argc, char* argv[])
{
	HINSTANCE hInstance = LoadLibrary("add.dll");
	assert(hInstance);

	STRADD stradd = (STRADD)GetProcAddress(hInstance, _str_add_name.c_str());  // ok
    //STRADD stradd = (STRADD)GetProcAddress(hInstance, MAKEINTRESOURCE(1));  // ok
	assert(stradd);
	ADD add = (ADD)GetProcAddress(hInstance, "?add@@YAHHH@Z");  // ok
	//ADD add = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(2)); //it's ok
	if (add)
		std::cout << stradd("the result of", "��add(1, 2)��:") << add(1, 2) << std::endl;

	ADD sub = (ADD)GetProcAddress(hInstance, "sub");  // ok
	//ADD sub = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(3)); //it's ok
	if (sub)
		std::cout << "the result of��sub(1, 2)��:" << sub(1, 2) << std::endl;

	FreeLibrary(hInstance);
	return 0;
}

// �ƺ��ò���ͷ�ļ�
// �������飬�� GetProcAddress() �в��Ƽ�ʹ�ú�����������ʹ�� MAKEINTRESOURCE(n)
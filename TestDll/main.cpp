#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
// 1. �ȿ��ǲ�ʹ�� def �ļ������ַ�ʽò���Ǻ���ֵ�
// 2. ��ʱҲ���������أ�c �� C++ �ڱ����ڼ�����������
// 3. �����ĵ��÷�ʽ���__cdecl / __stdcall / _fastcall ������ʽ�����η���Ҳ����ͬ

//typedef  int(_cdecl *ADD)(const int, const int);
typedef  int( *ADD)(const int, const int);

int main(int argc, char* argv[])
{
	HINSTANCE hInstance = LoadLibrary("add.dll");
	assert(hInstance);

	ADD add = (ADD)GetProcAddress(hInstance, "add"); // c �ĺ�����
	//ADD add = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(2)); //it's ok
	if (add)
		std::cout << "the result of��add(1, 2)��:" << add(1, 2) << std::endl;

	//ADD sub = (ADD)GetProcAddress(hInstance, "sub");  // ERR
	ADD sub = (ADD)GetProcAddress(hInstance, "?sub@@YAHHH@Z");  // c++ �ĺ�����
	//ADD sub = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(1)); //it's ok
	if (sub)
		std::cout << "the result of��sub(1, 2)��:" << sub(1, 2) << std::endl;

	FreeLibrary(hInstance);
	return 0;
}

// �ƺ��ò���ͷ�ļ�
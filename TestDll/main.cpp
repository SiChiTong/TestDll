#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
#include <string>
#include "../add/add.h"
// 1. �ȿ��ǲ�ʹ�� def �ļ������ַ�ʽò����ȱ�ݲų��ֵ� __declspec(dllexport/dllimport)
// 2. ��ʱҲ���������أ�c �� C++ �ڱ����ڼ�����������
// 3. �����ĵ��÷�ʽ���__cdecl / __stdcall / _fastcall ������ʽ�����η���Ҳ����ͬ

#pragma comment(lib, "../Debug/add.lib")
extern "C" __declspec(dllimport) int sub(const int a, const int b);

int main(int argc, char* argv[])
{
    //std::cout << add("the result of", "��add(1, 2)��:") << add(1, 2) << std::endl;
    std::cout << sum("the result of", "��add(1, 2)��:") << std::endl;

	std::cout << "the result of��sub(1, 2)��:" << sub(1, 2) << std::endl;
	std::cout << "the result of��add(1, 2)��:" << add(1, 2) << std::endl;

	return 0;
}

// �ƺ��ò���ͷ�ļ�
// �������飬�� GetProcAddress() �в��Ƽ�ʹ�ú�����������ʹ�� MAKEINTRESOURCE(n)
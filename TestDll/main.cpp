#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
#include <string>
// 1. �ȿ��ǲ�ʹ�� def �ļ������ַ�ʽò���Ǻ���ֵ�
// 2. ��ʱҲ���������أ�c �� C++ �ڱ����ڼ�����������
// 3. �����ĵ��÷�ʽ���__cdecl / __stdcall / _fastcall ������ʽ�����η���Ҳ����ͬ

#pragma comment(lib, "../Debug/add.lib")
extern "C" __declspec(dllimport) int sub(const int a, const int b);
__declspec(dllimport) int add(const int a, const int b);
__declspec(dllimport) std::string add(const std::string& a, const std::string& b);

int main(int argc, char* argv[])
{
	std::cout << add("the result of", "��add(1, 2)��:") << add(1, 2) << std::endl;

	std::cout << "the result of��sub(1, 2)��:" << sub(1, 2) << std::endl;
	std::cout << "the result of��add(1, 2)��:" << add(1, 2) << std::endl;

	return 0;
}

// �ƺ��ò���ͷ�ļ�
// �������飬�� GetProcAddress() �в��Ƽ�ʹ�ú�����������ʹ�� MAKEINTRESOURCE(n)
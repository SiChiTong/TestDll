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

using namespace std;
int main(int argc, char* argv[])
{
    string niel("niel");
    //helloValue(niel);   // run failed
    helloRef(niel); // ok
    {
        /*auto str = returnValue();
        cout << str << endl;*/
    }   // run failed 
        // ����ʱ __acrt_first_block == header ����
        // ���Ƴ� str ���� dll ģ����ɸ�ֵ�ģ�
    {
        auto str = returnRef();
        cout << str << endl;
    }
	return 0;
}

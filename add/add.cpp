#include <string>
#define __ADD_DLL
#include "add.h"
#include <iostream>

using namespace std;

string g_str("global value");

void helloValue(std::string name)
{
    cout << "hello world, " << name << endl;
}   // ����ʱ __acrt_first_block == header ����
    // ���Ƴ� name ���� exe ģ����ɸ�ֵ�ģ�

void helloRef(const std::string & name)
{
    cout << "hello kitty, " << name << endl;
}

std::string returnValue(void)
{
    return "value";
}

std::string & returnRef(void)
{
    return g_str;
}

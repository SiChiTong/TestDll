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

bool returnBy(std::string * out)
{
    if (out)
    {
        cout << "before " << out->size() << endl;
        cout << "before " << out->capacity() << endl;
        out->shrink_to_fit();
        out->resize(100);
        cout << "resize: " << out->size() << endl;

        *out = "niel";
        return true;
    }
    return false;
}

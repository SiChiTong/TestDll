#include <iostream>
#include "../add/add.h"
// 1. �ȿ��ǲ�ʹ�� def �ļ������ַ�ʽò����ȱ�ݲų��ֵ� __declspec(dllexport/dllimport)
// 2. ��ʱҲ���������أ�c �� C++ �ڱ����ڼ�����������
// 3. �����ĵ��÷�ʽ���__cdecl / __stdcall / _fastcall ������ʽ�����η���Ҳ����ͬ


using namespace std;
int main(int argc, char* argv[])
{
    Student niel;
    cout << "age: " << niel.age() << endl;
    {
        string liyw = "liyw";
        niel.change(liyw);  // swap �󲢲���������������
        // do something
        // swap1���ͷŶ��� liyw ʱ�����ڲ��洢�Ѿ�ָ�� dll �У�BANG
    }
    {
        auto ptr = CreateInstance2();
    }
    auto ptr = CreateInstance();
    //delete ptr;   // bang
    string cat("miao");
    //ptr->change(cat);
    ReleaseInstance(ptr);   // swap2���ͷ�dll �� m_name ʱ������洢ִ�� exe �У�BANG

    {
        Student::Date date;
        date.day();
        //date.month();   // err
    }
    return 0;
}

// �ƺ��ò���ͷ�ļ�
// �������飬�� GetProcAddress() �в��Ƽ�ʹ�ú�����������ʹ�� MAKEINTRESOURCE(n)
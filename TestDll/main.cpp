#include <iostream>
#include "../add/add.h"
// 1. �ȿ��ǲ�ʹ�� def �ļ������ַ�ʽò����ȱ�ݲų��ֵ� __declspec(dllexport/dllimport)
// 2. ��ʱҲ���������أ�c �� C++ �ڱ����ڼ�����������
// 3. �����ĵ��÷�ʽ���__cdecl / __stdcall / _fastcall ������ʽ�����η���Ҳ����ͬ


using namespace std;
int main(int argc, char* argv[])
{
    std::cout << sum("love ", " liyw") << std::endl;
    std::string res;
    res.resize(100);


    cout << "#################" << endl;
    Student niel;
    cout << "age: " << niel.age() << endl;
    {
        auto ptr = CreateInstance2();
    }
    auto ptr = CreateInstance();
    //delete ptr;   // bang
    ReleaseInstance(ptr);

    {
        Student::Date date;
        date.day();
        //date.month();   // err
    }
    return 0;
}

// �ƺ��ò���ͷ�ļ�
// �������飬�� GetProcAddress() �в��Ƽ�ʹ�ú�����������ʹ�� MAKEINTRESOURCE(n)
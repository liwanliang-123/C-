// 成员变量和成员函数分开存储
//     在C++中，类内的成员变量和成员函数分开存储。

//     只有非静态成员变量才属于类的对象上。

#include <iostream>
using namespace std;

class Person1 {
    //空对象
};

class Person2 {
//非空对象
    int a; //非静态成员变量
};

class Person3 {
//非空对象
    static int a; //静态成员变量

    void func() { //非静态成员函数也不属于某个类的对象
    }
    static void func() { //静态成员函数也不属于某个类的对象
    }
};

int Person3::a = 1;

void test01()
{
    Person1 P1;
//空对象占用 1 字节的内存空间
//C++编译器会为每一个空对象分配一个字节空间，是为了区分空对象占内存的位置
//每个空对象也应该有一个独一无二的内存地址
    cout << "P1 size : " << sizeof(P1) << endl;
}

void test02()
{
    Person2 P2; //非静态成员变量属于某一个对象
    cout << "P2 size : " << sizeof(P2) << endl;
}

void test03()
{
    Person3 P3; //静态成员变量不属于某一个对象
    cout << "P3 size : " << sizeof(P3) << endl;
}

int main()
{
    test01();
    test02();
    test03();

    return 0;
}
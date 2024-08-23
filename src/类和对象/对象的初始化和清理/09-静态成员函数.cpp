// 静态成员函数
//     所有对象共享同一个函数；
//     静态成员函数只能访问静态成员变量。

#include <iostream>
using namespace std;

class Person {
public:
    static void func()
    {
        P_a = 200; //静态成员函数可以访问静态成员变量
        //P_b = 200; //静态成员函数不可以访问非静态成员变量,因为无法区别是哪一个对象的P_b属性
        cout << "func call" << endl;
    }

    static int P_a;
    int P_b;

private: //静态成员函数也有访问权限，类外访问不到
    static void func2()
    {
        cout << "func call" << endl;
    }

};

int Person::P_a = 100;

void test01()
{
// 1、通过对象访问成员函数
    cout << "P1_A = " << Person::P_a << endl;
    Person P1;
    P1.func();

//2、通过类名访问成员函数
    Person::func();
    cout << "P1_A = " << Person::P_a << endl; //通过静态成员函数改变了

    //Person::func2();  func2 是 private 类型，类外访问不到
}

int main()
{
    test01();

    return 0;
}
// 问题：继承中同名的静态成员在子类对象上如何进行访问？

// 静态成员和非静态成员出现同名，处理方式一致：
//                                      访问子类同名成员直接访问即可；
//                                      访问父类同名成员需要加作用域。

//静态成员有两种访问方法：通过类和对象都可以

//总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象和通过类名）。

#include <iostream>

using namespace std;

class Base {
public:
    static int m_A;
    static void func();
};

void Base::func()
{
    cout << "Base static func call" << endl;
}

class Son : public Base {
public:
    static int m_A;
    static void func();
};

void Son::func()
{
    cout << "Son static func call" << endl;
}

int Base::m_A = 100;
int Son::m_A = 200;

void test01()
{
    Son son;
// 访问静态同名函数 (通过对象访问)
    cout << "通过对象访问 m_A = " << son.m_A << endl; //访问子类静态成员
    cout << "通过对象访问 m_A = " << son.Base::m_A << endl; //访问父类静态成员

// 通过类名访问
    cout << "通过类名访问 m_A = " << Son::m_A << endl;
    cout << "通过类名访问 m_A = " << Son::Base::m_A << endl;

// 访问静态成员函数(通过对象访问)
    son.func();
    son.Base::func();

// 通过类名访问
    Son::func();
    Son::Base::func();
}

int main()
{
    test01();
    return 0;
}
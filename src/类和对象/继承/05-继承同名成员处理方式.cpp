// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？

//      1、访问子类同名成员直接访问即可；
//      2、访问父类同名成员需要加作用域。


// 总结：
// 子类对象可以直接访问到子类中同名成员；
// 子类对象加作用域可以访问到父类同名成员；
// 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数。

#include <iostream>

using namespace std;

class Base {
public:
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "base func call" << endl;
    }
//函数重载
    void func(int a)
    {
        cout << "base 重载 func call" << endl;
    }
    int m_A;
};

class Son : public Base {
public:
    Son()
    {
        m_A = 20;
    }
    void func()
    {
        cout << "son func call" << endl;
    }
    int m_A;
};

void test01()
{
    Son son;
//访问同名变量
    cout << "m_A = " << son.m_A << endl;     //访问之内数据直接访问
    cout << "m_A = " << son.Base::m_A << endl; //访问父类中的变量需要加作用域

//访问同名函数
    son.func();     //访问之内数据直接访问
    son.Base::func(); //访问父类中的变量需要加作用域

//函数重载
//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数,包括重载函数
//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    //son.func(100);
    son.Base::func(20);
}

int main()
{
    test01();
    return 0;
}

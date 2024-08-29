// 子类继承父类后，当创建子类对象，也会调用父类的构造函数。

// 问题：父类和子类的构造和析构顺序是谁先谁后？

// 答：
//      base 构造函数
//      son 构造函数
//      son 析构函数
//      base 析构函数
//总结：继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反。

#include <iostream>

using namespace std;

class Base {
public:
    Base()
    {
        cout << "base 构造函数" << endl;
    }
    ~Base()
    {
        cout << "base 析构函数" << endl;
    }
};

class Son : public Base{
public:
    Son()
    {
        cout << "son 构造函数" << endl;
    }
    ~Son()
    {
        cout << "son 析构函数" << endl;
    }
};

void test01()
{
//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
    Son son;
}

int main()
{
    test01();
    return 0;
}
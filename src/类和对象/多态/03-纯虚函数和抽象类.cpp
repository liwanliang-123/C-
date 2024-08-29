// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容，因此可以将虚函数改为纯虚函数。

// 纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;
// 当类中有了纯虚函数，这个类也称为抽象类。

// 抽象类特点：
//     无法实例化对象；
//     子类必须重写抽象类中的纯虚函数，否则也属于抽象类。

#include <iostream>

using namespace std;

class Base {
public:
    virtual void func() = 0; // 虚函数变成纯虚函数，此时这个类也就变成抽象类了
};

class Son : public Base {
public:
    void func() // 子类重写父类的纯虚函数
    {
        cout << "func call" << endl;
    }
};

void test01()
{
    //Base b;  //不能这样写，因为抽象类无法实例化对象
    //Base *b = new Base; //也不能这样写,因为无法实例化对象

    //Son s; //如果子类中没有重写纯虚函数，那么子类也是一个抽象类，也不能实例化，但如果子类不重写纯虚函数那多态将没有任何意义

    Base *base = new Son;  //产生多态
    base->func(); // 调用 Son 中的 func
}

int main()
{
    test01();
    return 0;
}
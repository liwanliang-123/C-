// 类模板中成员函数和普通类中成员函数创建时机是有区别的：
//     普通类中的成员函数一开始就可以创建；
//     类模板中的成员函数在调用时才创建。

#include <iostream>

using namespace std;

class Person1 {
public:
    void showPerson1()
    {
        cout << "Call Person1" << endl;
    }
};

class Person2 {
public:
    void showPerson2()
    {
        cout << "Call Person2" << endl;
    }
};

template<class T>
class Myclass{
public:
    T obj;
//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
    void func1() { obj.showPerson1(); }
    void func2() { obj.showPerson2(); }
};

void test01()
{
    Myclass<Person1> P;
    P.func1();
    P.func2();  //这里 func2会出错
}

int main()
{
    test01();
    return 0;
}
// 初始化列表
//     作用：C++提供了初始化列表语法，用来初始化属性。

//     语法： 构造函数()：属性1(值1),属性2（值2）... {}

#include <iostream>
using namespace std;

class Person {
public:

//传统方式
    // Person(int a, int b, int c)
    // {
    //     P_a = a;
    //     P_b = b;
    //     P_c = c;
    // }

//==========================================

//初始化列表
//  Person() :P_a(1), P_b(2), P_c(3)
    Person(int a, int b, int c) :P_a(a), P_b(b), P_c(c)
    {

    }

    ~Person()
    {

    }

    int P_a;
    int P_b;
    int P_c;
};

void test01()
{
    Person P1(1,2,3);
    cout << "a = " << P1.P_a << endl;
    cout << "b = " << P1.P_b << endl;
    cout << "c = " << P1.P_c << endl;
}

void test02()
{
    // Person P1;
    Person P1(10,30,20);
    cout << "a = " << P1.P_a << endl;
    cout << "b = " << P1.P_b << endl;
    cout << "c = " << P1.P_c << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}
// 构造函数调用规则

// 默认情况下，C++编译器至少给一个类添加3个函数：
//     默认构造函数(无参，函数体为空)
//     默认析构函数(无参，函数体为空)
//     默认拷贝构造函数，对属性进行值拷贝

// 构造函数调用规则如下：
//     如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造；
//     如果用户定义拷贝构造函数，C++不会再提供其他构造函数。

#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "无参构造函数被调用" << endl;
    }

    Person(int age)
    {
        A_ge = age;
        cout << "有参构造函数被调用" << endl;
    }

    // Person(const Person &P) {    如果不写拷贝函数会使用默认拷贝构造函数，并对所有属性进行值拷贝，也就是会执行 A_ge = P.A_ge;
    //     A_ge = P.A_ge;
    //     cout << "拷贝构造函数被调用" << endl;
    // }

    ~Person() {
        cout << "析构函数被调用" << endl;
    }
    int A_ge;
};

void test01()
{
// 如果不写拷贝函数会使用默认拷贝构造函数，并对所有属性进行值拷贝
    Person P;
    P.A_ge = 20;

    Person P1(P);
    cout << "P1.age = " << P1.A_ge << endl;
}

int main()
{
    test01();
    return 0;
}

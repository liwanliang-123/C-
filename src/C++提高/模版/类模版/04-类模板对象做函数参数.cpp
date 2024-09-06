// 学习目标：类模板实例化出的对象，向函数传参的方式。

// 一共有三种传入方式：
//             1. 指定传入的类型 — 直接显示对象的数据类型；
//             2. 参数模板化 — 将对象中的参数变为模板进行传递；
//             3. 整个类模板化 — 将这个对象类型 模板化进行传递。

#include <iostream>

using namespace std;

template<class T1, class T2>
class Person {
public:

    Person(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }

    void showInfo()
    {
        cout << "name = " << this->name << endl;
        cout << "age = " << this->age << endl; 
    }

    T1 name;
    T2 age;
};

//  1、指定传入的类型 ======================
void PrintPerson1(Person<string, int> &P)
{
    P.showInfo();
}

void test01()
{
    Person<string, int> P("Tom", 128);
    PrintPerson1(P);  //将模版对象传递到函数中
}
//=======================================

// 2. 参数模板化===========================
template<class T1, class T2>
void PrintPerson2(Person<T1, T2> &P)
{
    P.showInfo();
    cout << "T1 的类型为： " << typeid(T1).name() << endl;
    cout << "T2 的类型为： " << typeid(T2).name() << endl;
}

void test02()
{
    Person<string, int> P("xiao", 100);
    PrintPerson2(P);  //将模版对象传递到函数中
}
// =======================================

// 3. 整个类模板化===========================
template<class T>
void PrintPerson3(T &P)
{
    P.showInfo();
    cout << "T 的类型为： " << typeid(T).name() << endl;
}

void test03()
{
    Person<string, int> P("liang", 1000);
    PrintPerson3(P);
}
// =======================================

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}
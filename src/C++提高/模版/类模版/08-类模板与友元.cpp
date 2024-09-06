// 学习目标：
//         掌握类模板配合友元函数的类内和类外实现。

// 全局函数类内实现 - 直接在类内声明友元即可；
// 全局函数类外实现 - 需要提前让编译器知道全局函数的存在。

#include <iostream>
#include <string>

using namespace std;

//全局函数配合友元 类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template<class T1, class T2>
class Person;

//需要先将类外实现的全局函数 printInfo2 声明在程序前面，这里还需要将 Person 进行声明
template<class T1, class T2>
void printInfo2(Person<T1, T2> &P2)
{
    cout << "name: " << P2.name << " age: " << P2.age << endl;
}

template<class T1, class T2>
class Person {
//全局函数类内实现
friend void printInfo1(Person<T1, T2> &P1)
{
    cout << "name: " << P1.name << " age: " << P1.age << endl;
}

//全局函数配合友元 类外实现
friend void printInfo2<>(Person<T1, T2> &P2);

public:
    Person(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }

private:
    T1 name;
    T2 age;
};

// template<class T1, class T2>
// void printInfo2(Person<T1, T2> &P2)
// {
//     cout << "name: " << P1.name << " age: " << P1.age << endl;
// }

void test01()
{
    Person<string, int> P("class", 120);
    printInfo1(P);  //调用类内的全局函数
}

void test02()
{
    Person<string, int> P("Jerry", 11001);
    printInfo2(P);  //调用类外的全局函数
}

int main()
{
    // test01();
    test02();
    return 0;
}
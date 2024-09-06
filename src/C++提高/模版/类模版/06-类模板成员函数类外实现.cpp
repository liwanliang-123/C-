// 总结：类模板中成员函数类外实现时，需要加上模板参数列表。

#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age);
    void showInfo();
    T1 name;
    T2 age;
};

//类外实现构造函数的初始化
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

//类外实现普通函数的初始化
template<class T1, class T2>
void Person<T1, T2>::showInfo()
{
    cout << "name = " << this->name << endl;
    cout << "age = " << this->age << endl;
}

void test01()
{
    Person<string, int> P("xiao李", 1000);
    P.showInfo();
}

int main()
{
    test01();
    return 0;
}
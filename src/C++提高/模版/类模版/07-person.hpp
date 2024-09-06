// 第二种解决办法就是将声明和实现写到同一个文件中，并更改后缀名为.hpp，如下

#include <iostream>

using namespace std;

template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age);
    void showInfo();
    T1 name;
    T2 age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showInfo()
{
    cout << "name = " << this->name << endl;
    cout << "age = " << this->age << endl;
}
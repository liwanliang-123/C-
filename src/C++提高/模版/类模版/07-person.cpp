#include "07-person.h"

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
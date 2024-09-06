#pragma

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
// C++中空指针也是可以调用成员函数的，但要注意有没有用到this指针；
// 如果用到this指针，需要加以判断，保证代码的健壮性。

#include <iostream>
using namespace std;

class Person {
public:
    void showClassName()
    {
        cout << "this is Person class" << endl; //这个可以访问
    }

    void showPersonAge()
    {
        if (this == NULL)
            return; //this == NULL 直接返回 

        cout << "age = " << m_age << endl; //报错原因是因为传入的指针为 NULL 即 this为NULL，this->m_age即 m_age 当然有问题了
    }

    int m_age;
};

void test01()
{
    Person* P1 = NULL;

    P1->showClassName(); //可以访问
    P1->showPersonAge(); //因为this为NULL，所以this->m_age肯定有问题了
}

int main()
{
    test01();

    return 0;
}
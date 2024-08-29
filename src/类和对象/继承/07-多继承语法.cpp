// C++允许一个类继承多个类。

// 语法：class 子类 ：继承方式 父类1 ， 继承方式 父类2...

// 多继承可能会引发父类中有同名成员出现，需要加作用域区分。

// 但在C++实际开发中不建议用多继承。

#include <iostream>

using namespace std;

class Base1 {
public:
    Base1()
    {
        m_A = 100;
        m_B = 150;
    }
    int m_A;
    int m_B; //和Base2中的成员重名
};

class Base2 {
public:
    Base2()
    {
        m_B = 200;
    }
    int m_B;
};

class Son : public Base1,public Base2 {
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

void test01()
{
    Son son;
    cout << "Son size = " << sizeof(Son) << endl; //Son 的大小等于 Son + Base1 + Base2

//Base1
    cout << "Son.m_A = " << son.m_A << endl;
    cout << "Son.Base1.m_B = " << son.Base1::m_B << endl;
//Base2
    // cout << "Son.m_B = " << son.m_B << endl;
    cout << "Son.Base2.m_B = " << son.Base2::m_B << endl;
//Son
    cout << "Son.m_C = " << son.m_C << endl;
    cout << "Son.m_D = " << son.m_D << endl;
}

int main()
{
    test01();
    return 0;
}
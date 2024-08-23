//加号运算符重载
//作用：实现两个自定义数据类型相加的运算

// 总结：
//      对于内置的数据类型的表达式的的运算符是不可能改变的；
//      不要滥用运算符重载。

#include <iostream>

using namespace std;

class Person {
public:
//成员函数实现 + 号运算符重载
    Person operator+(Person P)
    {
        Person temp;
        temp.m_A = this->m_A + P.m_A;
        temp.m_B = this->m_B + P.m_B;
        return temp;   
    }

    int m_A;
    int m_B;
};

//全局函数实现 + 号运算符
Person operator+(Person &P1, Person &P2)
{
    Person temp;
    temp.m_A = P1.m_A + P2.m_A;
    temp.m_B = P1.m_B + P2.m_B;
    return temp;
}

//运算符重载也可以进行函数重载
Person operator+(Person &P1, int P2)
{
    Person temp;
    temp.m_A = P1.m_A + P2;
    temp.m_B = P1.m_B + P2;
    return temp;
}

void test01()
{
    Person P1;
    P1.m_A = 1;
    P1.m_B = 2;

    Person P2;
    P2.m_A = 3;
    P2.m_B = 4;

    Person P3;

//调用成员函数
    // P3 = P1.operator+(P2);
//调用全局函数
    P3 = operator+(P1, P2);
    // P3 = P1 + P2;
    // P3 = operator+(P1, 100);
    cout << "P3.m_A = " << P3.m_A << endl;
    cout << "P3.m_B = " << P3.m_B << endl;
}

int main()
{
    test01();

    return 0;
}
//作用：可以输出自定义数据类型。

//总结：重载左移运算符配合友元可以实现输出自定义数据类型。

#include <iostream>

using namespace std;

class Person {

//为了让重载函数访问私有成员
friend ostream &operator<<(ostream &cout ,Person &P);

public:

    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

//成员函数重载 << 运算符
//一般不用成员函数实现 << 重载，因为 cout 在 左边
    // void operator<<(cout)
    // {
    // }
private:
    int m_A;
    int m_B;
};

//只能利用全局函数重载 << 运算符
//通过引用传递，是因为这个对象只有一个，不能创建一个新的对象
// void operator<<(ostream &cout ,Person &P)    //operator<<(cout ,P) 简化=> cout << P
ostream &operator<<(ostream &cout ,Person &P)    //operator<<(cout ,P) 简化=> cout << P
{
    cout << "P.m_A = " << P.m_A << "P.m_B = " << P.m_B;
    return cout; //链式编程
}

void test01()
{
    Person P(10, 20);

    //operator<<(cout, P);
    cout << P << endl; //如果函数返回 void 则不能写 << endl, 但如果返回的是 cout 则可以写 (链式调用)
    //cout << P; //直接输出 P 这个对象
}

int main()
{
    test01();

    return 0;
}
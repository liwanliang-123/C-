// 结论： 父类中的私有成员也被子类继承下去了，只是由编译器给隐藏后访问不到。

#include <iostream>

using namespace std;

class Base {
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

class Son : public Base {
public:
    int m_D;
};

void test01()
{
    cout << "size Son is " << sizeof(Son) << endl; // size = 16, 私有成员也会被继承
}

int main()
{
    test01();

    return 0;
}
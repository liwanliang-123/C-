//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作。

#include <iostream>

using namespace std;

class Person {
public:

    Person(int age, string name)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

// 重载 == 运算符
    bool operator==(Person &P)
    {
        if ((this->m_Age == P.m_Age) && (this->m_Name == P.m_Name))
            return true;
        return false;
    }

// 重载 ！= 运算符
    bool operator!=(Person &P)
    {
        if ((this->m_Age == P.m_Age) && (this->m_Name == P.m_Name))
            return false;
        return true;
    }

private:
    int m_Age;
    string m_Name;
};

void test01()
{
    Person P1(20, "小红");
    Person P2(20, "小红");

    if(P1.operator==(P2)) {
        cout << "两个类相等" << endl;
    }

    if(P1 == P2) {  //等价于 P1.operator==(P2)
        cout << "两个类相等" << endl;
    }

    if(P1 != P2) {
        cout << "两个类不相等" << endl;
    }
}

int main()
{
    test01();

    return 0;
}
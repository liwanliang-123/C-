// 继承的语法：class 子类 : 继承方式 父类

// 继承方式一共有三种：
//     公共继承
//     保护继承
//     私有继承
#include <iostream>

using namespace std;

class Base {
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

//公开继承
class Son1 : public Base {
public:
    void func()
    {
        m_A = 10; //父类中的公共权限成员在子类中可以访问
        m_B = 10; //父类中的保护权限成员在子类中可以访问
        //m_C = 10; //父类中的私有权限在子类中不可以访问
    }
};

void test01()
{
    Son1 son1;
    son1.m_A = 10; //可以访问，因为m_A也是public权限的
    //son1.m_B = 10; //不可以访问，因为m_B是保护权限，类内中可以访问，类外不可以访问
}

//保护继承
class Son2 : protected Base {
public:
    void func()
    {
        m_A = 100;  //在Base中是public 继承过来就是 protected,类内中可以访问
        m_B = 10;   //还是 protected,类内可以访问
        //m_C = 20;   //私有权限还是不可以访问
    }
};

void test02()
{
    Son2 son2;
    //son2.m_A = 100; //因为是保护权限，所以只能在类内中访问,类外不可访问
    //son2.m_B = 10;   //保护权限类外不可访问
}

//私有继承
class Son3 : private Base {
public:
    void func()
    {
        m_A = 100;  // public成员变成 private 成员，类内中可以访问，类外不可访问
        m_B = 20;   // protected 保护成员也变成 private 成员，类内中可以访问，类外不可访问
        //m_C = 30;  //父类私有成员子类不可访问    
    }
};

void test03()
{
    Son3 son3;
// private 权限继承的类外都不可以访问
    // son3.m_A = 10;
    // son3.m_B = 20;
    // son3.m_C = 47;
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}
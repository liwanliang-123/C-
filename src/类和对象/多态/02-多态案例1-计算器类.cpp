//案例描述：分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类。

// 多态的优点：

//     代码组织结构清晰；
//     可读性强；
//     利于前期和后期的扩展以及维护。

//总结：C++开发提倡利用多态设计程序架构，因为多态优点很多。

#include <iostream>
#include <string.h>

using namespace std;

//普通写法
//===========================================
class Calculator {
public:

    int getResult(string oper)
    {
        if (oper == "+") {
			return m_Num1 + m_Num2;
        }
		else if (oper == "-") {
			return m_Num1 - m_Num2;
        }
		else if (oper == "*") {
			return m_Num1 * m_Num2;
        }
        //如果要提供新的运算，需要修改源码,这不是想要的功能，这就用到多态了
    }
    int m_Num1;
    int m_Num2;
};

void test01()
{
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 20;
    cout << "result + = " << c.getResult("+") << endl;
    cout << "result - = " << c.getResult("-") << endl;
    cout << "result * = " << c.getResult("*") << endl;
}
//========================================

//多态写法
//抽象计算器类
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator {
public:
    virtual int getResult() //多态： 父类有虚函数，子类重写
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

//加法类
class Add : public AbstractCalculator {
public:
    int getResult() //子类重写
    {
        return m_Num1 + m_Num2;
    }
};

//减法类
class Sub : public AbstractCalculator {
public:
    int getResult() //子类重写
    {
        return m_Num1 - m_Num2;
    }
};

//乘法类
class Mul : public AbstractCalculator {
public:
    int getResult() //子类重写
    {
        return m_Num1 * m_Num2;
    }
};

//多态使用条件：父类指针或引用指向子类对象。
void test02()
{
    AbstractCalculator *ac = new Add; //这里父类指针ac已经指向子类Add对象了，即产生了多态
    ac->m_Num1 = 10;
    ac->m_Num2 = 20;
    //ac->getResult(); //重写了 getResult 函数，这里其实是调用的子类中的getResult函数
    cout << ac->m_Num1 << " + " << ac->m_Num2 << " = " << ac->getResult() << endl;
    delete ac;

    ac = new Sub;
    ac->m_Num1 = 10;
    ac->m_Num2 = 20;
    cout << ac->m_Num1 << " - " << ac->m_Num2 << " = " << ac->getResult() << endl;
    delete ac;
}

int main()
{
    //test01();
    test02();
    return 0;
}
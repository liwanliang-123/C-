// 常函数：
//     成员函数后加const后我们称为这个函数为常函数；
//     常函数内不可以修改成员属性；
//     成员属性声明时加关键字mutable（可变的） 后，在常函数中依然可以修改。


// 常对象：
//     声明对象前加const称该对象为常对象；
//     常对象只能调用常函数。

#include <iostream>
using namespace std;

class Person {
public:
    Person(int a): m_B(a)
    {
    }

//常函数
	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数，即在函数后面加 const 修饰
    //const 其实修饰的是this,让this指向的值也不能修改
    void showPerson() const
    {
        //m_age = 100; //被const修饰之后不能修改，因为加上就相当于 const Person* const this
        //this->m_age = 100; //同上

        //this = NULL; //不能修改指针的指向，相当于 Person* const this;

        this->m_B = 100; //这里就不会报错了
    }

    void func()
    {

    }

    int m_age;
    mutable int m_B; //特殊变量声明，就算是const修饰也可以修改、可变的
};

void test01()
{
    Person P1(0);
    P1.showPerson();
}

void test02()
{
    const Person P2(0); //在对象前面加const变成常对象
    P2.showPerson();
    //P1.m_age = 10;  // 不可更改
    P2.m_B = 20;    // 因为 m_B是特殊值，所以在常对象下也能够修改

//常函数对象只能调用常函数
    P2.showPerson();  //没问题
    //P1.func();    //不可以，因为普通成员函数可以修改
}

int main()
{
    test01();

    test02();

    return 0;
}

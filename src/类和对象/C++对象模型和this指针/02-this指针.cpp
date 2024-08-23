// 通过前面一节我们知道在C++中成员变量和成员函数是分开存储的。
// 每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码。

// 那么问题是：这一块代码是如何区分哪个对象调用自己的呢？
// C++通过提供特殊的对象指针 — this指针，解决上述问题。 /***** this指针指向被调用的成员函数所属的对象。 ******/
// this指针是隐含每一个非静态成员函数内的一种指针。
// this指针不需要定义，直接使用即可。

// this指针的用途：
//      当形参和成员变量同名时，可用this指针来区分；
//      在类的非静态成员函数中返回对象本身，可使用return *this。

#include <iostream>
using namespace std;

class Person {
public:

//在类的非静态成员函数中返回对象本身
    // Person personAddAge(Person &P)
    Person& personAddAge(Person &P) 
    {   //为什么这里是返回 Person& 而不是 Person ？ 
        //答：因为如果返回 Person 的话其实是返回的拷贝构造函数，可以回看拷贝构造函数的调用时机第三点（以值方式返回局部对象）
        //如果返回 Person 则Person 的拷贝构造函数会被调用
        this->age = this->age + P.age; //this->age指向P2的age，P.age指向P1的age

        return *this; //this是指向对象的指针，而*this指向p2这个对象本体
    }

//当形参和成员变量同名时，可用this指针来区分；
    Person(int age)
    {
        this->age = age;
    }

    Person(const Person &P)
    {
        cout << "拷贝构造函数被调用"<< endl;
    }

    int age; // this->age 就是这个 age ,因为 this指向被调用的成员函数所属对象，即this指向 test01中的 P
};

void test01()
{
    Person P(100);
    cout << "age  = " << P.age << endl;
}

void test02()
{
    Person P1(100);
    Person P2(100);

    P2.personAddAge(P1); //将P1的age加到P2上

// P2.personAddAge(P1)函数将 P2 返回了，然后又调用 personAddAge(P1)函数
// 链式调用
    P2.personAddAge(P1).personAddAge(P1).personAddAge(P1); //一直追加
//如果返回的是 Person而不是Person&，则P2.personAddAge(P1)并不会返回P2本身
//所以 .personAddAge(P1).personAddAge(P1) 也就不会真正 age 的值了
    cout << "P2 age  = " << P2.age << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}
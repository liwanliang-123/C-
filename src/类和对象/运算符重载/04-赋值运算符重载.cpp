// C++编译器至少给一个类添加4个函数：

//     默认构造函数(无参，函数体为空)
//     默认析构函数(无参，函数体为空)
//     默认拷贝构造函数，对属性进行值拷贝
//     赋值运算符 operator=, 对属性进行值拷贝

//如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题。

#include <iostream>

using namespace std;

class Person {
public:
    Person(int age)
    {
        this->m_Age = new int(age); //new 返回 int*
    }

    ~Person()
    {
        if(m_Age != NULL) {
            delete(m_Age);
            m_Age = NULL;
        }
    }

//重载赋值运算符
    Person &operator=(Person &P)
    {
        //编译器提供的是浅拷贝，类似于 m_Age = P.m_Age，这样写在释放的时候会出问题
        //所以需要自己实现深拷贝代码

        //如果有属性在堆区，则应该先释放，然后再进行深拷贝操作
        if(m_Age != NULL) {
            delete(m_Age);
            m_Age = NULL;
        }

        //进行深拷贝操作
        m_Age = new int(*P.m_Age);
        //返回对象的指针
        return *this;
    }

    int *m_Age;
};

void test01()
{
    Person P1(20);
    Person P2(30);
    // cout << "P1 age = " << *P1.m_Age << endl;
    // cout << "P2 age = " << *P2.m_Age << endl;


    //P2.operator=(P1);//等价于 P2 = P1
    P2 = P1;  //赋值运算,这里只会做浅拷贝，也就是将P1中的成员拷贝到P2,但P1中有指针，拷贝的是地址，
              //P2最后也会释放P1的地址，这里会出现重复释放P1地址的操作
    cout << "P1 age = " << *P1.m_Age << endl;
    cout << "P2 age = " << *P2.m_Age << endl;


    Person P3(50);
    P3 = P2 = P1;
    cout << "P1 age = " << *P1.m_Age << endl;
    cout << "P2 age = " << *P2.m_Age << endl;
    cout << "P3 age = " << *P3.m_Age << endl;
}

int main()
{
    test01();
    return 0;
}
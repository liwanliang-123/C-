//C++类中的成员可以是另一个类的对象，我们称该成员为对象成员。

// class A {
// };

// class B
// {
// 	A a；
// };


// B类中有对象A作为成员，A为对象成员。
// 那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？
//答： 这里是先构建 A 再构建 B，析构函数则相反

//当类中成员是其他类对象时，我们称该成员为 对象成员
//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
//析构顺序与构造相反

#include <iostream>
#include <string>
using namespace std;

//手机
class Phone {
public:

    Phone(string name ,int virsion): Name(name), Virsion(virsion)
    {
        cout << "Phone 构造函数被调用" << endl;
    }

    ~Phone()
    {
        cout << "Phone 析构函数被调用" << endl;
    }

    string Name;
    int Virsion;
};

//人
class Person {
public:

    Person(string name, string P_name):Name(name),P_hone(P_name,16) //  相当于Phone P_hone = P_name
    {
       cout << "Person 构造函数被调用" << endl;
    }

    ~Person()
    {
        cout << "Person 析构函数被调用" << endl;
    }
    string Name;
    Phone P_hone;  //这里会先构造 Phone 类，再构造 Person 类
};

void test01()
{
    Person P("小黄","MAX");
    cout << "name :" << P.Name << endl;
    cout << "phone :" << P.P_hone.Name << endl;
    cout << "virsion :" << P.P_hone.Virsion << endl;
}

int main()
{
    test01();
    return 0;
}
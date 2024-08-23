// C++中拷贝构造函数调用时机通常有三种情况：

//     1、使用一个已经创建完毕的对象来初始化一个新对象；
//     2、值传递的方式给函数参数传值；
//     3、以值方式返回局部对象。

#include <iostream>
using namespace std;

class Person {
public:
    Person() {
        cout << "无参构造函数被调用" << endl;
    }

    Person(int age)
    {
        A_ge = age;
        cout << "有参构造函数被调用" << endl;
    }

    Person(const Person &P) {
        A_ge = P.A_ge;
        cout << "拷贝构造函数被调用" << endl;
    }

    ~Person() {
        cout << "析构函数被调用" << endl;
    }
    int A_ge;
};

void test01()
{
    Person P1;
    Person P2(100);
    cout << "P2 age = " << P2.A_ge << endl;
    Person P3(P2);
    cout << "P3 age = " << P3.A_ge << endl;
}

void test02(Person P)
{
}

Person test03()
{
    Person P1;
    cout << &P1 << endl; //打印地址
    return Person(P1);
}

int main()
{
    //test01(); //使用一个已经创建完毕的对象来初始化一个新对象；

    // Person P;
    // test02(P); //值传递的方式给函数参数传值；

    Person P = test03(); //以值方式返回局部对象。
    cout << &P << endl;

    return 0;
}
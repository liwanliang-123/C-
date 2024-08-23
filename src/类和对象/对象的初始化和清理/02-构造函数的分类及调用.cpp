// 两种分类方式：
//     按参数分为： 有参构造和无参构造；
//     按类型分为： 普通构造和拷贝构造。
//================================================
// 三种调用方式：
//     括号法
//     显示法
//     隐式转换法

#include <iostream>
using namespace std;

class Person {
public:
//无参构造函数 或叫默认构造函数
    Person()
    {
        cout << "无参构造函数被调用" << endl;
    }
//有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数被调用" << endl;
    }
//拷贝构造函数
    Person(const Person &P)
    {
        age = P.age; //将传入的人的属性拷贝到自己身上
        cout << "拷贝构造函数被调用" << endl;
    }

    ~Person()
    {
        cout << "析构函数被调用" << endl;
    }

    int age;
};

//构造函数的调用：
void test01()
{
//括号法：
//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    Person P1;     //无参构造函数
    Person P2(10); //有参构造函数
    cout << "P2 age  = " << P2.age << endl;
    Person P3(P2); //拷贝构造函数
    cout << "P3 age  = " << P3.age << endl;
}

void test02()
{
//显示法：
    Person P1;           
    Person P2 = Person(10); //显示指定有参构造
    Person P3 = Person(P2); //拷贝构造

    //Person(10) 单独拿出来叫做匿名对象，当前行结束之后，马上析构


    //Person(P3)
    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明 Person(P3) = Person P3
}

void test03()
{
//隐式转换法：
    Person P1 = 10; //相当于写了 Person P2 = Person(10);
    Person P2 = P1; //相当于写了 Person P2 = Person(P1);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}
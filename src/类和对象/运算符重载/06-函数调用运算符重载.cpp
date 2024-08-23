// 函数调用运算符 () 也可以重载；
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数；
// 仿函数没有固定写法，非常灵活。

#include <iostream>
#include <string>

using namespace std;

class Print {
public:

//重载 （）运算符
    void operator()(string str)
    {
        cout << str << endl;
    }

};

class Add {
public:

//重载 （）运算符
    int operator()(int a, int b)
    {
        return a + b;
    }

};

void test01()
{
    Print print;
    print("hello,world"); //相当于将 （）重载了，即调用到了 operator()，使用起来就像函数调用
}

void test02()
{
    Add add;
    int ret = add(10,20);  //调用 operator()(int a, int b)
    cout << "ret = " << ret << endl;

    //匿名函数对象
    cout << Add()(100 ,200) << endl;
}

int main()
{
    // test01();

    test02();

    return 0;
}
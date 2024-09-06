// 调用规则如下：
//     1. 如果函数模板和普通函数都可以实现，优先调用普通函数；
//     2. 可以通过空模板参数列表来强制调用函数模板；
//     3. 函数模板也可以发生重载；
//     4. 如果函数模板可以产生更好的匹配，优先调用函数模板。

//总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性。

#include <iostream>

using namespace std;

void Print(int &a, int &b)
{
    cout << "调用的普通函数" << endl;
}

template<typename T>
void Print(T &a, T &b)
{
    cout << "调用的函数模版函数" << endl;
}

//重载函数模版
template<typename T>
void Print(T &a, T &b, T &c)
{
    cout << "调用的重载的函数模版函数" << endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    int c = 30;
    Print(a,b);    //如果有普通函数和函数模版，优先调用普通函数

    Print<>(a,b);  //但是可以通过空模版参数强制调用函数模板

    Print(a,b,c);  //调用函数模版的重载函数
}

void test02()
{
    char a = 'a';
    char b = 'b';

    Print(a,b);  //这里会调用模版函数，如果是普通函数还需要隐式转换
}

int main()
{
    test01();
    test02();
    return 0;
}
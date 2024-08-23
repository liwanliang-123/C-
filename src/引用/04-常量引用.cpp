// 2.6常量引用
// <1>常量引用主要用来修饰形参，防止误操作

// <2>在函数形参列表中，可以加const修饰形参，防止形参改变实参

#include <iostream>
using namespace std;

void func(const int& v)
{
    // v += 10;//错误
    cout << v << endl;
}

int main()
{
    int a = 10;
    int& ref = a;//正确
    int a = 10;
    //int& ref = 10;//错误，引用本身需要一个合法的内存空间，因此就这行错误
    const int& ref = 10;//正确，编译器优化代码：int temp=10;const int& ref=temp;
    ref = 20;//错误，加入const之后变为只读，不可修改
    return 0;
}

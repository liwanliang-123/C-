// 函数默认参数
// <1>在C++中，函数的形参列表中的形参是可以有默认值的

// <2>语法：返回值类型 函数名 （参数=默认值）{}

// eg:int func(int a,int b=20,int c=30)

// <3>注意事项：如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值；
// 如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
// 如果函数声明有默认函数，函数实现就不能有默认函数，声明与实现只能有一个默认参数

#include<iostream>
using namespace std;

int func(int a,int b);

int func(int a = 10,int b = 20)
{
    return a + b;
}

int main()
{
    int c = func(100);
    cout << "c = " << c << endl;
}
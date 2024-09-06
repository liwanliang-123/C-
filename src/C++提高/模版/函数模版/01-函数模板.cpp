// C++另一种编程思想称为泛型编程，主要利用的技术就是模板；
// C++提供两种模板机制：函数模板和类模板。

// 函数模板作用：
//     建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。

// 语法：
//     template<typename T>
//     函数声明或定义

// 解释：
//      template： 声明创建模板；
//      typename：表明其后面的符号是一种数据类型，可以用class代替；
//      T：通用的数据类型，名称可以替换，通常为大写字母。

// 总结：
//     函数模板利用关键字template；
//     使用函数模板有两种方式：自动类型推导、显示指定类型；
//     模板的目的是为了提高复用性，将类型参数化。

#include <iostream>
using namespace std;

//函数模版写两个数交换的代码
template<typename T>
void mySwap(T &a ,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    //使用函数模版的两种方法：
    //1、自动类型推导
    //mySwap(a ,b);       //也就是编译器会自动推到 T 的类型

    //2、显示指定 T 的类型
    mySwap<int>(a ,b);    //也就是显示的指定a和b的数据类型为int

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    test01();
    return 0;
}
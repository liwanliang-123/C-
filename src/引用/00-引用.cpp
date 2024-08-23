// <1>作用：给变量起别名
// <2>语法：数据类型 &别名=原名

// 注：别名，原名使用同一存储空间，一改全改；

// 引用的注意事项
//     1、引用必须初始化    int &b
//     2、引用在初始化之后，不可更改对象，但可用赋值改变存储空间的值

#include<iostream>
using namespace std;

int main()
{
    int a = 100;
    int &b = a; //起别名

    cout << "a = " << a << "b = " << b << endl;
    b = 200;
    cout << "a = " << a << "b = " << b << endl;

    return 0;
}
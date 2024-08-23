// 引用做函数返回值
// <1>作用：引用是可以作为函数的返回值存在的

// <2>不要返回局部变量引用

// <3>用法：函数调用作为左值

#include <iostream>
using namespace std;

//返回局部变量引用
int& test01(){
    int a = 10;//局部变量(位于栈区)
    return a;
}
//返回静态变量引用
int& test02(){
    static int a = 20;//静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
    return a;
}
int main()
{
    // int &ref01 = test01(); 使用 g++ 编译器直接出现 Segmentation fault (core dumped)
    // cout << "ref01=" << ref01 << endl;

    int &ref02 = test02();
    cout << "ref02=" << ref02 << endl;

    test02() = 1000;//如果函数的返回值是引用，这个函数调用可以作为左值
    cout << "ref02=" << ref02 << endl;//test02为原名，ref为别名
}
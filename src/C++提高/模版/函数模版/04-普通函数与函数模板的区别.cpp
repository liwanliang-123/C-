// 普通函数与函数模板区别：
//      普通函数调用时可以发生自动类型转换（隐式类型转换）；
//      函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换；
//      如果利用显示指定类型的方式，可以发生隐式类型转换。

#include <iostream>

using namespace std;

//普通函数
int add(int a,int b)
{
    return a + b;
}

//模版函数
template<typename T>
T myAdd(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10;
    int b = 30;
    char c = 'c';
    cout << add(a,b) << endl;
    cout << add(a,c) << endl;  //普通函数可以发生隐式转换 add(a,c)结果为 109
}

void test02()
{
    int a = 10;
    int b = 30;
    char c = 'c';
    cout << myAdd(a,b) << endl;
    //cout << myAdd(a,c) << endl;  //这里函数模版不会发生隐式转换
    cout << myAdd<int>(a,c) << endl; // 但是可以显示指定 T 的数据类型，也就是这里会发生隐式类型转换, char 转换成 int
}

int main()
{
    test01();
    test02();

    return 0;
}
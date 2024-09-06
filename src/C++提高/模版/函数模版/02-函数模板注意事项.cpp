// 注意事项：
//     自动类型推导，必须推导出一致的数据类型T，才可以使用；
//     模板必须要确定出T的数据类型，才可以使用。

// 总结：使用模板时必须确定出通用数据类型T，并且能够推导出一致的类型。

#include <iostream>

using namespace std;

template <typename T> //typename 可以写成 class
void mySwap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void func()
{
    cout << " func called " << endl;
}

void test01()
{
    int a = 10,b = 20;
    char c = 'c';
    //mySwap(a,b);
    //mySwap(a,c);  //  自动类型推导，必须能推导出一致的数据类型T

    //func();       // 模板必须要确定出T的数据类型，才可以使用
    //解决方法就是显示指定 T 的类型，如下
    func<int>();  //显示指定 T 的数据类型

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    test01();
    return 0;
}
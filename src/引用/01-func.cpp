// 引用做函数参数
// <1>作用：函数传参时，可以利用引用的技术让形参修饰实参（效果与地址传递相同）

// <2>优点：可以简化指针修改实参

#include<iostream>
using namespace std;

//值传递
void func01(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
//地址传递
void func02(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//引用传递
void func03(int &a,int &b)//别名
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 100;
    int b = 200;

    // func01(a, b);
    // func02(&a, &b);
    func03(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
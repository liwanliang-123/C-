// 函数重载
// <1>作用：函数名可以相同，提高复用性

// <2>函数重载满足条件：
// ​ 同一个作用域下
// ​ 函数名称相同

// ​ 函数参数类型不同 或者 个数不同 或者 顺序不同

// <3>注意：函数的返回值（函数的数据类型）不可以作为函数重载的条件

// 函数重载注意事项

// <1>引用作为重载条件
// <2>函数重载碰到函数默认参数

#include<iostream>
using namespace std;

//引用作为重载条件
void func(int &a)
{
    cout<<"func(int &a)调用"<<endl;
}

void func(const int &a)
{
    cout<<"func(const int &a)调用"<<endl;
}
//函数重载碰到函数默认参数
void func2(int a,int b=10)
{
    cout<<"void func2(int a,int b=10)调用"<<endl;
}

void func2(int a)
{
    cout<<"void func2(int a)调用"<<endl;
}

void func2()
{
    cout<<"void func2()调用"<<endl;
}

int main()
{
    int a = 10;
    func(a);  //调用无const
    func(10); //调用有const
   //func2(10);//碰到默认参数产生歧义，需要避免

    // func2();
}



// <1>用new操作符在堆区开辟数据
// <2>堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
// eg:delete p;//释放堆区数据
// delete[]arr;//释放数组时，需加[];
// <3>语法：new 数据类型
// <4>利用new创建的数据，会返回该数据对应的类型的指针
// eg:int *p=new int(10);//在堆区创建整型数据,并赋值为10
// eg:int *arr=new int[10];//在堆区创建10整型数据,10代表数组有10个元素

#include <iostream>
#include <stdio.h>

using namespace std;

int *func()
{
    // int *p = new int(100); //整数
    int *p = new int[10];  //数组
    return p;
}

int main()
{
    int *p = func();

    // printf("*p = %d\n",*p);

    for(int i = 0; i < 10; i++){
        p[i] = 101;
    }

    for(int i = 0; i < 10; i++){
        printf("p[%d] = %d\n",i,*p);
    }

    delete []p;
    delete p;
    return 0;
}
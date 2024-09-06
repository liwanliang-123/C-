// 学习目标： 掌握类模板成员函数分文件编写产生的问题以及解决方式。

// 问题： 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到。

// 解决：
//     解决方式1： 直接包含.cpp源文件；
//     解决方式2： 将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制。

//总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp。

#include <iostream>
#include <string>

//#include "07-person.h"    //如果直接写成 .h 文件和 .cpp文件会出错，因为模版的成员函数是在调用时初始化，在编译链接时就会出错
//#include "07-person.cpp"  //第一种解决方法就是直接包含 .cpp 文件
#include "07-person.hpp"    //第二种解决办法就是将类模版的声明和实现写到同一个文件中

using namespace std;

void test01()
{
    Person<string, int> P("Tom Cat", 110);
    P.showInfo();
}

int main()
{
    test01();
    return 0;
}
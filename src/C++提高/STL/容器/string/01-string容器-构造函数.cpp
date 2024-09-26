/*
    string是C++风格的字符串，而string本质上是一个类
*/

#include <iostream>
#include <string>

/*
string构造函数

构造函数原型
    string()创建一个空的字符串
    string(const char* s)使用字符串s初始化
    string(const string& str)使用一个string对象初始化另一个string对象
    string(int n,char c)使用n个字符c初始化
*/

void test01()
{
    std::string s1;  //默认构造

    const char* str = "hello world";
    std::string s2(str);
    std::cout << "s2 = " << s2 << std::endl;

    std::string s3(s2);
    std::cout << "s3 = " << s3 << std::endl;

    std::string s4(10,'c');
    std::cout << "s4 = " << s4 << std::endl;
}

int main()
{
    test01();
    return 0;
}


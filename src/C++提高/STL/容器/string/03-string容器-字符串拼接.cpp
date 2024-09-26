#include <iostream>
#include <string>

// 实现在字符串末尾拼接字符串

/*
函数原型：
    string& operator+=(const char* str)    重载+=操作符
    string& operator+=(const char c)       重载+=操作符
    string& operator+=(const string& str)  重载+=操作符

    string& append(const char* s)          把字符串s连接到当前字符串结尾
    string& append(const char* s，int n)    把字符串s的前n个字符连接到当前字符串的结尾
    string& append(const string &s)         同operator+=(const string& str)
    string& append(const string &s,int pos,int n)把字符串s中从pos开始的n个字符连接到字符串结尾
*/

void test01()
{
    std::string str1 = "hello";
    str1 += " world ";
    std::cout << "str1 = " << str1 << std::endl;

    str1 += 'C';
    std::cout << "str1 = " << str1 << std::endl;

    std::string str2 = " HELLO";
    str1 += str2;
    std::cout << "str1 = " << str1 << std::endl;

    str2.append(" WORLD");
    std::cout << "str2 = " << str2 << std::endl;

    str2.append(" AAAAA", 3);
    std::cout << "str2 = " << str2 << std::endl;

    std::string str3 = " HILLOU";
    str2.append(str3);
    std::cout << "str2 = " << str2 << std::endl;

    std::string str4 = "world hello";
    str4.append(str3, 2, 3);  //从str3的第二个字符串截取三个字符追加到 str4 中
    std::cout << "str4 = " << str4 << std::endl;
}

int main()
{
    test01();
    return 0;
}


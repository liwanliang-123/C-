#include <iostream>
#include <string>

/*
    字符串比较是按字符的ASCII码进行对比
    两个字符串相等返回0，> 返回1，< 返回-1
*/

void test01()
{
    std::string str1 = "abcd";
    std::string str2 = "abcde";

    if (str2.compare(str1) == 0) {
        std::cout << "两个字符串相等" << std::endl;
    } else if(str2.compare(str1) == 1) {
        std::cout << "str2 大于 str1" << std::endl;
    } else {
        std::cout << "str2 小于 str1" << std::endl;
    }
}

int main()
{
    test01();
    return 0;
}


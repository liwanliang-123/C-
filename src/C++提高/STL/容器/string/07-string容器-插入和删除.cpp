#include <iostream>
#include <string>

/*
    对string字符串进行插入和删除字符操作。
    插入和删除的起始下标都是从0开始。
*/

void test01()
{
    std::string str1 = "abcdefg";
    str1.insert(2, "ABC");    //在第2个位置后面插入字符串 ABC
    std::cout << str1 << std::endl;

    str1.erase(0, 2);  //从地 0 个位置起删除2 个字符串
    std::cout << str1 << std::endl;
}

int main()
{
    test01();
    return 0;
}


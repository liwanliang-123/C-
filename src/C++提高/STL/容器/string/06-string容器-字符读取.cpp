#include <iostream>
#include <string>

/*
    string字符串中单个字符存取有两种方式，利用[]或at
*/

void test01()
{
    std::string str1 = "abcdefg";
//	通过[]访问单个字符
    for (size_t i = 0; i < str1.size(); i++) {
        str1[0] = 'A';  //可以修改该字符串
        std::cout << str1[i];
    }
    std::cout << std::endl;

//  通过at方式访问的单个字符
    for (size_t i = 0; i < str1.size(); i++) {
        std::cout << str1.at(i);
    }
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}


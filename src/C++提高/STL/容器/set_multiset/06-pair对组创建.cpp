/*
    成对出现的数据，利用对组可以返回两个数据。
*/

#include <iostream>
#include <string>

void test01()
{ 
// 第一种方式方式创建
    std::pair<std::string, int> p("Tom", 20);
	std::cout << p.first <<" "<< p.second << std::endl;

// 第二种方式创建
    std::pair<std::string, int> p2 = std::make_pair("jerry", 100);
    std::cout << p2.first << " " << p2.second << std::endl;
}

int main()
{
    test01();
    return 0;
}
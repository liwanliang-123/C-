/*
    实现四则运算
    其中negate是一元运算，其它 + - * / %都是二元运算
*/

#include <iostream>
#include <functional>

void test01()
{
   //  取反
    std::negate<int> n;
    int num = n(10);
    std::cout << num << std::endl;
}

void test02()
{
    // 加法
    std::plus<int> p;
    int sum = p(10, 20);
    std::cout << sum << std::endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}
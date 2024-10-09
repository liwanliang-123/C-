/*
    向容器中填充指定的元素。
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Myprint {
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};

void test01()
{
    std::vector<int> v1;
    v1.resize(10);  // 初始化10个容器，并且元素值为 0
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;

    // 重新为容器填充值, 将初始值 0 替换成 1000
    fill(v1.begin(), v1.end(), 1000);
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
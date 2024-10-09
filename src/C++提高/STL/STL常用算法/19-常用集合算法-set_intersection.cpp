/*
    求两个容器的交集。

    总结:
        求交集的两个容器必须得是有序序列。
        目标容器开辟空间需要从两个容器中取小值。
        set_intersection返回值(迭代器)是交集中最后一个元素的位置。
*/
#include <iostream>
#include <vector>
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
    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    std::vector<int> v2;
    for (size_t i = 5; i < 15; i++) {
        v2.push_back(i);
    }

    std::vector<int> vTarget;
    vTarget.resize(std::min(v1.size(), v2.size())); //交集取两个容器中最小的值

    // 取交集
    std::vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, Myprint());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
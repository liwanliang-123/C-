/*
    求两个集合的差集。

    总结：
        求差集的两个集合必须得是有序序列。
        目标容器开辟空间需要从两个容器取较大值。
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
    // 最特殊的情况：两个容器没有交集，需要取最大的容器开辟空间
    vTarget.resize(std::max(v1.size(), v2.size()));

    // 取差集
    // v1 和 v2 的差集
    std::vector<int>::iterator itEnd1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd1, Myprint());
    std::cout << std::endl;

    std::cout << "-----------" << std::endl;

    // v2 和 v1 的差集
    std::vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd2, Myprint());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
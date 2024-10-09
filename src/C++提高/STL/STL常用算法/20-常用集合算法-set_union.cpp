/*
    求两个集合的并集。

    总结：
        求并集的两个集合必须得是有序序列。
        目标容器开辟空间需要两个容器相加。
        set_union返回值(迭代器)是并集中最后一个元素的位置。
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
    vTarget.resize(v1.size() + v2.size()); //并集取两个容器的和

    // 取并集
    std::vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, Myprint());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
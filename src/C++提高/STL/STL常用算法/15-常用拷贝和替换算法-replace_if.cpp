/*
    将区间内满足条件的元素，替换成指定元素。
    replace_if按条件查找，可以利用仿函数灵活筛选满足的条件。
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

class Greater30 {
public:
    bool operator()(int val)
    {
        return val >= 30;
    }
};

void test01()
{
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(70);
    v1.push_back(90);
    v1.push_back(90);

    std::cout << "替换前:" << std::endl;
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;

    // 将 >= 30 的元素替换成1000
    replace_if(v1.begin(), v1.end(), Greater30(), 1000);

    std::cout << "替换后:" << std::endl;
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
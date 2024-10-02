/*
    搬运容器到另一个容器中
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Trancsform {
public:
    int operator()(int v)
    {
        // return v + 100;
        return v;
    }
};

class Print {
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};

void test01()
{
    std::vector<int> v;
    for (size_t i = 0; i < 10; i++) {
        v.push_back(i);
    }

    std::vector<int> vTarget;  // 目标容器
    vTarget.resize(v.size());  // 目标容器需要提前开辟空间

    transform(v.begin(), v.end(), vTarget.begin(), Trancsform());

    for_each(vTarget.begin(), vTarget.end(), Print());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
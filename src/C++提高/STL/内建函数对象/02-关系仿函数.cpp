/*
    实现关系对比
    =  != >  <  >=  <=
*/

#include <iostream>
#include <functional>
#include <vector>

//  > 运算符
class myCompare {
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void printVector(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(80);
    v.push_back(40);
    v.push_back(90);

    printVector(v);

    sort(v.begin(), v.end());
    printVector(v);

//  sort(v.begin(), v.end(), myCompare());
//  greater： 大于仿函数
    sort(v.begin(), v.end(), std::greater<int>());
    printVector(v);
}

int main()
{
    test01();
    return 0;
}
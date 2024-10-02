/*
    对容器内元素进行排序。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void printVector(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

class mySort {
public:
    int operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test01()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(80);
    v.push_back(60);

    printVector(v);
    sort(v.begin(), v.end());  // 默认从小到大排序
    printVector(v);

//  变为从大到小排序
    // sort(v.begin(), v.end(), mySort());
    sort(v.begin(), v.end(), std::greater<int>());
    printVector(v);
}

int main()
{
    test01();
    return 0;
}
/*
    两个容器元素合并，并存储到另一个容器中。

    merge合并的两个容器必须得是有序序列。
*/

#include <iostream>
#include <vector>
#include <algorithm>

void myPrint(int val)
{
    std::cout << val << " ";
}

void test01()
{
    std::vector<int> v1;
    std::vector<int> v2;

    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i+1);
    }
    
//  目标容器
    std::vector<int> vTarget;
//  提前分配空间
    vTarget.resize(v1.size() + v2.size());

//  merge
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), myPrint);
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
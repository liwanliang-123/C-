/*
    实现逻辑运算

    logical_and: 逻辑与
    logical_or : 逻辑或
    logical_not: 逻辑非
*/

#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<bool> &v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::vector<bool> vb;
    vb.push_back(true);
    vb.push_back(true);
    vb.push_back(true);
    vb.push_back(false);
    vb.push_back(false);

    printVector(vb);

//  利用逻辑非 将容器v 搬运到容器v2中，并执行取反操作
    std::vector<bool> vb2;
    vb2.resize(vb.size());  // 需要提前开辟空间才能搬运

//  vb 元素搬运到 vb2
    std::transform(vb.begin(), vb.end(), vb2.begin(), std::logical_not<bool>());
    printVector(vb2);
}

int main()
{
    test01();
    return 0;
}
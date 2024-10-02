/*
    查找相邻重复元素。
*/

#include <iostream>
#include <vector>
#include <algorithm>

void test01()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(60);
    v.push_back(40);
    v.push_back(30);
    v.push_back(10);

    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if(it == v.end()) {
        std::cout << "没有找到" << std::endl;
    } else {
        std::cout << "找到了" << std::endl;
        std::cout << *it << std::endl;
    }
}

int main()
{
    test01();
    return 0;
}
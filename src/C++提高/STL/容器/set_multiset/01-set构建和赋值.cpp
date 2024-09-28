/*
    set容器插入数据时用insert
    set容器插入的数据会自动排序
*/

#include <iostream>
#include <set>

void printSet(std::set<int> &s)
{
    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
//  默认构造
    std::set<int> s1;
//  set 插入数据只有 insert 方式
    s1.insert(11);
    s1.insert(20);
    s1.insert(3);
    s1.insert(40);
    s1.insert(100);
//    s1.insert(40);  set不允许插入重复元素

    printSet(s1);    // 默认从小到大排序

//  拷贝构造
    std::set<int> s2(s1);
    printSet(s2);
}

int main()
{
    test01();
    return 0;
}
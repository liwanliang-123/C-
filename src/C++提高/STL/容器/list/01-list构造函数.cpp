/*
    创建list容器
*/

#include <iostream>
#include <list>

void printList(std::list<int> &l)
{
    for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
// 默认构造
    std::list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);
// 遍历容器
    printList(l1);

// 区间构造
    std::list<int> l2(l1.begin(), l1.end());
    printList(l2);

// 拷贝构造
    std::list<int> l3(l2);
    printList(l3);

// n个elem
    std::list<int> l4(5, 1000);
    printList(l4);
}

int main()
{
    test01();
    return 0;
}
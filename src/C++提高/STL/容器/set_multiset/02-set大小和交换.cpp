/*
    统计set容器大小以及交换set容器。

    统计大小——size
    判断是否为空——empty
    交换容器——swap
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
    std::set<int> s1;
    s1.insert(11);
    s1.insert(20);
    s1.insert(3);

    std::cout << "s1 size = " << s1.size() << std::endl;

    if(s1.empty()) {
        std::cout << "s1 为空" << std::endl;
    } else {
        std::cout << "s1 不为空" << std::endl;
    }

    std::set<int> s2;
    s2.insert(110);
    s2.insert(200);
    s2.insert(30);

    std::cout << "交换前： " << std::endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);

    std::cout << "交换后： " << std::endl;
    printSet(s1);
    printSet(s2);
}

int main()
{
    test01();
    return 0;
}
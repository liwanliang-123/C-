/*
区别：
    set不可以插入重复数据，而multiset可以
    set插入数据的同时会返回插入结果，表示插入是否成功
    multiset不会检测数据，因此可以插入重复数据

总结：
    如果不允许插入重复数据可以利用set
    如果需要插入重复数据利用multiset
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

void printMultiSet(std::multiset<int> &s)
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
    s1.insert(50);
    s1.insert(96);
    s1.insert(96);

    printSet(s1);

    std::multiset<int> ms;
    ms.insert(110);
    ms.insert(201);
    ms.insert(32);
    ms.insert(540);
    ms.insert(110);
    ms.insert(110);

    printMultiSet(ms);
}

int main()
{
    test01();
    return 0;
}
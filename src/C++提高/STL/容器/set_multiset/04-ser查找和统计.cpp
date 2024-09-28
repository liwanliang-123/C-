/*
    对set容器进行查找数据以及统计数据

    查找——find(返回的是迭代器)
    统计——count(对于set,结果为0或者1)
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
    s1.insert(50);
    s1.insert(96);

    printSet(s1);

    std::set<int>::iterator it = s1.find(11);
//  find
    if(it != s1.end()) {
        std::cout << "OK" << " " << *it << std::endl;
    } else {
        std::cout << "NO" << " " << *it << std::endl;
    }

//统计 s1 中 11 的个数
    int num = s1.count(111);
    std::cout << "num = " << num << std::endl;
}

int main()
{
    test01();
    return 0;
}
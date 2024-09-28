/*
    set容器默认排序规则为从小到大，掌握如何改变排序规则。

    主要技术点：利用仿函数，可以改变排序顺序
*/

#include <iostream>
#include <string>
#include <set>

class myCompare {
public:
    bool operator()(int v1, int v2)const  // 重载 ()  , 这里需要加 const
    {
        return v1 > v2;
    }
};

void printSet(std::set<int> &s)
{
    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printSet2(std::set<int, myCompare> &s)
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

//  指定排序规则为从大到小
//  set容器要在还没插数据之前对排序进行改变
    std::set<int, myCompare> s2;
    s2.insert(11);
    s2.insert(20);
    s2.insert(3);
    s2.insert(50);
    s2.insert(96);
    s2.insert(96);

    printSet2(s2);
}

int main()
{
    test01();
    return 0;
}
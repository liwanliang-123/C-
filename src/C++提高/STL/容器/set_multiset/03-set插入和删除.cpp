/*
    set容器进行插入数据和删除数据

    插入——insert
    删除——erase
    清空——clear
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
//  插入
    s1.insert(11);
    s1.insert(20);
    s1.insert(3);
    printSet(s1);

//  删除
    //s1.erase(11);          // 直接输入要删除的元素
    s1.erase(s1.begin());  // 通过迭代器删除
    //s1.erase(s1.begin(), s1.end());  //清空
    printSet(s1);

//  清除
    s1.clear();
    printSet(s1);
}

int main()
{
    test01();
    return 0;
}
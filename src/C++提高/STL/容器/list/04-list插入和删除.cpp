/*
    对list容器进行数据的插入和删除

    尾插——push_back
    尾删——pop_back
    头插——push_front
    头删——pop_front
    插入——insert
    删除——erase
    移除——remove
    清空——clear
*/

#include <iostream>
#include <list>

void printList(std::list<int> &l)
{
    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::list<int> l1;
//  尾插
    l1.push_back(11);
    l1.push_back(22);
    l1.push_back(33);
    printList(l1);

//  尾删
    l1.pop_back();
    l1.pop_back();
    printList(l1);

//  头插
    l1.push_front(100);
    l1.push_front(200);
    printList(l1);

//  头删
    l1.pop_front();
    printList(l1);

//  插入
    //l1.insert(++l1.begin(), 10000);
    l1.insert(l1.begin(), 10000);  // 在最开始插入10000
    printList(l1);

//  删除
    //l1.erase(l1.begin(), l1.end());
    l1.erase(l1.begin());
    printList(l1);

//  移除
    l1.remove(11);  //remove 不用提供迭代器
    printList(l1);

//  clear
    l1.clear();
    printList(l1);
}

int main()
{
    test01();
    return 0;
}
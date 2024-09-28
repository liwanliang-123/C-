/*
    给list容器进行赋值，以及交换list容器。
*/
#include <iostream>
#include <list>

void printList(std::list<int> &l)
{
//    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::list<int> l1;
    l1.push_back(11);
    l1.push_back(22);
    l1.push_back(33);
    printList(l1);

// 等号赋值
    std::list<int> l2 = l1;
    printList(l2);

// assign
    std::list<int> l3;
    l3.assign(l1.begin(), l1.end());
    printList(l3);

    std::list<int> l4;
    l4.assign(5, 999);  //n 个 elem
    printList(l4);

// swap 交换
    std::cout << "交换前：" << std::endl;
    printList(l1);
    printList(l4);

    l4.swap(l1);

    std::cout << "交换后：" << std::endl;
    printList(l1);
    printList(l4);
}

int main()
{
    test01();
    return 0;
}
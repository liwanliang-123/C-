/*
    deque容器构造函数
*/

#include <iostream>
#include <deque>

void printDeque(std::deque<int> &d)
{                        //限制为只读迭代器
//    for (auto it = d.begin(); it != d.end(); it++) {
    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
//默认构造
    std::deque<int> d1;
    for (size_t i = 0; i < 10; i++) {
        d1.push_back(i);
        //d1.push_front(10);
    }
    printDeque(d1);

// 区间构造
    std::deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

// elem
    std::deque<int> d3(3, 100);
    printDeque(d3);

// 拷贝构造
    std::deque<int> d4(d3);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}
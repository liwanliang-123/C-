/*
    给deque容器进行赋值
*/

#include <iostream>
#include <deque>

void printDeque(std::deque<int> &d)
{                        // const_iterator: 限制为只读迭代器
//    for (auto it = d.begin(); it != d.end(); it++) {
    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::deque<int> d1;
    for (size_t i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);
// 重载等号运算符赋值
    std::deque<int> d2 = d1;
    printDeque(d2);

// assign 区间赋值
    std::deque<int> d3;
    d3.assign(d2.begin(), d2.end());
    printDeque(d3);

// assign n 个 elem 拷贝赋值
    std::deque<int> d4;
    d4.assign(5, 200);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}
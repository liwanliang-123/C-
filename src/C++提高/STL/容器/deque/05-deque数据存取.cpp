/*
    对deque中的数据的存取操作
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

// 两端数据操作
void test01()
{
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(40);
    d.push_front(50);
    d.push_front(60);

// 通过中括号 [] 进行输出
    for (size_t i = 0; i < d.size(); i++) {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;

// 提供 at 进行输出
    for (size_t i = 0; i < d.size(); i++) {
        std::cout << d.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "第一个元素为：" << d.front() << std::endl;
    std::cout << "最后一个元素为： " << d.back() << std::endl;
}

int main()
{
    test01();
    return 0;
}
/*
    利用算法实现对deque容器进行排序
*/

#include <iostream>
#include <deque>
#include <algorithm>  //标准算法

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

    std::cout << "排序前：";
    printDeque(d);

// 开始排序
// 默认是从小到大升序
// 对于支持随机访问的迭代器容器，都可以用sort算法对其进行排序
// vector容器也可以利用sort进行排序
    sort(d.begin(), d.end());

    std::cout << "排序后：";
    printDeque(d);
}

int main()
{
    test01();
    return 0;
}
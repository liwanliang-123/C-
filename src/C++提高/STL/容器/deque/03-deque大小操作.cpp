/*
    对deque容器的大小进行操作

    deque没有容量概念
    判断是否为空——empty
    返回元素个数——size
    重新指定个数——resize
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
// empty
    if(d1.empty()) {
        std::cout << "d1 为空" << std::endl;
    } else {
        std::cout << "d1 不为空" << std::endl;
    }
// size
    std::cout << "d1 size = " << d1.size() << std::endl;

// resize
    //d1.resize(5);
    //d1.resize(20);  //重新指定大小,多余的空间添加 0
    d1.resize(20, 100); // 多余的空间添加 100
    std::cout << "d1 size = " << d1.size() << std::endl;
    printDeque(d1);
}

int main()
{
    test01();
    return 0;
}
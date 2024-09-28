/*
    对list容器中数据进行存储。

    list容器中不可以通过[]或者at方式访问数据
    因为List本质是链表，不是用连续的线性空间存储数据，迭代器也是不支持随机访问的
    
    返回第一个元素——front
    返回最后一个元素——back

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

    l1.push_back(11);
    l1.push_back(22);
    l1.push_back(33);

    std::cout << "第一个元素: " << l1.front() << std::endl;
    std::cout << "最后一个元素：" << l1.back() << std::endl;

//  验证list不支持随机访问
    std::list<int>::iterator it = l1.begin();
    it++;
    it--;
    --it;
    ++it;  // 支持双向访问
    //it = it + 1 // 不能这样写，也就是不支持随机访问
}

int main()
{
    test01();
    return 0;
}
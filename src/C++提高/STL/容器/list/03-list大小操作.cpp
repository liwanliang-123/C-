/*
    对list容器的大小进行操作。

    判断是否为空——empty
    返回元素个数——size
    重新指定个数——resize
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

    if(l1.empty()) {
        std::cout << " l1 为空 " << std::endl;
    } else {
        std::cout << " l1 不为空 " << std::endl;
    }

    std::cout << " l1 size =  " << l1.size() << std::endl;

//  重新指定大小, 多的添加0，少的删除
    // l1.resize(10);
    l1.resize(10, 1000);   // 指定用 1000 来填充
    printList(l1);
    std::cout << " l1 size =  " << l1.size() << std::endl;
}

int main()
{
    test01();
    return 0;
}
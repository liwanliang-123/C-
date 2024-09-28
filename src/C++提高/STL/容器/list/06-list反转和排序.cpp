/*
    将容器中的元素反转，以及将容器中的数据进行排序。

    反转——reverse
    排序——sort(成员函数)
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

// 反转
void test01()
{
    std::list<int> l1;

    l1.push_back(11);
    l1.push_back(23);
    l1.push_back(3);
    l1.push_back(73);
    l1.push_back(43);

    std::cout << "反转前：" << std::endl;
    printList(l1);

    l1.reverse();

    std::cout << "反转后：" << std::endl;
    printList(l1);

}

bool myCompare(int v1, int v2)
{
    // 降序： 第一个数大于第二个数
    return v1 > v2;
}

// 排序
void test02()
{
    std::list<int> l1;

    l1.push_back(11);
    l1.push_back(23);
    l1.push_back(3);
    l1.push_back(73);
    l1.push_back(43);

    std::cout << "排序前：" << std::endl;
    printList(l1);

    //sort(l1.begin(), l1.end());
    //所有不支持随机访问迭代器的容器不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应的一些算法
    l1.sort();  //默认是从小到大排序

    std::cout << "排序后：" << std::endl;
    printList(l1);

    std::cout << "降序：" << std::endl;
    l1.sort(myCompare);  //降序排序
    printList(l1);
}

int main()
{
//    test01();
    test02();
    return 0;
}
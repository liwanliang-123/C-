/*
vector基本概念
功能:
    vector数据结构和数组非常相似，也称为单端数组

vector与普通数组区别:
    不同之处在于数组是静态空间，而vector可以动态扩展

动态扩展:
    并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间。

vector容器的迭代器是支持随机访问的迭代器
*/

#include <iostream>
#include <vector>

void printVector(std::vector<int>&v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

void test01()
{
//无参构造
    std::vector<int>v1;
    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector(v1);

//通过区间的方式进行构造
    std::vector<int>v2(v1.begin(), v1.end());
    printVector(v2);

// n个elem方式构造
    std::vector<int>v3(10, 100);  //v3初始化为 10 个 100
    printVector(v3);

//拷贝构造
    std::vector<int>v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}
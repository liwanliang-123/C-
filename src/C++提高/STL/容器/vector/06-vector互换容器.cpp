/*
    实现两个容器内元素进行互换
    
    作用：swap可以使两个容器互换，可以达到实用的收缩内存效果。
*/

#include <iostream>
#include <vector>

void printVector(std::vector<int> &v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::vector<int> v1;
    std::vector<int> v2;
    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    std::cout << "交换前: " << std::endl;
    printVector(v1);

    for (size_t i = 10; i < 20; i++) {
        v2.push_back(i);
    }
    printVector(v2);

    std::cout << "交换后: " << std::endl;
    v1.swap(v2);  //交换

    printVector(v1);
    printVector(v2);
}

//实际 用途
//巧用swap可以收缩内存空间
void test02()
{
    std::vector<int> v;
    for (size_t i = 0; i < 100000; i++) {
        v.push_back(i);
    }

    std::cout << "v 的容量 = " << v.capacity() << std::endl;
    std::cout << "v 的大小 = " << v.size() << std::endl;

    v.resize(3);  //重新指定大小

    std::cout << "v 的容量 = " << v.capacity() << std::endl;  //不会变化
    std::cout << "v 的大小 = " << v.size() << std::endl;

//  std::vector<int>(v)表示初始化一个匿名对象，并且将v传入调用了匿名对象的拷贝构造函数
//  这个对象会根据 v 实际的容量大小进行初始化，所以这个匿名对象的容量和大小都是3
//  然后调用 swap 函数将匿名对象的成员和 v 进行交换，这样 v 的容量和大小就变成了 3
//  通过拷贝构造初始化的容器好像容量等于大小，具体如 test3() 函数
    std::vector<int>(v).swap(v);

//交换之后容量大小都相等
    std::cout << "v 的容量 = " << v.capacity() << std::endl;
    std::cout << "v 的大小 = " << v.size() << std::endl;
}

void test03()
{
    std::vector<int> v1;
    for (size_t i = 0; i < 5; i++) {
        v1.push_back(i);
    }

    std::cout << "v1 的容量 = " << v1.capacity() << std::endl;
    std::cout << "v1 的大小 = " << v1.size() << std::endl;

    std::vector<int> v2(v1);  //v2调用拷贝构造进行初始化

    std::cout << "v2 的容量 = " << v2.capacity() << std::endl;
    std::cout << "v2 的大小 = " << v2.size() << std::endl;
}

int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}
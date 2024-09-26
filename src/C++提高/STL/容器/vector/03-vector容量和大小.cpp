/*
    对vector容器的容量和大小操作

    判断是否为空——empty
    返回元素个数——size
    返回容器容量——capacity
    重新指定大小——resize
*/

#include <iostream>
#include <vector>

void printVector(std::vector<int> &v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

void test01()
{
    std::vector<int> v1;
    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    if (v1.empty()) {
        std::cout << "v1 为空" << std::endl;
    } else {
        std::cout << "v1 不为空" << std::endl;
    }

    // v1 的容量和大小
    std::cout << "v1 的容量 = " << v1.capacity() << std::endl;
    std::cout << "v1 的大小 = " << v1.size() << std::endl;

    // 重新指定大小
    v1.resize(15);      // 如果重新指定的比原来的长，默认用0填充
    v1.resize(15, 100); // 利用重载版本，可以指定默认填充值
    std::cout << "v1 的大小 = " << v1.size() << std::endl;
    printVector(v1);

    v1.resize(5); //如果重新指定的比原来短，超出的部分会删除掉
    std::cout << "v1 的大小 = " << v1.size() << std::endl;
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}
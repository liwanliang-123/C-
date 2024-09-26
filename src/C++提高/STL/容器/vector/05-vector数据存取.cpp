/*
    对vector中的数据进行存取操作

    除了用迭代器获取vector中元素，[]和at也可以
    front返回容器第一个元素
    back返回容器最后一个元素
*/

#include <iostream>
#include <vector>

void test01()
{
    std::vector<int> v1;
    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }
//	利用[]访问数组中的元素
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
// 	利用at方式访问元素
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1.at(i) << " ";
    }
    std::cout << std::endl;

//  获取第一个元素
    std::cout << v1.front() << std::endl;
//  获取最后一个元素
    std::cout << v1.back() << std::endl;
}

int main()
{
    test01();
    return 0;
}
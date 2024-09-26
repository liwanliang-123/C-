/*
    对vector容器进行插入、删除操作

    尾插——push_back
    尾删——pop_back
    插入——insert(位置迭代器)
    删除——erase(位置迭代器)
    清空——clear
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
// 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

// 尾删
    v1.pop_back();
    v1.pop_back();
    printVector(v1);

// 插入
    v1.insert(v1.begin(), 100);  // 在最开始插入 100 ,但不是删除第一个数再插入
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);  //在最开始插入两个 1000
    printVector(v1);

// 删除, 参数也是迭代器
    v1.erase(v1.begin());  // 删除第一个数
    printVector(v1);

    // v1.erase(v1.begin(), v1.end());  // 重头到尾的删除,相当于清空
    // printVector(v1);

// 清空
    v1.clear();
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}
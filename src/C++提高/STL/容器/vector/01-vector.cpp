/*
Vector存放内置数据类型

 容器:vector
 算法:for_each
 迭代器:vector<int>::iterator
*/

#include<iostream>
#include<vector>
#include<algorithm>

//using namespace std;

void myPrint(int val)
{
    std::cout << val << std::endl;
}

void test01()
{
    std::vector<int> v;
//插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

//第一种访问方式：
//创建迭代器
    // std::vector<int>::iterator itBegin = v.begin();
    // std::vector<int>::iterator itEnd = v.end();

    // while(itBegin != itEnd) {
    //     std::cout << *itBegin << std::endl;
    //     itBegin++;
    // }

//第二种访问方式：
    // for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    //     std::cout << *it << std::endl;
    // }

//第三种遍历方式，标准算法
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}
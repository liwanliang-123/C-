/*
    给vector容器进行赋值
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
    std::vector<int>v1;
    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector(v1);

//赋值 operator= 
    std::vector<int>v2;
    v2 = v1;
    printVector(v2);

//assign
    std::vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

//n个elem方式赋值
    std::vector<int>v4;
    v4.assign(10, 100);  //赋值10个100
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}
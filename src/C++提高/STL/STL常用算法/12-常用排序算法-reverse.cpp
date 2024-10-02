/*
    将容器内元素进行反转。
*/

#include <iostream>
#include <vector>
#include <algorithm>

void myPrint(int val)
{
    std::cout << val << " ";
}

void test01()
{
    std::vector<int> v1;

    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    for_each(v1.begin(), v1.end(), myPrint);
    std::cout << std::endl;

//  反转
    reverse(v1.begin(), v1.end());

    for_each(v1.begin(), v1.end(), myPrint);
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
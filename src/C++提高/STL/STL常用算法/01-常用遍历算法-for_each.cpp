/*
    for_each
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 普通函数
void print01(int val)
{
    std::cout << val << " ";
}

// 仿函数
class print02 {
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};

void test01()
{
    std::vector<int> v1;

    for (size_t i = 0; i < 10; i++) {
        v1.push_back(i);
    }

//  for_each  普通函数
    for_each(v1.begin(), v1.end(), print01);
    std::cout << std::endl;

//  防函数
    for_each(v1.begin(), v1.end(), print02());  //  print02():汉
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
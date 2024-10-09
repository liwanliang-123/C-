/*
    互换两个容器的元素

    swap交换容器时，注意交换的容器是同种类型。
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Myprint {
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};

void test01()
{
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);

    std::vector<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);
    v2.push_back(400);
    v2.push_back(500);
    v2.push_back(600);

    std::cout << "交换前:" << std::endl;
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;
    for_each(v2.begin(), v2.end(), Myprint());
    std::cout << std::endl;

    swap(v1, v2);

    std::cout << "交换后:" << std::endl;
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;
    for_each(v2.begin(), v2.end(), Myprint());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
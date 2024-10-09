/*
    将容器内指定范围的旧元素修改为新元素。
    
    replace会替换区间内满足条件的所有元素。
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
    v1.push_back(70);
    v1.push_back(90);
    v1.push_back(90);

    std::cout << "替换前:" << std::endl;
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;

    replace(v1.begin(), v1.end(), 90, 900);  // 将90 替换成 900

    std::cout << "替换后:" << std::endl;
    for_each(v1.begin(), v1.end(), Myprint());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
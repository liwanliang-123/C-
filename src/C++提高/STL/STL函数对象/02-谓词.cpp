/*
概念:
    返回bool类型的仿函数称为谓词
    如果operator()接受一个参数，那么叫做一元谓词
    如果operator()接收两个参数，那么叫做二元谓词
*/

#include <iostream>
#include <vector>
#include <algorithm>

class CreaterFive {
public:
    bool operator()(int num)
    {
        return num > 5;
    }
};

void test01()
{
    std::vector<int> v;
    for (size_t i = 0; i < 10; i++) {
        v.push_back(i);
    }
    // 查找容器中是否有大于5的数
//    std::vector<int>::iterator it = find_if(v.begin(), v.end(), CreaterFive());
    auto it = find_if(v.begin(), v.end(), CreaterFive());  // 匿名函数对象
    if(it == v.end()) {
        std::cout << "没有找到" << std::endl;
    } else {
        std::cout << "找到了,数字为 = " << *it << std::endl;
    }
}

int main()
{
    test01();
    return 0;
}
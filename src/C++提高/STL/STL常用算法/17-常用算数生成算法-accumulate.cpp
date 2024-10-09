/*
    算数生成算法属于小型算法，使用时包含的头文件为#include< numeric >

    accumulate: 计算区间内容器元素累计总和
*/
#include <iostream>
#include <vector>
#include <numeric>

void test01()
{
    std::vector<int> v1;
    for (size_t i = 0; i <= 100; i++) {
        v1.push_back(i);
    }
    
    // 参数三表示初始累加值
    int total = accumulate(v1.begin(), v1.end(), 0);

    std::cout << "total = " << total << std::endl;
}

int main()
{
    test01();
    return 0;
}
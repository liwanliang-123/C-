/*
    查找指定元素是否存在。

    注意：二分查找法效率很高，值得注意的是查找的容器中元素必须得是有序序列，否则结果未知。
*/

#include <iostream>
#include <vector>
#include <algorithm>

void test01()
{
    std::vector<int> v;
    for (size_t i = 0; i < 10; i++) {
        v.push_back(i);
    }

//  查找是否有数字 5
    bool ret = binary_search(v.begin(), v.end(), 5);
    if(!ret) {
        std::cout << "没找到" << std::endl;
    }
    std::cout << "找到了" << std::endl;
}

int main()
{
    test01();
    return 0;
}
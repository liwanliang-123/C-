/*
    容器内指定范围的元素拷贝到另一容器中。
*/
#include <iostream>
#include <vector>
#include <algorithm>

void test01()
{
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    std::vector<int> v2;
    v2.resize(v1.size());  // 需要先指定大小

    copy(v1.begin(), v1.end(), v2.begin());

    for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}
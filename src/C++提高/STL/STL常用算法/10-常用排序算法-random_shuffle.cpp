/*
    洗牌 指定范围内的元素随机调整次序。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

void printVector(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::vector<int> v;
    for (size_t i = 0; i < 10; i++) {
        v.push_back(i);
    }
    
    printVector(v);

//  利用洗牌算法打乱顺序
    random_shuffle(v.begin(), v.end());
    printVector(v);
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    test01();
    return 0;
}
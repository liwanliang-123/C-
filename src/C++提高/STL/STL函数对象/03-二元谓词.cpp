#include <iostream>
#include <vector>
#include <algorithm>

class myCompare {
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void printVectot(std::vector<int> &v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;    
}

void test01()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(20);
    v.push_back(200);
    v.push_back(40);

    std::cout << "排序前：";
    printVectot(v);

//  标准算法排序默认按照从小到大排序
    std::cout << "标准算法排序后： ";
    sort(v.begin(), v.end());
    printVectot(v);

//  利用二元谓词从大到小排序
    std::cout << "二元谓词排序后： ";
    sort(v.begin(), v.end(), myCompare());  // myCompare(): 匿名对象
    printVectot(v);
}

int main()
{
    test01();
    return 0;
}
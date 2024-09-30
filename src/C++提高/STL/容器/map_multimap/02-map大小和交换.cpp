/*
    统计map容器大小以及交换map容器

    统计大小——size
    判断是否为空——empty
    交换容器——swap
*/

#include <iostream>
#include <map>

void printMap(std::map<int, int> &m)
{
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << "key = " << it->first << " <-> " << "value = " << \
                     it->second << std::endl;
    }
    std::cout << "-----------" << std::endl;
}

void test01()
{
    std::map<int, int> m1;
    m1.insert(std::pair<int, int>(1, 100));
    m1.insert(std::pair<int, int>(4, 400));
    m1.insert(std::pair<int, int>(5, 500));
    m1.insert(std::pair<int, int>(2, 200));
    m1.insert(std::pair<int, int>(3, 300));

//  map size
    std::cout << "m1 size = " << m1.size() << std::endl;

//  empty
    if(m1.empty()) {
        std::cout << "m1 空" << std::endl;
    } else {
        std::cout << "m1 不空" << std::endl;
    }

//  交换
    std::map<int, int> m2;
    m2.insert(std::pair<int, int>(6, 600));
    m2.insert(std::pair<int, int>(10, 1000));
    m2.insert(std::pair<int, int>(8, 800));
    m2.insert(std::pair<int, int>(7, 700));
    m2.insert(std::pair<int, int>(9, 900));

    std::cout << "交换前: " << std::endl;
    printMap(m1);
    printMap(m2);

    m1.swap(m2);

    std::cout << "交换后: " << std::endl;
    printMap(m1);
    printMap(m2);
}

int main()
{
    test01();
    return 0;
}
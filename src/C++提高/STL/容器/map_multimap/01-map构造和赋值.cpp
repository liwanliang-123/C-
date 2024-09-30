/*
    对map容器进行构造和赋值操作

    总结：map中所有元素都是成对出现，插入数据时要使用对组。
*/

#include <iostream>
#include <map>

void printMap(std::map<int, int> &m)
{
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        std::cout << (*it).first << " <-> " << (*it).second << std::endl;
    }
    std::cout << "-----------" << std::endl;
}

void test01()
{
//  默认构造
    std::map<int, int> m1;
    m1.insert(std::pair<int, int>(1, 100));
    m1.insert(std::pair<int, int>(2, 200));
    m1.insert(std::pair<int, int>(4, 400));
    m1.insert(std::pair<int, int>(5, 500));
    m1.insert(std::pair<int, int>(3, 300));

    printMap(m1);

//  拷贝构造
    std::map<int, int> m2(m1);
    printMap(m2);

//  等号赋值
    std::map<int, int> m3 = m2;
    printMap(m3);
}

int main()
{
    test01();
    return 0;
}
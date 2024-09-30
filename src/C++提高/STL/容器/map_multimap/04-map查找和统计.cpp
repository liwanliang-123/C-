/*
    对map容器进行查找和数据以及统计数据

    查找——find(返回的是迭代器)
    统计——cout(对于map,结果为0或1)
*/

#include <iostream>
#include <map>

void printMap(std::map<int, int> &m)
{
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << "key = " << it->first << " <-> " <<  \
            "value = " << it->second << std::endl;
    }
}

void test01()
{
    std::map<int, int> m1;
    m1.insert(std::pair<int, int>(1, 10));
    m1.insert(std::pair<int, int>(2, 20));
    m1.insert(std::pair<int, int>(3, 30));

//  find 返回迭代器
    std::map<int, int>::iterator it = m1.find(2);
    if(it != m1.end()) {
        std::cout << "find OK" << std::endl;
        std::cout << "key = " << it->first << "value = " << it->second << std::endl;
    } else {
        std::cout << "find NO" << std::endl;
    }

//  count
//map不允许插入重复key,0 or 1
//multimap可以大于1，可以重复
    int num = m1.count(1);
    std::cout << "num = " << num << std::endl;
}

int main()
{
    test01();
    return 0;
}
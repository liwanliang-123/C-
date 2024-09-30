/*
    map容器进行插入数据和删除数据
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

//  插入
//  第一种
    m1.insert(std::pair<int, int>(1, 100));

//  第二种
    m1.insert(std::make_pair(2, 200));

//  第三种
    m1.insert(std::map<int, int>::value_type(3, 300));

//  第四种
//  不建议这种，用途是利用key访问到value,不存在会自动创建，所以应该确定存在再访问
//  但可以通过这种方式访问
    m1[4] = 400;
    //std::cout << m1[5] << std::endl;
    printMap(m1);

//  删除
    m1.erase(m1.begin());   // 根据迭代器删除
    std::cout << "-----删除-----" << std::endl;
    printMap(m1);

    std::cout << "===" << std::endl;

//  根据 key 进行删除
    m1.erase(2);
    printMap(m1);

    std::cout << "===" << std::endl;

//  清空
    m1.erase(m1.begin(), m1.end());
    printMap(m1);

    std::cout << "===" << std::endl;

    m1.clear();
}

int main()
{
    test01();
    return 0;
}
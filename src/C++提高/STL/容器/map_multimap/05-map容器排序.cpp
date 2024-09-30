/*
    map容器默认排序规则为按照key值进行从小到大排序，掌握如何改变排序规则。

    利用仿函数可以指定map容器的排序规则
    对于自定义数据类型，map必须要指定排序规则，同set容器
*/

#include <iostream>
#include <map>

class myCompare {
public:
	bool operator()(int v1,int v2)const {
		return v1 > v2;
	}
};

void printMap(std::map<int, int, myCompare> &m)
{
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << "key = " << it->first << " <-> " <<  \
            "value = " << it->second << std::endl;
    }
}

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
    m1.insert(std::make_pair(1, 10));
    m1.insert(std::make_pair(4, 40));
    m1.insert(std::make_pair(5, 50));
    m1.insert(std::make_pair(2, 20));
    m1.insert(std::make_pair(3, 30));

//  默认按照 Key 从小到大排序
    printMap(m1);

    std::map<int, int, myCompare> m2;
    m2.insert(std::make_pair(8, 80));
    m2.insert(std::make_pair(6, 60));
    m2.insert(std::make_pair(9, 90));
    m2.insert(std::make_pair(7, 70));
    m2.insert(std::make_pair(10, 100));

//  通过仿函数实现从大到小了
    printMap(m2);
}

int main()
{
    test01();
    return 0;
}
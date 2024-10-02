/*
    查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//  查找内置数据类型
void test01()
{
    std::vector<int> v;
    for (size_t i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //  查找容器中是否有 5 这个元素
    std::vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if(it == v.end()) {
        std::cout << "没有找到" << std::endl;
    } else {
        std::cout << "找到了"  << *it << std::endl;
    }
}

class Person {
public:
    Person(int age, std::string name)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

//  重载 == 运算符
    bool operator==(const Person &p)
    {
        if(this->m_Age == p.m_Age && this->m_Name == p.m_Name) {
            return true;
        } else {
            return false;
        }
    }

    int m_Age;
    std::string m_Name;
};

//查找自定义数据类型
void test02()
{
    std::vector<Person> v;
    Person p1(10, "AAA");
    Person p2(10, "BBB");
    Person p3(10, "CCC");
    Person p4(10, "DDD");
    Person p5(10, "EEE");

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    auto it = find(v.begin(), v.end(), p3);
    //std::vector<Person>::iterator it = find(v.begin(), v.end(), p3);
    if(it == v.end()) {    //  == 需要重载
        std::cout << "没有找到" << std::endl;
    } else {
        std::cout << "找到了" << std::endl;
        std::cout << "name = " << it->m_Name << std::endl;
        std::cout << "age = " << it->m_Age << std::endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}
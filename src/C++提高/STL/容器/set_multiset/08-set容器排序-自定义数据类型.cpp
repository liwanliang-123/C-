/*
    set容器默认排序规则为从小到大，掌握如何改变排序规则。

    主要技术点：利用仿函数，可以改变排序顺序
*/

#include <iostream>
#include <string>
#include <set>

class Person {
public:
    Person(std::string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    ~Person(){}

    int m_Age;
    std::string m_Name;
};

class myCompare {
public:
    bool operator()(const Person &v1, const Person &v2)const
    {
        return v1.m_Age > v2.m_Age;    // 从大到小排序
    }
};

void printSet(std::set<Person, myCompare> &s)
{
    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << "name =  " << it->m_Name << "age =  " << it->m_Age << std::endl;
    }
}

void test01()
{
    std::set<Person, myCompare> sp;
    Person P1("AAA", 100);
    Person P2("BBB", 230); 
    Person P3("CCC", 50); 
    Person P4("DDD", 70); 
    Person P5("EEE", 90); 

    sp.insert(P1);
    sp.insert(P2);
    sp.insert(P3);
    sp.insert(P4);
    sp.insert(P5);

    printSet(sp);
}

int main()
{
    test01();
    return 0;
}
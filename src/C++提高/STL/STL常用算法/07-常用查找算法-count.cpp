/*
    统计元素个数。

    统计自定义数据类型时候，需要配合重载operator==
*/
#include <iostream>
#include <vector>
#include <algorithm>

// 统计内置数据类型
void test01()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(70);
    v.push_back(40);
    v.push_back(10);
    v.push_back(90);
    v.push_back(40);
    v.push_back(60);
    v.push_back(90);

//  40 的元素个数
    int num = count(v.begin(), v.end(), 40);
    std::cout << "40 的元素个数为：" << num << std::endl;
}


class Person {
public:
    Person(std::string name, int age)
    {
        this->age = age;
        this->name = name;
    }

//  重载 == 
    bool operator==(const Person &p)
    {
        if(this->age == p.age) {
            return true;
        } else {
            return false;
        }
    }
    std::string name;
    int age;    
};

// 统计自定义数据类型
void test02()
{
    std::vector<Person> v;

    Person p1("AAA", 10);
    Person p2("BBB", 10);
    Person p3("CCC", 50);
    Person p4("DDD", 70);
    Person p5("EEE", 20);
    Person p6("FFF", 10);
    Person p7("GGG", 90);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);

    Person P("KKK", 10);

//  查一查和 P 年龄差不多的人有多少个
    int num = count(v.begin(), v.end(), P);
    std::cout << "和 KKK 一样大的 = " << num << std::endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}
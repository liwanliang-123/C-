/*
    按条件统计元素个数。
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Greater20 {
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};

// 统计内置数据类型
void test01()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(70);
    v.push_back(40);

//  统计有多少个大于 20 的数
    int num = count_if(v.begin(), v.end(), Greater20());
    std::cout << "大于20的元素个数为:" << num << std::endl;
}

class Person {
public:
    Person(std::string name, int age)
    {
        this->age = age;
        this->name = name;
    }
    std::string name;
    int age;    
};

class AgeGreater20 {
public:
    bool operator()(const Person &p)
    {
        return p.age > 20;
    }
};

// 统计自定义数据类型
void test02()
{
    std::vector<Person> v;

    Person p1("AAA", 10);
    Person p2("BBB", 10);
    Person p3("CCC", 50);
    Person p4("DDD", 70);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

//  统计大于 20 岁的人员个数
    int num = count_if(v.begin(), v.end(), AgeGreater20());
    std::cout << "大于 20 岁的人员个数 = " << num << std::endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}
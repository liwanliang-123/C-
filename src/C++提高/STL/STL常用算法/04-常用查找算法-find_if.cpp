/*
    按条件查找元素。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class GreaterFive {
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

// 查找内置数据类型
void test01()
{
    std::vector<int> v;
    for (size_t i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //  查找是否有大于 5 的数
    std::vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if(it == v.end()) {
        std::cout << "没有找到" << std::endl;
    } else {
        std::cout << "找到了 " << *it << std::endl;
    }
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

class Greater20 {
public:
    bool operator()(const Person &p)
    {
        return p.age >20;
    }
};

// 查找自定义数据类型
void test02()
{
    std::vector<Person> vp;
    Person p1("AAA", 10);
    Person p2("AAA", 20);
    Person p3("AAA", 30);
    Person p4("AAA", 40);
    Person p5("AAA", 50);

    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);
    vp.push_back(p5);

//  找年龄大于 20 的人员
    std::vector<Person>::iterator it = find_if(vp.begin(), vp.end(), Greater20());
    if(it == vp.end()) {
        std::cout << "没有找到" << std::endl;
    } else {
        std::cout << "找到了" << std:: endl;
        std::cout << "age = " << it->age << std::endl;
        std::cout << "name = "<< it->name << std::endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}
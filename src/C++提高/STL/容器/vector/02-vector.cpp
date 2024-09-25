/*
  Vector存放自定义数据类型
*/

#include<iostream>
#include<vector>
#include<string>

class Person {
public:
    Person(int age, std::string name);
    ~Person();

    int m_Age;
    std::string m_Name;
};

Person::Person(int age, std::string name)
{
    this->m_Age = age;
    this->m_Name = name;
}

Person::~Person() {}

void test01()
{
//创建容器
    std::vector<Person> v;
//初始化
    Person P1(10, "aaaa");
    Person P2(20, "bbbb");
    Person P3(30, "cccc");

    v.push_back(P1);
    v.push_back(P2);
    v.push_back(P3);

//遍历容器
// 在这里 *it 的类型为 Person
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        // std::cout << "name:" << (*it).m_Name << "  age:" << (*it).m_Age << std::endl;
        std::cout << "name:" << it->m_Name << "  age:" << it->m_Age << std::endl;
    }
}

void test02()
{
//创建容器
    std::vector<Person*> v;
//初始化
    Person P1(10, "aaaa");
    Person P2(20, "bbbb");
    Person P3(30, "cccc");

    v.push_back(&P1);
    v.push_back(&P2);
    v.push_back(&P3);
// it 可以看作一个指针，而 *it 就是取指针的内容
// *it 的类型和 vector<Person*> 中 <>中的内容相同，在这里 *it 的类型为 Person*
    for (std::vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << "name = " << (*it)->m_Name << "age = " << (*it)->m_Age << std::endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}
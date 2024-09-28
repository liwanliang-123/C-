/*
    案例描述：将Person自定义类型进行排序，Person中属性有姓名、年龄、身高。
    排序规则：按照年龄进行升序，如果年龄相同则按照身高进行降序
*/

#include <iostream>
#include <list>
#include <string>

class Person {
friend bool comparePerson(Person &p1, Person &p2);
friend void printList(std::list<Person> &l);
public:
    Person(std::string name, int age, int height)
    {
        this->m_Age = age;
        this->m_Height = height;
        this->m_Name = name;
    }
    ~Person(){}
private:
    int m_Age;
    int m_Height;
    std::string m_Name;
};

void printList(std::list<Person> &l)
{
    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << "name = " << (*it).m_Name << "  " << "age = "  \
            << (*it).m_Age << "  " << "height = " << (*it).m_Height << std::endl;
    }
    std::cout << std::endl;
}

//  指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
    //  按照年龄进行升序
    if (p1.m_Age == p2.m_Age) {
        //年龄相同，按照身高进行排序
        return p1.m_Height > p2.m_Height;  // 升高降序
    } else {
        //  按照年龄进行升序
        return p1.m_Age < p2.m_Age;
    }
}

void test01()
{
    std::list<Person> l;

    Person P1("AAA", 34, 180);
    Person P2("BBB", 39, 110);
    Person P3("CCC", 34, 190);
    Person P4("DDD", 40, 135);
    Person P5("EEE", 53, 189);

    l.push_back(P1);
    l.push_back(P2);
    l.push_back(P3);
    l.push_back(P4);
    l.push_back(P5);

    std::cout << "排序前： " << std::endl;
    printList(l);

//  排序
    l.sort(comparePerson);
    std::cout << "排序后： " << std::endl;
    printList(l);
}

int main()
{
    test01();
    return 0;
}
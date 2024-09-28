/*
    入队——push
    出队——pop
    返回队头元素——front
    返回队尾元素——back
    判断队是否为空——empty
    返回队列大小——size
*/

#include <iostream>
#include <queue>

class Person {
friend void test01();
public:
    Person(int age, std::string name)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    ~Person(){}

private:
    int m_Age;
    std::string m_Name;
};

void test01()
{
    std::queue<Person> q;

    Person p1(10, "aaa");
    Person p2(20, "bbb");
    Person p3(30, "ccc");
    Person p4(40, "ddd");
    Person p5(50, "eee");

    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    q.push(p5);

    //只要 queue 不为空，则查看头和尾，出队
    while (!q.empty()) {
        std::cout << "队头: name = " << q.front().m_Name<< " " << "age = " << q.front().m_Age << std::endl;
        std::cout << "队尾: name = " << q.back().m_Name << " " << "age = " << q.back().m_Age << std::endl;
        q.pop();  //出队
    }
    std::cout << "queue size = " << q.size() << std::endl;
}

int main()
{
    test01();
    return 0;
}
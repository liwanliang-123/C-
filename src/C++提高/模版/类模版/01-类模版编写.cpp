#include <iostream>
#include <string>

using namespace std;

//类模版
template<class ageType, class nameType>
class Person {
public:
    Person(nameType name, ageType age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    void showInfo()
    {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
    }

    nameType m_Name;
    ageType m_Age;
};

void test01()
{
    Person<int, string> P("lwl", 18);
    P.showInfo();
}

int main()
{
    test01();
    return 0;
}
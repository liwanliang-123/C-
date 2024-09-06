#include <iostream>

using namespace std;

class Person {
public:
    Person(string name, int age)
    {
        this->age = age;
        this->name = name;
    }
    string name;
    int age;
};

//两个数比较的模版
template<typename T>
bool compare(T &a, T &b)
{
    return a==b ? true : false;
}

void test01()
{
    int a = 10;
    int b = 20;
    bool ret = compare(a,b);
    if(!ret) {
        cout << "a != b" << endl;
    } else {
        cout << "a == b" << endl;
    }
}

//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<> bool compare(Person &p1, Person &p2)
{
	return (p1.name == p2.name && p1.age == p2.age) ? true : false;
}

void test02()
{
    Person P1("Tom" ,10);
    Person P2("Tom" ,20);
    bool ret = compare(P1,P2); //这里直接传入 Person 数据类型编译器是推不出模版 T 的数据类型的，所以这里需要用到运算符重载
    if(!ret) {
        cout << "P1 != P2" << endl;
    } else {
        cout << "P1 == P2" << endl;
    }
}

int main()
{
    // test01();
    test02();

    return 0;
}
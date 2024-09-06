// 类模板与函数模板区别主要有两点：
//     1.类模板没有自动类型推导的使用方式；
//     2.类模板在模板参数列表中可以有默认参数。

#include <iostream>
#include <string>

using namespace std;

template<class nameType = string, class ageType = int>  //类模版这里可以有默认参数
class Person {
public:
    Person(nameType name, ageType age)
    {
        this->age = age;
        this->name = name;
    }

    void showInfo()
    {
        cout << "name = " << this->name << endl;
        cout << "age = " << this->age << endl;
    }

    ageType age;
    nameType name;
};

void test01()
{
    //Person P("Tom", 18);  //自动类型推导在类模版中无法使用
    Person<string, int> P("Tom", 18);  //显示指定类型才能实例化对象
    P.showInfo();
}

void test02()
{
    Person<> P("Tom1", 100); //在声明类的时候已经指定了参数的数据类型，这里可不再指定
    P.showInfo();
}

int main()
{
    // test01();
    test02();
    return 0;
}
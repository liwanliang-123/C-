// 菱形继承概念：
//     两个派生类继承同一个基类；
//     又有某个类同时继承这两个派生类；
//     这种继承被称为菱形继承，或者钻石继承。

/*             动物
              /    \
            羊       驼
               \   /
                羊驼
*/

// 菱形继承问题：
//     羊继承了动物的数据，驼同样继承了动物的数据，当羊驼使用数据时，就会产生二义性。
//     羊驼继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。

// 总结：
//      菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费并且毫无意义；
//      利用虚继承可以解决菱形继承问题。

#include <iostream>

using namespace std;

//虚基类
class Animal {
public:
    int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheet : virtual public Animal {};
class Camel : virtual public Animal {};
class SheetCamel : public Camel ,public Sheet {};

void test01()
{
    SheetCamel sc;

    //sc.m_Age = 100;  //不能这样写，因为 m_Age 有两份数据
    sc.Camel::m_Age = 120;
    sc.Sheet::m_Age = 300; //使用 virtual 之后数据就只有一份，最后的值是以最后一次赋值的结果为准

    cout << "Sheet m_Age = " << sc.Sheet::m_Age << endl; //羊的 m_Age
    cout << "Camel m_Age = " << sc.Camel::m_Age << endl; //驼的 m_Age

//但是羊驼 SheetCamel 应该多少岁呢？ 那就用到了 virtual 关键字了
//直接在 Sheet 和 Camel 加上 virtual 关键字
//当使用 virtual 之后数据就只有一份了
    cout << "SheetCamel m_Age = " << sc.m_Age << endl; //使用 virtual 之后也可以这样访问 m_Age 了
}

int main()
{
    test01();
    return 0;
}

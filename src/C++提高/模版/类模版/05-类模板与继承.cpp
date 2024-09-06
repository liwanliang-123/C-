// 当类模板碰到继承时，需要注意以下几点：
//         1、当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型；
//         2、如果不指定，编译器无法给子类分配内存；
//         3、如果想灵活指定出父类中T的类型，子类也需变为类模板。

#include <iostream>

using namespace std;

template<class T>
class Base {
public:
    T a;
};

// class Son : public Base {     //错误：必须要知道父类中的数据类型才能继承给之类
class Son1 : public Base<int> {   //正确，明确了父类中 T 的类型
public:

};

//如果想灵活指定出父类中T的类型，子类也需变为类模板。
template<class T1, class T2>
class Son2 : public Base<T2> {
public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
    }
};

void test01()
{
    Son2<char, int> son;  //这里创建 Son2 的时候将数据类型传到了 Son2 类中，即 char 传入 T1, int 传入 T2
                        // 当 T2 = int 时，也就指定了父类中 T 的数据类型
}

int main()
{
    test01();
    return 0;
}
//多态满足条件：
//      1、有继承关系
//      2、子类重写父类中的虚函数，即 Animal::speack() 被 Cat::speack() 重写了
//多态使用：
//      父类指针或引用指向子类对象


// 总结：
// 多态满足条件：
//      有继承关系；
//      子类重写父类中的虚函数。
// 多态使用条件：
//      父类指针或引用指向子类对象。


// 重写：函数返回值类型、函数名、参数列表完全一致称为重写。

#include <iostream>

using namespace std;

class Animal {
public:
    virtual void speack(); //加上 virtual 就是虚函数了
};

void Animal::speack()
{
    cout << "Animal speack" << endl;
}

class Cat : public Animal {
public:
    void speack();
};

void Cat::speack()
{
    cout << "Cat speack" << endl;
}

//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
void doSpeack(Animal &animal) //父类引用接收子类对象,即 Animal &animal = cat
{
    animal.speack();  //这里打印的是 Animal speack 因为该函数地址早绑定了，即静态联编
                      //如果需要打印 Cat speack 则需要在运行时绑定，即动态联编，地址晚绑定
                      //解决方法就是在 Animal::speack() 函数前面加上 virtual 关键字
}

void test01()
{
    Cat cat;
    doSpeack(cat);
}

int main()
{
    test01();
    return 0;
}


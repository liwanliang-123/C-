// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码。

// 解决方式：将父类中的析构函数改为虚析构或者纯虚析构。

// 虚析构和纯虚析构共性：
//     可以解决父类指针释放子类对象；
//     都需要有具体的函数实现。

// 虚析构和纯虚析构区别：
//      如果是纯虚析构，该类属于抽象类，无法实例化对象。

// 虚析构语法：
// virtual ~类名(){}

// 纯虚析构语法：
// virtual ~类名() = 0; //声明

// 总结：
//      虚析构或纯虚析构就是用来解决通过父类指针释放子类对象；
//      如果子类中没有堆区数据，可以不写为虚析构或纯虚析构；
//      拥有纯虚析构函数的类也属于抽象类。

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:

    Animal()
    {
        cout << "Animal 构造函数" << endl;
    }

//析构函数加上virtual关键字，变成虚析构函数
//虚析构函数，为了调用子类的析构函数
    // virtual ~Animal()
    // {
    //     cout << "Animal 析构函数" << endl;
    // }

//纯虚析构函数
    virtual ~Animal() = 0;

    virtual void speak() = 0;
};

//纯虚析构需要声明和定义
//如果类中有纯虚析构，类也就变成了抽象类
Animal::~Animal()
{
    cout << "Animal 纯析构函数" << endl;
}

class Cat : public Animal {
public:
    void speak()
    {
        cout << "cat 构造函数" << endl;
        cout << *m_Name << "cat speak" << endl;
    }

    Cat(string name)
    {
        this->m_Name = new string(name);
    }
    ~Cat()
    {
        cout << "cat 析构函数" << endl;
        if(m_Name != NULL) {
            delete m_Name;
            m_Name == NULL;
        }
    }

    string *m_Name;
};

void test01()
{
    Animal *a = new Cat("Tom");
    a->speak();
	/*
	通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	怎么解决？给父类增加一个虚析构函数
	虚析构函数就是用来解决通过父类指针释放子类对象
	*/
    delete(a);
}

int main()
{
    test01();
    return 0;
}

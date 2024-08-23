// 深浅拷贝是面试经典问题，也是常见的一个坑。

//     浅拷贝：简单的赋值拷贝操作；
//     深拷贝：在堆区重新申请空间，进行拷贝操作。

//总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题。

#include <iostream>
using namespace std;

class Person {
public:
    Person()
    {
        cout << "无参构造函数被调用" << endl;
    }
    Person(int age, int hight)
    {
        cout << "有参构造函数被调用" << endl;
        A_ge = age;
        H_eight = new int(hight); //在堆区开辟空间,由用户开辟和释放空间
    }
//自己实现一个拷贝构造函数来解决浅拷贝带来的问题
    Person(const Person &P)
    {
        cout << "拷贝构造函数被调用" << endl;
        A_ge = P.A_ge;
        //H_eight = P.H_eight; //这是编译器实现的代码
        //自己实现深拷贝操作
        H_eight = new int(*P.H_eight);
    }
    ~Person()
    {
        cout << "析构函数被调用" << endl;
        //将在堆区开辟的内存空间做释放作用；
        if(H_eight != NULL) {
            delete(H_eight);
            H_eight = NULL;
        }
    }

    int A_ge;
    int *H_eight;
};

void test01()
{
    Person P1(100, 180);
    cout << "P1.age = " << P1.A_ge << endl;
    cout << "P1.hight = " << *P1.H_eight << endl;

//如果Person里面的属性有指针，并使用默认的拷贝构造函数，会将指针指向的地址拷贝
//即是将 P1 中 H_eight 指向的地址拷贝给 P2 中的 H_eight ，如果P1中H_eight为0x0111,则P2的H_eight也是0x0111
//因为 P1和P2都会执行自己的析构函数，并且 H_eight指针都不为空，所以会释放两次堆区的空间，这也是浅拷贝的问题

//为了解决这个问题使用深拷贝来解决浅拷贝问题
//即自己写一个拷贝构造函数，自己再重新在堆区申请空间，这就是深拷贝
    Person P2(P1);
    cout << "P2.age = " << P2.A_ge << endl;
    cout << "P2.hight = " << *P2.H_eight << endl;
}

int main()
{
    test01();
    return 0;
}
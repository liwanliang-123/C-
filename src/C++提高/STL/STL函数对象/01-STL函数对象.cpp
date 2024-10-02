#include <iostream>
#include <string>

//  加法仿函数
class myAdd {
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

class myPrint {
public:
    myPrint()
    {
        this->count = 0;
    }

    void operator()(std::string s)
    {
        std::cout << s << std::endl;
        this->count++;
    }

    int count;
};

void test01()
{
//创建函数对象
//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
    myAdd ma;
    int ret = ma(10, 10);
    std::cout << ret << std::endl;
}

void test02()
{
//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
    myPrint mp;
    mp("hello");
    mp("world");

    std::cout << "函数调用次数为： " << mp.count << std::endl;
}

void do_print(myPrint mp, std::string s)
{
    mp(s);
}

void test03()
{
//  函数对象可以作为参数传递
    myPrint mp;
    do_print(mp, "hello C++");
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}
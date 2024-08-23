//作用： 通过重载递增运算符，实现自己的整型数据。

//总结： 前置递增返回引用，后置递增返回值。

#include <iostream>

using namespace std;

//自定义整型变量
class MyInteger {

friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger()
    {
        this->m_Num = 0;
    }

//重载前置 ++ 运算符
//返回 & 是为了一直对一个数操作，也就是一直对 m_Num 进行操作
    MyInteger &operator++()
    {
        this->m_Num++; //先进行 ++ 运算
        return *this;  //再将计算之后的this自身返回
    }

//重载后置 ++ 运算符
//这里为什么又是返回值而不是返回引用呢？
//因为这里返回的是局部变量 temp ,局部变量在函数结束后就释放了，如果返回引用就会出错
//所以这里是返回值
    MyInteger operator++(int) //int 表示占位参数，可以用来区分是前置递增还是后置递增，也必须写 int
    {
        //先记录当时的结果
        MyInteger temp = *this;
        //记录完后再递增
        this->m_Num++;
        //然后将记录的结果再返回
        return temp;
    }

private:
    int m_Num;
};

//重载左移运算符
ostream &operator<<(ostream &cout, MyInteger myint)
{
    cout << "myint = " << myint.m_Num;
    return cout;
}

//前置递增
void test01()
{
    MyInteger myint; //自定义数据类型
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

//后置递增
void test02()
{
    MyInteger myint; //自定义数据类型
    cout << myint++ << endl;
    cout << myint << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}
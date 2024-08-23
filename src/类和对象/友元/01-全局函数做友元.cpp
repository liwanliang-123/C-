//为了让一个全局函数访问一个类的私有成员
#include <iostream>
#include <string>

using namespace std;

class Building {

//告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
friend void goodGay(Building &build);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom; //客厅

private:
    string m_BedRoom;   //卧室
};

// 全局函数访问类的私有成员
void goodGay(Building &build)
{
    cout << build.m_SittingRoom << endl; //公共属性，类外也可以访问
    cout << build.m_BedRoom << endl;     //私有属性，类外不可访问，但可以通过 friend 关键字访问
}

void test01()
{
    Building build;
    goodGay(build);
}

int main()
{
    test01();

    return 0;
}


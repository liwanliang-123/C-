//为了让一个类访问另外一个类的私有成员
#include <iostream>
#include <string>

using namespace std;

class Building {

//告诉编译器：goodGay类是Building类的好朋友，可以访问到Building类中私有内容
friend class Goodgay;

public:
    Building();
    ~Building();

public:
    string m_SittingRoom; //客厅

private:
    string m_BedRoom;   //卧室
};

//类外写成员函数
Building::Building()
{
    m_SittingRoom = "building的客厅";
    m_BedRoom = "building的卧室";
}

Building::~Building()
{
}

class Goodgay{
public:

    Goodgay();
    ~Goodgay();
    void visit();  //参观函数，访问 Building 中的属性

   Building *build; 
};

Goodgay::Goodgay()
{
    //创建建筑物的对象
    build = new Building; //在堆区创建一个 Building 的对象，new什么数据类型就返回什么数据类型的指针
}

void Goodgay::visit()
{
    cout << build->m_SittingRoom << endl; //访问公共Building中的公共成员，可以访问
    cout << build->m_BedRoom << endl; //访问公共Building中的私有成员，不可以访问,但可以将 Goodgay 类添加到Building中
}

Goodgay::~Goodgay()
{
    delete(build);
}

void test01()
{
    Goodgay ga;
    ga.visit();
}

int main()
{
    test01();

    return 0;
}
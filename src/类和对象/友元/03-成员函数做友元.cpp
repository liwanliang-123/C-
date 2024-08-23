//为了让一个成员函数访问另外一个类的私有成员
#include <iostream>

using namespace std;

class Building;

class Goodgay {
public:
    Goodgay();
    ~Goodgay();
    void visit1();  //可以访问 Building 中的私有成员

    void visit2();  //不可以访问 Building 中的私有成员

    Building *build;
};

class Building {
//告诉编译器：goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
friend void Goodgay::visit1();

public:
    Building();
    ~Building();

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom;   //卧室
};

Goodgay::Goodgay()
{
    build = new Building; //调用的时候 Building 的构造函数就会被调用
}

void Goodgay::visit1()
{
    cout << "visit1: " << build->m_SittingRoom << endl; //访问Building中的公共成员，可以访问
    cout << "visit1: " << build->m_BedRoom << endl;  //可以访问 building 中的私有成员，因为 visit 在Building中有 friend 声明
}

void Goodgay::visit2()
{
    cout << "visit2: " << build->m_SittingRoom << endl;
    //cout << "visit2: "build->m_BedRoom << endl; //不能访问Building中的私有成员
}

Goodgay::~Goodgay()
{
    delete(build);
}

//类外实现成员函数
Building::Building()
{
    m_SittingRoom = "building的客厅";
    m_BedRoom = "building的卧室";
}

Building::~Building()
{
}

void test01()
{
    Goodgay ga;
    ga.visit1();
    ga.visit2();
}

int main()
{
    test01();
    return 0;
}
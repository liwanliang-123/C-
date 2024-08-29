// 案例描述:
//     制作饮品的大致流程为：煮水-冲泡-倒入杯中-加入辅料

// 利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶水。

#include <iostream>

using namespace std;

class Drinking {
public:
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSomething() = 0;
    //制作饮品
    void MakeDrinking()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

//制作咖啡
class Coffee : public Drinking {
public:
    //煮水
    void Boil()
    {
        cout << "煮咖啡水" << endl;
    }
    //冲泡
    void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    //倒入杯中
    void PourInCup()
    {
        cout << "咖啡倒入杯中" << endl;
    }
    //加入辅料
    void PutSomething()
    {
        cout << "咖啡加入辅料" << endl;
    }
};

//制作茶叶
class Tea : public Drinking {
public:
    //煮水
    void Boil()
    {
        cout << "煮茶水" << endl;
    }
    //冲泡
    void Brew()
    {
        cout << "冲泡茶" << endl;
    }
    //倒入杯中
    void PourInCup()
    {
        cout << "茶倒入杯中" << endl;
    }
    //加入辅料
    void PutSomething()
    {
        cout << "茶加入辅料" << endl;
    }
};

// void doWork(Drinking &dr) //父类指针指向子类对象
void doWork(Drinking *dr)
{
    dr->MakeDrinking();
    delete(dr);
}

void test01()
{
    Tea *t = new Tea;
    doWork(t);  //泡茶

    // Coffee c;
    // doWork(c);  //泡咖啡
}

int main()
{
    test01();
    return 0;
}
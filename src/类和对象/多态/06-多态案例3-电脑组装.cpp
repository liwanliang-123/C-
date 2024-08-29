// 案例描述:
//     电脑主要组成部件为CPU(用于计算)，显卡(用于显示)，内存条（用于存储)，
//     将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，
//     例如Intel厂商和Lenovo厂商创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口，
//     测试时组装三台不同的电脑进行工作。

#include <iostream>

using namespace std;

//抽象不同的零件
//抽象CPU
class CPU {
public:
    // 抽象计算函数
    virtual void calculate() = 0;
};

//抽象显卡
class VideoCard {
public:
    // 抽象计算函数
    virtual void display() = 0;
};

//抽象内存
class Memory {
public:
    // 抽象计算函数
    virtual void storage() = 0;
};

//电脑类
class Computer {
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)//创建第二台电脑的时候也就产生多态了，因为父类指针指向了子类对象，即CPU *cpu = new LenovoCpu 
    {
        this->cpu = cpu;
        this->vc = vc;
        this->mem = mem;
    }

    //提供析构函数释放三个零件
    ~Computer()
    {
        if(this->cpu != NULL) {
            delete this->cpu;
        }
        if(this->vc != NULL) {
            delete this->vc;
        }
        if(this->mem != NULL) {
            delete this->mem;
        }
    }

    //提供工作函数
    void work()
    {
        //让零件工作起来，调用相关接口
        this->cpu->calculate();
        this->vc->display();
        this->mem->storage();
    }

private:
    CPU *cpu;  //cpu 零件指针
    VideoCard *vc; //显卡零件指针
    Memory *mem;  //内存零件指针
};

//具体厂商
//Intel 厂商
class IntelCpu : public CPU {
public:
    void calculate() //重写虚函数
    {
        cout << "Intel CPU 开始计算" << endl;
    }
};

class IntelVideoCard : public VideoCard {
public:
    void display()
    {
        cout << "Intel display 开始显示" << endl;
    }
};

class IntelMemory : public Memory {
public:
    void storage()
    {
        cout << "Intel Memory 开始存储" << endl;
    }
};

//Lenovo 厂商
class LenovoCpu : public CPU {
public:
    void calculate() //重写虚函数
    {
        cout << "Lenovo CPU 开始计算" << endl;
    }
};

class LenovoVideoCard : public VideoCard {
public:
    void display()
    {
        cout << "Lenovo display 开始显示" << endl;
    }
};

class LenovoMemory : public Memory {
public:
    void storage()
    {
        cout << "Lenovo Memory 开始存储" << endl;
    }
};

//组装不同的电脑
void test01()
{
    //第一台电脑的零件 
    CPU *IntCpu = new IntelCpu; //父类指针指向子类对象
    VideoCard *IntVC = new IntelVideoCard;
    Memory *IntMem = new IntelMemory;

    //创建第一台电脑
    Computer *c1 = new Computer(IntCpu, IntVC, IntMem);
    //电脑开始工作函数
    c1->work();
    delete(c1);

    cout << "================================" << endl;

    //创建第二台电脑
    Computer *c2 = new Computer(new LenovoCpu, new IntelVideoCard, new LenovoMemory);
    //电脑开始工作函数
    c2->work();
    delete(c2);
}

int main()
{
    test01();
    return 0;
}
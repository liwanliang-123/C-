/*
 当复制或拷贝时，引用计数加1，当智能指针析构时，引用计数减1，
 如果计数为零，代表已经没有指针指向这块内存，就释放内存
*/
#include<iostream>
#include<memory>

using namespace std;

class Test {
public:
    Test() { cout << "Test func" << endl; }
    ~Test() { cout << "~Test func" << endl; }
    int getNum() { return this->Num; }
private:
    int Num = 100;
};

void test01()
{
    std::shared_ptr<Test> T1;
    std::shared_ptr<Test> T2(new Test);  //智能指针T2指向 new Test 返回的指针

    cout << "T1	use_count() = " << T1.use_count() << endl;  // 0
    cout << "T2	use_count() = " << T2.use_count() << endl;  // 1
    T1 = T2;  // 将T2的值赋给T1，T1和T2现在共享同一个对象
    cout << "T1	use_count() = " << T1.use_count() << endl;  // 2
    cout << "T2	use_count() = " << T2.use_count() << endl;  // 2

    std::shared_ptr<Test> T3(T2);   //T3 指向 T2 指针
    cout << "T1	use_count() = " << T1.use_count() << endl;  // 3
    cout << "T2	use_count() = " << T2.use_count() << endl;  // 3
    cout << "T3	use_count() = " << T3.use_count() << endl;  // 3

    // T1.reset();
    // T2.reset();
    // T3.reset();

    cout << T1.get() << endl;
    cout << T2.get() << endl;
    cout << T3.get() << endl;
//程序运行到这里 3个 sharead_ptr T1,T2,T3都共享同一个对象，即 new Test
}

int main()
{
    test01();
    return 0;
}
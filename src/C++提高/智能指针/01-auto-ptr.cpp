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

int main()
{
//    Test *test = new Test;

// 定义智能指针
    std::auto_ptr<Test> test(new Test);
    cout << test.get() << endl;

    return 0;
}
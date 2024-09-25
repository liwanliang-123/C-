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
    std::unique_ptr<Test> T1(new Test);
    std::unique_ptr<Test> T2(new Test);
    // std::auto_ptr<Test> T1(new Test);
    // std::auto_ptr<Test> T2(new Test);

    cout << "T1.get = " << T1.get() << endl;
    cout << "T2.get = " << T2.get() << endl;
    T1 = std::move(T2);
    cout << "T1.get = " << T1.get() << endl;
    cout << "T2.get = " << T2.get() << endl;

    cout << T1->getNum() << endl;

    return 0;
}
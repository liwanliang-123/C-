#include <iostream>
#include <memory>

class Test {
public:
    Test() { std::cout << "Test constructed" << std::endl; }
    Test(int a) { std::cout << "a = " << a << std::endl; }
    ~Test() { std::cout << "~Test destroyed" << std::endl; }
    void greet() { std::cout << "Hello from Test" << std::endl; }
};

void test01()
{
    //std::unique_ptr<Test> test(new Test);
    //std::unique_ptr<Test> test = std::make_unique<Test>();
    std::unique_ptr<Test> test = std::make_unique<Test>(10);

    std::cout << test.get() << std::endl;
    test->greet();
}

void test02()
{
    std::unique_ptr<int> t1 = std::make_unique<int>();
    std::unique_ptr<int> t2 = std::make_unique<int>(102);

    std::cout << "t1 = " << *t1 << std::endl;
    std::cout << "t2 = " << *t2 << std::endl;
    std::cout << "t1 ptr = " << t1.get() << std::endl;
    std::cout << "t2 ptr = " << t2.get() << std::endl;

    t1 = std::move(t2);

    std::cout << "t1 ptr = " << t1.get() << std::endl;
    std::cout << "t2 ptr = " << t2.get() << std::endl;
    std::cout << "t1 = " << *t1 << std::endl;
    std::cout << "t2 = " << *t2 << std::endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}
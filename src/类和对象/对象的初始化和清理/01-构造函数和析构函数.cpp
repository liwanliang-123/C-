#include<iostream>
using namespace std;

class Person
{
public:
	//构造函数
	Person()
	{
		cout << "Person的构造函数调用" << endl;
	}

	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

void test()
{
	Person p;
}

int main()
{
	test();

	return 0;
}

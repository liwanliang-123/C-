#include<iostream>
using namespace std;

//三种权限
//公共权限 public 类内可以访问 类外可以访问
//保护权限 protected 类内可以访问 类外不可以访问
//私有权限 private 类内可以访问 类外不可以访问

class Person
{
public:
	//姓名 公共权限
	string m_Name;
protected:
	//汽车 保护权限
	string m_Car;
private:
	//银行卡密码 私有权限
	int m_Password;
public:
	void func()  //类内部可以访问
	{
		m_Name = "张三";
		m_Car = "宝马";
		m_Password = 123456;
	}
};

int main()
{
	Person p;
	p.m_Name = "李四";
	// p.m_Car = "奔驰"; //保护权限类外访问不到
	// p.m_Password = 123; //私有权限类外访问不到

	return 0;
}

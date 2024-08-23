// 优点：

// 将所有成员属性设置为私有，可以自己控制读写权限；
// 对于写权限，我们可以检测数据的有效性。

#include<iostream>
using namespace std;

class Person 
{
public:
//公有方法
	//姓名设置可读可写
	void setName(string name)
	{
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}
	//设置年龄
	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			cout << "年龄不正确！" << endl;
			return;
		}
		m_Age = age;
	}

	//情人设置为只写
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
//私有属性
	string m_Name;   //可读可写 姓名
	int m_Age;      //可读可写 年龄
	string m_Lover; //只写 情人
};

int main()
{
	Person p;
	//姓名设置
	p.setName("张三");
	cout << "姓名： " << p.getName() << endl;

	//年龄设置
	p.setAge(50);
	cout << "年龄： " << p.getAge() << endl;

	//情人设置
	p.setLover("小花");
	//cout << "情人： " << p.m_Lover << endl; //只写属性，不可以读取

	return 0;
}

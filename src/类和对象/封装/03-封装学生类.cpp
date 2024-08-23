//示例2：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号。

#include<iostream>
using namespace std;

//学生类
class Student
{  
//类中的属性和行为统一称为成员
public:
//成员函数 or 成员方法
	void setName(string name)
	{
		m_name = name;
	}
	void setID(int id)
	{
		m_id = id;
	}
	void showStudent()
	{
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
//成员属性 or 成员变量
	string m_name;
	int m_id;
};

int main()
{
	Student stu1;

	stu1.setName("小强");
	stu1.setID(1);
	stu1.showStudent();

    Student stu2;

    stu2.setName("小刘");
    stu2.setID(2);
	stu2.showStudent();

	return 0;
}

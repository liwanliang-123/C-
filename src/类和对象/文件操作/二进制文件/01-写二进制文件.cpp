// 二进制方式写文件主要利用流对象调用成员函数write。

// 函数原型 ：ostream& write(const char * buffer,int len);
// 参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数。


//总结：文件输出流对象，可以通过write函数，以二进制方式写数据。

#include<iostream>
#include<fstream> //1.包含头文件
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test01()
{
	//2.创建流对象
	ofstream ofs("person.txt", ios::out | ios::binary);
	//3.打开文件
	//ofs.open("person.txt",ios::out | ios::binary);

	//4.写文件
	Person p = { "张三",18 };
	ofs.write((const char*)&p,sizeof(Person));

	//5.关闭文件
	ofs.close();
}

int main()
{
	test01();

	return 0;
}
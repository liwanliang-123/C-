#include <iostream>

using namespace std;

class BasePage {
public:
    void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};

class Java : public BasePage {
public:
	void content()
	{
		cout << "JAVA学科视频" << endl;
	}
};

class Python : public BasePage {
public:
	void content()
	{
		cout << "PYTHON学科视频" << endl;
	}
};

void test01()
{
    Java ja;
    ja.content();
    ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;
    Python py;
    py.content();
    py.footer();
	py.left();
	py.content();
}

int main()
{
    test01();
    return 0;
}
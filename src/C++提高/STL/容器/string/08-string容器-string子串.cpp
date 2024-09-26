#include <iostream>
#include <string>

/*
    从字符串中获得想要的字串。
*/

void test01()
{
    std::string str1 = "abcdefg";
    std::string substr = str1.substr(0, 3);  //从0开始起截取3个字符串为子串
    std::cout << substr << std::endl;
}

void test02()
{
	std::string email = "liwanliang@github.com";
	//从邮箱地址中获取用户名信息   
    int pos = email.find("@");
    std::cout << pos << std::endl;

    std::string username = email.substr(0, pos);
    std::cout << username << std::endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}


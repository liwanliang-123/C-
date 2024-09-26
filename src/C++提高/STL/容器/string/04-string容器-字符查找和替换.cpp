#include <iostream>
#include <string>

/*
    查找: 查找指定位置字符串是否存在
    替换: 在指定的位置替换字符串
*/

//find查找是从左往右，rfind从右往左
// 查找
void test01()
{
    std::string str1 = "helloworld ll";
    int ret = str1.find("ll", 0);  //从左往右查找
    if (ret == -1) {
        std::cout << "没有字符串" << std::endl;
    } else {
        std::cout << "找到该字符串，下标为：" << ret << std::endl;
    }

//  rfind
    ret = str1.rfind("ll"); //从右往左查找
    std::cout << "ret = " << ret << std::endl;
}

//替换
//replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
void test02()
{
    std::string str = "hello";
    str.replace(0, 2, "AAA");  //从 0 号位置开始的 2 个位置的字符串替换为 AAA
    std::cout << str << std::endl;
}

int main()
{
    test01();
    test02();
    return 0;
}


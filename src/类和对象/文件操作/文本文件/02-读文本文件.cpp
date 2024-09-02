// 读文件与写文件步骤相似，但是读取方式相对于比较多。

// 读文件步骤如下：
//     包含头文件：#include <fstream>
//     创建流对象：ifstream ifs;
//     打开文件并判断文件是否打开成功：ifs.open("文件路径",打开方式);
//     读数据：四种方式读取
//     关闭文件：ifs.close();

// 总结：
//     读文件可以利用ifstream，或者fstream类；
//     利用is_open函数可以判断文件是否打开成功；
//     close 关闭文件。

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void test01()
{
    //创建流对象
    ifstream ifs;

    //打开文件
    ifs.open("test.txt", ios::in);

    //判断是否打开出错
    if(!ifs.is_open()) {
        cout << "打开失败" << endl;
    }

    // //第一种读数据操作
    // char buf[128] = {0};
    // while(ifs >> buf) {
    //     cout << buf << endl;
    // }

    // //第二种读数据操作
    // char buf[128] = {0};
    // while(ifs.getline(buf, sizeof(buf))) {
    //     cout << buf << endl;
    // }

    // //第三种读数据操作
    // string buf;
    // while(getline(ifs, buf)) {
    //     cout << buf << endl;
    // }

    //第四种读数据操作（一个字符一个字符的读，不推荐）
    char c;
    while((c = ifs.get()) != EOF) {  //EOF 表示文件尾
        cout << c;
    }

    //关闭文件
    ifs.close();
}

int main()
{
    test01();
    return 0;
}
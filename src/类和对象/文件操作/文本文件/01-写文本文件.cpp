// 写文件步骤如下：
//     包含头文件：#include <fstream>
//     创建流对象：ofstream ofs;
//     打开文件：ofs.open("文件路径",打开方式);
//     写数据：ofs << "写入的数据";
//     关闭文件：ofs.close();

// 文件打开方式：
//     ios::in	为读文件而打开文件
//     ios::out	为写文件而打开文件
//     ios::ate	初始位置：文件尾
//     ios::app	追加方式写文件
//     ios::trunc	如果文件存在先删除，再创建
//     ios::binary	二进制方式

// 注意： 文件打开方式可以配合使用，利用 | 操作符。
// 例如：用二进制方式写文件 ios::binary | ios:: out

#include <fstream>
using namespace std;

void test01()
{
    //创建流对象
    ofstream ofs;
    //指定打开方式
    ofs.open("test.txt",ios::out); //写

    //写内容
    ofs << "hello" << endl;
    ofs << "world" << endl;

    //关闭文件
    ofs.close();
}

int main()
{
    test01();
    return 0;
}
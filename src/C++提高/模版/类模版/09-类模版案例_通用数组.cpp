#include <iostream>
#include <string>

#include "09-MyArray.hpp"

using namespace std;

void print_int(Myarray<int> &arr1)
{
    for (int i = 0; i < arr1.get_size(); i++) {
        cout << arr1[i];
    }
    cout << endl;
}

//测试内置数据类型 int
void test01()
{
    Myarray<int> arr1(10);

    for (int i = 0; i < 5; i++) {
        arr1.Push_Back(i);  //利用尾插法向数组插入数据
    }
    cout << "arr1输出为: ";
    print_int(arr1);
    cout << "arr1的容量为: " << arr1.get_Capacity() << endl;
    cout << "arr1的大小为: " << arr1.get_size() << endl;

    cout << "=====================================" << endl;

    Myarray<int> arr2(arr1);  //会调用拷贝构造函数
    cout << "arr2输出为: ";
    print_int(arr2);
    cout << "arr2的容量为: " << arr2.get_Capacity() << endl;
    cout << "arr2的大小为: " << arr2.get_size() << endl;

    cout << " ========== arr2尾删后 ==========" << endl;;
    arr2.Pop_Back();
    cout << "arr2输出为: ";
    print_int(arr2);
    cout << "arr2的容量为: " << arr2.get_Capacity() << endl;
    cout << "arr2的大小为: " << arr2.get_size() << endl;
}

//测试自定义数据类型
class Person {
public:
    Person()  //这里需要定义 Person 的无参构造函数
    {         //因为如果用户定义有参构造函数，C++不再提供默认无参构造
              //在 09.hpp 文件的 Myarray 有参构造函数中有 this->pAddress = new T[arr.m_Capacity]代码段,当 T 为Person时
              //this->pAddress = new Person[arr.m_Capacity]，这里会调用Person的无参构造函数，如果用户只提供Person的有参构造，系统就不会提供
              //所以这里需要写 Person 的无参构造函数
        cout << "Person 无参构造函数" << endl;
    }

    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    ~Person(){}

    string m_Name;
    int m_Age;
};

void print_Personarr(Myarray<Person> &arr)
{
    for (int i = 0; i < arr.get_size(); i++) {
        cout << "姓名： " << arr[i].m_Name << "年龄： " << arr[i].m_Age << endl;
    }
}

void test02()
{
    Myarray<Person> arr(10);

//准备数据
    Person P1("小明", 111);
    Person P2("小红", 120);
    Person P3("小亮", 113);
    Person P4("小章", 119);
    Person P5("小王", 114);

//将数据插入到数组中
    arr.Push_Back(P1);
    arr.Push_Back(P2);
    arr.Push_Back(P3);
    arr.Push_Back(P4);
    arr.Push_Back(P5);
    
//打印数组
    print_Personarr(arr);
//输出数组容量
    cout << "数组容量为： " << arr.get_Capacity() << endl;
//输出数组大小
    cout << "数组大小为： " << arr.get_size() << endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}
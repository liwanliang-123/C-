// 案例描述：
//     利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//     排序规则从大到小，排序算法为选择排序
//     分别利用char数组和int数组进行测试

#include <iostream>

using namespace std;

//交换函数模版
template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//排序算法
template<typename T>
void mySort(T array[], int len)
{
    for (int i = 0; i < len; i++) {
        int Max = i;  //认定第一个数为最大值
        for (int j = i + 1; j < len; j++) {
            if(array[Max] < array[j]) {  //认定的最大值比遍历的值还要小
                Max = j;
            }
        }
        if(Max != i) {
            //交换Max和i
            mySwap(array[Max], array[i]);
        }
    }
}

//打印数组的模版
template<typename T>
void printArr(T array, int len)
{
    for (int i = 0; i < len; i++) {
        cout << array[i];
    }
    cout << endl;
}

void test01()
{
    char array[] = "abcdefg";
    int len = sizeof(array)/sizeof(array[0]);
    mySort(array, len);
    printArr(array, len);
}

void test02()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(array)/sizeof(array[0]);
    mySort(array, len);
    printArr(array, len);
}

int main()
{
    test01(); //char
    test02(); //int
    return 0;
}
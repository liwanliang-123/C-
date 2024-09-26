/*
    reserve(int len);  容器预留len个元素长度，只是预留，并不初始化，不可访问

    作用：减少vector在动态内存扩容时的扩展次数

    如果数据量较大，可以一开始利用reserve预留空间。
*/

#include <iostream>
#include <vector>

void test01()
{
    int num = 0;  //统计动态开辟空间的次数
    int *p = NULL;
    std::vector<int> v1;

    // 利用 reserve 提前预留好需要的空间，后面就不需要动态扩展了
    v1.reserve(100000);

    for (size_t i = 0; i < 100000; i++) {
        v1.push_back(i);
        if(p != &v1[0]) {//vector 开辟空间不会在原地址后面开辟，而是会寻找一个更大的内存区域
            p = &v1[0]; //将所有数据般到新的内存中，所以通过记录首地址的变化次数就能够得到动态分配了几次空间
            num++;
        }
    }
    std::cout << "num = " << num << std::endl;
}

int main()
{
    test01();
    return 0;
}
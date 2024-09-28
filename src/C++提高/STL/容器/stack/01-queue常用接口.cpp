/*
    入栈——push
    出栈——pop
    返回栈顶——top
    判断栈是否为空——empty
    返回栈大小——size
*/

#include <iostream>
#include <stack>

void test01()
{
    std::stack<int> s;
// 入栈
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "栈的大小为：" << s.size() << std::endl;

// 只要栈不为空，查看栈顶，并执行出栈操作
    while (!s.empty()) { //不为空
        std::cout << "栈顶元素为：" << s.top() << std::endl;
        //出栈
        s.pop();
    }
    std::cout << "栈的大小为：" << s.size() << std::endl;
}

int main()
{
    test01();
    return 0;
}
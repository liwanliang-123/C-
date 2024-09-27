/*
    向deque容器中插入和删除数据

    两端插入操作：
        push_back()/push_front()  在容器尾部和头部插入一个元素
        pop_back()/pop_front()    在容器尾部和头部删除一个元素

    指定位置操作：
        insert() 插入
        clear()  清除
        erase()  删除
    
    注意：插入和删除提供的位置是迭代器！
*/

#include <iostream>
#include <deque>

void printDeque(std::deque<int> &d)
{                        // const_iterator: 限制为只读迭代器
//    for (auto it = d.begin(); it != d.end(); it++) {
    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 两端数据操作
void test01()
{
    std::deque<int> d1;

// 尾插
    d1.push_back(10);
    d1.push_back(20);
// 头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

// 尾删
    d1.pop_back();
    printDeque(d1);

// 头删
    d1.pop_front();
    printDeque(d1);
}

// 指定位置操作
void test02()
{
    std::deque<int> d2;
    d2.push_back(100);
    d2.push_back(200);
    d2.push_front(300);
    d2.push_front(400);

    printDeque(d2);

    d2.insert(d2.begin(), 1000);  // 头部插入 1000
    printDeque(d2);

    d2.insert(d2.begin(), 2, 2000); //头部插入 2个20000
    printDeque(d2);

// 按照区间进行插入
    std::deque<int> d3;
    d3.push_back(11);
    d3.push_back(22);
    d3.push_back(33);

// 将 d3 的 begin - end 区间元素插入到 d2 的开始位置
    d2.insert(d2.begin(), d3.begin(), d3.end());
    printDeque(d2);
}

// 删除
void test03()
{
    std::deque<int> d3;
    d3.push_back(11);
    d3.push_back(22);
    d3.push_back(33);

// 通过迭代器进行删除
    std::deque<int>::const_iterator it = d3.begin();
    //it++;
    d3.erase(it);
    printDeque(d3);

// 提供区间进行删除
    //d3.erase(d3.begin(), d3.end());
    //printDeque(d3);

// 清空
    d3.clear();
    printDeque(d3);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}
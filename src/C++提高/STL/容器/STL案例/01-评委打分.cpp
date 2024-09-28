/*
    有五名选手，选手ABCDE,10个评委分别对每一个选手打分，去除最高分和最低分，取平均分。

实现步骤：
    1.创建五名选手，放到vector中
    2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
    3.sort算法对deque容器中分数排序，去除最高分和最低分
    4.deque容器遍历一遍，累加总分
    5.获取平均分
*/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>

// 选手类
class Person {
//友元
friend void printVector(std::vector<Person> &v);
friend void setScore(std::vector<Person> &v);
public:

    Person(std::string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }
    ~Person(){}

private:
    int m_Score;
    std::string m_Name;
};

void creatPerson(std::vector<Person> &v)
{
    std::string nameSeed = "ABCDE";
    for (size_t i = 0; i < 5; i++) {
        std::string name = "选手";
        name += nameSeed[i];
        int score = 0;

        Person P(name, score);
        v.push_back(P);  //将选手保存到容器中
    }
}

void printVector(std::vector<Person> &v)
{
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << "选手：" << (*it).m_Name << " " << "平均分：" << (*it).m_Score << std::endl;
    }
}

void setScore(std::vector<Person> &v)
{   
    int score = 0;
    int sum = 0;
    int avg = 0;
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        //将分数放到 deque
        std::deque<int> d;
        for (size_t i = 0; i < 10; i++) {
            score = rand() % 41 + 60; //  60 - 100
            d.push_back(score);
        }

        std::cout << it->m_Name <<"评委打分为：" << std::endl;
        for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        //排序
        sort(d.begin(), d.end());
        // 去除最高和最低分
        d.pop_back();
        d.pop_front();
        //取平均分
        for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
            sum += (*it);
        }
        avg = sum / d.size();
        //将平均分赋值给选手
        it->m_Score = avg;
        score = 0;
        sum = 0;
        avg = 0;
    }
}

int main()
{
//  随机数种子
    srand((unsigned int)time(NULL));

//  创建5名选手
    std::vector<Person> v;
    creatPerson(v);
    //printVector(v);

//  给5名选手打分
    setScore(v);

//  显示分数
    printVector(v);

    return 0;
}
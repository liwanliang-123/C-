/*
案例描述:
    公司今天招聘了10个员工(ABCDEFGHIJ)，10名员工进入公司之后，需要指派员工在哪个部门工作。
    员工信息有：姓名、工资组成、部门分为：策划、美术、研发
    通过multimap进行信息的插入 key(部门编号)value(员工)
    分部门显示员工信息

实现步骤:
    创建10名员工，放到vector中
    遍历vector容器，取出每个员工，进行随机分组
    分组后，将员工部门编号作为key,具体员工作为value,放入到multimap容器中
    分部门显示员工信息
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

class Worker {
public:
    int m_Salary;
    std::string m_Name;
};

void creatWorker(std::vector<Worker> &vw)
{
    std::string nameSeed = "ABCDEFGHIJ";
    for (size_t i = 0; i < 10; i++) {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_Salary = rand() % 10000 + 10000;
        vw.push_back(worker);
    }
}

void printWorker(std::vector<Worker> &vw)
{
    for (auto it = vw.begin(); it != vw.end(); it++) {
        std::cout << "name: " << it->m_Name << " " << "Salary: " <<  \
                it->m_Salary << std::endl;
    }
}

void SetGroup(std::vector<Worker> &vw, std::multimap<int, Worker> &mw)
{
    for (auto it = vw.begin(); it != vw.end(); it++) {
        int deptId = rand() % 3;  // 0 - 2
        mw.insert(std::make_pair(deptId, *it));  //(编号， 员工)
    }
}

void printAll(std::multimap<int, Worker> &mw, int id)
{
    int index = 0;
    int count = mw.count(id);
    auto it = mw.find(id);
    for (; it != mw.end() && index < count; it++, index++) {
        std::cout << "id = " << it->first << " " << "name = " << \
            (it->second).m_Name << " " << "Salary = " << \
                    (it->second).m_Salary << std::endl;
    }
}

void ShowWorkerByGroup(std::multimap<int, Worker> &mw)
{
    std::cout << "策划:" << std::endl;
    printAll(mw, CEHUA);

    std::cout << "美术:" << std::endl;
    printAll(mw, MEISHU);

    std::cout << "研发:" << std::endl;
    printAll(mw, YANFA);
}

int main()
{
    srand((unsigned int)time(NULL));

    std::vector<Worker> vwork;
    creatWorker(vwork);

    //printWorker(vwork);

    std::multimap<int, Worker> mwork;
    SetGroup(vwork, mwork);
    ShowWorkerByGroup(mwork);

    return 0;
}
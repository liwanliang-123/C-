#include "teacher.h"
#include "orderFile.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empId, std::string name, std::string pwd)
{
    this->m_Empid = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//  操作菜单
void Teacher::operMenu()
{
	std::cout << "欢迎教师: " << this->m_Name << "登录! " << std::endl;
	std::cout << "——————————" << std::endl;
	std::cout << "——1.查看所有预约——" << std::endl;
	std::cout << "——2.审核预约————" << std::endl;
	std::cout << "——0.注销登录———" << std::endl;
	std::cout << "——————————" << std::endl;
	std::cout << "请选择你的操作" << std::endl;
}

//  查看所有人的预约
void Teacher::showAllOrder()
{
    OrderFile of;
    if(of.m_Size == 0) {
        std::cout << "没有预约记录" << std::endl;
        return ;
    }

    for (size_t i = 0; i < of.m_Size; i++) {
        std::cout << "第" << i + 1 << "条:" << " ";
        std::cout << "预约人: " << of.m_OrderData[i]["stuName"] << " ";
        std::cout << "学号: " << of.m_OrderData[i]["stuId"] << "号" << " ";
        std::cout << "预约日期：周" << of.m_OrderData[i]["date"] << " ";
        std::cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
        std::cout << "机房编号：" << of.m_OrderData[i]["roomId"] << " ";

        std::string status = "状态: ";
        int sta = atoi(of.m_OrderData[i]["status"].c_str());
        switch (sta) {
        case 0:
            status += "预约已取消";
            break;
        case 1:
            status += "审核中";
            break;
        case 2:
            status += "预约成功";
            break;
        case -1:
            status += "预约失败, 审核未通过";
            break;
        default:
            break;
        }
        std::cout << status << std::endl;
    }
}

//  审核预约
void Teacher::validOrder()
{
    OrderFile of;
    if(of.m_Size == 0) {
        std::cout << "没有预约记录" << std::endl;
        return ;
    }

    std::cout << "待审核的预约记录如下: " << std::endl;
    int sta = 0;
    int index = 1;
    std::vector<int> v;
    for (size_t i = 0; i < of.m_Size; i++) {
        if(of.m_OrderData[i]["status"] == "1") {
            v.push_back(i);
            std::cout << index++ << " ";
            std::cout << "第" << i + 1 << "条:" << " ";
            std::cout << "预约人: " << of.m_OrderData[i]["stuName"] << " ";
            std::cout << "学号: " << of.m_OrderData[i]["stuId"] << "号" << " ";
            std::cout << "预约日期：周" << of.m_OrderData[i]["date"] << " ";
            std::cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
            std::cout << "机房编号：" << of.m_OrderData[i]["roomId"] << " ";

            std::string status = "状态: 审核中";
            std::cout << status << std::endl;
        }
    }

    std::cout << "请输入需要审核的预约记录, 0表示取消" << std::endl;
    int select;
    int ret = 0;  // 保存预约结果

    while (true) {
        std::cin >> select;
        if(select >= 0 && select <= v.size()) {
            if(select == 0) {
                break;
            }
            std::cout << "请输入审核结果" << std::endl;
            std::cout << "1 通过 / 2 不通过" << std::endl;
            std::cin >> ret;
            if(ret == 1) {
                //通过
                of.m_OrderData[v[select - 1]]["status"] = "2";
            } else{
                //不通过
                of.m_OrderData[v[select - 1]]["status"] = "-1";  
            }
            // 更新预约记录
            of.updateOrder();
            std::cout << "审核完毕!" << std::endl;
            break;
        }
        std::cout << "输入有误,请重新输入" << std::endl;
    }
}

Teacher::~Teacher()
{

}
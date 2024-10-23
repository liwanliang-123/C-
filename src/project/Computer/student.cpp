#include "student.h"
#include "orderFile.h"

Student::Student()
{

}

Student::Student(int id, std::string name, std::string pwd)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;
//  初始化机房
    std::ifstream ifs;
    ifs.open(COMPUTER_FILE, std::ios::in);

    ComputerRoom com;

    while (ifs >> com.m_Comid && ifs >> com.m_Maxnum) {
    //  将从文件读取的信息放入到 vector 中
        this->vCom.push_back(com);
    }
    ifs.close();
}

//  菜单显示
void Student::operMenu()
{
	std::cout << "欢迎学生代表:" << this->m_Name << "登录!" << std::endl;
	std::cout << "——————————" << std::endl;
	std::cout << "——1.申请预约——" << std::endl;
	std::cout << "——2.查看我的预约—" << std::endl;
	std::cout << "——3.查看所有预约—" << std::endl;
	std::cout << "——4.取消预约——" << std::endl;
	std::cout << "——0.注销登录——" << std::endl;
	std::cout << "——————————" << std::endl;
	std::cout << "请选择您的操作:" << std::endl;
}

//  申请预约
void Student::applyOrder()
{
    std::cout << "机房开放的时间为周一 到 周五" << std::endl;
    std::cout << "请选择申请预约的时间, 1/2/3/4/5" << std::endl;

    int date = 0;      // 日期
    int interval = 0;  // 时间段
    int room = 0;      // 机房编号

    while (true) {
        std::cin >> date;
        if(date >= 1 && date <= 5 ) {
            break;
        }
        std::cout << "日期输入有误,请输入" << std::endl;
    }

    std::cout << "请输入申请预约的时间段" << std::endl;
    std::cout << "1 —— 上午" << std::endl;
    std::cout << "2 —— 下午" << std::endl;
    while (true) {
        std::cin >> interval;
        if(interval >= 1 && interval <= 2) {
            break;
        }
        std::cout << "时间段输入有误,请输入" << std::endl;
    }

    std::cout << "请选择机房" << std::endl;
    for (size_t i = 0; i < this->vCom.size(); i++) {
        std::cout << vCom[i].m_Comid << "号机房的容量为" << vCom[i].m_Maxnum << std::endl;
    }

    while (true) {
        std::cin >> room;
        if(room >=1 && room <= 3) {
            break;
        }
        std::cout << "机房输入有误,请输入" << std::endl;
    }
    std::cout << "预约成功！审核中..." << std::endl;

//  将预约信息写入到文件中
    std::ofstream ofs;
    ofs.open(ORDER_FILE, std::ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << " " << std::endl;

    ofs.close();
}

//  查看自身预约
void Student::showMyOrder()
{
    OrderFile of;
    if(of.m_Size == 0) {
        std::cout << "没有预约记录" << std::endl;
        return ;
    }

//  C++ string 转 int
//  1. string利用c_str()转成 const char *
//  2. 利用 atoi 将 const char * 转成 int
    for (size_t i = 0; i < of.m_Size; i++) {
        if(this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str())) {  // 找到自身预约
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
                status += "已预约";
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
}

//  查看所有预约
void Student::showAllOrder()
{
    OrderFile of;
    if(of.m_Size == 0) {
        std::cout << "没有预约记录" << std::endl;
        return ;
    }

    for (size_t i = 0; i < of.m_Size; i++) {
        std::cout << i + 1 << " ";
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
            status += "已预约";
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

//  取消预约
void Student::cancelOrder()
{
    OrderFile of;
    if(of.m_Size == 0) {
        std::cout << "没有预约记录" << std::endl;
        return ;
    }

    std::cout << "审核中和预约成功的记录是可以取消的, 请输入需要取消的记录:" << std::endl;
    int index = 1;  // 存放自身一共有多少预约
    std::vector<int> v; // 存放最大容器中的下标编号
    for (size_t i = 0; i < of.m_Size; i++) {
        // 先判读自身的学号
        if(this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str())) {
            // 再筛选状态, 审核中或者预约成功
            if(of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2") {
                v.push_back(i);
                std::cout << "index = " << index++ <<  " ";
                std::cout << "i = " << i << " ";  // i 表示 数据在文件中的行数,也就是大容器的 key 值
                std::cout << "预约日期: 周" << of.m_OrderData[i]["date"] << " ";
                std::cout << "时间段:" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
                std::cout << "机房编号：" << of.m_OrderData[i]["roomId"] << " ";

                std::string status = "状态: ";
                int sta = atoi(of.m_OrderData[i]["status"].c_str());
                switch (sta) {
                case 1:
                    status += "审核中";
                    break;
                case 2:
                    status += "已预约";
                    break;
                default:
                    break;
                }
                std::cout << status << std::endl;
            }
        }
    }

    std::cout << "请输入需要取消的记录, 0 表示返回" << std::endl;
    int select = 0;
    while (true) {
        std::cin >> select;
        if(select >= 0 || select <= v.size()) {
            if(select == 0) {
                break;
            } else {  // 比如我想把第 4 条预约记录删除,那就是 v[4-1] = v[3],就刚好是第四个记录
                of.m_OrderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                std::cout << "已取消预约" << std::endl;
                break;
            }
        }
        std::cout << "输入有误,重新输入" << std::endl;
    }
}

Student::~Student()
{
    
}
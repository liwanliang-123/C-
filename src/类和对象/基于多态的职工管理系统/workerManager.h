#pragma once

#include <iostream>
#include <fstream>

#include "worker.h" 
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager {
public:

    // 展示菜单
    void Show_Menu();

    // 退出系统
    void ExitSystem();

    WorkerManager();
    ~WorkerManager();

    //添加职工函数
    void Add_Emp();

    //保存文件
    void save_file();

    //判断文件是否为空的标志
    bool m_FileIsEmpty;

    //统计文件中的人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工
    void show_emp();

    //删除职工
    void del_emp();

    //判断职工是否存在，如果存在返回职工所在数组中的位置，否则返回 -1
    int is_exist(int id);

    //修改职工
    void modify_emp();

    //查找职工
    void find_emp();

    //按照职工编号排序
    void sort_emp();

    //清除文件操作
    void clear_file();

    //记录职工人数
    int m_EmpNum;
    //职工数组指针
    Worker **m_EmpArray;
};
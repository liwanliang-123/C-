//普通员工文件
#pragma once

#include <iostream>

#include "worker.h"

using namespace std;

// 重写 Worker 父类
class Employee : public Worker {
public:
    //显示个人信息
    virtual void show_Info();
    //获取岗位名称
    virtual string getDeptName();

    Employee(int id, string name, int d_id);

    ~Employee();
};


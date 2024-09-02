#pragma once

#include <iostream>

#include "worker.h"

using namespace std;

// 经理类
class Manager : public Worker {
public:

    Manager(int id, string name, int d_id);

    ~Manager();

    //显示个人信息
    virtual void show_Info();
    //获取岗位名称
    virtual string getDeptName();
};
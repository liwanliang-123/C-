#pragma once

#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Manager : public Identity {
public:
    Manager();
    Manager(std::string name, std::string pwd);

//  菜单显示
    virtual void operMenu();

//  添加帐号
    void addPerson();

//  查看帐号
    void showPerson();

//  查看机房信息
    void showComputer();

//  清空预约记录
    void cleanFile();

//  初始化容器
    void initVector();

//  检测重复
    bool checkRepeat(int id, int type);

//  学生容器
    std::vector<Student> vstu;

//  教师容器
    std::vector<Teacher> vtea;

//  机房信息
    std::vector<ComputerRoom> vcomR;

    ~Manager();
};
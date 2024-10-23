#pragma once

#include "identity.h"
#include "computerRoom.h"

class Student : public Identity {
friend class Manager;
friend void printStu(Student &s);
friend void readStudentFile(std::ifstream &ifs, std::vector<Student> &vstu);
public:
    Student();
    Student(int id, std::string name, std::string pwd);

//  菜单显示
    virtual void operMenu();

//  申请预约
    void applyOrder();

//  查看自身预约
    void showMyOrder();

//  查看所有预约
    void showAllOrder();

//  取消预约
    void cancelOrder();

    ~Student();

//  机房容器
    std::vector<ComputerRoom> vCom;

private:
    int m_Id;
};
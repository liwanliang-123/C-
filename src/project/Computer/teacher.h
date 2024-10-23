#pragma once

#include "identity.h"

class Teacher : public Identity {
friend class Manager;
friend class printTea;
friend void readTeacherFile(std::ifstream &ifs, std::vector<Teacher> &vtea);
public:
    Teacher();
    Teacher(int empId, std::string name, std::string pwd);

//  操作菜单
    virtual void operMenu();

//  查看所有人的预约
    void showAllOrder();

//  审核预约
    void validOrder();

    ~Teacher();

private:
    int m_Empid;
};
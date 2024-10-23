#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "globalFile.h"

class OrderFile {
friend class Student;
friend class Teacher;
public:
    OrderFile();

//  更新预约记录
    void updateOrder();

private:
//  记录预约条数
    int m_Size;

//  记录所有预约信息的容器
//  key 表示记录的条数， value 表示具体记录的键值对信息，也就是表示一个学生的所有信息
    std::map<int, std::map<std::string, std::string>> m_OrderData;
};

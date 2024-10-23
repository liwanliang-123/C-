#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "globalFile.h"

// 身份抽象基类
class Identity {
public:

//  操作菜单
    virtual void operMenu() = 0;

    std::string m_Name;
    std::string m_Pwd;
};
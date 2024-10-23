#include <iostream>
#include <string>
#include <fstream>

#include "student.h"
#include "teacher.h"
#include "manager.h"

#include "identity.h"
#include "globalFile.h"

// 进入教师子菜单
void teacherMenu(Identity* &teacher)
{
    int select;
    while (true) {
        teacher->operMenu();
        Teacher* t = (Teacher*)teacher;

        std::cin >> select;
        switch (select) {
        case 1:
            t->showAllOrder();
            break;
        case 2:
            t->validOrder();
            break;
        case 0:
            delete teacher;
            std::cout << "注销成功" << std::endl;
            return ;
        default:
            break;
        }
    }
}

//进入学生子菜单界面
/*
个人理解：这里 Identity* &student 加引用主要是不想再次创建一个指针，避免野指针
    因为如果不加引用这里就会再创建一个指针用来接收传递过来的父类指针
    如果加了引用就会将 loginIn 函数中创建的父类指针传递过来
    在 studentMenu 函数中 delete 时才能真正的销毁，如果不加引用
    loginIn 函数中的 父类指针可能就会变成野指针
*/
void studentMenu(Identity* &student)
{
    int select;
    while (true) {
        student->operMenu();
        Student* s = (Student*)student;

        std::cin >> select;
        switch (select) {
        case 1:
            s->applyOrder();
            break;
        case 2:
            s->showMyOrder();
            break;
        case 3:
            s->showAllOrder();
            break;
        case 4:
            s->cancelOrder();
            break;
        case 0:
            delete student;  // 因为加了引用，所以这里delete的是loginIn中的父类指针
            std::cout << "注销成功" << std::endl;
            return ;
        default:
            break;
        }
    }
}

//进入管理员子菜单界面
void managerMenu(Identity* &manager)
{
    int select;
    while (true) {
    //  管理员子菜单
        manager->operMenu();
    //  将父类指针转为子类指针，调用子类里其它特有接口
        Manager* man = (Manager*)manager;

        std::cin >> select;
        switch (select) {
        case 1:
            man->addPerson();
            break;
        case 2:
            man->showPerson();
            break;
        case 3:
            man->showComputer();
            break;
        case 4:
            man->cleanFile();
            break;
        case 0:
            delete manager;
            std::cout << "注销成功" << std::endl;
            return ;
        default:
            break;
        }
    }
}

void show_manu()
{
    std::cout << "——————————————" << std::endl;
    std::cout << "  欢迎使用机房预约系统系统" << std::endl;
    std::cout << "——————————————" << std::endl;
    std::cout << "\t1.学生代表" << std::endl;
    std::cout << "\t2.老  师" << std::endl;
    std::cout << "\t3.管理员" << std::endl;
    std::cout << "\t0.退  出" << std::endl;
    std::cout << "——————————————" << std::endl;
    std::cout << "请输入你的选择：" << std::endl;
}

//                       操作文件名      身份类型
void loginIn(std::string fileName, int type)
{
//  创建父类指针用于指向子类对象
    Identity *person = NULL;

//  读文件
    std::ifstream ifs;
    ifs.open(fileName, std::ios::in);
    if (!ifs.is_open()) {
        std::cout << "文件不存在" << std::endl;
        ifs.close();
        return ;
    }

//  接收用户信息
    int id = 0;
    std::string name;
    std::string pwd;

    if(type == 1) {
        std::cout << "请输入学号:" << std::endl;
        std::cin >> id;

    } else if(type == 2) {
        std::cout << "请输入职工号:" << std::endl;
        std::cin >> id;
    }

    std::cout << "请输入用户名:" << std::endl;
    std::cin >> name;

    std::cout << "请输入密码:" << std::endl;
    std::cin >> pwd;

    int fid;
    std::string fname;
    std::string fpwd;
    if(type == 1) {
//  学生身份验证
        while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
        //  将从文件中读取的信息和用户输入的信息做对比
            if(fid == id && fname == name && fpwd == pwd) {
                std::cout << "学生验证通过，登录成功" << std::endl;
                person  = new Student(id, name, pwd);
                //  进入学生身份的子菜单
                studentMenu(person);
                return ;
            }
        }
    } else if(type == 2) {
//  教师身份验证
        while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
        //  将从文件中读取的信息和用户输入的信息做对比
            if(fid == id && fname == name && fpwd == pwd) {
                std::cout << "教师验证通过，登录成功" << std::endl;
                person  = new Teacher(id, name, pwd);
                //  进入老师身份的子菜单
                teacherMenu(person);
                return ;
            }
        }

    } else if(type == 3) {
//  管理员身份验证
        while (ifs >> fname && ifs >> fpwd) {
        //  将从文件中读取的信息和用户输入的信息做对比
            if(fname == name && fpwd == pwd) {
                std::cout << "管理员验证通过，登录成功" << std::endl;
                person  = new Manager(name, pwd);
                //  进入管理员的子菜单
                managerMenu(person);
                return ;
            }
        }
    }

    std::cout << "验证失败 !!!" << std::endl;
    return ;
}

int main()
{
    int select = 0;
    while (true) {

        show_manu();

        std::cin >> select;
        switch (select) {
        case 1:
            loginIn(STUDENT_FILE, 1);
            break;
        case 2:
            loginIn(TEACHER_FILE, 2);
            break;
        case 3:
            loginIn(ADMIN_FILE, 3);
            break;
        case 0:
            std::cout << "欢迎下次使用" << std::endl;
            exit(0);
            break;
        default:
            std::cout << "输入有误" << std::endl;
            exit(0);
            break;
        }
    }

    return 0;
}
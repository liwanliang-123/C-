#include <iostream>

#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main()
{
    //实例化管理者的对象
    WorkerManager wm;
    int choice = 0;
    while(true) {
        //展示菜单
        wm.Show_Menu();

        cout << "请输入您的选择：";
        cin >> choice;

        switch (choice) {
        case 0:
            wm.ExitSystem();
            break;
        case 1:
            wm.Add_Emp();
            break;
        case 2:
            wm.show_emp();
            break;
        case 3:
        {
            wm.del_emp();
            break;
        }
        case 4:
            wm.modify_emp();
            break;
        case 5:
            wm.find_emp();
            break;
        case 6:
            wm.sort_emp();
            break;
        case 7:
            wm.clear_file();
            break;
        default:
            cout << "输入错误" << endl;
            break;
        }
    }

    return 0;
}
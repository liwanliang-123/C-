#include "manager.h"

Manager::Manager(int id, string name, int d_id)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = d_id;
}

Manager::~Manager()
{

}

string Manager::getDeptName()
{
    return string("经理");
}

void Manager::show_Info()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t职责: 完成老板下发的任务..." << endl;
}
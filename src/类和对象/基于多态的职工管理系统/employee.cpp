#include "employee.h"

void Employee::show_Info()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t职责: 完成经理下发的任务..." << endl;
}

string Employee::getDeptName()
{
	return string("员工");
}

Employee::Employee(int id, string name, int d_id)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = d_id;
}

Employee::~Employee()
{

}
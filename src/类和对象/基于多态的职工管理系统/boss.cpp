#include "boss.h"

Boss::Boss(int id, string name, int d_id)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = d_id;
}

Boss::~Boss()
{

}

string Boss::getDeptName()
{
    return string("老板");
}

void Boss::show_Info()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t职责: 给经理下发的任务..." << endl;
}
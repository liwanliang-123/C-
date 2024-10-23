#include "manager.h"

Manager::Manager()
{

}

Manager::Manager(std::string name, std::string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;

//  初始化容器
	this->initVector();
//  初始化机房信息
	ComputerRoom com;
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);

	while (ifs >> com.m_Comid && ifs >> com.m_Maxnum) {
		this->vcomR.push_back(com);
	}
	ifs.close();
	std::cout << "机房的数量为：" << this->vcomR.size() << std::endl;
}

//  菜单显示
void Manager::operMenu()
{
	std::cout << "欢迎管理员:" << this->m_Name << "登录!" << std::endl;
	std::cout << "——————————" << std::endl;
	std::cout << "——1.添加账号——" << std::endl;
	std::cout << "——2.查看账号——" << std::endl;
	std::cout << "——3.查看机房——" << std::endl;
	std::cout << "——4.清空预约——" << std::endl;
	std::cout << "——0.注销登录——" << std::endl;
	std::cout << "——————————" << std::endl;
	std::cout << "请选择您的操作:" << std::endl;
}

//  添加帐号
void Manager::addPerson()
{
	std::cout << "请输入需要添加的帐号类型" << std::endl;
	std::cout << "1 —— 添加学生" << std::endl;
	std::cout << "2 —— 添加老师" << std::endl;

	std::string fileName;  // 操作的文件名
	std::string tip;       // 操作的 id 号
	std::string errTip;

	std::ofstream ofs;

	int select = 0;
	std::cin >> select;
	if(select == 1) {  // 添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号: ";
		errTip = "学号重复,请重新输入：";
	} else {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号: ";
		errTip = "职工号重复,请重新输入：";
	}

	ofs.open(fileName, std::ios::out | std::ios::app);
	int id;
	std::string name;
	std::string pwd;

	std::cout << tip << std::endl;
	while (true) {
		std::cin >> id;
		if(checkRepeat(id, select)) {
			std::cout << errTip << std::endl;
		} else {
			break;
		}
	}
	std::cout << "请输入姓名: " << std::endl;
	std::cin >> name;
	std::cout << "请输入登录密码: " << std::endl;
	std::cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << std::endl;
//  向文件中添加新的数据之后需要重新获取文件中的数据保存到 Vector 中
	initVector();
	std::cout << "添加成功！" << std::endl;

	ofs.close();
}

// 普通函数
void printStu(Student &s)
{
	std::cout << "学号：" << s.m_Id << "  ";
	std::cout << "姓名：" << s.m_Name << " ";
	std::cout << "密码：" << s.m_Pwd << std::endl;
}

// 仿函数
class printTea {
public:
	void operator()(Teacher &s)
	{
		std::cout << "编号：" << s.m_Empid << "  ";
		std::cout << "姓名：" << s.m_Name << " ";
		std::cout << "密码：" << s.m_Pwd << std::endl;
	}
};

//  查看帐号
void Manager::showPerson()
{
	std::cout << "请选择查看的内容：" << std::endl;
	std::cout << "1 —— 查看所有学生" << std::endl;
	std::cout << "2 —— 查看所有老师" << std::endl;

	int select = 0;
	std::cin >> select;
	if(select == 1) {
	//  查看学生
		std::cout << "所有的学生信息如下：" << std::endl;
		for_each(vstu.begin(), vstu.end(), printStu);

	} else {
	//  查看老师
		std::cout << "所有的老师信息如下：" << std::endl;
		for_each(vtea.begin(), vtea.end(), printTea());
	}
}

//  查看机房信息
void Manager::showComputer()
{
	std::cout << "机房的信息如下：" << std::endl;
	for (auto it = this->vcomR.begin(); it != this->vcomR.end(); it++) {
		std::cout << "机房编号：" << it->m_Comid << " ";
		std::cout << "最大容量为：" << it->m_Maxnum << std::endl;
	}
}

//  清空预约记录
void Manager::cleanFile()
{
	std::ofstream ofs(ORDER_FILE, std::ios::trunc);
	ofs.close();

	std::cout << "清空成功" << std::endl;
}

void readStudentFile(std::ifstream &ifs, std::vector<Student> &vstu)
{
	ifs.open(STUDENT_FILE, std::ios::in);
	if(!ifs.is_open()) {
		std::cout << "文件打开失败" << std::endl;
		return ;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vstu.push_back(s);	
	}
	std::cout << "当前学生数量为： " << vstu.size() << std::endl;
	ifs.close();
}

void readTeacherFile(std::ifstream &ifs, std::vector<Teacher> &vtea)
{
	ifs.open(TEACHER_FILE, std::ios::in);
	if(!ifs.is_open()) {
		std::cout << "文件打开失败" << std::endl;
		return ;
	}

	Teacher t;
	while (ifs >> t.m_Empid && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vtea.push_back(t);
	}
	std::cout << "当前老师数量为： " << vtea.size() << std::endl;
	ifs.close();
}

void Manager::initVector()
{
	std::ifstream ifs;
	this->vstu.clear();
	this->vtea.clear();

//  读取学生的信息
	readStudentFile(ifs, this->vstu);

//  读取老师的信息
	readTeacherFile(ifs, this->vtea);
}

bool Manager::checkRepeat(int id, int type)
{
	if(type == 1) {
	//  检测学生
		for (std::vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
			if(id == it->m_Id) {
				return true;
			}
		}
	} else {
	//  检测老师
		for (auto it = vtea.begin(); it != vtea.end(); it++) {
			if(id == it->m_Empid) {
				return true;
			}
		}
	}
	return false;
}

Manager::~Manager()
{

}
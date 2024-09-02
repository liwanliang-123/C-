#include "workerManager.h"

void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "*****欢迎使用职工管理系统*****" << endl;
	cout << "*******0-退出管理程序*********" << endl;
	cout << "*******1-增加职工信息*********" << endl;
	cout << "*******2-显示职工信息*********" << endl;
	cout << "*******3-删除离职职工*********" << endl;
	cout << "*******4-修改职工信息*********" << endl;
	cout << "*******5-查找职工信息*********" << endl;
	cout << "*******6-按照编号排序*********" << endl;
	cout << "*******7-清空所有文档*********" << endl;
	cout << "******************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
    cout << "欢迎下次再使用" << endl;
    exit(0);
}

void WorkerManager::save_file()
{
	ofstream ofs;
	ofs.open(FILENAME ,ios::out);  //用输出的方式打开文件 （写文件）

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量: " << endl;
	int add_num = 0;     //保存输入数量

	cin >> add_num;
	if(add_num <= 0) {
    	cout << "输入数字有误" << endl;
	}

	//添加
	//计算添加新空间的大小     新空间大小 = 原来记录人数 + 新增加人数  （动态的为数组分配空间）
	int new_size = 	this->m_EmpNum + add_num;
	
	//开辟新空间
	Worker** new_space = new Worker * [new_size];

	//将之前空间的数组拷贝到新的内存空间中
	if(this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			new_space[i] = m_EmpArray[i];
		}
	}
	// 开始批量添加新的数据
	for (int i = 0; i < add_num; i++) {
		int id; //职工编号
		int d_select; //部门选择
		string name; //职工姓名

		cout << "请输入第" << i + 1 << "个新员工的编号：" << endl;
		cin >> id;

		cout << "请输入第" << i + 1 << "个新员工的姓名：" << endl;
		cin >> name;

		cout << "请选择该职工岗位" << endl;
		cout << "1-普通员工" << endl;
		cout << "2-经理" << endl;
		cout << "3-老板" << endl;
		cin >> d_select;

		Worker *worker = NULL;
		switch (d_select) {
		case 1:
			worker = new Employee(id ,name ,d_select);
			break;
		case 2:
			worker = new Manager(id ,name ,d_select);
			break;
		case 3:
			worker = new Boss(id ,name ,d_select);
			break;
		default:
			break;
		}

		//将创建的职工职责保存到数组中
		new_space[this->m_EmpNum + i] = worker;
	}

	//释放旧数组的空间
	delete[] this->m_EmpArray;
	//更改新空间的指向
	this->m_EmpArray = new_space;
	//更新新的职工人数
	this->m_EmpNum = new_size;
	//保存数据到文件中
	this->save_file();
	//更新职工不为空
	this->m_FileIsEmpty = false;
	//提示添加成功
	cout << "成功添加" << add_num << "名新职工！" << endl;

	//清屏
	// system("clear");
}

int WorkerManager::get_EmpNum()
{
	int id;
	string name;
	int d_id;
	int num = 0;

	ifstream ifs;
	ifs.open(FILENAME ,ios::in); //打开文件

	while (ifs >> id && ifs >> name && ifs >> d_id) {
		num++;  //统计人数的变量
	}

	return num;
}

//删除职工
void WorkerManager::del_emp()
{
	int id = 0;
	if(this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	} else {
		//按照职工编号删除
		cout << "请输入想要删除的职工编号: ";
		cin >> id;

		int index = this->is_exist(id);
		if(index != -1) { //判断职工是否存在
			//数组删除数据就是数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;  //更新数组中记录的人员个数
			//同步更新到文件中
			this->save_file();
			cout << "删除成功" << endl;
			
		} else {
			cout << "删除失败，未找到员工" << endl;
		}
	}
	//system("clear")
}

//判断职工是否存在，如果存在返回职工所在数组中的位置，否则返回 -1
int WorkerManager::is_exist(int id)
{
	int index = -1;  //开始就认定职工不存在

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//找到职工
			index = i;
			break;
		}
	}
	
	return index;
}

//修改职工
void WorkerManager::modify_emp()
{
	int id;
	if(this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	} else {
		cout << "请输入修改职工的编号: ";
		cin >> id;

		int ret = this->is_exist(id);
		if(ret != -1) {  //查找到编号职工
			delete this->m_EmpArray[ret];

			int new_id = 0;
			string new_name = "";
			int new_dselect = 0;

			cout << "查找到： " << id << "号职工，请输入新职工号： ";
			cin >> new_id;

			cout << "请输入新的姓名： ";
			cin >> new_name;

			cout << "请选择该职工岗位" << endl;
			cout << "1-普通员工" << endl;
			cout << "2-经理" << endl;
			cout << "3-老板" << endl;
			cin >> new_dselect;

			Worker *worker = NULL;
			switch (new_dselect) {
			case 1:
				worker = new Employee(new_id ,new_name ,new_dselect);
				break;
			case 2:
				worker = new Manager(new_id ,new_name ,new_dselect);
				break;
			case 3:
				worker = new Boss(new_id ,new_name ,new_dselect);
				break;
			default:
				break;
			}

			//更新数据更新到数组中
			this->m_EmpArray[ret] = worker;
			//保存数据到文件中
			this->save_file();

			//提示添加成功
			cout << "职工修改成功！" << endl;

		} else {
			cout << "修改失败，未找到员工" << endl;
		}
	}
	// system("clear");
}

//查找职工
void WorkerManager::find_emp()
{
	int select;
	if(this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	} else {
		cout << "请输入查找职工的方法: " << endl;
		cout << "1-按照职工编号查找 " << endl;
		cout << "2-按照职工姓名查找 " << endl;
		cin >> select;
		
		if(select == 1) {
			//按照职工编号查找
			int id;
			cout << "请输入要查找的职工编号： ";
			cin >> id;
			int ret = this->is_exist(id);
			if(ret != -1) {  //查找到编号职工
				cout << "通过编号查找到该职工，信息如下： " << endl;
				this->m_EmpArray[ret]->show_Info();
			} else {
				cout << "查找失败，未找到员工" << endl;
			}
		} else if(select == 2) {
			//按照职工姓名查找
			string name;
			cout << "请输入要查找的职工姓名： ";
			cin >> name;

			//加入判断是否查找到的标志
			bool flag = false;  //默认没有找到该员工

			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) { //查找到该职工
					cout << "通过姓名查找到该职工，信息如下： " << endl;
					this->m_EmpArray[i]->show_Info();

					flag = true;
				}
			}
			if (flag == false) {
				cout << "查找失败，未找到员工" << endl;
			}
		} else {
			cout << "输入有误" << endl;
		}
	}
	//system("clear");
}

//按照职工编号排序
void WorkerManager::sort_emp()
{
	int select;
	if(this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	} else {
		cout << "请选择一种排序方式: " << endl;
		cout << "1-按照职工号进行升序排序 " << endl;
		cout << "2-按照职工号进行降序排序 " << endl;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++) {
			int Min_or_Max = i;  // 声明最小值或者最大值
			for (int j = i + 1; j < this->m_EmpNum; j++) {

				if (select == 1) {      //升序
					if (this->m_EmpArray[Min_or_Max]->m_Id > this->m_EmpArray[j]->m_Id) {
						Min_or_Max = j;
					}
				} else if (select == 2) {  //降序
					if (this->m_EmpArray[Min_or_Max]->m_Id < this->m_EmpArray[j]->m_Id) {
						Min_or_Max = j;
					}
				} else {
					cout << "输入有误 !" << endl;
				}
			}
			//判断一开始认定的最小值或最大值是不是真正的最大小值，如果不是则交换数据
			if (i != Min_or_Max) {
				Worker *temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[Min_or_Max];
				this->m_EmpArray[Min_or_Max] = temp;
			}
		}

		cout << "排序成功！ 排序后的结果为：  " << endl;
		this->show_emp();  //显示所以员工
		this->save_file(); //排序结构保存到文件中
	}
}

//清除操作
void WorkerManager::clear_file()
{
	int select;
	cout << "确定清空吗？ " << endl;
	cout << "1-确定 ";
	cout << "2-取消 " << endl;
	cin >> select;

	if (select == 1) {
		//清空文件
		ofstream ofs(FILENAME ,ios::trunc);  //删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL) {
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区的数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "清空成功！" << endl;
	}
	//system("clear");
}

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME ,ios::in);  //读文件
	if (!ifs.is_open()) { //  1、文件不存在时初始化流程
		cout << "文件不存在！" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
    	this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//  2、文件存在，但是数据为空的情况
	char ch;
	ifs >> ch;
	if(ifs.eof()) {  //文件为空
		cout << "文件为空！" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
    	this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//  3、文件存在，并且有记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为： " << num << endl;

	this->m_EmpNum = num;  //更新员工人数,因为文件中就有员工，所以要加上文件中的人数

	this->m_EmpArray = new Worker*[this->m_EmpNum];  //为数组开辟空间
	this->init_Emp();  //将文件中的数据存储到程序中的数组中
}

//显示职工
void WorkerManager::show_emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	}

	for (int i = 0; i < this->m_EmpNum; i++) {
		//利用多态调用程序接口
		this->m_EmpArray[i]->show_Info();
	}
	//清屏
	// system("clear");
}

void WorkerManager::init_Emp()
{
	string name;
	int id;
	int d_id;
	int index = 0;

	ifstream ifs;
	ifs.open(FILENAME ,ios::in); //读文件

	while (ifs >> id && ifs >> name && ifs >> d_id) {
		Worker *worker = NULL;
		if (d_id == 1) {        //普通员工
			worker = new Employee(id ,name ,d_id);
		} else if(d_id == 2) {  //经理
			worker = new Manager(id ,name ,d_id);
		} else if(d_id == 3) {  //老板
			worker = new Boss(id ,name ,d_id);
		} else {
			/* do nothing */
		}

		this->m_EmpArray[index++] = worker;
	}

	ifs.close();
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
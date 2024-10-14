#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->InitSpeech();

//  创建 12 名选手
	this->GreateSpeaker();

//  加载往届记录
	this->LoadRecord();
}

void SpeechManager::InitSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vvictory.clear();
	this->m_Speaker.clear();

	this->m_Index = 1;

	this->m_Record.clear();
}

void SpeechManager::GreateSpeaker()
{
	std::string nameSeed = "ABCDEFGHIJKL";
	for (size_t i = 0; i < nameSeed.size(); i++) {
		std::string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (size_t j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}
	
	//  初始化选手的编号  
		this->v1.push_back(i + 10001);

	//  将选手编号和对应的选手对应起来
		this->m_Speaker.insert(std::make_pair(i + 10001, sp));
	}
}

/*
	用m_Index来判断是第几轮抽签
	用random_shuffle()来给v1与v2容器洗牌，
	这样就得到了每一轮抽签的结果
*/
void SpeechManager::SpeechDraw()
{
	std::cout << "第 << " << this->m_Index << " >>轮选手正在抽签！" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "抽签的结果如下：" << std::endl;

	if(this->m_Index == 1) {
		// 第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (auto it = v1.begin(); it != v1.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

	} else {
		// 第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (auto it = v2.begin(); it != v2.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
}

void SpeechManager::SpeechContest()
{
	std::cout << "第 << " << this->m_Index << " >>场比赛正式开始！" << std::endl;
	std::cout << "--------------------------" << std::endl;

//  通过准备临时的容器，存放小组成绩
//  创建一个按照降序排序的 std::multimap
	std::multimap<double, int, std::greater<double>> grourpSource;

	int num = 0;  // 记录人员的个数，六人一组

	std::vector<int> v_Src; // 比赛选手的容器
	if(this->m_Index == 1) {
		v_Src = v1;
	} else {
		v_Src = v2;
	}

//  遍历所有选手
	for (auto it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;
		//  10个评委打分， 将分数存放到 score 中
		std::deque<double> d;
		for (size_t i = 0; i < 10; i++) {
			double score = (rand()%401 + 600) / 10.f;
			//std::cout << "score = " << score << " ";
			d.push_back(score);
		}
		// std::cout << std::endl;

	//  将分数排序, 降序排列
		sort(d.begin(), d.end(), std::greater<double>());

	//  去除最高分
		d.pop_front();
	//  去除最低分
		d.pop_back();

	//  累加总分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
	//  平均分
		double avg = sum / (double)d.size();

		// std::cout << "编号：" << *it << "选手name: " << this->m_Speaker[*it].m_Name \
		// 					<< "平均分："<< avg << std::endl;

	//  将平均分放到 map 容器
	//  m_Speaker[*it]: 通过 key 访问到 value, 也就是通过编号找到对应的选手
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

	//  将打分数据放入到临时的小组容器中
	//  key 是得分， value 是具体选手的编号
		grourpSource.insert(std::make_pair(avg, *it));

	//  每6人取出前3名
		if(num % 6 == 0) {  // num = 6 和 等于 12 才会进入
			std::cout << "第" << num/6 << "小组比赛成绩如下：" << std::endl;
			for (auto it = grourpSource.begin(); it != grourpSource.end(); it++) {
				std::cout << "编号：" << it->second << "  name = " << this->m_Speaker[it->second].m_Name << "  成绩 = " << \
					this->m_Speaker[it->second].m_Score[this->m_Index - 1] << std::endl;
			}

			// 取走前三名, 因为是降序排列，所以前三个就是最高分
			int count = 0;
			for (auto it = grourpSource.begin(); it != grourpSource.end() && count < 3; it++, count++) {
				if(this->m_Index == 1) {
					v2.push_back((*it).second);
				} else {
					vvictory.push_back((*it).second);
				}
			}
			grourpSource.clear();  // 清空小组容器
		}
	}
	std::cout << "第" << this->m_Index << "轮比赛完毕！" << std::endl;
}

void SpeechManager::ShowScore()
{
	std::cout << "----------第" << this->m_Index << "轮" << "晋级的选手信息如下：----------" << std::endl;

	std::vector<int> v;
	if(this->m_Index == 1) {
		v = v2;
	} else {
		v = vvictory;
	}

	for (auto it = v.begin(); it != v.end(); it++) {
		std::cout << "选手编号：" << *it << "姓名：" << this->m_Speaker[*it].m_Name <<\
				 "得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << std::endl;
	}
	this->ShowMenu();
}

void SpeechManager::StartSpeech()
{
//第一轮开始比赛
	//1、抽签
	this->SpeechDraw();
	//2、比赛
	this->SpeechContest();
	//3、显示晋级结果
	this->ShowScore();
//第二轮开始比赛
	this->m_Index++;
	//1、抽签
	this->SpeechDraw();
	//2、比赛
	this->SpeechContest();
	//3、显示最终结果
	this->ShowScore();
	//4  保存分数到文件中
	this->SaveRecord();

//如果不加后面三行代码，调用几次 StartSpeech 函数就会出现系统崩溃
//重置比赛，需要从文件中重新获取记录
	this->InitSpeech();
//  创建 12 名选手
	this->GreateSpeaker();
//  加载往届记录
	this->LoadRecord();

	std::cout << "本届演讲比赛结束" << std::endl;
}

void SpeechManager::ShowMenu()
{
    std::cout << "****************************************" << std::endl;
	std::cout << "************欢迎参加演讲比赛************" << std::endl;
	std::cout << "************1、开始演讲比赛*************" << std::endl;
	std::cout << "************2、查看往届记录*************" << std::endl;
	std::cout << "************3、清空比赛记录*************" << std::endl;
	std::cout << "************0、退出比赛程序*************" << std::endl;
	std::cout << "****************************************" << std::endl;
}

void SpeechManager::ExitSystem()
{
	std::cout << "欢迎下次使用" << std::endl;
	exit(0);
}

void SpeechManager::SaveRecord()
{
	std::ofstream ofs;

	ofs.open("spech.csv", std::ios::out | std::ios::app);  // 用追加的方式写文件

//  将最后冠军的数据写入到文件中
	for (std::vector<int>::iterator it = vvictory.begin(); it != vvictory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";  //冠军
	}
	ofs << std::endl;

	ofs.close();
	std::cout << "文件已经保存完毕" << std::endl;
	this->FileIsEmpty = false;
}

void SpeechManager::LoadRecord()
{
	std::ifstream ifs("spech.csv", std::ios::in);  // 读文件
	if (!ifs.is_open()) {
		this->FileIsEmpty = true;
		std::cout << "文件不存在" << std::endl;
		ifs.close();
		return ;
	}

	//  文件被清空的情况
	char ch;
	ifs >> ch;
	if(ifs.eof()) {
		std::cout << "文件为空" << std::endl;
		this->FileIsEmpty = true;
		ifs.close();
		return ;
	}

//  文件不为空
	this->FileIsEmpty = false;
	ifs.putback(ch);  // 将上面读取的单个字符再放回去

	std::string data;
	int index = 0;  // 第几届选手的成绩

	while (ifs >> data) {
		int pos = -1;  // 查到 "," 位置的变量
		int start = 0;  // 起始位置
		std::vector<std::string> v;

		while (true) {
			pos = data.find(",", start);  // 会返回 "," 的位置
			if(pos == -1) {
				break;  // 找完了就退出
			}

			std::string temp = data.substr(start, pos - start);
			// std::cout << temp << std::endl;
			v.push_back(temp);  // 将每一届选手的信息放到 V 中
			start = pos + 1;
		}

//  通过是那一届的 index 编号就能够找到对应届的选手名字和成绩
		this->m_Record.insert(std::make_pair(index, v));
		index++;
	}

	ifs.close();
}

void SpeechManager::showRecord()
{
	if(this->FileIsEmpty) {
		std::cout << "文件为空或者不存在" << std::endl;
		return ;
	}

	// for (int i = 0; i < this->m_Record.size(); i++) {
	// 	std::cout << "第" << i + 1 << "届 " <<
	// 		"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
	// 		"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
	// 		"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << std::endl;
	// }

	for (auto it = this->m_Record.begin(); it != this->m_Record.end(); it++) {
		std::cout << "第" << it->first + 1 << "界的冠军编号: " << it->second[0] << " 成绩：" << it->second[1] \
		<< " 亚军编号: " << it->second[2] << " 成绩：" << it->second[3] \
		<< " 季军编号: " << it->second[4] << " 成绩：" << it->second[5] << std::endl;
	}
}

void SpeechManager::ClearRecord()
{
	std::cout << "是否确定清空文件？" << std::endl;
	std::cout << "1 是 / 2 否" << std::endl;

	int select = 0;
	std::cin >> select;
	if(select == 1) {
		std::ofstream ofs("spech.csv", std::ios::trunc);
		ofs.close();

		this->InitSpeech();
	//  创建 12 名选手
		this->GreateSpeaker();

	//  加载往届记录
		this->LoadRecord();
		std::cout << "清空成功" << std::endl;
	}

	std::cout << "请按任意键继续" << std::endl;
}

SpeechManager::~SpeechManager()
{

}
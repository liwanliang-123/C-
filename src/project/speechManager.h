#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>

#include "speaker.h"

// 演讲管理类
class SpeechManager {
public:
    SpeechManager();

    void ShowMenu();

    void ExitSystem();

    void InitSpeech();

//  创建 12 名选手
    void GreateSpeaker();

//  开始比赛
    void StartSpeech();

//  抽签
    void SpeechDraw();

//  比赛函数
    void SpeechContest();

//  显示得分
    void ShowScore();

//  保存记录
    void SaveRecord();

//  读取记录
    void LoadRecord();

//  显示往届记录
    void showRecord();

//  判断文件是否为空
    bool FileIsEmpty;

//  清空文件
    void ClearRecord();

//  存放往届记录的容器
    std::map<int, std::vector<std::string>> m_Record;

    ~SpeechManager();

//  成员属性
//  保存第一轮选手编号的容器
    std::vector<int> v1;

//  第一轮晋级选手编号容器
	std::vector<int>v2;

//  胜出前三名选手编号容器
	std::vector<int>vvictory;

//  存放编号以及对应选手容器
	std::map<int, Speaker>m_Speaker;

//  记录比赛轮数
	int m_Index;
};
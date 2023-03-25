#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>
#include"speaker.h"
using namespace std;
/*
	1.提供惨淡界面与用户交互
	2.对演讲比赛流程进行控制
	3.与文件读写交互
*/
class SpeechManager
{
public:
	vector<int> v1;				//比赛选手		12人 第一轮
	vector<int> v2;				//第一轮晋级		6人
	vector<int> vVectory;		//晋级			3人
	map<int, Speaker> m_Speaker;//编号，具体选手	map容器
	int m_Index;				//比赛轮数
	map<int, vector<string>> m_Record;		//存放往届记录
	bool fileIsEmpty;			//file是否为空


	SpeechManager();
	void show_Menu();
	void initSpeech();			//初始化容器属性
	void createSpeaker();		//创建12名选手
	void exit_Sys_0();
	void speechDraw();			//抽签
	void speechContest();		//竞赛
	void showScore();			//显示得分
	void saveRecord();			//Save 记录
	void startSpeech_1();			//开始整个流程
	void loadRecode();			//读取往届记录
	void showRecode_2();			//查看记录
	void clearRecode_3();
	

	~SpeechManager();
};


class printVectorInt{
public:
	void operator()(int val) {
		cout << val << " ; ";
	}
};
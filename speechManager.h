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
	1.�ṩ�ҵ��������û�����
	2.���ݽ��������̽��п���
	3.���ļ���д����
*/
class SpeechManager
{
public:
	vector<int> v1;				//����ѡ��		12�� ��һ��
	vector<int> v2;				//��һ�ֽ���		6��
	vector<int> vVectory;		//����			3��
	map<int, Speaker> m_Speaker;//��ţ�����ѡ��	map����
	int m_Index;				//��������
	map<int, vector<string>> m_Record;		//��������¼
	bool fileIsEmpty;			//file�Ƿ�Ϊ��


	SpeechManager();
	void show_Menu();
	void initSpeech();			//��ʼ����������
	void createSpeaker();		//����12��ѡ��
	void exit_Sys_0();
	void speechDraw();			//��ǩ
	void speechContest();		//����
	void showScore();			//��ʾ�÷�
	void saveRecord();			//Save ��¼
	void startSpeech_1();			//��ʼ��������
	void loadRecode();			//��ȡ�����¼
	void showRecode_2();			//�鿴��¼
	void clearRecode_3();
	

	~SpeechManager();
};


class printVectorInt{
public:
	void operator()(int val) {
		cout << val << " ; ";
	}
};
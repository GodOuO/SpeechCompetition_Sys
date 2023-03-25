#include<iostream>
#include<string>
#include <ctime>
#include"speechManager.h"
#include"speaker.h"

using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	SpeechManager sm;
//test:
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); ++it) {
	//	double* arr = it->second.getScore();
	//	cout << "Test ID: " << it->first
	//		<< "\t Name: " << it->second.getName()
	//		<< "\t Score: " << arr[0] << endl;
	//}
	
	int inputChoice = -1;
	while (1) {
		sm.show_Menu();
		cout << "Please input Your Choice :" << endl;
		cin >> inputChoice;
		switch (inputChoice) {
		case 1:		//开始比赛
			sm.startSpeech_1();
			break;
		case 2:		//往届记录
			sm.showRecode_2();
			break;
		case 3:		//清空记录
			sm.clearRecode_3();
			break;
		case 0:		//退出
			sm.exit_Sys_0();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
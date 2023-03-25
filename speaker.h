#pragma once
#include <iostream>
using namespace std;

class Speaker
{
public:
	void setSpeakerName(string name);
	void setSpeakerS1(double a);
	void setSpeakerS2(double a);
	string getName();
	double* getScore();

private:
	string m_Name;
	double* m_Score = new double[2];		//两轮得分，数组
};

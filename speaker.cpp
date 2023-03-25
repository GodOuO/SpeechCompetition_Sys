#include"speaker.h"
#include<string>
using namespace std;

void Speaker::setSpeakerName(string name) {
	this->m_Name = name;
}

void Speaker::setSpeakerS1(double a) {
	this->m_Score[0] = a;
}

void Speaker::setSpeakerS2(double a) {
	this->m_Score[1] = a;
}

string Speaker::getName() {
	return m_Name;
}
double* Speaker::getScore() {
	return this->m_Score;
/*
	Speaker s;
		string name = "GodOuO";
		double score[2] = { 12,34.5 };
		s.setSpeaker(name, score);
		double* arr = s.getScore();
		cout << arr[0] << arr[1];
		delete[] arr;
*/
}

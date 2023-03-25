#include"speechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeech();		//��ʼ����������
	this->createSpeaker();	//����12��ѡ��
	this->loadRecode();		//��������
}

void SpeechManager::show_Menu() {
	cout << "*******************************" << endl
		<< "*****SpeechCompetition_Sys*****" << endl
		<< "**********#1.Start   **********" << endl
		<< "**********#2.Histry  **********" << endl
		<< "**********#3.Clean   **********" << endl
		<< "**********#0.Quit    **********" << endl << endl;
}

void SpeechManager::exit_Sys_0() {
	cout << "Bye Bye !!!" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech() {
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVectory.clear();
	this->m_Speaker.clear();
	//index�ÿ�
	this->m_Index = 1;

	this->m_Speaker.clear();
}

void SpeechManager::createSpeaker() {
	string nameSpace = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSpace.length(); ++i)
	{
		string name = "Name";
		name += nameSpace[i];
		Speaker s;
		s.setSpeakerName(name);
		s.setSpeakerS1(0.0);
		s.setSpeakerS2(0.0);

		this->v1.push_back(i + 10001);		//ѡ�ֱ�� ����v1
		this->m_Speaker.insert(make_pair(i + 10001, s));//ѡ�ֱ�� �Ͷ�Ӧѡ�� ����map
	}
}

void SpeechManager::speechDraw() {
	cout << "The No.(" << this->m_Index << ") Round's Player is Drawing..." << endl
		<< "-----------------------------------------------------" << endl
		<< "The Order is :" << endl;

	if (1 == this->m_Index) {			//Round 1
		random_shuffle(v1.begin(),v1.end());
		for_each(v1.begin(), v1.end(), printVectorInt());
	}
	else if (2 == this->m_Index) {		//Round 2
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), printVectorInt());
	}
	cout <<endl
		<< "-----------------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest() {
	cout << "The No.(" << this->m_Index << ") Round's Contest is Fighting..." << endl
		<< "-----------------------------------------------------" << endl;
	vector<int> v_Player;		//����ѡ������
	multimap<double, int, greater<double>> groupScore;		//׼����ʱ���������С��ɼ�
	int num = 0;		//��¼��Ա����	6��һ��

	if (1 == this->m_Index) {
		v_Player = this->v1;
	}
	else if (2 == this->m_Index) {
		v_Player = this->v2;
	}
	for (vector<int>::iterator it= v_Player.begin(); it != v_Player.end(); ++it){	//��������ѡ��
		deque<double> d;		//��ί���
		++num;					//ͳ������
		for (int i = 0; i < 10; ++i)
		{
			double score = (rand() % 401 + 600) / 10.f;			//(600-1000) /10.f
			//test:
			// cout<<"Test:"<<endl;
			//cout << score << " ; ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());	//��������

		d.pop_front();		//del Top
		d.pop_back();		//del Last

		double sum = accumulate(d.begin(), d.end(), 0.0f);		//��ʼ�ۼ�ֵ 0.0fС��
		double avg = sum / (double)d.size();					//ƽ����

		if (1 == m_Index)
			this->m_Speaker[*it].setSpeakerS1(avg);			//ƽ���� ���� map����
		else if(2 == m_Index)
			this->m_Speaker[*it].setSpeakerS2(avg);			//ƽ���� ���� map����

		groupScore.insert(make_pair(avg, *it));				//key =ƽ���ɼ���value =ID
		if (0 == num % 6) {			//ÿ������ ȡǰ��
			cout << "No.<" << num / 6 << "> group��s Contest List: " << endl
				 << "-----------------------------------------------------" << endl;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); ++it)
			{
				double* arr = this->m_Speaker[it->second].getScore();
				cout << "ID: " << it->second
					<< "\tName: " << this->m_Speaker[it->second].getName()
					<< "\tScore: " << arr[this->m_Index - 1]<<endl;
			}

			//ȡ��ǰ��
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; ++it,++count)
			{
				if (1 == this->m_Index)
					this->v2.push_back((*it).second);
				else 
					this->vVectory.push_back((*it).second);
			}
			groupScore.clear();		//del ���� ��ɼ�
			cout << endl;
		}

		/*
		cout << "Test:" << endl;
		double* arr = this->m_Speaker[*it].getScore();
		cout << "ID: " << *it
			<< "\tName: " << this->m_Speaker[*it].getName()
			<< "\tScore: " << arr[0];
		*/
	}			
	cout << "No.(" << this->m_Index << ") group��s Contest Done!!! " << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::showScore() {
	cout << "The No.(" << this->m_Index << ") Round's Winner List:" << endl
		<< "-----------------------------------------------------" << endl;

	vector<int> v;

	if (1 == this->m_Index)
	{
		v = v2;
	}
	else if (2 == this->m_Index) {
		v = vVectory;
	}
	
	for (vector<int>::iterator it = v.begin(); it!= v.end(); ++it)
	{
		double* arr = this->m_Speaker[*it].getScore();
		cout << "ID: " << *it
			<< "\tName: " << this->m_Speaker[*it].getName()
			<< "\tScore: " << arr[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv",ios::out | ios::app);		//׷�� д��
	for (vector<int>::iterator it = vVectory.begin(); it != vVectory.end(); ++it)	//����д���ļ�
	{
		double* arr = this->m_Speaker[*it].getScore();		//���Ǽ�����
		ofs << *it << "," << arr[1] << ",";
	}
	ofs << endl;

	ofs.close();
	this->fileIsEmpty = false;
	cout << "Save it!!!" << endl;
}

void SpeechManager::startSpeech_1(){
	//��һ�ֱ�����1.��ǩ��2.������3.��ʾ���
	this->speechDraw();
	this->speechContest();
	this->showScore();
	//�ڶ��ֱ�����1.��ǩ��2.������3.��ʾ���
	++m_Index;
	this->speechDraw();
	this->speechContest();
	this->showScore();
	//����������ļ�
	this->saveRecord();
	//���ñ�������ȡ��¼
	this->initSpeech();		//��ʼ����������
	this->createSpeaker();	//����12��ѡ��
	this->loadRecode();		//��������
	cout << endl << "This Round is Finished!!!" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::showRecode_2() {
	if (this->fileIsEmpty)
	{
		cout << "File is Empty!!!" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); ++i)
		{
			cout << " NO.(" << i + 1 << ") Round Champion's ID: " << this->m_Record[i][0]
				<< "\tScore: " << this->m_Record[i][1] << endl;
			cout << " NO.(" << i + 1 << ") Round <No.2>'s ID: " << this->m_Record[i][2]
				<< "\tScore: " << this->m_Record[i][3] << endl;
			cout << " NO.(" << i + 1 << ") Round <No.3>'s ID: " << this->m_Record[i][4]
				<< "\tScore: " << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::loadRecode() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())		//�ļ�������
	{
		this->fileIsEmpty = true;
		//cout << "File is NOT Exist !!!" << endl;
		ifs.close();
		return;
	}

	//�ļ����
	char c;
	ifs >> c;
	if (ifs.eof()) {
		this->fileIsEmpty = true;
		//cout << "File is Empty !!!" << endl;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;
	ifs.putback(c);			//�����Ķ�ȡ�����ַ� ���

	string data; 
	int index = 0;			//�ڼ���
	while (ifs >> data) {
		//test:
		//cout << data << endl;

		int loc = -1;			//�鵽������ loc
		int start = 0;
		
		vector<string> vtemp;		//��� 6�� string �ַ���

		while (1)
		{
			loc = data.find(",", start);
			if (-1 == loc) {			//δ�ҵ� ������
				break;
			}
			string temp = data.substr(start, loc - start);
			//test:
			//cout << temp << endl;
			vtemp.push_back(temp);
			start = loc + 1;
		}
		this->m_Record.insert(make_pair(index, vtemp));
		++index;
	}
	ifs.close();
	// test:
	// for (map<int,vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end() ; ++it)
	//{
	//	cout << it->first
	//		<< " Winner ID: " << it->second[0]
	//		<< "\tScore: " << it->second[1] << endl;
	//}

}

void SpeechManager::clearRecode_3(){
	cout << endl << "Sure ?" << endl << "1.Yes" << endl << "2.No" << endl;
	int select = 0;
	cin >> select;
	if (1 == select) {
		//ios::trunc ����ļ����ڣ�ɾ���ļ� ���´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ��
		this->initSpeech();		//��ʼ����������
		this->createSpeaker();	//����12��ѡ��
		this->loadRecode();		//��������

		cout << "Clean Done!" << endl;
	}
	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{
}
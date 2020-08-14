#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<string>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager : public Identity //ע��д��
{
public:


	//Ĭ�Ϲ��캯��
	Manager ();

	//�вι��캯��
	Manager(string name, string pwd);

	//����Ա����չʾ
	virtual void operMeun();


	//����˺�
	void AddAccout();

	//�鿴�˺�
	void CheckAccout();

	//�鿴������Ϣ
	void CheckComputer();

	//���ԤԼ��¼
	void CleanOrder();

	//������ʼ��--���ڱ��ȥ��
	void InitVector();

	vector<Student>vStu;//ѧ������
	vector<Teacher>vTea;//��ʦ����
	vector<computerRoom>vComsize;//��������

	//�鿴�Ƿ��ظ�
	bool checkRepeat(int id, int type);
};
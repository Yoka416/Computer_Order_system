#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include "computerRoom.h"
#include<fstream>
#include"globalfile.h"
#include "orderFile.h"

class Student : public Identity
{
public:

	//ѧ��ѧ��
	int S_Id;

	//Ĭ�Ϲ��캯��
	Student();

	//�вι��캯��
	Student(int Id,string name, string pwd);

	//ѧ������չʾ
	virtual void operMeun();

	//����ԤԼ
	void ApplyOrder();

	//�鿴�ҵ�ԤԼ
	void ShowmyOrder();

	//�鿴����ԤԼ
	void ShowallOrder();

	//ȡ��ԤԼ
	void CancelOrder();

	//ѧ������,�ѻ�������Ϣ��ŵ������������
	vector<computerRoom>vCom;//



};
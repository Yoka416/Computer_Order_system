#pragma once
#include<iostream>
using namespace std;
#include <map>
#include <string>

class orderfile
{
public:
	//���캯��
	orderfile();

	//����ԤԼ����
	void updateorder();

	//��¼ԤԼ����
	int m_ordersize;

	//����������ԤԼ�ļ���ԤԼ��Ϣ���������Լ����е���Ϣ
	map<int, map<string,string>>m;
};
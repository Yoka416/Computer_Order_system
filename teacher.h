#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include"student.h"

#include<string>

class Teacher : public Identity
{
public:

	//��ʦ���
	int T_Id;

	//Ĭ�Ϲ��캯��
	Teacher();

	//�вι��캯��
	Teacher(int num,string name, string pwd);

	//��ʦ����չʾ
	virtual void operMeun();//������Ʊ���͸���һ������Ȼ�ᱨ��û��ʵ��������


	//�鿴����ԤԼ
	void TShowallOrder();

	//���ԤԼ
	void TCheckOrder();

};
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

	//学生学号
	int S_Id;

	//默认构造函数
	Student();

	//有参构造函数
	Student(int Id,string name, string pwd);

	//学生界面展示
	virtual void operMeun();

	//申请预约
	void ApplyOrder();

	//查看我的预约
	void ShowmyOrder();

	//查看所有预约
	void ShowallOrder();

	//取消预约
	void CancelOrder();

	//学生容器,把机房的信息存放到这个容器里面
	vector<computerRoom>vCom;//



};
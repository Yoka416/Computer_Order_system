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

class Manager : public Identity //注意写法
{
public:


	//默认构造函数
	Manager ();

	//有参构造函数
	Manager(string name, string pwd);

	//管理员界面展示
	virtual void operMeun();


	//添加账号
	void AddAccout();

	//查看账号
	void CheckAccout();

	//查看机房信息
	void CheckComputer();

	//清空预约记录
	void CleanOrder();

	//容器初始化--用于编号去重
	void InitVector();

	vector<Student>vStu;//学生容器
	vector<Teacher>vTea;//老师容器
	vector<computerRoom>vComsize;//机房容器

	//查看是否重复
	bool checkRepeat(int id, int type);
};
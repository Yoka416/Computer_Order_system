#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include"student.h"

#include<string>

class Teacher : public Identity
{
public:

	//教师编号
	int T_Id;

	//默认构造函数
	Teacher();

	//有参构造函数
	Teacher(int num,string name, string pwd);

	//老师界面展示
	virtual void operMeun();//这个名称必须和父类一样，不然会报错没有实例化对象


	//查看所有预约
	void TShowallOrder();

	//审核预约
	void TCheckOrder();

};
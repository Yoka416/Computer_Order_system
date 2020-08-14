#pragma once
#include<iostream>
using namespace std;
#include<string>

class Identity
{
public:
	string m_name;//姓名
	string m_pwd;//密码

	virtual void operMeun()=0;//对应界面展示
};
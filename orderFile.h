#pragma once
#include<iostream>
using namespace std;
#include <map>
#include <string>

class orderfile
{
public:
	//构造函数
	orderfile();

	//更新预约函数
	void updateorder();

	//记录预约条数
	int m_ordersize;

	//这个用来存放预约文件中预约信息的条数，以及所有的信息
	map<int, map<string,string>>m;
};
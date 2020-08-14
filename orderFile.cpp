#include "orderFile.h"
#include<fstream>
#include"globalfile.h"
#include <string>
    //构造函数
	orderfile::orderfile()
	{
		ifstream ifs;
		ifs.open(ORDER,ios::in);

		//接收预约文件中的信息
		string data;
		string interval;
		string StuId;
		string StuName;
		string computer;//机房
		string state;//状态
		
		
		map<string,string>m2;//用来存储预约信息，第一个预约项目，第二个预约数值

		this->m_ordersize=0;//!!
		while(ifs>>data && ifs>>interval && ifs>>StuId && ifs>>StuName && ifs>>computer && ifs>>state)
		{
			/*cout<<data<<"  ";
			cout<<interval<<"  ";
			cout<<StuId<<"  ";
			cout<<StuName<<"  ";
			cout<<computer<<"  ";
			cout<<state<<endl;
			cout<<endl;*/
			
			//下面两个变量只需要定义一次
			string key;
			string value;

			

			//日期
			int pos =data.find("：");//!pos定义一下就可以！!
			if(pos!=-1)//！！切记判断！！
			{
				 key = data.substr(0,pos);//0代表从0开始，pos表示截取pos个
				 value=data.substr(pos+2,data.size()-pos-1);//截取对应的日期数值
				 m2.insert(make_pair(key,value));//将这两个数据存到容器中
			}
			
			//时段：
			pos =interval.find("：");
			if(pos!=-1)
			{
				 key = interval.substr(0,pos);//0代表从0开始，pos表示截取pos个
				 value=interval.substr(pos+2,interval.size()-pos-1);//截取对应的日期数值
				 m2.insert(make_pair(key,value));//将这两个数据存到容器中
			}
			//学号
			pos =StuId.find("：");
			if(pos!=-1)
			{
				 key = StuId.substr(0,pos);//0代表从0开始，pos表示截取pos个
				 value=StuId.substr(pos+2,StuId.size()-pos-1);//截取对应的日期数值
				 m2.insert(make_pair(key,value));//将这两个数据存到容器中
			}
			//姓名
			pos =StuName.find("：");
			if(pos!=-1)
			{
				 key = StuName.substr(0,pos);//0代表从0开始，pos表示截取pos个
				 value=StuName.substr(pos+2,StuName.size()-pos-1);//截取对应的日期数值
				 m2.insert(make_pair(key,value));//将这两个数据存到容器中
			}
			//机房
			pos =computer.find("：");
			if(pos!=-1)
			{
				 key =  computer.substr(0,pos);//0代表从0开始，pos表示截取pos个
				 value= computer.substr(pos+2, computer.size()-pos-1);//截取对应的日期数值
				 m2.insert(make_pair(key,value));//将这两个数据存到容器中
			}
			//状态
			pos =state.find("：");
			if(pos!=-1)
			{
				 key = state.substr(0,pos);//0代表从0开始，pos表示截取pos个
				 value=state.substr(pos+2,state.size()-pos-1);//截取对应的日期数值
				 m2.insert(make_pair(key,value));//将这两个数据存到容器中
			}

			this->m.insert(make_pair(this->m_ordersize,m2));
			this->m_ordersize++;
			m2.clear();
		}
		ifs.close();

		//测试是否放到容器中

		//for(map<int, map<string,string>>::iterator it=m.begin(); it!=m.end();it++)
		//{
		//	cout<<"预约第"<<it->first<<"条："<<endl;
		//	for(map<string,string>::iterator itm =(*it).second.begin(); itm!=(*it).second.end(); itm++)
		//	{
		//		cout<<itm->first<<":"<<itm->second<<"  ";
		//		//J R S X X Z打印出来的顺序是按照key首字母排列的
		//	}
		//	cout<<endl;
		//}
		//system("pause");
		//system("cls");
	}

	//更新预约函数
	void orderfile::updateorder()
	{
		if(this->m_ordersize==0)
		{
			return;
		}
		ofstream ofs;
		ofs.open(ORDER,ios::out|ios::trunc);
		//trunc代表清空再写入

		for(int i=0; i<this->m_ordersize;i++)
		{
			ofs<<"日期："<<this->m[i]["日期"]<<"  ";//!因为这里的冒号是英文的导致无法输出!
			ofs<<"时段："<<this->m[i]["时段"]<<"  ";
			ofs<<"学号："<<this->m[i]["学号"]<<"  ";
			ofs<<"姓名："<<this->m[i]["姓名"]<<"  ";
			ofs<<"机房："<<this->m[i]["机房"]<<"  ";
			ofs<<"状态："<<this->m[i]["状态"]<<endl;
		}
		ofs.close();
	}

	//记录预约条数
	int m_ordersize;
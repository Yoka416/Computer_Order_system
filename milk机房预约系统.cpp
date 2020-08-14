#include<iostream>
using namespace std;
#include<string>
#include "Identity.h"
#include <fstream>
#include "globalfile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include<string>

//管理员登进去之后界面函数
void ManagerMeun(Identity * &manager)
{
	while(true)
	{
		//将展示界面指向管理类
		manager->operMeun();
		Manager * man = (Manager*)manager;
		
		int select = 0;
		cin>>select;
		if(select==1)//添加账号
		{
			//cout<<"添加账号！"<<endl;
			man->AddAccout();
		}
		else if(select==2)//查看账号
		{
			//cout<<"查看账号！"<<endl;
			man->CheckAccout();
		}
		else if(select==3)//查看机房
		{
			//cout<<"查看机房！"<<endl;
			man->CheckComputer();
		}
		else if(select==4)//清空预约
		{
			//cout<<"清空预约！"<<endl;
			man->CleanOrder();
		}
		else
		{
			delete manager;
			cout<<"注销成功！"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生登录后界面
void StudentMeun(Identity * &student)
{
	while(true)
	{
		//将展示界面指向管理类
		student->operMeun();
		Student * man = (Student*)student;
		
		int select = 0;
		cin>>select;
		if(select==1)//申请预约
		{
			//cout<<"申请预约！"<<endl;
			man->ApplyOrder();
		}
		else if(select==2)//查看我的预约
		{
			//cout<<"查看我的预约！"<<endl;
			man->ShowmyOrder();
		}
		else if(select==3)//查看所有预约
		{
			//cout<<"查看所有预约！"<<endl;
			man->ShowallOrder();
		}
		else if(select==4)//取消预约
		{
			//cout<<"取消预约！"<<endl;
			man->CancelOrder();
		}
		else
		{
			delete student;
			cout<<"注销成功！"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity * &teacher)
{
	while(true)
	{
		teacher->operMeun();
		Teacher *tea = (Teacher *)teacher;
		int select=0;
		
		//cout<<"请输入您的选择：";
		cin>>select;

		if(select==1)//查看所有预约
		{
			tea->TShowallOrder();

		}else if(select==2)//审核预约
		{
			tea->TCheckOrder();
		}else
		{
			delete teacher;
			cout<<"注销登录成功！"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录函数
void LogIn(string filename, int type)
{
	Identity *person = NULL;
	ifstream ifs(filename,ios::in);


	//判断文件是否存在
	if(!ifs.is_open())//注意是.is_open()不是.open()
	{
		cout<<"文件为空或不存在！"<<endl;
		//经常忘下面两个
		ifs.close();
		return;
	}

	int Id=0;
	string name;
	string Pwd;


		if(type==1)
	{
		cout<<"请输入您的学号："<<endl;
		cin>>Id;
	}
	else if(type==2)
	{
		cout<<"请输入您的职工编号："<<endl;
		cin>>Id;//和学号用的同一个变量
	}
		cout<<"请输入用户姓名："<<endl;
		cin>>name;
		cout<<"请输入密码："<<endl;
		cin>>Pwd;

	//接下来进行验证

		int fId=0;
		string fname;
		string fPwd;

	if(type==1)
	{
			while(ifs>>fId && ifs>>fname && ifs>>fPwd)//遍历文件中的数据
			{
				//从文件中获取数据与输入的数据进行对比
				if(Id==fId && name==fname && Pwd==fPwd)
				{
					cout<<"验证通过，欢迎进入学生系统！"<<endl;
					system("pause");
					system("cls");
					person = new Student(Id,name,Pwd);
					StudentMeun(person);
					return;//不退出的话就会执行后面的“输入错误，请重新输入”
				}	
			}
	}
	else if(type==2)
	{
		while(ifs>>fId && ifs>>fname && ifs>>fPwd)//遍历文件中的数据
			{
				if(Id==fId && name==fname && Pwd==fPwd)
				{
						cout<<"验证通过，欢迎进入教师系统！"<<endl;
						system("pause");
						system("cls");
						person =new Teacher(Id,name,Pwd);
						TeacherMenu(person);
						return;
				}							
			}
	}
	else if(type == 3)
	  {
		while(ifs>>fname && ifs>>fPwd)//遍历文件中的数据
			{
				if(name==fname && Pwd==fPwd)
				{
					cout<<"验证通过，欢迎进入管理员系统！"<<endl;
					system("pause");
					system("cls");
					person = new  Manager(name,Pwd);
					//一旦类中有了纯虚函数，那么这个类就被称为纯虚函数
					ManagerMeun(person);//进入到管理员菜单
//!!!!!!!！！！！！！！！！！！!!一定要把ManagerMeun()函数放到前面，否则会显示找不到标识符！！！！！！！！！！！！！！！
					return;
				}	
			}
	  }
	
		cout<<"输入错误，请重新输入！"<<endl;
		system("pause");
		system("cls");
		return;//不加这个无法返回上一个界面

}

int main()
{

	int select=0;
	
	while(true)//！不加while循环每次学生或者老师管理员注销登录都会直接退出！
	{
			cout<<"===========================欢迎来到牛奶机房预约系统！==============================="<<endl;
			cout<<"请输入您的身份："<<endl;
			cout<<"\t\t ------------------------------- "<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          1、学    生          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          2、老    师          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          3、管 理 员          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          0、退    出          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t ------------------------------- "<<endl;
			cout<<"请输入您的选择：";
			cin>>select;

			switch(select)
			{
				case 1: //显示学生接口
					LogIn(STUDENT, 1);
					break;
				case 2://显示老师接口
					LogIn(TEACHER, 2);
					break;
				case 3://显示管理员接口
					LogIn(MANAGER, 3);
					break;
				case 0:
					cout<<"欢迎下次光临！"<<endl;
					system("pause");
					system("cls");
					return 0;
					break;
				default:
					system("pause");
					system("cls");
					//return;
					break;
			}
	}

	system("pause");
	return 0;
}
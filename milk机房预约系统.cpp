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

//����Ա�ǽ�ȥ֮����溯��
void ManagerMeun(Identity * &manager)
{
	while(true)
	{
		//��չʾ����ָ�������
		manager->operMeun();
		Manager * man = (Manager*)manager;
		
		int select = 0;
		cin>>select;
		if(select==1)//����˺�
		{
			//cout<<"����˺ţ�"<<endl;
			man->AddAccout();
		}
		else if(select==2)//�鿴�˺�
		{
			//cout<<"�鿴�˺ţ�"<<endl;
			man->CheckAccout();
		}
		else if(select==3)//�鿴����
		{
			//cout<<"�鿴������"<<endl;
			man->CheckComputer();
		}
		else if(select==4)//���ԤԼ
		{
			//cout<<"���ԤԼ��"<<endl;
			man->CleanOrder();
		}
		else
		{
			delete manager;
			cout<<"ע���ɹ���"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ����¼�����
void StudentMeun(Identity * &student)
{
	while(true)
	{
		//��չʾ����ָ�������
		student->operMeun();
		Student * man = (Student*)student;
		
		int select = 0;
		cin>>select;
		if(select==1)//����ԤԼ
		{
			//cout<<"����ԤԼ��"<<endl;
			man->ApplyOrder();
		}
		else if(select==2)//�鿴�ҵ�ԤԼ
		{
			//cout<<"�鿴�ҵ�ԤԼ��"<<endl;
			man->ShowmyOrder();
		}
		else if(select==3)//�鿴����ԤԼ
		{
			//cout<<"�鿴����ԤԼ��"<<endl;
			man->ShowallOrder();
		}
		else if(select==4)//ȡ��ԤԼ
		{
			//cout<<"ȡ��ԤԼ��"<<endl;
			man->CancelOrder();
		}
		else
		{
			delete student;
			cout<<"ע���ɹ���"<<endl;
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
		
		//cout<<"����������ѡ��";
		cin>>select;

		if(select==1)//�鿴����ԤԼ
		{
			tea->TShowallOrder();

		}else if(select==2)//���ԤԼ
		{
			tea->TCheckOrder();
		}else
		{
			delete teacher;
			cout<<"ע����¼�ɹ���"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����
void LogIn(string filename, int type)
{
	Identity *person = NULL;
	ifstream ifs(filename,ios::in);


	//�ж��ļ��Ƿ����
	if(!ifs.is_open())//ע����.is_open()����.open()
	{
		cout<<"�ļ�Ϊ�ջ򲻴��ڣ�"<<endl;
		//��������������
		ifs.close();
		return;
	}

	int Id=0;
	string name;
	string Pwd;


		if(type==1)
	{
		cout<<"����������ѧ�ţ�"<<endl;
		cin>>Id;
	}
	else if(type==2)
	{
		cout<<"����������ְ����ţ�"<<endl;
		cin>>Id;//��ѧ���õ�ͬһ������
	}
		cout<<"�������û�������"<<endl;
		cin>>name;
		cout<<"���������룺"<<endl;
		cin>>Pwd;

	//������������֤

		int fId=0;
		string fname;
		string fPwd;

	if(type==1)
	{
			while(ifs>>fId && ifs>>fname && ifs>>fPwd)//�����ļ��е�����
			{
				//���ļ��л�ȡ��������������ݽ��жԱ�
				if(Id==fId && name==fname && Pwd==fPwd)
				{
					cout<<"��֤ͨ������ӭ����ѧ��ϵͳ��"<<endl;
					system("pause");
					system("cls");
					person = new Student(Id,name,Pwd);
					StudentMeun(person);
					return;//���˳��Ļ��ͻ�ִ�к���ġ�����������������롱
				}	
			}
	}
	else if(type==2)
	{
		while(ifs>>fId && ifs>>fname && ifs>>fPwd)//�����ļ��е�����
			{
				if(Id==fId && name==fname && Pwd==fPwd)
				{
						cout<<"��֤ͨ������ӭ�����ʦϵͳ��"<<endl;
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
		while(ifs>>fname && ifs>>fPwd)//�����ļ��е�����
			{
				if(name==fname && Pwd==fPwd)
				{
					cout<<"��֤ͨ������ӭ�������Աϵͳ��"<<endl;
					system("pause");
					system("cls");
					person = new  Manager(name,Pwd);
					//һ���������˴��麯������ô�����ͱ���Ϊ���麯��
					ManagerMeun(person);//���뵽����Ա�˵�
//!!!!!!!����������������������!!һ��Ҫ��ManagerMeun()�����ŵ�ǰ�棬�������ʾ�Ҳ�����ʶ��������������������������������
					return;
				}	
			}
	  }
	
		cout<<"����������������룡"<<endl;
		system("pause");
		system("cls");
		return;//��������޷�������һ������

}

int main()
{

	int select=0;
	
	while(true)//������whileѭ��ÿ��ѧ��������ʦ����Աע����¼����ֱ���˳���
	{
			cout<<"===========================��ӭ����ţ�̻���ԤԼϵͳ��==============================="<<endl;
			cout<<"������������ݣ�"<<endl;
			cout<<"\t\t ------------------------------- "<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          1��ѧ    ��          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          2����    ʦ          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          3���� �� Ա          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t|          0����    ��          |"<<endl;
			cout<<"\t\t|                               |"<<endl;
			cout<<"\t\t ------------------------------- "<<endl;
			cout<<"����������ѡ��";
			cin>>select;

			switch(select)
			{
				case 1: //��ʾѧ���ӿ�
					LogIn(STUDENT, 1);
					break;
				case 2://��ʾ��ʦ�ӿ�
					LogIn(TEACHER, 2);
					break;
				case 3://��ʾ����Ա�ӿ�
					LogIn(MANAGER, 3);
					break;
				case 0:
					cout<<"��ӭ�´ι��٣�"<<endl;
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
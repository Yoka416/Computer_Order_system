#include"manager.h"
#include"globalfile.h"
#include<fstream>
#include<string>


	//Ĭ�Ϲ��캯��
	Manager::Manager ()
	{}

	//�вι��캯��
	Manager::Manager(string name, string pwd)
	{
		string m_name =name;
		string m_pwd = pwd;
		this->InitVector();

		//��ʼ��������Ϣ
		ifstream ifs;
		ifs.open(COMPUTER,ios::in);
		computerRoom c;

		while(ifs>>c.m_comId && ifs>>c.m_Maxsize)
		{
			vComsize.push_back(c);
		}
		cout<<"��������Ϊ��"<<vComsize.size()<<endl;
		ifs.close();
	}

	//����Ա����չʾ
	 void Manager::operMeun()
	 {
	cout<<"��ӭ����Ա"<<this->m_name<<"��¼��"<<endl;
	cout<<"\t\t ------------------------------- "<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          1������˺�          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          2���鿴�˺�          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          3���鿴����          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          4�����ԤԼ          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          0��ע����¼          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t ------------------------------- "<<endl;
	cout<<"����������ѡ��";
	 }


	//����˺�
	void Manager::AddAccout()
	{
		cout<<"��ѡ������˺����ͣ�"<<endl;
		cout<<"1��ѧ��"<<endl;
		cout<<"2����ʦ"<<endl;

		string tip;
		string fileNmae;
		string error;

		int select=0;
		cin>>select;


		ofstream ofs;

		if(select==1)
		{
			fileNmae = STUDENT;
			tip="������ѧ�ţ�";
			error="ѧ���ظ������������룡";
		}
		else 
		{
			fileNmae = TEACHER;
			tip="������ְ����ţ�";
			error="ְ������ظ������������룡";
		}
		
		//���������Ϣд���ļ�
		ofs.open(fileNmae,ios::out|ios::app);

		cout<<tip<<endl;
		 int Id;
		

		while(true)//!�����ﲻ��ret
		{
			//�����������ŵ�while����ͻ��ظ���ӡ���������
			 cin>>Id;
			 int ret = this->checkRepeat(Id,select);

			if(ret)
			{
				cout<<error<<endl;
			}else
			{
				break;
			}
		}
		

		cout<<"������������"<<endl;
		string name;
		cin>>name;

		cout<<"���������룺"<<endl;
		string pwd;
		cin>>pwd;


		ofs<<Id<<" "<<name<<" "<<pwd<<" "<<endl;
		system("pause");
		system("cls");

		ofs.close();
		//return;

		//�������ӣ���������ļ�Ϊ�յĻ����������о�û�취����
		//��Ϊ�ļ����вι����ʼ����ʱ���ļ�Ϊ�գ���û���������з���Ƚϲο����������º������ϼ���ı��û�а취����
		//�������֮��ÿ������ӵ���Ϣ����ŵ������У����ں�������
		this->InitVector();
	}


	void printfStu(Student &s)
	{
		cout<<"ѧ��ѧ�ţ�"<<s.S_Id<<"  "<<"������"<<s.m_name<<"  "<<"���룺"<<s.m_pwd<<endl;
	}

	void printfTea(Teacher &t)
	{
		cout<<"ְ����ţ�"<<t.T_Id<<"  "<<"������"<<t.m_name<<"  "<<"���룺"<<t.m_pwd<<endl;
	}
	//�鿴�˺�
	void Manager::CheckAccout()
	{
		cout<<"������鿴�˺����ͣ�"<<endl;
		cout<<"1��ѧ��"<<endl;
		cout<<"2����ʦ"<<endl;
		int select=0;
		cin>>select;
		if(select==1)
		{
			cout<<"ѧ�����˺���Ϣ���£�"<<endl;
			for_each(vStu.begin(),vStu.end(),printfStu);//ע���ӡ������Ҫ�����ţ�������
		}else
		{
			cout<<"��ʦ���˺���Ϣ���£�"<<endl;
			for_each(vTea.begin(),vTea.end(),printfTea);
		}
		system("pause");
		system("cls");
	}

	//�鿴������Ϣ
	void Manager::CheckComputer()
	{
		for(vector<computerRoom>::iterator it=vComsize.begin(); it!=vComsize.end();it++)
			{
				cout<<"������ţ�"<<it->m_comId<<"  "<<"����������"<<it->m_Maxsize<<endl;
			}
		system("pause");
		system("cls");
	}

	//���ԤԼ��¼
	void Manager::CleanOrder()
	{
		ofstream ofs(ORDER,ios::trunc);
		ofs.close();

		cout<<"��ճɹ���"<<endl;
		system("pause");
		system("cls");
	}

	//��ʼ������
	void Manager::InitVector()
	{
		vStu.clear();
		vTea.clear();

		ifstream ifs;
		ifs.open(STUDENT,ios::in);

		if(!ifs.is_open())
		{
			cout<<"�ļ�Ϊ�ջ򲻴��ڣ�"<<endl;
			//������������
			ifs.close();
			return;
		}

		Student s;

		//���ļ��е����ݸ�����
		while(ifs>>s.S_Id && ifs>>s.m_name && ifs>>s.m_pwd)//�������������ڸ�������
		{
			vStu.push_back(s);//�����ѧ������뵽������
		}
		int snum = vStu.size();
		cout<<"��ǰѧ��������Ϊ��"<<snum<<endl;
			ifs.close();


		ifs.open(TEACHER,ios::in);

		if(!ifs.is_open())
		{
			cout<<"�ļ�Ϊ�ջ򲻴��ڣ�"<<endl;
			//������������
			ifs.close();
			return;
		}

		Teacher t;

		while(ifs>>t.T_Id && ifs>>t.m_name && ifs>>t.m_pwd)//�������������ڸ�������
		{
			vTea.push_back(t);
		}
		int tnum = vTea.size();
		cout<<"��ǰ��ʦ������Ϊ��"<<tnum<<endl;

		ifs.close();//���رյĻ���ʦ���������������
	}


	bool  Manager::checkRepeat(int id, int type)
	{
		if(type==1)
		{
			//ѧ��
			for(vector<Student>::iterator it=this->vStu.begin(); it!=this->vStu.end();it++)
			{
				if(id==it->S_Id)
				return true;
			}
		}
		else 
		{
			for(vector<Teacher>::iterator it=this->vTea.begin(); it!=this->vTea.end();it++)
			{
				if(id==it->T_Id)
				return true;
			}
		}
		return false;
	}
#include"manager.h"
#include"globalfile.h"
#include<fstream>
#include<string>


	//默认构造函数
	Manager::Manager ()
	{}

	//有参构造函数
	Manager::Manager(string name, string pwd)
	{
		string m_name =name;
		string m_pwd = pwd;
		this->InitVector();

		//初始化机房信息
		ifstream ifs;
		ifs.open(COMPUTER,ios::in);
		computerRoom c;

		while(ifs>>c.m_comId && ifs>>c.m_Maxsize)
		{
			vComsize.push_back(c);
		}
		cout<<"机房数量为："<<vComsize.size()<<endl;
		ifs.close();
	}

	//管理员界面展示
	 void Manager::operMeun()
	 {
	cout<<"欢迎管理员"<<this->m_name<<"登录："<<endl;
	cout<<"\t\t ------------------------------- "<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          1、添加账号          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          2、查看账号          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          3、查看机房          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          4、清空预约          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t|          0、注销登录          |"<<endl;
	cout<<"\t\t|                               |"<<endl;
	cout<<"\t\t ------------------------------- "<<endl;
	cout<<"请输入您的选择：";
	 }


	//添加账号
	void Manager::AddAccout()
	{
		cout<<"请选择添加账号类型："<<endl;
		cout<<"1、学生"<<endl;
		cout<<"2、老师"<<endl;

		string tip;
		string fileNmae;
		string error;

		int select=0;
		cin>>select;


		ofstream ofs;

		if(select==1)
		{
			fileNmae = STUDENT;
			tip="请输入学号：";
			error="学号重复，请重新输入！";
		}
		else 
		{
			fileNmae = TEACHER;
			tip="请输入职工编号：";
			error="职工编号重复，请重新输入！";
		}
		
		//把输入的信息写入文件
		ofs.open(fileNmae,ios::out|ios::app);

		cout<<tip<<endl;
		 int Id;
		

		while(true)//!括号里不是ret
		{
			//下面这两个放到while外面就会重复打印出输入错误！
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
		

		cout<<"请输入姓名："<<endl;
		string name;
		cin>>name;

		cout<<"请输入密码："<<endl;
		string pwd;
		cin>>pwd;


		ofs<<Id<<" "<<name<<" "<<pwd<<" "<<endl;
		system("pause");
		system("cls");

		ofs.close();
		//return;

		//这个必须加，否则如果文件为空的话，重新运行就没办法查重
		//因为文件在有参构造初始化的时候文件为空，并没有往容器中放入比较参考变量，导致后续不断加入的编号没有办法查重
		//这里添加之后，每次新添加的信息都会放到容器中，用于后续查重
		this->InitVector();
	}


	void printfStu(Student &s)
	{
		cout<<"学生学号："<<s.S_Id<<"  "<<"姓名："<<s.m_name<<"  "<<"密码："<<s.m_pwd<<endl;
	}

	void printfTea(Teacher &t)
	{
		cout<<"职工编号："<<t.T_Id<<"  "<<"姓名："<<t.m_name<<"  "<<"密码："<<t.m_pwd<<endl;
	}
	//查看账号
	void Manager::CheckAccout()
	{
		cout<<"请输入查看账号类型："<<endl;
		cout<<"1、学生"<<endl;
		cout<<"2、老师"<<endl;
		int select=0;
		cin>>select;
		if(select==1)
		{
			cout<<"学生的账号信息如下："<<endl;
			for_each(vStu.begin(),vStu.end(),printfStu);//注意打印函数不要带括号！！！！
		}else
		{
			cout<<"老师的账号信息如下："<<endl;
			for_each(vTea.begin(),vTea.end(),printfTea);
		}
		system("pause");
		system("cls");
	}

	//查看机房信息
	void Manager::CheckComputer()
	{
		for(vector<computerRoom>::iterator it=vComsize.begin(); it!=vComsize.end();it++)
			{
				cout<<"机房编号："<<it->m_comId<<"  "<<"机房容量："<<it->m_Maxsize<<endl;
			}
		system("pause");
		system("cls");
	}

	//清空预约记录
	void Manager::CleanOrder()
	{
		ofstream ofs(ORDER,ios::trunc);
		ofs.close();

		cout<<"清空成功！"<<endl;
		system("pause");
		system("cls");
	}

	//初始化容器
	void Manager::InitVector()
	{
		vStu.clear();
		vTea.clear();

		ifstream ifs;
		ifs.open(STUDENT,ios::in);

		if(!ifs.is_open())
		{
			cout<<"文件为空或不存在！"<<endl;
			//这两个又忘了
			ifs.close();
			return;
		}

		Student s;

		//将文件中的内容给变量
		while(ifs>>s.S_Id && ifs>>s.m_name && ifs>>s.m_pwd)//后两个变量是在父类里面
		{
			vStu.push_back(s);//将这个学生类插入到容器中
		}
		int snum = vStu.size();
		cout<<"当前学生的数量为："<<snum<<endl;
			ifs.close();


		ifs.open(TEACHER,ios::in);

		if(!ifs.is_open())
		{
			cout<<"文件为空或不存在！"<<endl;
			//这两个又忘了
			ifs.close();
			return;
		}

		Teacher t;

		while(ifs>>t.T_Id && ifs>>t.m_name && ifs>>t.m_pwd)//后两个变量是在父类里面
		{
			vTea.push_back(t);
		}
		int tnum = vTea.size();
		cout<<"当前老师的数量为："<<tnum<<endl;

		ifs.close();//不关闭的话老师的数量会出错！！！
	}


	bool  Manager::checkRepeat(int id, int type)
	{
		if(type==1)
		{
			//学生
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
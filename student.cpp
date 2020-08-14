#include "student.h"

//默认构造函数
	 Student::Student()
	 {}

	//有参构造函数
	Student::Student(int Id,string name, string pwd)
	{
		this->S_Id = Id;
		this->m_name = name;
		this->m_pwd = pwd;

		//初始化容器，就是把机房文件的信息都读到学生存储选择的机房信息容器里
		//为了让学生获得机房信息

		ifstream ifs;
		ifs.open(COMPUTER,ios::in);
		computerRoom c;
		while(ifs>>c.m_comId && ifs>>c.m_Maxsize)
		{
			vCom.push_back(c);
		}
		ifs.close();
	}

	//学生界面展示
 void Student::operMeun()
{
	cout<<"欢迎"<<this->m_name<<"同学登录："<<endl;
	cout<<"\t\t ----------------------------------- "<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          1、申 请 预 约           |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          2、查看我的预约          |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          3、查看所有预约          |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          4、取 消 预 约           |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          0、注 销 登 录           |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t ----------------------------------- "<<endl;
	cout<<"请输入您的选择：";
 }

	//申请预约
	void Student::ApplyOrder()
	{
		//this->vCom.clear();

		cout<<"机房开放预约时间是周一到周五："<<endl;
		cout<<"请选择申请预约的日期："<<endl;
		cout<<"1、周一"<<endl;
		cout<<"2、周二"<<endl;
		cout<<"3、周三"<<endl;
		cout<<"4、周四"<<endl;
		cout<<"5、周五"<<endl;
		int data=0;
		cin>>data;

		while(true)
		{
			if(data>=1 && data<=5)
			{
				break;
			}
			else
			{
				cout<<"日期选择错误，请重新输入！"<<endl;
			}
		}

		cout<<"请输入申请预约时间段："<<endl;
		cout<<"1、上午"<<endl;
		cout<<"2、下午"<<endl;
		int interval=0;
		cin>>interval;
		while(true)
		{
			if(interval>=1 && interval<=2)
			{
				break;
			}
			else
			{
				cout<<"时段选择错误，请重新输入！"<<endl;
			}
		}
		cout<<"请选择机房："<<endl;
		for(vector<computerRoom>::iterator it=vCom.begin();it!=vCom.end();it++)
		{
			cout<<it->m_comId<<"号机房的容量为："<<it->m_Maxsize<<endl;
		}
		/*for(int i=0;i<vCom.size();i++)
		{
			cout<<vCom[i].m_comId<<"号机房的容量为："<<vCom[i].m_Maxsize<<endl;
		}*/
		int num;
		cin>>num;

		while(true)
		{
			if(num>=1 && num<=3)
			{
				break;
			}
			else
			{
				cout<<"机房选择错误，请重新输入！"<<endl;
			}
		}

		ofstream ofs;
		ofs.open(ORDER,ios::app);
		ofs<<"日期："<<data<<" ";
		ofs<<"时段："<<interval<<" ";
		ofs<<"学号："<<this->S_Id<<" ";
		ofs<<"姓名："<<this->m_name<<" ";
		ofs<<"机房："<<num<<" ";
		ofs<<"状态："<<1;
		ofs<<endl;

		ofs.close();

		system("pause");
		system("cls");
	
	}

	//查看自身预约
	void Student::ShowmyOrder()
	{
		orderfile ofs;//创建好之后，它就会自动调用构造函数
		if(ofs.m_ordersize==0)
		{
			cout<<"预约记录为空！"<<endl;
			system("pause");
			system("cls");
			return;
		}
	
		for(int i=0; i<ofs.m_ordersize;i++ )//把for写成if，导致里面用到ofs.不出来
	 {
		 //因为string类型不能等于int类型，需要转换
		 //先将string类型通过.c_str()转换为const char类型
		 //再用atoi转换为int类型
		 if(this->S_Id == atoi(ofs.m[i]["学号"].c_str()) )
		 {
			 cout<<"预约日期："<< "星期"<<ofs.m[i]["日期"]<<"  ";//！！注意容器内容的输出方式！！
			 cout<<"预约时间段："<<(ofs.m[i]["时段"]=="1"?"上午":"下午")<<"  ";//!注意1加引号，问号要用英文的!
			 //上面不加括号仍然会显示出数字

			/* cout<<"学号："<<ofs.m[i]["学号"];
			 cout<<"姓名："<<ofs.m[i]["学号"];*/

			 cout<<"机房号："<<ofs.m[i]["机房"]<<"  ";

			 string status="状态：";
			 	// 1 审核中  2 已预约  -1 预约失败  0 取消预约
			 if(ofs.m[i]["状态"]=="1")
			 {
				 status+="审核中";
			 }else if(ofs.m[i]["状态"]=="2")
			 {
				 status+="预约成功";
			 }else if(ofs.m[i]["状态"]=="-1")
			 {
				 status+="预约失败,审核未通过";
			 }else
			 {
				   status+="预约已取消";
			 }
			 cout<<status<<endl;;
		 }
	 }
		system("pause");
		system("cls");
	}

	//查看所有预约
	void Student::ShowallOrder()
	{
		orderfile ofs;//创建好之后，它就会自动调用构造函数
		if(ofs.m_ordersize==0)
		{
			cout<<"预约记录为空！"<<endl;
			system("pause");
			system("cls");
			return;
		}
	
		for(int i=0; i<ofs.m_ordersize;i++ )//把for写成if，导致里面用到ofs.不出来
	   {
			 
		      cout<<i+1<<"、";
			 cout<<"学号："<<ofs.m[i]["学号"]<<"  ";
			 cout<<"姓名："<<ofs.m[i]["姓名"]<<"  ";

			 //因为string类型不能等于int类型，需要转换
			 //先将string类型通过.c_str()转换为const char类型
			 //再用atoi转换为int类型
			 cout<<"预约日期："<<"星期"<<ofs.m[i]["日期"]<<"  ";//！！注意容器内容的输出方式！！
			 cout<<"预约时间段："<<(ofs.m[i]["时段"]=="1"?"上午":"下午")<<"  ";//!注意1加引号，问号要用英文的!
			 //上面不加括号仍然会显示出数字


			 cout<<"机房号："<<ofs.m[i]["机房"]<<"  ";

			 string status="状态：";
			 	// 1 审核中  2 已预约  -1 预约失败  0 取消预约
			 if(ofs.m[i]["状态"]=="1")
			 {
				 status+="审核中";
			 }else if(ofs.m[i]["状态"]=="2")
			 {
				 status+="预约成功";
			 }else if(ofs.m[i]["状态"]=="-1")
			 {
				 status+="预约失败,审核未通过";
			 }else
			 {
				   status+="预约已取消";
			 }
			 cout<<status<<endl;;
		 
		 }
		system("pause");
		system("cls");
	}

	//取消预约
	void Student::CancelOrder()
{
		orderfile ofs;//创建好之后，它就会自动调用构造函数
		if(ofs.m_ordersize==0)
		{
			cout<<"预约记录为空！"<<endl;
			system("pause");
			system("cls");
			return;
		}

	cout<<"申请状态为预约成功或者审核中可以取消预约."<<endl;
		  int index = 1;//!放在循环里面就不会变了!
		  vector<int>v;
	for(int i=0; i<ofs.m_ordersize;i++ )//把for写成if，导致里面用到ofs.不出来
	 {
		 
		 //v.push_back(i);//放在这里会导致无法取消第二个预约
		 //因为string类型不能等于int类型，需要转换
		 //先将string类型通过.c_str()转换为const char类型
		 //再用atoi转换为int类型
		 if(this->S_Id == atoi(ofs.m[i]["学号"].c_str()) )
		 {
			if(ofs.m[i]["状态"]=="2"||ofs.m[i]["状态"]=="1")
			{
				 v.push_back(i);//！必须放在里面！
					cout<<index<<"、";
				 cout<<"预约日期："<<"星期"<<ofs.m[i]["日期"]<<"  ";//！！注意容器内容的输出方式！！
				 cout<<"预约时间段："<<(ofs.m[i]["时段"]=="1"?"上午":"下午")<<"  ";//!注意1加引号，问号要用英文的!
				 //上面不加括号仍然会显示出数字

				/* cout<<"学号："<<ofs.m[i]["学号"]<<"  ";
				 cout<<"姓名："<<ofs.m[i]["姓名"]<<"  ";*/

				 cout<<"机房号："<<ofs.m[i]["机房"]<<"  ";

				 string status="状态：";
			 		// 1 审核中  2 已预约  -1 预约失败  0 取消预约
				 if(ofs.m[i]["状态"]=="1")
				 {
					 status+="审核中";
				 }else if(ofs.m[i]["状态"]=="2")
				 {
					 status+="预约成功";
				 }
				 index++;
				 cout<<status<<endl;
			}
			 
		 }
	 }

cout<<"输入0返回，请输入您要取消的预约编号：";
			
			int select=0;//int类型会出现“<=”: 有符号/无符号不匹配警告
			
			while(true)//一般与重新输入放在一起
			{
				cin>>select;
				if(select>=0 && select<=v.size() )
				{
					 if(select == 0)
					 {
						 break;
					 }else
					 {
						 //下面注意用到v,根据容器v的序号取出m大容器的序号
						  ofs.m[v[select-1]]["状态"] = "0";//写成“==”就变成判断了，不会出现赋值了！！！

						  //将更改后的容器的内容重新写进文件中
						  ofs.updateorder();

						  //这两句一定要加
						  cout<<"取消预约成功！"<<endl;
						  break;
					 }
				}
				//这句话一般伴随着while循环
				cout<<"输入有误，请重新输入！"<<endl;
			}

			system("pause");
			system("cls");
	}
			
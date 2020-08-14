#include "teacher.h"

	//默认构造函数
	Teacher::Teacher()
	{
	}

	//有参构造函数
	Teacher:: Teacher(int num,string name, string pwd)
	{
		this->T_Id = num;
		this->m_name = name;
		this->m_pwd = pwd;
	}

	//老师界面展示
	void Teacher::operMeun()
	{
		cout<<"欢迎"<<this->m_name<<"老师登录："<<endl;
		cout<<"\t\t ----------------------------------- "<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t|          1、查看所有预约          |"<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t|          2、审 核 预 约           |"<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t|          0、注 销 登 录           |"<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t ----------------------------------- "<<endl;
		cout<<"请输入您的选择：";
	}


	//查看所有预约
	void Teacher::TShowallOrder()
	{
		Student tea;
		tea.ShowallOrder();
	}

	//审核预约
	void Teacher::TCheckOrder()
	{
		orderfile ofs;//创建好之后，它就会自动调用构造函数
		if(ofs.m_ordersize==0)
		{
			cout<<"预约记录为空！"<<endl;
			system("pause");
			system("cls");
			return;
		}

	//cout<<"申请状态为审核中可以进行预约审核。"<<endl;
		  int index = 1;//!放在循环里面就不会变了!
		  vector<int>v;
	for(int i=0; i<ofs.m_ordersize;i++ )//把for写成if，导致里面用到ofs.不出来
	    {
		 //v.push_back(i);//放在这里会导致无法取消第二个预约
			if(ofs.m[i]["状态"]=="1")
			{
				 v.push_back(i);//！必须放在里面！
					cout<<index<<"、";
				 cout<<"预约日期："<<"星期"<<ofs.m[i]["日期"]<<"  ";//！！注意容器内容的输出方式！！
				 cout<<"预约时间段："<<(ofs.m[i]["时段"]=="1"?"上午":"下午")<<"  ";//!注意1加引号，问号要用英文的!
				 //上面不加括号仍然会显示出数字

				 cout<<"学号："<<ofs.m[i]["学号"]<<"  ";
				 cout<<"姓名："<<ofs.m[i]["姓名"]<<"  ";

				 cout<<"机房号："<<ofs.m[i]["机房"]<<"  ";

				 string status="状态：审核中";
				 index++;
				 cout<<status<<endl;//状态不是从文件中读出来的，是强制打印出来的
			}
	    }
		
	   
	    int select=0;
		int ret=0;	
		while(true)//一般与重新输入放在一起
		{
			 cout<<"输入0返回，请输入要审核的编号：";
				cin>>select;
				if(select>=0 && select<=(int)v.size() )
				{
					 if(select == 0)
					 {
						 break;
					 }else
					 {
						 cout<<"输入0返回，请进行审核："<<endl;
						 cout<<"1、通过"<<endl;
						 cout<<"2、不通过"<<endl;
						 int ret;
						 cin>>ret;
						 if(ret==1)
						 {
							 //下面注意用到v,根据容器v的序号取出m大容器的序号
						  ofs.m[v[select-1]]["状态"] = "2";//写成“==”就变成判断了，不会出现赋值了！！！
						 }else
						 {
							 ofs.m[v[select-1]]["状态"] = "-1";//写成“==”就变成判断了，不会出现赋值了！！！
						 }
						 

						  //将更改后的容器的内容重新写进文件中
						  ofs.updateorder();

						  //这两句一定要加
						  cout<<"审核完成！"<<endl;
						  break;//记得跳出循环
					 }
				}
				//这句话一般伴随着while循环
				cout<<"输入有误，请重新输入！"<<endl;
		}

			system("pause");
			system("cls");
	}


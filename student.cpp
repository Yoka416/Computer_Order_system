#include "student.h"

//Ĭ�Ϲ��캯��
	 Student::Student()
	 {}

	//�вι��캯��
	Student::Student(int Id,string name, string pwd)
	{
		this->S_Id = Id;
		this->m_name = name;
		this->m_pwd = pwd;

		//��ʼ�����������ǰѻ����ļ�����Ϣ������ѧ���洢ѡ��Ļ�����Ϣ������
		//Ϊ����ѧ����û�����Ϣ

		ifstream ifs;
		ifs.open(COMPUTER,ios::in);
		computerRoom c;
		while(ifs>>c.m_comId && ifs>>c.m_Maxsize)
		{
			vCom.push_back(c);
		}
		ifs.close();
	}

	//ѧ������չʾ
 void Student::operMeun()
{
	cout<<"��ӭ"<<this->m_name<<"ͬѧ��¼��"<<endl;
	cout<<"\t\t ----------------------------------- "<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          1���� �� Ԥ Լ           |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          2���鿴�ҵ�ԤԼ          |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          3���鿴����ԤԼ          |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          4��ȡ �� Ԥ Լ           |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t|          0��ע �� �� ¼           |"<<endl;
	cout<<"\t\t|                                   |"<<endl;
	cout<<"\t\t ----------------------------------- "<<endl;
	cout<<"����������ѡ��";
 }

	//����ԤԼ
	void Student::ApplyOrder()
	{
		//this->vCom.clear();

		cout<<"��������ԤԼʱ������һ�����壺"<<endl;
		cout<<"��ѡ������ԤԼ�����ڣ�"<<endl;
		cout<<"1����һ"<<endl;
		cout<<"2���ܶ�"<<endl;
		cout<<"3������"<<endl;
		cout<<"4������"<<endl;
		cout<<"5������"<<endl;
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
				cout<<"����ѡ��������������룡"<<endl;
			}
		}

		cout<<"����������ԤԼʱ��Σ�"<<endl;
		cout<<"1������"<<endl;
		cout<<"2������"<<endl;
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
				cout<<"ʱ��ѡ��������������룡"<<endl;
			}
		}
		cout<<"��ѡ�������"<<endl;
		for(vector<computerRoom>::iterator it=vCom.begin();it!=vCom.end();it++)
		{
			cout<<it->m_comId<<"�Ż���������Ϊ��"<<it->m_Maxsize<<endl;
		}
		/*for(int i=0;i<vCom.size();i++)
		{
			cout<<vCom[i].m_comId<<"�Ż���������Ϊ��"<<vCom[i].m_Maxsize<<endl;
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
				cout<<"����ѡ��������������룡"<<endl;
			}
		}

		ofstream ofs;
		ofs.open(ORDER,ios::app);
		ofs<<"���ڣ�"<<data<<" ";
		ofs<<"ʱ�Σ�"<<interval<<" ";
		ofs<<"ѧ�ţ�"<<this->S_Id<<" ";
		ofs<<"������"<<this->m_name<<" ";
		ofs<<"������"<<num<<" ";
		ofs<<"״̬��"<<1;
		ofs<<endl;

		ofs.close();

		system("pause");
		system("cls");
	
	}

	//�鿴����ԤԼ
	void Student::ShowmyOrder()
	{
		orderfile ofs;//������֮�����ͻ��Զ����ù��캯��
		if(ofs.m_ordersize==0)
		{
			cout<<"ԤԼ��¼Ϊ�գ�"<<endl;
			system("pause");
			system("cls");
			return;
		}
	
		for(int i=0; i<ofs.m_ordersize;i++ )//��forд��if�����������õ�ofs.������
	 {
		 //��Ϊstring���Ͳ��ܵ���int���ͣ���Ҫת��
		 //�Ƚ�string����ͨ��.c_str()ת��Ϊconst char����
		 //����atoiת��Ϊint����
		 if(this->S_Id == atoi(ofs.m[i]["ѧ��"].c_str()) )
		 {
			 cout<<"ԤԼ���ڣ�"<< "����"<<ofs.m[i]["����"]<<"  ";//����ע���������ݵ������ʽ����
			 cout<<"ԤԼʱ��Σ�"<<(ofs.m[i]["ʱ��"]=="1"?"����":"����")<<"  ";//!ע��1�����ţ��ʺ�Ҫ��Ӣ�ĵ�!
			 //���治��������Ȼ����ʾ������

			/* cout<<"ѧ�ţ�"<<ofs.m[i]["ѧ��"];
			 cout<<"������"<<ofs.m[i]["ѧ��"];*/

			 cout<<"�����ţ�"<<ofs.m[i]["����"]<<"  ";

			 string status="״̬��";
			 	// 1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
			 if(ofs.m[i]["״̬"]=="1")
			 {
				 status+="�����";
			 }else if(ofs.m[i]["״̬"]=="2")
			 {
				 status+="ԤԼ�ɹ�";
			 }else if(ofs.m[i]["״̬"]=="-1")
			 {
				 status+="ԤԼʧ��,���δͨ��";
			 }else
			 {
				   status+="ԤԼ��ȡ��";
			 }
			 cout<<status<<endl;;
		 }
	 }
		system("pause");
		system("cls");
	}

	//�鿴����ԤԼ
	void Student::ShowallOrder()
	{
		orderfile ofs;//������֮�����ͻ��Զ����ù��캯��
		if(ofs.m_ordersize==0)
		{
			cout<<"ԤԼ��¼Ϊ�գ�"<<endl;
			system("pause");
			system("cls");
			return;
		}
	
		for(int i=0; i<ofs.m_ordersize;i++ )//��forд��if�����������õ�ofs.������
	   {
			 
		      cout<<i+1<<"��";
			 cout<<"ѧ�ţ�"<<ofs.m[i]["ѧ��"]<<"  ";
			 cout<<"������"<<ofs.m[i]["����"]<<"  ";

			 //��Ϊstring���Ͳ��ܵ���int���ͣ���Ҫת��
			 //�Ƚ�string����ͨ��.c_str()ת��Ϊconst char����
			 //����atoiת��Ϊint����
			 cout<<"ԤԼ���ڣ�"<<"����"<<ofs.m[i]["����"]<<"  ";//����ע���������ݵ������ʽ����
			 cout<<"ԤԼʱ��Σ�"<<(ofs.m[i]["ʱ��"]=="1"?"����":"����")<<"  ";//!ע��1�����ţ��ʺ�Ҫ��Ӣ�ĵ�!
			 //���治��������Ȼ����ʾ������


			 cout<<"�����ţ�"<<ofs.m[i]["����"]<<"  ";

			 string status="״̬��";
			 	// 1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
			 if(ofs.m[i]["״̬"]=="1")
			 {
				 status+="�����";
			 }else if(ofs.m[i]["״̬"]=="2")
			 {
				 status+="ԤԼ�ɹ�";
			 }else if(ofs.m[i]["״̬"]=="-1")
			 {
				 status+="ԤԼʧ��,���δͨ��";
			 }else
			 {
				   status+="ԤԼ��ȡ��";
			 }
			 cout<<status<<endl;;
		 
		 }
		system("pause");
		system("cls");
	}

	//ȡ��ԤԼ
	void Student::CancelOrder()
{
		orderfile ofs;//������֮�����ͻ��Զ����ù��캯��
		if(ofs.m_ordersize==0)
		{
			cout<<"ԤԼ��¼Ϊ�գ�"<<endl;
			system("pause");
			system("cls");
			return;
		}

	cout<<"����״̬ΪԤԼ�ɹ���������п���ȡ��ԤԼ."<<endl;
		  int index = 1;//!����ѭ������Ͳ������!
		  vector<int>v;
	for(int i=0; i<ofs.m_ordersize;i++ )//��forд��if�����������õ�ofs.������
	 {
		 
		 //v.push_back(i);//��������ᵼ���޷�ȡ���ڶ���ԤԼ
		 //��Ϊstring���Ͳ��ܵ���int���ͣ���Ҫת��
		 //�Ƚ�string����ͨ��.c_str()ת��Ϊconst char����
		 //����atoiת��Ϊint����
		 if(this->S_Id == atoi(ofs.m[i]["ѧ��"].c_str()) )
		 {
			if(ofs.m[i]["״̬"]=="2"||ofs.m[i]["״̬"]=="1")
			{
				 v.push_back(i);//������������棡
					cout<<index<<"��";
				 cout<<"ԤԼ���ڣ�"<<"����"<<ofs.m[i]["����"]<<"  ";//����ע���������ݵ������ʽ����
				 cout<<"ԤԼʱ��Σ�"<<(ofs.m[i]["ʱ��"]=="1"?"����":"����")<<"  ";//!ע��1�����ţ��ʺ�Ҫ��Ӣ�ĵ�!
				 //���治��������Ȼ����ʾ������

				/* cout<<"ѧ�ţ�"<<ofs.m[i]["ѧ��"]<<"  ";
				 cout<<"������"<<ofs.m[i]["����"]<<"  ";*/

				 cout<<"�����ţ�"<<ofs.m[i]["����"]<<"  ";

				 string status="״̬��";
			 		// 1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
				 if(ofs.m[i]["״̬"]=="1")
				 {
					 status+="�����";
				 }else if(ofs.m[i]["״̬"]=="2")
				 {
					 status+="ԤԼ�ɹ�";
				 }
				 index++;
				 cout<<status<<endl;
			}
			 
		 }
	 }

cout<<"����0���أ���������Ҫȡ����ԤԼ��ţ�";
			
			int select=0;//int���ͻ���֡�<=��: �з���/�޷��Ų�ƥ�侯��
			
			while(true)//һ���������������һ��
			{
				cin>>select;
				if(select>=0 && select<=v.size() )
				{
					 if(select == 0)
					 {
						 break;
					 }else
					 {
						 //����ע���õ�v,��������v�����ȡ��m�����������
						  ofs.m[v[select-1]]["״̬"] = "0";//д�ɡ�==���ͱ���ж��ˣ�������ָ�ֵ�ˣ�����

						  //�����ĺ����������������д���ļ���
						  ofs.updateorder();

						  //������һ��Ҫ��
						  cout<<"ȡ��ԤԼ�ɹ���"<<endl;
						  break;
					 }
				}
				//��仰һ�������whileѭ��
				cout<<"�����������������룡"<<endl;
			}

			system("pause");
			system("cls");
	}
			
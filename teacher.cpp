#include "teacher.h"

	//Ĭ�Ϲ��캯��
	Teacher::Teacher()
	{
	}

	//�вι��캯��
	Teacher:: Teacher(int num,string name, string pwd)
	{
		this->T_Id = num;
		this->m_name = name;
		this->m_pwd = pwd;
	}

	//��ʦ����չʾ
	void Teacher::operMeun()
	{
		cout<<"��ӭ"<<this->m_name<<"��ʦ��¼��"<<endl;
		cout<<"\t\t ----------------------------------- "<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t|          1���鿴����ԤԼ          |"<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t|          2���� �� Ԥ Լ           |"<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t|          0��ע �� �� ¼           |"<<endl;
		cout<<"\t\t|                                   |"<<endl;
		cout<<"\t\t ----------------------------------- "<<endl;
		cout<<"����������ѡ��";
	}


	//�鿴����ԤԼ
	void Teacher::TShowallOrder()
	{
		Student tea;
		tea.ShowallOrder();
	}

	//���ԤԼ
	void Teacher::TCheckOrder()
	{
		orderfile ofs;//������֮�����ͻ��Զ����ù��캯��
		if(ofs.m_ordersize==0)
		{
			cout<<"ԤԼ��¼Ϊ�գ�"<<endl;
			system("pause");
			system("cls");
			return;
		}

	//cout<<"����״̬Ϊ����п��Խ���ԤԼ��ˡ�"<<endl;
		  int index = 1;//!����ѭ������Ͳ������!
		  vector<int>v;
	for(int i=0; i<ofs.m_ordersize;i++ )//��forд��if�����������õ�ofs.������
	    {
		 //v.push_back(i);//��������ᵼ���޷�ȡ���ڶ���ԤԼ
			if(ofs.m[i]["״̬"]=="1")
			{
				 v.push_back(i);//������������棡
					cout<<index<<"��";
				 cout<<"ԤԼ���ڣ�"<<"����"<<ofs.m[i]["����"]<<"  ";//����ע���������ݵ������ʽ����
				 cout<<"ԤԼʱ��Σ�"<<(ofs.m[i]["ʱ��"]=="1"?"����":"����")<<"  ";//!ע��1�����ţ��ʺ�Ҫ��Ӣ�ĵ�!
				 //���治��������Ȼ����ʾ������

				 cout<<"ѧ�ţ�"<<ofs.m[i]["ѧ��"]<<"  ";
				 cout<<"������"<<ofs.m[i]["����"]<<"  ";

				 cout<<"�����ţ�"<<ofs.m[i]["����"]<<"  ";

				 string status="״̬�������";
				 index++;
				 cout<<status<<endl;//״̬���Ǵ��ļ��ж������ģ���ǿ�ƴ�ӡ������
			}
	    }
		
	   
	    int select=0;
		int ret=0;	
		while(true)//һ���������������һ��
		{
			 cout<<"����0���أ�������Ҫ��˵ı�ţ�";
				cin>>select;
				if(select>=0 && select<=(int)v.size() )
				{
					 if(select == 0)
					 {
						 break;
					 }else
					 {
						 cout<<"����0���أ��������ˣ�"<<endl;
						 cout<<"1��ͨ��"<<endl;
						 cout<<"2����ͨ��"<<endl;
						 int ret;
						 cin>>ret;
						 if(ret==1)
						 {
							 //����ע���õ�v,��������v�����ȡ��m�����������
						  ofs.m[v[select-1]]["״̬"] = "2";//д�ɡ�==���ͱ���ж��ˣ�������ָ�ֵ�ˣ�����
						 }else
						 {
							 ofs.m[v[select-1]]["״̬"] = "-1";//д�ɡ�==���ͱ���ж��ˣ�������ָ�ֵ�ˣ�����
						 }
						 

						  //�����ĺ����������������д���ļ���
						  ofs.updateorder();

						  //������һ��Ҫ��
						  cout<<"�����ɣ�"<<endl;
						  break;//�ǵ�����ѭ��
					 }
				}
				//��仰һ�������whileѭ��
				cout<<"�����������������룡"<<endl;
		}

			system("pause");
			system("cls");
	}


#include "orderFile.h"
#include<fstream>
#include"globalfile.h"
#include <string>
    //���캯��
	orderfile::orderfile()
	{
		ifstream ifs;
		ifs.open(ORDER,ios::in);

		//����ԤԼ�ļ��е���Ϣ
		string data;
		string interval;
		string StuId;
		string StuName;
		string computer;//����
		string state;//״̬
		
		
		map<string,string>m2;//�����洢ԤԼ��Ϣ����һ��ԤԼ��Ŀ���ڶ���ԤԼ��ֵ

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
			
			//������������ֻ��Ҫ����һ��
			string key;
			string value;

			

			//����
			int pos =data.find("��");//!pos����һ�¾Ϳ��ԣ�!
			if(pos!=-1)//�����м��жϣ���
			{
				 key = data.substr(0,pos);//0�����0��ʼ��pos��ʾ��ȡpos��
				 value=data.substr(pos+2,data.size()-pos-1);//��ȡ��Ӧ��������ֵ
				 m2.insert(make_pair(key,value));//�����������ݴ浽������
			}
			
			//ʱ�Σ�
			pos =interval.find("��");
			if(pos!=-1)
			{
				 key = interval.substr(0,pos);//0�����0��ʼ��pos��ʾ��ȡpos��
				 value=interval.substr(pos+2,interval.size()-pos-1);//��ȡ��Ӧ��������ֵ
				 m2.insert(make_pair(key,value));//�����������ݴ浽������
			}
			//ѧ��
			pos =StuId.find("��");
			if(pos!=-1)
			{
				 key = StuId.substr(0,pos);//0�����0��ʼ��pos��ʾ��ȡpos��
				 value=StuId.substr(pos+2,StuId.size()-pos-1);//��ȡ��Ӧ��������ֵ
				 m2.insert(make_pair(key,value));//�����������ݴ浽������
			}
			//����
			pos =StuName.find("��");
			if(pos!=-1)
			{
				 key = StuName.substr(0,pos);//0�����0��ʼ��pos��ʾ��ȡpos��
				 value=StuName.substr(pos+2,StuName.size()-pos-1);//��ȡ��Ӧ��������ֵ
				 m2.insert(make_pair(key,value));//�����������ݴ浽������
			}
			//����
			pos =computer.find("��");
			if(pos!=-1)
			{
				 key =  computer.substr(0,pos);//0�����0��ʼ��pos��ʾ��ȡpos��
				 value= computer.substr(pos+2, computer.size()-pos-1);//��ȡ��Ӧ��������ֵ
				 m2.insert(make_pair(key,value));//�����������ݴ浽������
			}
			//״̬
			pos =state.find("��");
			if(pos!=-1)
			{
				 key = state.substr(0,pos);//0�����0��ʼ��pos��ʾ��ȡpos��
				 value=state.substr(pos+2,state.size()-pos-1);//��ȡ��Ӧ��������ֵ
				 m2.insert(make_pair(key,value));//�����������ݴ浽������
			}

			this->m.insert(make_pair(this->m_ordersize,m2));
			this->m_ordersize++;
			m2.clear();
		}
		ifs.close();

		//�����Ƿ�ŵ�������

		//for(map<int, map<string,string>>::iterator it=m.begin(); it!=m.end();it++)
		//{
		//	cout<<"ԤԼ��"<<it->first<<"����"<<endl;
		//	for(map<string,string>::iterator itm =(*it).second.begin(); itm!=(*it).second.end(); itm++)
		//	{
		//		cout<<itm->first<<":"<<itm->second<<"  ";
		//		//J R S X X Z��ӡ������˳���ǰ���key����ĸ���е�
		//	}
		//	cout<<endl;
		//}
		//system("pause");
		//system("cls");
	}

	//����ԤԼ����
	void orderfile::updateorder()
	{
		if(this->m_ordersize==0)
		{
			return;
		}
		ofstream ofs;
		ofs.open(ORDER,ios::out|ios::trunc);
		//trunc���������д��

		for(int i=0; i<this->m_ordersize;i++)
		{
			ofs<<"���ڣ�"<<this->m[i]["����"]<<"  ";//!��Ϊ�����ð����Ӣ�ĵĵ����޷����!
			ofs<<"ʱ�Σ�"<<this->m[i]["ʱ��"]<<"  ";
			ofs<<"ѧ�ţ�"<<this->m[i]["ѧ��"]<<"  ";
			ofs<<"������"<<this->m[i]["����"]<<"  ";
			ofs<<"������"<<this->m[i]["����"]<<"  ";
			ofs<<"״̬��"<<this->m[i]["״̬"]<<endl;
		}
		ofs.close();
	}

	//��¼ԤԼ����
	int m_ordersize;
#pragma once
#include <fstream>
#include <iostream>
#include"manager.h"
#include"employee.h"
#include"boss.h"
class Workermanager
{
public:
	Workermanager();
	void exit_system();//�˳�ϵͳ
	void show_menu();//ϵͳ��ʼ������ʾ
	void add_worker();//���Ա��
	void save();//����Ա����Ϣ
	int get_num();//��ȡ�ļ��е�����
	void init_worker();//���ļ��г�ʼ��Ա����Ϣ
	void show_worker();//��ʾԱ����Ϣ
	void delete_worker();//ɾ��Ա����Ϣ
	void rectify_worker();//�޸�Ա����Ϣ
	void find_worker();//����Ա����Ϣ
	void sort_up(Worker**p,int num);//����������
	void sort_down(Worker**p, int num);//����������
	void sort();//����
	~Workermanager();
public:
	int num;//ϵͳ���Ѵ��������
	Worker **worker;//����˵���Ϣ
	bool file_flag;//��־�ļ��Ƿ���ڻ��������Ƿ�������
};
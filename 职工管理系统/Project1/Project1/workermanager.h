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
	void exit_system();//退出系统
	void show_menu();//系统初始界面显示
	void add_worker();//添加员工
	void save();//保存员工信息
	int get_num();//获取文件中的人数
	void init_worker();//从文件中初始化员工信息
	void show_worker();//显示员工信息
	void delete_worker();//删除员工信息
	void rectify_worker();//修改员工信息
	void find_worker();//查找员工信息
	void sort_up(Worker**p,int num);//按升序排序
	void sort_down(Worker**p, int num);//按降序排序
	void sort();//排序
	~Workermanager();
public:
	int num;//系统中已存入的人数
	Worker **worker;//存放人的信息
	bool file_flag;//标志文件是否存在或者里面是否存放数据
};
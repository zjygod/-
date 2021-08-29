#include "workermanager.h"
using namespace std;
Workermanager::Workermanager()
{
	ifstream ifs("worker_info.txt",ios::in);
	if (!ifs.is_open())
	{
		this->num = 0;
		this->worker = NULL;
		this->file_flag = 0;
		return;
	}
	ifs.seekg(0,ios::end);
	streampos fp = ifs.tellg();
	if (int(fp) == 0)
	{
		this->num = 0;
		this->worker = NULL;
		this->file_flag = 0;
		ifs.close();
	}
	else
	{
		this->file_flag = 1;
		this->num = this->get_num();
		this->worker = new Worker*[this->num];
		this->init_worker();
	}
}
Workermanager::~Workermanager()
{

}
void Workermanager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void Workermanager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void Workermanager::add_worker()
{
	int add_num = 0;
	cout << "请输入要添加的员工信息个数：";
	cin >> add_num;
	if (add_num > 0)
	{
		this->file_flag = 1;
		int new_size = this->num + add_num;
		Worker** new_worker = new Worker*[new_size];//更新新的内存
		if (this->worker != NULL)
		{
			for (int i = 0; i < this->num; i++)
			{
				new_worker[i] = this->worker[i];
			}
		}
		for (int i = 0; i < add_num; i++)
		{
			int id = 0;//记录职工编号
			string name;//记录名字
			int  job;//记录工作部门
			cout << "第" <<i+1<< "个人的职工编号: ";
			cin >> id;
			cout << endl;
			cout << "第" <<i+1<< "个人的名字: ";
			cin >> name;
			cout << endl;
			cout << "1: 工人 " << endl << "2: 经理" << endl<<"3: 老板" << endl;
			cout << "第" << i + 1 << "个人的岗位: ";
			cin >> job;
			cout << endl;
			Worker *temp=NULL;
			switch (job)
			{
			case 1:
				temp = new Employee(id, name, "工人");
				break;
			case 2:
				temp = new Manager(id, name, "经理");
				break;
			case 3:
				temp = new Boss(id, name, "老板");
				break;
			}
			new_worker[i + this->num] = temp;
			//delete temp;这边切忌不能delete掉，delete掉数据就没了！
		}
		delete[] this->worker;//销毁原来的堆区内存
		this->worker = new_worker;//指向新的内存
		this->num = new_size;
		cout << "成功添加" << add_num << "名新职工"<<endl;
	}
	else
	{
		cout << "输入格式不正确，请重新输入";

	}
	system("pause");
	system("cls");
}
void Workermanager::save()
{
	ofstream ofs("worker_info.txt",ios::out);
	for (int i = 0; i < this->num; i++)
	{
		ofs << this->worker[i]->w_num  << "  "<<this->worker[i]->w_name<<"  "<<this->worker[i]->w_job<<endl;
	}
	ofs.close();
}
int Workermanager::get_num()
{
	ifstream ifs("worker_info.txt",ios::in);
	int num;
	string name;
	string job;
	int m_num = 0;
	while (ifs >> num&&ifs >> name&&ifs >> job)
	{
		m_num++;
	}
	return m_num;
}
void Workermanager::init_worker()
{
	ifstream ifs("worker_info.txt", ios::in);
	int num;
	string name;
	string job;
	int index = 0;
	while (ifs >> num&&ifs >> name&&ifs >> job)
	{
		Worker *temp1 = NULL;
		if (job == "工人")
		{
			temp1 = new Employee(num,name,job);
		}
		else if (job == "经理")
		{
			temp1 = new Manager(num, name, job);
		}
		else if(job == "老板")
		{
			temp1 = new Boss(num,name,job);
		}
		this->worker[index] = temp1;
		index++;
	}
}
void Workermanager::show_worker()
{
	if (this->file_flag)
	{
		for (int i = 0; i < this->num; i++)
		{
			this->worker[i]->show_Info();
		}
	}
	else
	{
		cout << "您所访问的文件不存在或文件内无信息" << endl;
	}
	system("pause");
	system("cls");
}
void Workermanager::delete_worker()
{
	cout << "请输入要删除的员工编号: ";
	int delete_ID;
	cin >> delete_ID;
	int note = 0;
	for (int i = 0; i < this->num; i++)
	{
		if (this->worker[i]->w_num == delete_ID)
		{
			note = i;
			break;
		}
	}
	for (int i = note; i < this->num-1; i++)
	{
	    this->worker[i] = this->worker[i + 1];
	}
	Worker **new_worker = new Worker*[this->num - 1];
	for (int i = 0; i < this->num - 1; i++)
	{
		new_worker[i] = this->worker[i];
	}
	this->num--;
	delete[]worker;
	this->worker = new_worker;
	this->save();
	if (this->num == 0)
	{
		this->file_flag = 0;
	}
	cout << "修改成功" << endl;
	system("pause");
	system("cls");
}
void Workermanager::rectify_worker()
{
	cout << "请输入要修改信息的员工编号: ";
	int rectify_ID;
	cin >> rectify_ID;
	int temp;
	for (int i = 0; i < this->num; i++)
	{
		if (this->worker[i]->w_num == rectify_ID)
		{
			temp = i;
			break;
		}
	}
	cout << "请输入修改的职位: ";
	string job;
	cin >> job;
	Worker *new_worker = NULL;
	if (job == "工人")
	{
		new_worker = new Employee(this->worker[temp]->w_num, this->worker[temp]->w_name, job);
	}
	else if (job == "经理")
	{
		new_worker = new Manager(this->worker[temp]->w_num, this->worker[temp]->w_name, job);
	}
	else if (job == "老板")
	{
		new_worker = new Boss(this->worker[temp]->w_num, this->worker[temp]->w_name, job);
	}
	delete worker[temp];
	worker[temp] = new_worker;
	this->save();
	cout << "修改成功" << endl;
	system("pause");
	system("cls");
}
void Workermanager::find_worker()
{
	cout << "请输入您要查找信息的方式: " << endl;
	cout << "1: 根据员工编号查找信息" << endl << "2: 根据员工姓名查找信息" << endl;
	int get_way;
	cin >> get_way;
	switch (get_way)
	{
	case 1:
		cout << "请输入员工的编号: ";
		int get_num;
		cin >> get_num;
		for (int i = 0; i < this->num; i++)
		{
			if (this->worker[i]->w_num == get_num)
			{
				this->worker[i]->show_Info();
				break;
			}
		}
		break;
	case 2:
		cout << "请输入员工的姓名: ";
		string get_name;
		cin >> get_name;
		for (int i = 0; i < this->num; i++)
		{
			if (this->worker[i]->w_name == get_name)
			{
				this->worker[i]->show_Info();
				break;
			}
		}
		break;
	}
	system("pause");
	system("cls");
}
void Workermanager::sort_up(Worker**p, int num)
{
	for (int i = 1; i < num ; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			if (p[j]->w_num > p[j+ 1]->w_num)
			{
				Worker *temp = p[j+ 1];
				p[j+ 1] = p[j];
				p[j] = temp;
			}
		}
	}
}
void Workermanager::sort_down(Worker**p, int num)
{
	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			if (p[j]->w_num < p[j + 1]->w_num)
			{
				Worker *temp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = temp;
			}
		}
	}
}
void Workermanager::sort()
{
	cout << "请选择您要排序的方式:" << endl;
	cout << "1: 升序" << endl;
	cout << "2: 降序" << endl;
	int sort_way;
	cin >> sort_way;
	switch (sort_way)
	{
	case 1:
		sort_up(this->worker, this->num);
		this->save();
		break;
	case 2:
		sort_down(this->worker, this->num);
		this->save();
		break;
	}
	cout << "排序成功" << endl;
	system("pause");
	system("cls");
}
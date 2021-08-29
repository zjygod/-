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
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void Workermanager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void Workermanager::add_worker()
{
	int add_num = 0;
	cout << "������Ҫ��ӵ�Ա����Ϣ������";
	cin >> add_num;
	if (add_num > 0)
	{
		this->file_flag = 1;
		int new_size = this->num + add_num;
		Worker** new_worker = new Worker*[new_size];//�����µ��ڴ�
		if (this->worker != NULL)
		{
			for (int i = 0; i < this->num; i++)
			{
				new_worker[i] = this->worker[i];
			}
		}
		for (int i = 0; i < add_num; i++)
		{
			int id = 0;//��¼ְ�����
			string name;//��¼����
			int  job;//��¼��������
			cout << "��" <<i+1<< "���˵�ְ�����: ";
			cin >> id;
			cout << endl;
			cout << "��" <<i+1<< "���˵�����: ";
			cin >> name;
			cout << endl;
			cout << "1: ���� " << endl << "2: ����" << endl<<"3: �ϰ�" << endl;
			cout << "��" << i + 1 << "���˵ĸ�λ: ";
			cin >> job;
			cout << endl;
			Worker *temp=NULL;
			switch (job)
			{
			case 1:
				temp = new Employee(id, name, "����");
				break;
			case 2:
				temp = new Manager(id, name, "����");
				break;
			case 3:
				temp = new Boss(id, name, "�ϰ�");
				break;
			}
			new_worker[i + this->num] = temp;
			//delete temp;����мɲ���delete����delete�����ݾ�û�ˣ�
		}
		delete[] this->worker;//����ԭ���Ķ����ڴ�
		this->worker = new_worker;//ָ���µ��ڴ�
		this->num = new_size;
		cout << "�ɹ����" << add_num << "����ְ��"<<endl;
	}
	else
	{
		cout << "�����ʽ����ȷ������������";

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
		if (job == "����")
		{
			temp1 = new Employee(num,name,job);
		}
		else if (job == "����")
		{
			temp1 = new Manager(num, name, job);
		}
		else if(job == "�ϰ�")
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
		cout << "�������ʵ��ļ������ڻ��ļ�������Ϣ" << endl;
	}
	system("pause");
	system("cls");
}
void Workermanager::delete_worker()
{
	cout << "������Ҫɾ����Ա�����: ";
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
	cout << "�޸ĳɹ�" << endl;
	system("pause");
	system("cls");
}
void Workermanager::rectify_worker()
{
	cout << "������Ҫ�޸���Ϣ��Ա�����: ";
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
	cout << "�������޸ĵ�ְλ: ";
	string job;
	cin >> job;
	Worker *new_worker = NULL;
	if (job == "����")
	{
		new_worker = new Employee(this->worker[temp]->w_num, this->worker[temp]->w_name, job);
	}
	else if (job == "����")
	{
		new_worker = new Manager(this->worker[temp]->w_num, this->worker[temp]->w_name, job);
	}
	else if (job == "�ϰ�")
	{
		new_worker = new Boss(this->worker[temp]->w_num, this->worker[temp]->w_name, job);
	}
	delete worker[temp];
	worker[temp] = new_worker;
	this->save();
	cout << "�޸ĳɹ�" << endl;
	system("pause");
	system("cls");
}
void Workermanager::find_worker()
{
	cout << "��������Ҫ������Ϣ�ķ�ʽ: " << endl;
	cout << "1: ����Ա����Ų�����Ϣ" << endl << "2: ����Ա������������Ϣ" << endl;
	int get_way;
	cin >> get_way;
	switch (get_way)
	{
	case 1:
		cout << "������Ա���ı��: ";
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
		cout << "������Ա��������: ";
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
	cout << "��ѡ����Ҫ����ķ�ʽ:" << endl;
	cout << "1: ����" << endl;
	cout << "2: ����" << endl;
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
	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
}
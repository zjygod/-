#include<iostream>
#include<string>
#include<fstream>
#include"employee.h"
#include"worker.h"
#include"workermanager.h"
using namespace std;
void test01()
{
	Worker *p = new Employee(23,"����","����");
	p->show_Info();
	delete p;
}
int main()
{
	//test01();
	Workermanager worker;
	while (1)
	{
		worker.show_menu();
		int choice = 0;
		cout << "��ѡ����Ҫ���еĲ���" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			worker.exit_system();//�˳�ϵͳ
			break;
		case 1:
			worker.add_worker();//���Ա����Ϣ
			worker.save();//����Ա����Ϣ
			break;
		case 2:
			worker.show_worker();//��ʾԱ����Ϣ
			break;
		case 3:
			worker.delete_worker();//ɾ��Ա����Ϣ
			break;
		case 4:
			worker.rectify_worker();//�޸�Ա����Ϣ
			break;
		case 5:
			worker.find_worker();//����Ա����Ϣ
			break;
		case 6:
			worker.sort();//����
			break;
		case 7:

		case 8:

		default:
			system("cls");
			break;
		}
	}
	cout << "zjygod" << endl;
	return 0;
}
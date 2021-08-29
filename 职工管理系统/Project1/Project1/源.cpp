#include<iostream>
#include<string>
#include<fstream>
#include"employee.h"
#include"worker.h"
#include"workermanager.h"
using namespace std;
void test01()
{
	Worker *p = new Employee(23,"张三","工人");
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
		cout << "请选择您要进行的操作" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			worker.exit_system();//退出系统
			break;
		case 1:
			worker.add_worker();//添加员工信息
			worker.save();//保存员工信息
			break;
		case 2:
			worker.show_worker();//显示员工信息
			break;
		case 3:
			worker.delete_worker();//删除员工信息
			break;
		case 4:
			worker.rectify_worker();//修改员工信息
			break;
		case 5:
			worker.find_worker();//查找员工信息
			break;
		case 6:
			worker.sort();//排序
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
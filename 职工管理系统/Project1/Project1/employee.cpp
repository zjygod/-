#include "employee.h"
using namespace std;
Employee::Employee(int num, string name, string job)
{
	this->w_num = num;
	this->w_name = name;
	this->w_job = job;
}
void Employee::duty()
{
	cout << "��ɾ�����������" << endl;
}
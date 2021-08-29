#include "boss.h"
using namespace std;
Boss::Boss(int num, string name, string job)
{
	this->w_num = num;
	this->w_name = name;
	this->w_job = job;
}
void Boss::duty()
{
	cout << "管理公司所有事务" << endl;
}
#include"manager.h"
using namespace std;
Manager::Manager(int num, string name, string job)
{
	this->w_num = num;
	this->w_name = name;
	this->w_job = job;
}
void Manager::duty()
{
	cout << "����ϰ彻�������񣬲��·������Ա��" << endl;
}
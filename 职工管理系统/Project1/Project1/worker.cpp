#include "worker.h"
using namespace std;
void Worker::show_Info()
{
	cout << "职工编号: " << this->w_num << "\t职工姓名: " << this->w_name << "\t职工岗位: " << this->w_job << "\t职工职责：";
	this->duty();
	cout << endl;
}
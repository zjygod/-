#include "worker.h"
using namespace std;
void Worker::show_Info()
{
	cout << "ְ�����: " << this->w_num << "\tְ������: " << this->w_name << "\tְ����λ: " << this->w_job << "\tְ��ְ��";
	this->duty();
	cout << endl;
}
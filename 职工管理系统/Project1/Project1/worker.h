#pragma once
#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
	virtual void duty() = 0;
	void show_Info();
public:
	int w_num;
	string w_name;
	string w_job;
};

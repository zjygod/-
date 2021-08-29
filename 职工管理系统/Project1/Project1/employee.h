#pragma once
#include"worker.h"
#include<iostream>
using namespace std;
class Employee :public Worker
{
public:
	Employee(int num, string name, string job);
	virtual void duty();
	
};
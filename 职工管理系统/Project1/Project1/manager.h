#pragma once
#include <iostream>
#include"worker.h"
class Manager :public Worker
{
public:
	Manager(int num, string name, string job);
	virtual void duty();
};
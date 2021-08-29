#pragma once
#include <iostream>
#include "worker.h"
class Boss:public Worker
{
public:
	Boss(int num, string name, string job);
	virtual void duty();
};
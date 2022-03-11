#pragma once

#include"Conditioner.h"

class CondRemote
{
private:
	Conditioner* cond;
public:
	CondRemote(Conditioner* cond);
	void setTemp(Kitchen* kitchen, double temp);
};


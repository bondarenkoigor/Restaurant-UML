#include "CondRemote.h"

CondRemote::CondRemote(Conditioner* cond)
{
	this->cond = cond;
}

void CondRemote::setTemp(Kitchen* kitchen, double temp)
{
	(*cond).setTemp(kitchen, temp);
}

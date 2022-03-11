#include<iostream>
#include "Kitchen.h"
void Kitchen::setTemp(double temp)
{
	this->temperature = temp;
}

void Kitchen::plateSwitch()
{
	this->plateOn = !this->plateOn;
}

bool Kitchen::isPlateOn()
{
	return this->plateOn;
}

void Kitchen::addFridge()
{
	fridges.push_back(Fridge());
}

void Kitchen::addFood(int fridgeNum, string foodName)
{
	if (fridgeNum >= this->fridges.size())
	{
		std::cout << "wrong input\n";
		return;
	}
	fridges[fridgeNum].addFood(foodName);
	std::cout << foodName << " added to fridge #" << fridgeNum << "\n";
}

void Kitchen::takeOutFood(int fridgeNum, string foodName)
{
	this->fridges[fridgeNum].takeOut(foodName);
}

std::vector<Fridge> Kitchen::getFridges()
{
	return this->fridges;
}

std::string Kitchen::getAllFood()
{
	std::string str;
	for (int i = 0; i<this->fridges.size(); i++)
	{
		str += std::to_string(i) + ". " + this->fridges[i].getFoodList() + "\n";
	}
	return str;
}

double Kitchen::getTemp()
{
	return this->temperature;
}


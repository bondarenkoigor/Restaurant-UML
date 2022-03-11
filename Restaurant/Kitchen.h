#pragma once
#include"Fridge.h"
using std::string;

class Kitchen
{
private:
	std::vector<Fridge> fridges;
	double temperature;
	bool plateOn;
public:
	Kitchen() : temperature(20), plateOn(false) {}
	void plateSwitch();
	bool isPlateOn();
	void addFridge();
	void addFood(int, string);
	void takeOutFood(int, string);
	std::vector<Fridge> getFridges();
	std::string getAllFood();
	double getTemp();
	void setTemp(double temp);
};


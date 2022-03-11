#pragma once
#include<vector>
#include<string>

class Fridge
{
private:
	std::vector<std::string> food;
public:
	void addFood(std::string foodName);
	void takeOut(std::string foodName);
	std::string getFoodList();
};


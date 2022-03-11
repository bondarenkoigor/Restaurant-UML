#include <algorithm>
#include<iostream>
#include "Fridge.h"

void Fridge::addFood(std::string foodName)
{
	food.push_back(foodName);
}

void Fridge::takeOut(std::string foodName)
{
	auto iter = find_if(food.begin(), food.end(), [foodName](std::string food) {return foodName == food; });
	if (iter._Ptr == NULL)
	{
		std::cout << "no such food\n";
		return;  
	}
	food.erase(iter);
	std::cout << foodName << " is taken out\n";
}

std::string Fridge::getFoodList()
{
	std::string str;
	for (auto i : food)
	{
		str += i + ", ";
	}
	return str;
}


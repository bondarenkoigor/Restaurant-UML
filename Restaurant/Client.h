#pragma once
#include<string>
#include<list>

using std::string;

class Client
{
private:
	std::list<string> order;
	Client() {}
public:
	Client(std::list<string> order) : order(order) {}
	void addToOrder(string newItem);
};


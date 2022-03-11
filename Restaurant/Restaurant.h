#pragma once
#include<iostream>
#include<queue>
#include"Kitchen.h"
#include"Client.h"
class Restaurant
{
private:
	std::string name;
	Kitchen* kitchen;
	std::queue<Client> clients;
public:
	Restaurant(std::string name) : name(name), kitchen(new Kitchen) {}
	void addClient(Client client);
	void serveClient();
	Kitchen* getKitchen();
	std::string getInfo();
	bool isEmpty();
	~Restaurant();
};


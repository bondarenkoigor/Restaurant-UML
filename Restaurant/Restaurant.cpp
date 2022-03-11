#include "Restaurant.h"

void Restaurant::addClient(Client client)
{
	std::cout << "new client added\n";
	clients.push(client);
}

void Restaurant::serveClient()
{
	std::cout << "client served\n";
	clients.pop();
}


Kitchen* Restaurant::getKitchen()
{
	return this->kitchen;
}

std::string Restaurant::getInfo()
{
	std::string str = "Restaurant name: " + this->name + "\n"
		+ "number of clients: " + std::to_string(clients.size()) + "\n\n"
		+ "Kitchen info:\n"
		+ "number of fridges: " + std::to_string(kitchen->getFridges().size()) + "\n"
		+ "temperature: " + std::to_string(kitchen->getTemp()) + "\n"
		+ "plate: " + (kitchen->isPlateOn() ? "on" : "off") + "\n";
	return str;
}


bool Restaurant::isEmpty()
{
	return this->clients.empty();
}

Restaurant::~Restaurant()
{
	delete this->kitchen;
}

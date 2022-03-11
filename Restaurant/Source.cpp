#include<iostream>
#include"Restaurant.h"
#include"CondRemote.h"

using std::cout; using std::string;

void kitchenCase(Restaurant& rest)
{
	int choice;
	do
	{
		system("cls");
		cout << rest.getInfo() << "\n"
			<< "1 - add a fridge\n"
			<< "2 - add food\n"
			<< "3 - take out food\n"
			<< "4 - get food list\n"
			<< "5 - set new temperature\n"
			<< "6 - turn plate on/off\n"
			<< "0 - go back\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			rest.getKitchen()->addFridge();
			break;
		case 2: //fallthrough
		case 3:
		{
			if (rest.getKitchen()->getFridges().size() == 0)
			{
				cout << "no fridges\n";
				break;
			}
			cout << "select a fridge(0-" << rest.getKitchen()->getFridges().size() - 1 << "):";
			int fridgeNum;
			std::cin >> fridgeNum;
			cout << "enter food: ";
			string food;
			std::cin >> food;
			if (choice == 2) rest.getKitchen()->addFood(fridgeNum, food);
			else rest.getKitchen()->takeOutFood(fridgeNum, food);
			break;
		}
		case 4:
			cout << rest.getKitchen()->getAllFood();
			break;
		case 5:
		{
			cout << "enter temperature:";
			double temp;
			std::cin >> temp;
			Conditioner cond;
			CondRemote remote(&cond);
			remote.setTemp(rest.getKitchen(), temp);
		}
		case 6: rest.getKitchen()->plateSwitch();
		case 0: continue;
		}
		system("pause");
	} while (choice != 0);
}

int main()
{
	Restaurant rest("name");
	int choice;
	do
	{
		system("cls");
		cout << rest.getInfo() << "\n"
			<< "1 - add a client\n"
			<< "2 - serve a client\n"
			<< "3 - kitchen\n"
			<< "0 - exit\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::list<string> order;
			string item;
			cout << "client's order(enter 0 to stop):\n";
			while (item != "0")
			{
				std::cin >> item;
				order.push_back(item);
			}
			rest.addClient(Client(order));
		}
		break;
		case 2:
			if (rest.isEmpty())
			{
				cout << "no clients\n";
				break;
			}
			rest.serveClient();
			break;
		case 3: kitchenCase(rest);
			break;
		}
		system("pause");
	} while (choice != 0);
}

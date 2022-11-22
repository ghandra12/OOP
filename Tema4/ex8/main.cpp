#include <iostream>
#include <string>
#include <list>
using namespace std;

class Food
{
private:
	string name;
	int cookingTime; //expressed in the form: for 7 minutes 700, for 10 minutes 1000, minutes*100
	double price;
public:
	void setName(string name)
	{
		this->name = name;
	}
	void setCookingTime(int cookingTime)
	{
		this->cookingTime = cookingTime;
	}
	void setPrice(double price)
	{
		this->price = price;
	}

	string getName()
	{
		return name;
	}
	int getCookingTime()
	{
		return cookingTime;
	}
	double getPrice()
	{
		return price;
	}

	Food(string name = "UNKNOWN", int cookingTime=0, int price=0)
	{
		this->name = name;
		this->cookingTime = cookingTime;
		this->price = price;
	}
};
class Menu
{
private:
	list<Food> food;
public:
	void addFood(Food food)
	{
		this->food.push_back(food);
	}
	void displayMenu()
	{
		cout << "\n\n";
		cout << "Item number	" << "	Name	" << "	Cooking Time	" << "	Price	\n";
		list<Food>::iterator it;
		int counter = 0;
		for (it = food.begin(); it != food.end(); it++, counter++)
			cout << "Item no. " << counter << ": " << it->getName() << " " << it->getCookingTime() << " " << it->getPrice()<<"\n";
		cout << "\n\n";
	}

};
class Waiter
{
private:
	string name;
	list<Food> order;
public:
	void setName(string name)
	{
		this->name = name;
	}

	void addFood(Food food)
	{
		order.push_back(food);
	}

	string getName()
	{
		return name;
	}

	Waiter(string name = "UNKNOWN")
	{
		this->name = name;
	}

	double computeCost()
	{
		double cost=0;
		list<Food>::iterator it;
		for (it = order.begin(); it != order.end(); it++)
			cost += it->getPrice();
		return cost;
	}
	void deliverFood()
	{
		cout << "The waiter brings the food to the table. 'Enjoy!' he says and lets you eat in peace.\n";
		system("PAUSE");
	}
	void askCheck()
	{
		cout << "You asked for the check. \n";
		system("PAUSE");
		cout << "'I will bring you the check immediately!'\n";
		system("PAUSE");
		cout << "The waiter leaves and returns with the check.\n";
		system("PAUSE");
		double orderCost = computeCost();
		cout << "'Your total is " << orderCost << "\n";
		system("PAUSE");
		cout << "You pay for your meal.\n";
		system("PAUSE");
		cout << "'Thank you! I hope you ejoyed your time here!'\n";
		system("PAUSE");
		cout << "You walk out the door.\n";
		system("PAUSE");
	}
	void newCustomer(Menu menu)
	{
		cout << "'Hello! Welcome to our restaurant. How may I help you?'\n";
		system("PAUSE");
		cout << "You ask for a menu.\n";
		system("PAUSE");
		cout << "'I will bring you your menu immediately!'\n";
		system("PAUSE");
		cout << "The waiter brings your menu.\n";
		system("PAUSE");
		menu.displayMenu();
		cout << "You choose one of each items on the menu.\n";
		system("PAUSE");
		cout << "'I will bring your order immediately!'\n";
		system("PAUSE");
		cout << "The waiter leaves with your order.\n";
		system("PAUSE");
	}
};
class Cook
{
private:
	string name;
	list<Food> order;
public:
	void setName(string name)
	{
		this->name = name;
	}
	void addFood(Food food)
	{
		order.push_back(food);
	}

	string getName()
	{
		return name;
	}

	Cook(string name = "Unknown")
	{
		this->name = name;
	}

	int computeCookingTime()
	{
		int cookingTime=0;
		list<Food>::iterator it;
		for (it = order.begin(); it != order.end(); it++)
			cookingTime += it->getCookingTime();
		return cookingTime;
	}
	void cookFood()
	{
		cout << "The waiter delivers the order. The cook starts cooking it immediately.\n";
		system("PAUSE");


	}
	void askForCookingTime(Waiter waiter)
	{
		cout << "You ask the waiter if he knows the total cooking time of your order.\n";
		system("PAUSE");
		cout << "'I will go ask the cook, I will be back in a minute.\n";
		system("PAUSE");
		cout << "The waiter asks the cook and comes back to tell you his answer\n";
		system("PAUSE");
		int cookingTime = computeCookingTime();
		cout << "'The cook said the food will be ready in " << cookingTime << " minutes. I apologise for the long wait.'\n";
		system("PAUSE");
	}
};

int main()
{
	Food food1 = Food("French Fries", 5, 5);
	Food food2 = Food("Pancakes", 10, 5);
	Food food3 = Food("Salad", 5 ,10);
	Food food4 = Food("Fish", 15, 25);
	Food food5 = Food("Beef stew", 2, 30);

	Menu menu = Menu();
	menu.addFood(food1);
	menu.addFood(food2);
	menu.addFood(food3);
	menu.addFood(food4);
	menu.addFood(food5);

	Waiter waiter = Waiter("Jean");
	waiter.newCustomer(menu);
	waiter.addFood(food1);
	waiter.addFood(food2);
	waiter.addFood(food3);
	waiter.addFood(food4);
	waiter.addFood(food5);

	Cook cook = Cook("Marie");
	cook.addFood(food1);
	cook.addFood(food2);
	cook.addFood(food3);
	cook.addFood(food4);
	cook.addFood(food5);

	cook.cookFood();
	cook.askForCookingTime(waiter);

	waiter.deliverFood();
	waiter.askCheck();
	return 0;

}

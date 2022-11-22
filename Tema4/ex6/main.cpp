#include <iostream>
#include <string>
using namespace std;

class Driver
{
private:
	string name;
	string driverLicence;
public:
	//setters
	void setName(string name)
	{
		this->name = name;
	}
	void setDriverLicence(string driverLicence)
	{
		this->driverLicence = driverLicence;
	}

	//getters
	string getName()
	{
		return name;
	}
	string getDriverLicence()
	{
		return driverLicence;
	}

	//constructor
	Driver(string name = "UNKNOWN", string driverLicence="not ok")
	{
		this->name = name;
		this->driverLicence = driverLicence;
	}
};

class Car
{
private:
	string carNumber;
	Driver driver;
	string carBook;
public:
	//setters
	void setCarNumber(string carNumber)
	{
		this->carNumber = carNumber;
	}
	void setDriver(Driver driver)
	{
		this->driver = driver;
	}
	void setCarBook(string carBook)
	{
		this->carBook = carBook;
	}

	//getters
	string getCarNumber()
	{
		return carNumber;
	}
	Driver getDriver()
	{
		return driver;
	}
	string getCarBook()
	{
		return carBook;
	}

	//constructor
	Car(Driver driver, string carNumber = "UNKNOWN", string carBook = "not ok")
	{
		this->carNumber = carNumber;
		this->driver = driver;
		this->carBook = carBook;

	}
};

class Police
{
public:
	void askForDocuments()
	{
		cout << "Hello! Could you give me your driver's licence and your car's book?\n";
	}
	bool checkDriverLicence(string driverLicence)
	{
		if (driverLicence == "not ok")
		{
			cout << "I am sorry, your driver licence is not valid.\n";
				return false;
		}
		cout << "Your driver licence is valid.\n";
		return true;

	}
	bool checkCarBook(string carBook)
	{
		if (carBook == "not ok")
		{
			cout << "I am sorry, your car's book is not valid.\n";
			return false;
		}
		cout << "Your car's book is valid.\n";
		return true;

	}
	void stopCar(Car car)
	{
		askForDocuments();
		bool driverLicence = checkDriverLicence(car.getDriver().getDriverLicence()), carBook = checkCarBook(car.getCarBook());
		if (driverLicence == true && carBook == true)
		{
			cout << "Your papers are fine, you're free to go. Thank you!\n";
		}
		else
		{
			cout << "Your papers are not fine, we will have to take you to the station!\n";
		}

	}
};

int main()
{
	Driver driver1 = Driver("Andrei", "ok");
	Car car1 = Car(driver1, "AG27WXT", "ok");
	Police police;
	police.stopCar(car1);
	cout << "\n";

	Driver driver2 = Driver("Mihai", "not ok");
	Car car2 = Car(driver2, "AG27WXT", "ok");
	police.stopCar(car2);
	cout << "\n";

	Driver driver3 = Driver("Dana", "ok");
	Car car3 = Car(driver3, "AG27WXT", "not ok");
	police.stopCar(car3);
	cout << "\n";
}

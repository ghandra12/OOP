#include <iostream>
#include <string>
#include <list>
using namespace std;

class Address
{
private:
	string address;
public:
	Address(string address = "unknown")
	{
		this->address = address;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	string getAddress()
	{
		return address;
	}
};
class Person
{
private:
	string firstName;
	string lastName;
public:
	Person(string firstName="unknown", string lastName="unknown")
	{
		this->firstName = firstName;
		this->lastName = lastName;
	}

	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}
	void setLastName(string lastName)
	{
		this->lastName = lastName;
	}

	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
};
class Commuter : public Person
{
public:
	Commuter(string firstName = "unknown", string lastName = "unknown") :Person(firstName, lastName) {}
	string get1stName()
	{
		return getFirstName();
	}
	string get2ndName()
	{
		return getLastName();
	}
};
class Mosquito
{
private:
	string name;
public:
	Mosquito(string name = "unknown")
	{
		this->name = name;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}
};
class Apartment
{
private:
	Address* address;
	list<Person*> tenants;
public:
	Apartment(Address* address=NULL, Person* person=NULL)
	{
		this->address = address;
		tenants.push_back(person);
	}

	void setAddress(Address* address)
	{
		this->address = address;
	}
	void addTenant(Person* person)
	{
		tenants.push_back(person);
	}

	Address* getAddress()
	{
		return address;
	}

};
class Engine
{
private:
	string serialID;
public:
	Engine(string serialID="unknown")
	{
		this->serialID = serialID;
	}

	void setSerialID(string serialID)
	{
		this->serialID = serialID;
	}

	string getSerialID()
	{
		return serialID;
	}
};
class Driver : public Person
{
private:
	string drivingLicence;
public:
	Driver(string firstName = "unknown", string lastName = "unknown", string drivingLicence = "unknown") : Person(firstName, lastName)
	{
		this->drivingLicence = drivingLicence;
	}

	void setName(string firstName="unknown", string lastName="unknown")
	{
		setFirstName(firstName);
		setLastName(lastName);
	}
	void setDrivingLicence(string drivingLicence)
	{
		this->drivingLicence = drivingLicence;
	}

	string get1stName()
	{
		return getFirstName();
	}
	string get2ndName()
	{
		return getLastName();
	}

};
class Car
{
private:
	Engine* engine;
	Driver* driver;
public:
	Car(Engine* engine, Driver* driver)
	{
		this->engine = engine;
		this->driver = driver;
	}

	void setEngine(Engine* engine)
	{
		this->engine = engine;
	}
	void setDriver(Driver* driver)
	{
		this->driver = driver;
	}

	Engine* getEngine()
	{
		return engine;
	}
	Driver* getDriver()
	{
		return driver;
	}
};
class Buss : public Car
{
private:
	list<Address*> addresses;
	list<Commuter*> passengers;
	list<Mosquito*> mosquitoes;
public:
	Buss(Engine* engine = NULL, Driver* driver = NULL, Commuter* passenger = NULL, Mosquito* mosquito = NULL, Address *address=NULL) : Car(engine, driver)
	{
		addresses.push_back(address);
		passengers.push_back(passenger);
		mosquitoes.push_back(mosquito);
	}

	void addAddress(Address* address)
	{
		addresses.push_back(address);
	}
	void addCommuter(Commuter* commuter)
	{
		passengers.push_back(commuter);
	}
	void addMosquito(Mosquito* mosquito)
	{
		mosquitoes.push_back(mosquito);
	}

	bool canTakeBuss(Address* currentLocation, Address* destination)
	{
		bool ok1=0, ok2=0;
		list<Address*> ::iterator it;
		for (it = addresses.begin(); it != addresses.end(); it++)
		{
			if (*it == currentLocation)
				ok1 = 1;
			if (*it == destination)
				ok2 = 1;
		}
		if (ok1 == 1 && ok2 == 1)
			return 1;
		return 0;
	}

};
class BussStation
{
private:
	Address* address;
	list<Buss*> busses;
public:
	BussStation(Address* address=NULL, Buss* buss=NULL)
	{
		this->address = address;
		if(buss!=NULL)
			busses.push_back(buss);
	}

	void setAddress(Address* address)
	{
		this->address = address;
	}
	void addBuss(Buss* buss)
	{
		busses.push_back(buss);
	}

	Address* getAddress()
	{
		return address;
	}

	Buss* bussChoice(Address* currentLocation, Address* destination)
	{
		list<Buss*> ::iterator it;
		for (it = busses.begin(); it != busses.end(); it++)
		{
			if ((*it)->canTakeBuss(currentLocation, destination) == 1)
				return (*it);
		}
		return NULL;
	}
};
class Student : public Commuter
{
private:
	string school;
	string grade;
public:
	Student(string school="unknown", string grade="unknown", string firstName="unknown", string lastName="unknown") : Commuter( firstName, lastName)
	{
		this->school = school;
		this->grade = grade;
	}

	void setSchool(string school)
	{
		this->school = school;
	}
	void setGrade(string grade)
	{
		this->grade = grade;
	}

	string getSchool()
	{
		return school;
	}
	string getGrade()
	{
		return grade;
	}

	void leaveHome()
	{
		cout << "Student has left home.\n";
	}
	void goToStation(BussStation* station)
	{
		cout << "Student has gone to the closest station, which is station at address " << station->getAddress()->getAddress()<<".\n";
	}
	bool chooseBuss(BussStation* station, Address* destination)
	{
		Buss* buss=station->bussChoice(station->getAddress(), destination);
		if (buss != NULL)
		{
			cout << "Student has taken the buss to school.\n";
			return 1;
		}
		else
		{
			cout << "Student has no buss to take to school at this station.\n";
			return 0;
		}
	}
	void arrive(BussStation* station)
	{
		cout << "Student has arrived to the station at address " << station->getAddress()->getAddress() << " as it is the closest to his school, " << school << ".\n";
	}
	void goToSchool(BussStation* station, Address* destination)
	{
		leaveHome();
		goToStation(station);
		bool ok=chooseBuss(station, destination);
		if (ok == 1)
			arrive(station);
		else
			cout << "Student will stay at home today";
	}
};

int main()
{
	Address* address1 = new Address("Calea Bucuresti, 10B");
	Address* address2 = new Address("Nantere, 15C");
	Buss* buss1 = new Buss();
	Buss* buss2 = new Buss();
	buss1->addAddress(address1);
	buss1->addAddress(address2);
	buss2->addAddress(address1);
	buss2->addAddress(address2);

	BussStation* station1 = new BussStation(address1);
	BussStation* station2 = new BussStation(address2);
	station1->addBuss(buss1);
	station1->addBuss(buss2);
	station2->addBuss(buss1);
	station2->addBuss(buss2);

	Apartment* apartment1 = new Apartment(address1);
	Apartment* apartment2 = new Apartment(address2);

	Student* student1 = new Student("Mircea Eliade", "6B", "Andrei", "Popescu");
	Student* student2 = new Student("Mircea Eliade", "2B", "Elena", "Radu");
	apartment1->addTenant(student1);
	apartment2->addTenant(student2);

	buss1->addCommuter(student1);
	buss2->addCommuter(student2);

	student1->goToSchool(station1, address2);
}

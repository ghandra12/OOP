#include <iostream>
#include <cstring>
using namespace std;

struct Cat {
    char name[30], master[30];
    int age;
};

struct Person {
    char name[30];
    int age;
};

struct Car {
    char producer[30], licenceNumber[30];
    int age;
};

template <typename T>
T minimum(T a, T b)
{
    if (a.age < b.age)
        return a;
    else return b;
}

template <typename A, typename B>

bool checkAge(A a, B b)
{
    if (a.age == b.age)
        return true;
    else return false;
}
int main()
{
    Cat cat1, cat2;
    Person person1, person2;
    Car car1, car2;

    cin >> cat1.name >> cat1.master >> cat1.age;
    cin >> cat2.name >> cat2.master >> cat2.age;
    cin >> person1.name >> person1.age;
    cin >> person2.name >> person2.age;
    cin >> car1.producer >> car1.licenceNumber >> car1.age;
    cin >> car2.producer >> car2.licenceNumber >> car2.age;

    Cat resultCat;
    Person resultPerson;
    Car resultCar;

    resultCat = minimum(cat1, cat2);
    cout << "Cat with minimum age is: " << resultCat.name << " and is " << resultCat.age<< " years old.";
    resultPerson = minimum(person1, person2);
    cout << "Person with minimum age is: " << resultPerson.name << " and is " << resultPerson.age << " years old.";
    resultCar = minimum(car1, car2);
    cout << "Car with minimum age is: " << resultCar.producer << " and is " << resultCar.age << " years old.";




    cout << "\nAre the cats the same age? " << checkAge(cat1, cat2);
    cout << "\nAre the people the same age? " << checkAge(person1, person2);
    cout << "\nAre the cars the same age? " << checkAge(car1, car2);


    cout << "\nAre the cat and the person of the same age? " << checkAge(cat1, person2);
    cout << "\nAre the car and the person of the same age? " << checkAge(car1, person1);
}
/*template <typename T, typename P>

auto minimum(T a, P b)
{
    if (a.age < b.age)
        return a;
    else return b;
}

*/
//the template for a function that compares different structs would look something like this,
//while it is a property available in other languages, in C++ the function cannot be overloaded and therefor it does not allow different argument types.

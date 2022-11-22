#include <iostream>
#include <string>
using namespace std;

class NewClass
{
private:
    int number;
public:
    NewClass(int number) : number(number) {}
    NewClass(int* number) : number(*number) {}

    int getNumber()
    {
        return this->number;
    }
};

int main()
{
    NewClass *test;
    int nr = 6;

    test = new NewClass(7);
    cout << test->getNumber() << "\n";
    delete(test);

    test = new NewClass(&nr);
    cout << test->getNumber() << "\n";

    return 0;
}

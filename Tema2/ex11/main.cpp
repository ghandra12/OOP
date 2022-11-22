#include <iostream>
#include <cstring>
using namespace std;

int substraction(int x, int y)
{
    return x - y;
}

int addition(int x, int y)
{
    return x + y;
}


int main()
{
    int (*substr)(int, int) = &substraction;
    int (*add)(int, int) = &addition;
    int x, y;
    char c;
    cin >> x >> c >> y;
    if (c == '-')
    {
        cout << "Substraction:  ";
        cout << (*substr)(x, y);
    }
    else if (c == '+')
    {
        cout << "Addition: ";
        cout << (*add)(x, y);
    }

    return 0;
}

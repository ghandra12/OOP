#include <iostream>
#include <cstring>
using namespace std;

struct cat {
    char name[20];
    char gender;
};

int f(int x)
{
    return sizeof(x);
}
int f(double x)
{
    return sizeof(x);
}
int f(char* x)
{
    return strlen(x);
}
int f(cat x)
{
    return sizeof(x);
}

int main()
{


    int x=12345;
    double y = 46285.475;
    char z[] = "un string";
    cat C;
    strcpy(C.name, "Zeus");
    C.gender = 'm';


    cout << "int: " << f(x);
    cout << "\n";
    cout << "double: " << f(y);
    cout << "\n";
    cout << "char : " << f(z);
    cout << "\n";
    cout << "struct : " << f(C);
    cout << "\n";

    return 0;
}

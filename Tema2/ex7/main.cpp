#include <iostream>
#include <cmath>
using namespace std;

struct Cnumber {
    double
        a, b;
};


double absolute(Cnumber nr)
{
    double x = sqrt(nr.b * nr.b+ nr.a * nr.a);
    return x;
}

double absolute(double a, double b)
{
    double modulus = sqrt(a * a + b * b);
    return modulus;
}


int main()
{
    Cnumber complexNumber;
    cin >> complexNumber.a >> complexNumber.b;
    cout << "Function module(nrComplex nr): " << absolute(complexNumber) << "\n\nFunction mode(imaginaryPart, realPart): " << absolute(complexNumber.a, complexNumber.b);
    return 0;
}

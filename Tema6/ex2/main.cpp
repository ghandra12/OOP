#include <iostream>
using namespace std;

class Complex
{
    private:
      float real;
      float imag;
    public:

       void input()
       {
           cout << "Enter real and imaginary parts respectively: ";
           cin >> real;
           cin >> imag;
       }

       // Operator overloading
       Complex operator + (Complex c2)
       {
           Complex temp;
           temp.real = real + c2.real;
           temp.imag = imag + c2.imag;

           return temp;
       }

       void output()
       {
           if(imag < 0)
               cout << "Output Complex number: "<< real << imag << "i";
           else
               cout << "Output Complex number: " << real << "+" << imag << "i";
       }
};

int main()
{
    Complex ComplexNumber1, ComplexNumber2,ComplexNumber3;

    cout<<"Enter first complex number:\n";
    ComplexNumber1.input();

    cout<<"Enter second complex number:\n";
    ComplexNumber2.input();

    // In case of operator overloading of binary operators in C++ programming,
    // the object on right hand side of operator is always assumed as argument by compiler.
    ComplexNumber3 = ComplexNumber1 + ComplexNumber2;

    ComplexNumber3.output();

    return 0;
}

#include <iostream>
#include <math.h>
using namespace std;
class ComplexNumbers
{
private:
	double real;
	double imaginary;
public:
	//constructors

	ComplexNumbers(double real = 0, double imaginary = 0)
	{
		this->real = real;
		this->imaginary = imaginary;
	}

	//setters

	void setReal(double real)
	{
		this->real = real;
	}
	void setImaginary(double imaginary)
	{
		this->imaginary = imaginary;
	}

	//getters

	double getReal()
	{
		return real;
	}
	double getImaginary()
	{
		return imaginary;
	}
   double module()
	{
		return sqrt(real*real+ imaginary*imaginary);

	}
	bool operator < (ComplexNumbers n){
	    return  module()<n.module();
	}

};

int main()
{
	ComplexNumbers number1(2,3),number2(6,8);
	bool result= number1<number2;
	cout<<result;
}

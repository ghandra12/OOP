#include <iostream>
using namespace std;
class ComplexNumbers
{
private:
	double real;
	double imaginary;
public:


	ComplexNumbers(double real = 0, double imaginary = 0)
	{
		this->real = real;
		this->imaginary = imaginary;
	}



	void setReal(double real)
	{
		this->real = real;
	}
	void setImaginary(double imaginary)
	{
		this->imaginary = imaginary;
	}



	double getReal()
	{
		return real;
	}
	double getImaginary()
	{
		return imaginary;
	}

};



class Operations
{
private:
	ComplexNumbers number;
public:
	Operations(double real = 0, double imaginary = 0)
	{
		number = ComplexNumbers(real, imaginary);
	}
	double module()
	{
		return sqrt(number.getReal() * number.getReal() + number.getImaginary() * number.getImaginary());

	}
	double module(double real, double imaginary=0)
	{
		return sqrt(real * real + imaginary * imaginary);

	}
};
int main()
{
	Operations operations;
	operations = Operations(2);
	cout << operations.module()<<endl;
	operations = Operations(3, 4);
	cout << operations.module()<<endl;
	cout << operations.module(2)<<endl;
	cout << operations.module(3, 4)<<endl;
}

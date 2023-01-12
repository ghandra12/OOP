#include <iostream>
#include <math.h>
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
	///T.6.5
	static double module(ComplexNumbers number){
        return sqrt(number.getReal() * number.getReal() + number.getImaginary() * number.getImaginary());

	}
	static void display(ComplexNumbers number){

	    if(number.getImaginary()<0)
            cout<<number.getReal()<<number.getImaginary()<<"i";
        else
            cout<<number.getReal()<<"+"<<number.getImaginary()<<"i";
        }
};
int main()
{
	ComplexNumbers number(2,3);
	Operations::display(number);
	cout<<endl;
	cout<<"Modulul numarului complex este:\n";
	cout<<Operations::module(number);
}

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

public:

	double sum(double a, double b){
	   return a+b;
	}
	ComplexNumbers sum(ComplexNumbers a,ComplexNumbers b){
	     int SumRe=0;
	     int SumIm=0;
         SumRe=a.getReal()+b.getReal();
	     SumIm=a.getImaginary()+b.getImaginary();
	     return ComplexNumbers(SumRe,SumIm);

	}
};
int main()
{
	ComplexNumbers number1(2,3),number2(4,5);
	Operations instanceOfOperations;
	cout<<"Suma unui numar real:\n"<<instanceOfOperations.sum(6,7);
	cout<<"\nSuma a doua numere complexe:";
	ComplexNumbers number3=instanceOfOperations.sum(number1,number2);
	if(number3.getImaginary()<0)
        cout<<number3.getReal()<<number3.getImaginary()<<"i";
	else
        cout<<number3.getReal()<<" + "<<number3.getImaginary()<<"i";

}

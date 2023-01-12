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

	static double sum(double a, double b){
	   return a+b;
	}
	static ComplexNumbers sum(ComplexNumbers a,ComplexNumbers b){
	     int SumRe=0;
	     int SumIm=0;
         SumRe=a.getReal()+b.getReal();
	     SumIm=a.getImaginary()+b.getImaginary();
	     return ComplexNumbers(SumRe,SumIm);

	}
	static double division(double a, double b){
	   if(b>0)
          return a/b;
       return 0;
	}
	///!!!!!!
	static void division(ComplexNumbers a,ComplexNumbers b){
	       ///presupunem numarul complex a de forma a+b*i si b de forma c+d*i
	       int numitor;
	       numitor=b.getReal()*b.getReal()-b.getImaginary()*b.getImaginary();
	       int numarator,numarator_i;
	       numarator= a.getReal()*b.getReal() +a.getImaginary()*b.getImaginary();
	       numarator_i= a.getReal()*b.getImaginary() +a.getImaginary()*b.getReal();
          cout<<"["<<numarator<<"+"<<numarator_i<<"*i]/"<<numitor;

	}     ///(a+bi)/(c+di)=>>amplificand cu conjugata [(a+bi)(c-di)](c^2-d^2)
                                                 ///[numarator](numitor)
};
int main()
{
	ComplexNumbers number1(2,3),number2(4,5);
	///Operations instanceOfOperations;
	cout<<"Suma unui numar real:\n"<<Operations::sum(6,7);
	cout<<"\nSuma a doua numere complexe:";
	ComplexNumbers number3=Operations::sum(number1,number2);
	if(number3.getImaginary()<0)
        cout<<number3.getReal()<<number3.getImaginary()<<"i";
	else
        cout<<number3.getReal()<<" + "<<number3.getImaginary()<<"i";
    ComplexNumbers number4(5,4),number5(6,1);
    cout<<endl<<"Impartirea a doua numere reale:\n"<<Operations::division(4,5);
    cout<<endl<<"Impartirea a doua numere complexe:\n";
    Operations::division(number4,number5);
}

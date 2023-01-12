#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
class Shape
{
public:
	virtual void draw() = 0; // we define the general behavior
	virtual double computeArea() = 0;
};
class Circle : public Shape
{
	int radius;
public:
	Circle(int radius)
	{
		this->radius = radius;
	}
	void draw() { cout << "circle\n"; } // we specify the behavior for this shape
	double computeArea() {return 3.14 * radius * radius ; }
};
class Triangle : public Shape
{
	double a;
	double b;
	double c;
public:
	Triangle(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	void draw() { cout << "triangle\n"; } // we specify the behavior for this shape
	double computeArea() {
		double p = (double)(a + b + c) / 2;
		return sqrt((double)p * (p - a) * (p - b) * (p - c));
	}
};
class Square : public Shape
{
	int l;
public:
	Square(int l)
	{
		this->l = l;
	}
	void draw() { cout << "square\n"; } // we specify the behavior for this shape
	double computeArea() { return l*l; }
};
class Rectangle : public Shape
{
	double a;
	double b;
public:
	Rectangle(double a, double b)
	{
		this->a = a;
		this->b = b;
	}
	void draw() { cout << "rectangle\n"; } // we specify the behavior for this shape
	double computeArea() {
		return a*b;
	}
};
class Drawing
{
	Shape* pShape;
public:
	Drawing(Shape* pShape)
	{
		this->pShape = pShape;
	}
	void drawShape()
	{
		pShape->draw();
	}
};
class Test{
public:
    void isSquareAreaValid(int l,int expectedValue){
       Square square(l);
       double s=square.computeArea();
       if(s==expectedValue)
          cout<<"Result is correct!!!\n";
       else
          cout<<"Result is not correct!!!\n";

       }


};
int main()
{
      vector<Shape*> Shapes;
    Test* test;
    test-> isSquareAreaValid(4, 16);
    test-> isSquareAreaValid (400, 160000);
    test-> isSquareAreaValid (0, 0);
    test-> isSquareAreaValid (NULL, NULL);
    test-> isSquareAreaValid (-4, NULL);
}

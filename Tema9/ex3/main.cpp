#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Shape
{
public:
	virtual void draw() = 0; // we define the general behavior
	virtual void computeArea() = 0;
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
	void computeArea() { cout << 3.14 * radius * radius << "\n"; }
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
	void computeArea() {
		double p = (double)(a + b + c) / 2;
		cout << sqrt((double)p * (p - a) * (p - b) * (p - c)) << "\n";
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
	void computeArea() { cout << l*l << "\n"; }
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
	void computeArea() {
		cout << a*b<<"\n";
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
class Area
{
	Shape* pShape;
public:
	Area(Shape* pShape)
	{
		this->pShape = pShape;
	}
	void computeArea()
	{
		pShape->computeArea();
	}
};
int main()
{
	Drawing* d = new Drawing(new Triangle(4, 5, 6));
	Area* a = new Area(new Triangle(4, 5, 6));
	d->drawShape();
	a->computeArea();

	d = new Drawing(new Circle(4));
	a = new Area(new Circle(4));
	d->drawShape();
	a->computeArea();

	Drawing e = Drawing(new Triangle(5, 5, 5));
	Area b = Area(new Triangle(5, 5, 5));
	e.drawShape();
	b.computeArea();

	e = Drawing(new Circle(3));
	b = Area(new Circle(3));
	e.drawShape();
	b.computeArea();

	Triangle t1 = Triangle(2, 3, 4);
	Circle c1 = Circle(6);
	Drawing f = Drawing(&t1);
	Area c = Area(&t1);
	f.drawShape();
	c.computeArea();
	f = Drawing(&c1);
	c = Area(&c1);
	f.drawShape();
	c.computeArea();
}

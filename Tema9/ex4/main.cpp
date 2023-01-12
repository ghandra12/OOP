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

int main()
{
      vector<Shape*> Shapes;
      Triangle t(2,3,4);
      Square s(4);
      Rectangle r(2,2);
      Circle c(10);
      Shapes.push_back(&t);
      Shapes.push_back(&s);
      Shapes.push_back(&r);
      Shapes.push_back(&c);
      int suma=0;
      for(auto it=Shapes.begin();it!=Shapes.end();it++){
        suma=suma+(*it)->computeArea();

      }
    cout<<"Suma tututor formelor geometrice: "<<suma;
}

#include <iostream>
using namespace std;
class Form {
private:
	string color;
protected:
	string name;
	void setColor(string color) {
		this->color = color;
	}
public:
	Form(string name) {
		this->name = name;
	}
	string getName() {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
	void showMessage() {
		cout << "message from Form" << endl;
	}
	int computePerimeter()
	{
		return 0;
	}
};
class Rectangle :public Form {
protected:
	int width;
	int height;
public:
	Rectangle(string name, int width, int height) :Form(name) {
		this->width = width;
		this->height = height;
	}
	void setWidth(int width) {
		this->width = width;
	}
	int getWidth() {
		return this->width;
	}
	void showMessage() {
		Form::showMessage(); // operator :: used to call showMessage from base class
		cout << "message from Rectangle" << endl;
	}
	int computePerimeter()
	{
		return height*2+width*2;
	}
};
class Square :public Form {
protected:
	int side;
public:
	Square(string name, int side) :Form(name) {
		this->side = side;
	}
	void setSide(int side) {
		this->side = side;
	}
	int getSide() {
		return this->side;
	}
	void showMessage() {
		cout << " message from Square" << endl;
	}
	int computePerimeter()
	{
		return side*4;
	}
};
int main()
{
	Form* f = new Form("forma1");
	cout << "form: " << f->getName() << endl;
	f->showMessage();
	cout << "\n" << f->computePerimeter() << "\n";
	Rectangle* r = new Rectangle("rectangle 1", 1, 2);
	cout << "rectangle name: " << r->getName() << " width:" << r->getWidth() << endl;
	r->showMessage();
	cout << "\n" << r->computePerimeter() << "\n";
	Square* s = new Square("square 1", 20);
	cout << "square name: " << s->getName() << " side:" << s->getSide() << endl;
	s->showMessage();
	cout << "\n" << s->computePerimeter() << "\n";
	return 0;
}

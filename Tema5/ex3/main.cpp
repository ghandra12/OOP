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
    Form(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    void showMessage(){
        cout<<"message from Form"<<endl;
    }
    void computeArea(){
        cout<<"Vom calcula aria urmatoarei forme: ";
    }
};

class Rectangle:public Form {
protected:
    int width;
    int height;
public:
    Rectangle(string name, int width, int height) :Form(name){
        this->width = width;
        this->height = height;
    }
    void setWidth(int width){
        this->width = width;
    }
    int getWidth(){
        return this->width;
    }
   void showMessage(){
        Form::showMessage(); // operator :: used to call showMessage from base class
        cout<<"message from Rectangle"<<endl;
    }

    void computeArea(){
       int Area;;
       cout<<"Rectangle";
       Area=width*height;
       cout<<"\nMy Rectangle Area= "<<Area;
    }
};
class Square:public Form {
protected:
    int side;
public:
    Square(string name, int side) :Form(name){
        this->side = side;
    }
    void setSide(int side){
        this->side = side;
    }
    int getSide(){
        return this->side;
    }
    void showMessage(){
        cout<<" message from Square"<<endl;
    }
    void computeArea(){
       int Area;
       cout<<"Square";
       Area=side*side;
       cout<<"\nMy Square Area= "<<Area;
    }

};

int main()
{
    Form *f = new Form("forma1");
    cout<<"form: "<<f->getName()<<endl;
    f->showMessage();

    Rectangle *r = new Rectangle("rectangle 1", 1, 2);
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl;
    r->showMessage();

    Square *s = new Square("square 1", 20);
    cout<<"square name: "<<s->getName()<<" side:"<<s->getSide()<<endl;
    s->showMessage();

    cout<<endl<<endl<<endl;

    Form myForm("Form");
    myForm.computeArea();
    cout<<endl;

    Rectangle myRectangle("My Rectangle",2,3);
    myRectangle.computeArea();
    cout<<endl;

    Square mySquare("My Square",5);
    mySquare.computeArea();

    return 0;
}

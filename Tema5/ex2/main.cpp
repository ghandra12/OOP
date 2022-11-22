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
    Form(){
    cout<<"This is a constructor for class Form!!!!!!!!";

    }
    string getName(){
        return this->name;
}
    void setName(string name){
        this->name = name;}

   ~Form(){
   cout<<"\nThis is a destructor for class Form";
   }


};
class Rectangle:public Form {
protected:
    int width;
    int height;
public:
    Rectangle(string name, int width, int height) :Form(name){
// call :Form(name){ can miss
        this->width = width;
        this->height = height;
    }
    Rectangle():Form(){
    cout<<"This is a constructor for Rectangle class";
    }
    void setWidth(int width){
        this->width = width;
    }
    int getWidth(){
        return this->width;
    }
    ~Rectangle(){
    cout<<"\nThis is a destructor for class Rectangle";
    }
};
int main()
{
Form *f = new Form("forma1");
cout<<"forma: "<<f->getName()<<endl;
Rectangle *r = new Rectangle("rectangle 1", 1, 2);
cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl;
cout<<endl<<"DUPA CE AM CREAT UN NOU CONSTRUCTOR:\n";
Form();
cout<<endl;
Rectangle();//Afiseaza ce este afisat si in constructorul Form + ce am adaugat exclusiv in constructorul Rectangle;
///Obervatii:
/// Mai intai se apeleaza constructorii din mostenire apoi constructorul din clasa creata si destructorii,la final,in ordine inversa.

return 0;
}

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
class IntValueWrapper {
    int value;
public:
    IntValueWrapper(){}
    IntValueWrapper(int value) {
        this->value = value;
    }
    int getValue() {
        return this->value;
    }
    IntValueWrapper Random(){
         srand(time(NULL));
        IntValueWrapper i(rand());
        return i;
    }
};
class FloatValueWrapper {
float value;
public:
    FloatValueWrapper(){}
    FloatValueWrapper(float value) {
        this->value = value;
    }
    float getValue() {
        return this->value;
    }
     FloatValueWrapper Random(){
          srand(time(NULL));
         FloatValueWrapper f((float)(rand()) / (float)(rand()));
         return f;

    }
};
class ComplexNumber{
private:
    int real;
    int imaginar;
public:
        ComplexNumber(){}
        ComplexNumber(int real,int imaginar){
            this->real=real;
            this->imaginar=imaginar;
        }
        int getReal(){
            return real;
        }
       int getImaginar(){
            return imaginar;
       }
       ComplexNumber Random(){
            srand(time(NULL));
            int real=rand();
            int imaginar=rand();
            ComplexNumber z(real,imaginar);
            return z;
      }

};
template<class T>
class Random{
public:
   T getRandom(T t){
        return t.Random();
    };

};

int main()
{  Random<IntValueWrapper> random1;
   Random<FloatValueWrapper> random2;
   Random<ComplexNumber> random3;
   IntValueWrapper i;
   i=random1.getRandom(i);
   cout<<"Nr intreg random: "<<i.getValue();
   FloatValueWrapper f;
   f=random2.getRandom(f);
   cout<<"\nNr real random: "<<f.getValue();
   ComplexNumber z;
   z=random3.getRandom(z);
   cout<<"\nNr complex random: "<<z.getReal()<<" + " <<z.getImaginar()<<"*i";


    return 0;
}

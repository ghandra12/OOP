#include<iostream>
using namespace std;
class A
{
public:
    int aa;

    A(int val1,int val2,int val3){
        aa=val1;
        ab=val2;
        ac=val3;
    }
    int getAB(){
        return ab;
    }
    int getAC(){
        return ac;
    }

protected:
    int ab;

private:
    int ac;

public:
    void testA(){
    // set the attributes in class A
        aa = 1;
        ab = 2;
        ac = 3;
    }
};
class B : public A // => public inheritance: makes public members of the base class public in the derived class, and protected members of the base class remain protected in the derived class.
{
public:
    int ba;
    // public aa, protected ab, private ac from inheritance

    int getBC(){
        return bc;
    }

    int getBB(){
        return bb;
    }


    B(int val1,int val2,int val3, int val4, int val5, int val6):A(val4,val5,val6){
        ba=val1;
        bb=val2;
        bc=val3;
    }  //pseudo-constructor
     int getAC_fromA(){
       getAC();

     }
protected:
    int bb;
private:
    int bc;
public:
    void testB(){
        ba=10;
        bb=11;
        bc=12;
        aa=13;
        ab=14;
        //ac=15;
        //ac can't be modified since it's private
    }
};
class C : private B // => private inheritance: makes the public and protected members of the base class private in the derived class.
{
public:
    int ca;
    // private aa, ab, ac, ba, bb, bc from inheritance
    C(int val1,int val2,int val3, int val4, int val5, int val6, int val7, int val8, int val9):B(val4,val5,val6, val7, val8, val9){
        ca=val1;
        cb=val2;
        cc=val3;
    }

    int getCC(){
        return cc;
    }

    int getCB(){
        return cb;
    }
    int getBA(){
     return ba;
    }
    int getBB(){
      return bb;
    }
    int getBC_fromB(){
       getBC();
    }
    int getAA(){
       return aa;
    }
    int getAB(){
       return ab;
    }
    int getAC_fromB(){
       getAC_fromA();
    }
protected:
    int cb;
private:
    int cc;

public:
    void testC(){
        ca=20;
        cb=21;
        cc=22;
        ba=23;
        bb=24;
        //bc=25; bc can't be modified since it's private
        aa=26;
        ab=27;
        //ac=28; ac can't be modified since it's private
    }
};
///protected inheritance: makes the public and protected members of the base class protected in the derived class.
int main(){

    A obj1(3,4,5);
    cout<<"A: "<<obj1.aa<<" "<<obj1.getAB()<<" "<<obj1.getAC()<<endl;
    obj1.testA();
    cout<<"A: "<<obj1.aa<<" "<<obj1.getAB()<<" "<<obj1.getAC()<<endl;

    B obj2(1,2,3,4,5,6);
    cout<<"B: "<<obj2.ba<<" "<<obj2.getBB()<<" "<<obj2.getBC()<<" "<<obj2.aa<<" "<<obj2.getAB()<<" "<<obj2.getAC()<<endl;
    obj2.testB();
    cout<<"B: "<<obj2.ba<<" "<<obj2.getBB()<<" "<<obj2.getBC()<<" "<<obj2.aa<<" "<<obj2.getAB()<<" "<<obj2.getAC()<<endl;

    C obj3(1,2,3,4,5,6,7,8,9);
    cout<<"C: "<<obj3.ca<<" "<<obj3.getCB()<<" "<<obj3.getCC()<<" "<<obj3.getBA()<<" "<<obj3.getBB()<<" "<<obj3.getBC_fromB()<<" "<<obj3.getAA()<<" "<<obj3.getAB()<<" "<<obj3.getAC_fromB()<<endl;
    obj3.testC();
    cout<<"C: "<<obj3.ca<<" "<<obj3.getCB()<<" "<<obj3.getCC()<<" "<<obj3.getBA()<<" "<<obj3.getBB()<<" "<<obj3.getBC_fromB()<<" "<<obj3.getAA()<<" "<<obj3.getAB()<<" "<<obj3.getAC_fromB()<<endl;

    return 0;
}



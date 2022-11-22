#include <iostream>

using namespace std;
class Helper{
private:
    static Helper *instance;
    int x,y;

    Helper(){
        x=3;
        y=5;
    }

public:
   static Helper *getInstance(){
       if(!instance)
          instance=new Helper;
       return instance;
   }

   void setX(int val){
       x=val;
   }

   void setY(int val){
       y=val;
   }

   int sum(){
        return x+y;
   }

   int diff(){
        return x-y;
   }
};
Helper *Helper::instance = 0;
int main()
{

    Helper *s=s->getInstance();
    cout<<"suma="<<s->sum()<<endl;
    cout<<"diff="<<s->diff()<<endl;
    s->setX(100);
    s->setY(40);
   cout<<"suma="<<s->sum()<<endl;
    cout<<"diff="<<s->diff()<<endl;
    //toate urmatoarele instante vor fi la fel:
    Helper *b=b->getInstance();
     cout<<"suma="<<b->sum()<<endl;
    cout<<"diff="<<b->diff()<<endl;
    return 0;
}

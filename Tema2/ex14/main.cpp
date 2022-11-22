#include <iostream>

using namespace std;

float computeX(int a, int b){
    if(a == 0)
        throw 1;
    float ans = (float)-b/(float)a;
    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"x="<<computeX(a,b);
    return 0;
}

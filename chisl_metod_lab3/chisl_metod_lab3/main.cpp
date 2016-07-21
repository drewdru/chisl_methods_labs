#include <math.h>
#include <iostream>

#define pi 3.14
using namespace std;

double f(double x) {

    return   (x)*(x);
}

double f1(double x) {

    return  x+-0.35*f(x);
}

int main() {
    int n=0;
    double a,b,x,eps;
    cout<<"a="; cin>>a;
    cout<<"b="; cin>>b;
    cout<<"eps="; cin>>eps;
    /*if(f(a)*f2(a)>0) c=a;
    else c=b;*/
    //cout<<"x0="; cin>>x;
    if(a>b)
    {
        double temp = a;
        a=b;
        b=temp;
    }
    x=a;
    do {
        x=x-f(x)/f1(x);
        n+=1;
    }
    while ((fabs(f(x))>=eps)&&(f(x)!=0)&&(x<=b));
        cout<<"c="<<x<<"\n";
        cout<<"n="<<n<<"\n";

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class NewtonRaphson{
    private:
    double x, a, b, toll, next;
    double func(double x){
        return x*x*x-2*x-5;
    }
    double derfunc(double x){
        return 3*x*x-2;
    }
    void randGent(){
        srand(time(0));
        do{
            a = (rand()%200-100)/10.0;
            b = (rand()%200-100)/10.0;
            
        }while(func(a)*func(b)>=0);
        if(func(a)>func(b))
            swap(a,b);
        if(abs(func(a)-0)<abs(func(b)-0))
        x = a;
        else
        x = b;
        // x = (a+b)/2;
    }
public:
    NewtonRaphson(double x, double tollar){
        this->toll = tollar;
        this->x = x;
        randGent();
    }
        double roots(){
            next = x - func(x)/derfunc(x);
            while(abs(func(next)>toll)){
                x = next;
                next = x - func(x)/derfunc(x);
            }
            return next;
        }
};

int main(){
    
    NewtonRaphson ne(0, 0.001);
    cout<<ne.roots()<<endl;

}
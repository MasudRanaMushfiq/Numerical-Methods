#include<bits/stdc++.h>
using namespace std;

class Secant{
private:
    double x,next,tol,a,b;
    double f(double x){
        return x*x*x-2*x-5;
        // return x*sin(x)+cos(x);
    }
    double fp(double x){
        // return x*cos(x); 
        return 3*x*x-2;
    }
    void genRandom(){
        srand(time(0));
        do{
            a = (rand()%100-50)/10.0;
            b = (rand()%100-50)/10.0;

        }
        while(f(a)*f(b)>=0);
        if(f(a)>f(b))swap(a,b); 
        
    } 
public:
    Secant(double x, double tol){
        // this->x = x;
        this->tol = tol;
        genRandom();
        cout<<a<<"  "<<b<<endl;
        cout<<f(a)<<" "<<f(b)<<endl;
    }
    double root(){
        double fx = (b-a)/(f(b)-f(a));
        next = b-fx*f(b);
        while(abs(f(next))>tol){
            a = b;
            b = next;
            fx = (b-a)/(f(b)-f(a));
            next = b-fx*f(b);
            
        }
        return next;
    }
};

int main(){
    // Secant naughty = Secant(3.1416,0.001);
    Secant naughty = Secant(0,0.001);  //2.09

    cout<<naughty.root();
}

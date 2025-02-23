#include<bits/stdc++.h>
using namespace std;

class Newton{
private:
    double x, next, tol, a, b;
    double f(double x){
        return x*x*x-2*x-5;
    }
    double fp(double x){
        return 3*x*x-2;
    }
    void genRandom(){
        srand((time(0)));
        do{
            a = (rand()%100-50)/10.0;
            b = (rand()%100-50)/10.0;
        }
        while(f(a)*f(b)>=0);
        if(f(a)>f(b))swap(a,b);
        
        if(abs(f(a)-0)<abs(f(b)-0))
            x = a;
        else
            x = b;
    }
public:
    Newton(double x, double tol){
        this->x = x;
        this->tol = tol;
        genRandom();
    }
    double root(){
        next = x-(f(x)/fp(x));
        while(abs(f(next))>tol){
            x = next;
            next = x-(f(x)/fp(x));
        }
        return next;
    }
};

int main(){
    Newton naughty = Newton(0,0.001);
    cout<<naughty.root();
}

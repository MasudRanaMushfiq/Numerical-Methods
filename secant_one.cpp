#include<bits/stdc++.h>
using namespace std;

class Secant{
    private:
    double a, b, next, tol;
    double f(double x){
        return x*x*x-2*x-5;
    }
    void randGen(){
        srand(time(0));
        do{
            a = (rand()%100-50)/10.0;
            b = (rand()%100-50)/10.0;
        }while(f(a)*f(b)>=0);
        if(f(a)>f(b))
            swap(a,b);
    }
    public:
    Secant(double toll){
        this->tol = toll;
        randGen();
        cout<<a<<" "<<b<<endl;
        cout<<f(a)<<" "<<f(b)<<endl;
    }
    double roots(){
        double fx = (b-a)/(f(b)-f(a));
            next = b - fx*f(b);
        while(abs(f(next)>tol)){
                a = b;
                b = next;
                fx = (b-a)/(f(b)-f(a));
                next = b - fx*f(b);
        }
        return next;
    }
};

int main(){
    Secant sec(0.001);
    cout<<"Root is : "<<sec.roots()<<endl;
}
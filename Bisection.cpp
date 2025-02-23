#include<bits/stdc++.h>
using namespace std;

class Bisection{
private: 
    double x,y,tol;
    double f(double x){
        return x*x*x+x*x+x+7;
    }
    void genRandom(){
        srand(time(0));
        do{
            x = (rand()%200-100)/10.0;
            y = (rand()%200-100)/10.0;
        }
        while(f(x)*f(y)>=0);
        if(f(x)>f(y))swap(x,y);
    }

public:
    Bisection(double tol){
        this->tol = tol;
        genRandom();
        cout<<x<<" "<<y<<endl;
        cout<<f(x)<<" "<<f(y)<<endl;
    }
    double root(){
        double mid = (x+y)/2;
        while(abs(f(mid))>tol){
            if(f(mid)<0)
                x = mid;
            else
                y = mid;
            mid = (x+y)/2;
        }
        return mid;
    }
};

int main(){
    Bisection bc = Bisection(0.001);
    cout<<bc.root()<<endl;
}





















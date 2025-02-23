#include<bits/stdc++.h>
using namespace std;

class FalsePosition{
private:
    double x, y, tol;
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
    FalsePosition(double tol){
        this->tol = tol;
        genRandom();
    }
    double root(){
        double next,u,d;
        do{
            u = x*f(y)-y*f(x);
            d = f(y)-f(x);
            next = (u/d);
            if(f(next)<0)
                x = next;
            else
                y = next;
        }while(abs(f(next))>tol);
        return next;
    }
};

int main(){
    FalsePosition fp = FalsePosition(0.001);
    cout<<fp.root()<<endl;
}









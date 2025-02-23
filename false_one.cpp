#include <bits/stdc++.h>
using namespace std;

class FalsePosition{

    private:
    double x, y, tolle;
    double func(double x){
        return x*x*x + x*x + x + 7;
    }
    void randGen(){
        srand(time(0));
        do{
        x = (rand()%200 - 100)/10.0;
        y = (rand()%200 - 100)/10.0;
        if(func(x)>func(y))
            swap(x,y);
    }while(func(x)*func(y)>=0);
    }

    public:
    FalsePosition(double toll){
        this->tolle = toll;
        randGen();
        cout<<x<<" "<<y<<endl;
        cout<<func(x)<<" "<<func(y)<<endl;
    }

    double roots(){
        double one, two , h;

        do{
        one = x*func(y)-y*func(x);        
        two = func(y)-func(x);
        h = one / two;
            if(func(h)<0)
             x = h;
            else
             y = h;
        }while(func(h)>tolle);
        return h;
    }

};

int main(){
    FalsePosition fals(0.001);
    cout<<"Root is "<<fals.roots()<<endl;
}
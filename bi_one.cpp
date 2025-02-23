#include<bits/stdc++.h>
using namespace std;

class Bisection{
    private: 
    double a, b, toll;
    double f(double x){
        return x*x*x + x*x + x + 7;
    }

    void randomGen(){
            srand(time(0));
            do{
                a = (rand()%200-100)/10.0;
                b = (rand()%200-100)/10.0;
                if(f(a)>f(b)){
                    swap(a,b);
                }
            }while(f(a)*f(b)>=0);
        }

public:
        Bisection(double tol){
            this->toll = tol;
            randomGen();
        cout<<a<<" "<<b<<endl;
        cout<<f(a)<<" "<<f(b)<<endl;
        }
            
            double findRoot(){
                double mid = (a + b)/2;
                while(abs(f(mid)) > toll){
                    if(f(mid)<0){
                        a = mid;
                    }else{
                        b = mid;
                    }
                    mid = (a+b)/2;
                }
                return mid;
    }
};

int main(){

    Bisection bisec(0.001);
    cout<<"Root is: "<<bisec.findRoot()<<endl;

}
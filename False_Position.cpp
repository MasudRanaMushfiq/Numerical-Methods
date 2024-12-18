#include<bits/stdc++.h>
using namespace std;

class FalsePosition{
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
            if(f(next)<0)x= next;
            else y = next;
            
        }while(abs(f(next))>tol);
        return next;
    }
};

int main(){
    FalsePosition fp = FalsePosition(0.001);
    cout<<fp.root()<<endl;
}








// class falsePos{
// private:
//     double l,r,tol;
//     void genVal(){
//         srand(static_cast<double>(time(0)));
//         do{
//             l = (rand()%200-100)/10.0;
//             r = (rand()%200-100)/10.0;
//         }
//         while(f(l)*f(r)>=0);
//         if(f(l)>f(r))swap(l,r);
//     }
//     double f(double x){
//         return x*x*x-2*x-5;
//     }
//     double next(){
//         double u =l*f(r)- r*f(l);
//         double d = f(r)-f(l);
//         return u/d;
//     }
// public:
//     falsePos(double tol){
//         this->tol = tol;
//         // l = 2;
//         // r = 3;
//         genVal();
//     }
//     double root(){
//         double nxt = next();
//         int i =100;
//         while(abs(f(nxt))>tol){

//             // cout<<nxt<<" ";
//             if(f(nxt)>0)r = nxt;
//             else l = nxt;
//             nxt = next();
//         }
//         return nxt;
//     }
// };

// int main(){
//     falsePos fp = falsePos(0.0001);
//     cout<<fp.root();
// }
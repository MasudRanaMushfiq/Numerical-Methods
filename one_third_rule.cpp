#include<bits/stdc++.h>
using namespace std;
//typedef ...
#define ll long long
#define endl        '\n'
#define en          '\n';
class Simption{
private:
    double a,b,n;
    double function(double x){
        return 1/(1+x);
    }
public:
Simption(double a,double b,double n){
    this->a=a;
    this->b=b;
    this->n=n;
}
// formula = h/3((y0+yn) +( 4*∑yi for all even)+ (2*∑yi for all odd))
double integral(){
    double h = (b-a)/n;
    double sum = function(a) + function(b);
    for(int i=1;i<n;i++){
        double x = a + i*h;
        if(i%2==0)
        sum += 2*function(x);
        else
        sum+= 4*function(x);
    }
    return sum * h/3;
}
};
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Simption tz = Simption(0,1,8);
    cout<<tz.integral()<<endl;

    return 0;
}

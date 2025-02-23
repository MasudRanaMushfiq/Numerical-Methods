#include<bits/stdc++.h>
using namespace std;

class Lagra{
    private:
    vector<double> x, y;
    double ans = 0.0;
    public: 
    Lagra(vector<double> x, vector<double> y){
        this->x = x;
        this->y = y;
    };
    double root(double tar){
        double n = x.size();
        for(int i = 0; i<n; i++){
            double mult = y[i];
            for(int j = 0; j<n; j++){
                if(x[j]!=x[i]){
                    mult *= (tar - x[j])/(x[i]-x[j]);
                }
            }
            ans = ans + mult;
        }
        return ans;
    }
};

int main(){
    vector<double>x = {4,12,19};
    vector<double>y = {1,3,4};
    Lagra lg = Lagra(x,y);
    cout<<lg.root(21)<<endl; //38.14
}

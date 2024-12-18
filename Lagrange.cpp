#include<bits/stdc++.h>
using namespace std;

class Lagrage{
private:
    vector<double>x,y;
    double ans =0.0;
public:
    Lagrage(vector<double>x,vector<double>y){
        this->x = x;
        this->y = y;
    }
    double root(double tar){
        int n = x.size();
        for(int i=0;i<n;i++){
            // if(x[i]==tar)continue;
            double mul = y[i];
            for(int j=0;j<n;j++){
                if(x[j]!=x[i]){
                    mul*=(tar-x[j])/(x[i]-x[j]);
                }
                
            }
            ans+=mul;
        }
        return ans;
    }
};
int main(){
    // vector<double>x = {5,6,9,11};
    // vector<double>y = {12,13,14,16};
    // Lagrage lg = Lagrage(x,y);
    // cout<<lg.root(10)<<endl;  //root = 14.667
    // vector<double>x = {0,1,3,8};
    // vector<double>y = {1,3,13,123};
    // Lagrage lg = Lagrage(x,y);
    // cout<<lg.root(5)<<endl; //38.14
    vector<double>x = {4,12,19};
    vector<double>y = {1,3,4};
    Lagrage lg = Lagrage(x,y);
    cout<<lg.root(7)<<endl; //38.14
}   

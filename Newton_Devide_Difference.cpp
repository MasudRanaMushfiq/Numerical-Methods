#include<bits/stdc++.h>
using   namespace std;

class NewtonDevideDifference{
private: 
    vector<double>x,y;
    int n;
    vector<vector<double>>a;
public:
    NewtonDevideDifference(vector<double>x,vector<double>y){
        this->x = x;
        this->y = y;
        makeTable();
    }
    void makeTable(){
        n = x.size();
        a.resize(n,vector<double>(n,0.0));
        for(int i=0;i<n;i++)
        a[i][0]= y[i];
        for(int j=1;j<n;j++){
            for(int i=0;i<n-j;i++){
                a[i][j] = (a[i+1][j-1]-a[i][j-1])/(x[i+j]-x[i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++)
            cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    double root(double xx){
        double ans = a[0][0];
        double p = (xx-x[0])/(x[1]-x[0]);
        for(int i=1;i<n;i++){
            double mul =1;
            double val = a[0][i];
            for(int j=0;j<i;j++){
                mul*=(xx-x[j]);
            }
            ans+=val*mul;
        }
        return ans;
    }
};


int main(){

    vector<double>x = {300,304,305,307};
    vector<double>y = {2.4771,2.4829,2.4843,2.4871};
    NewtonDevideDifference np = NewtonDevideDifference(x,y);
    cout<<"root: "<<np.root(301)<<endl;
    
}
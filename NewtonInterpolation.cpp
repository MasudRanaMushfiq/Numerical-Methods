#include<bits/stdc++.h>
using   namespace std;

class NewtonInterpolation{
private: 
    vector<double>x,y;
    int n;
    vector<vector<double>>a;
public:
    NewtonInterpolation(vector<double>x,vector<double>y){
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
                a[i][j] = a[i+1][j-1]-a[i][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++)
            cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    double forwordRoot(double xx){
        double ans = a[0][0];
        double p = (xx-x[0])/(x[1]-x[0]);
        for(int i=1;i<n;i++){
            double mul =1;
            double val = a[0][i];
            for(int j=0;j<i;j++){
                mul*=(p-j)/(j+1);
            }
            ans+=val*mul;
        }
        return ans;
    }
    double backwordRoot(double xx){
        double ans = y[n-1];
        double p = (xx-x[n-1])/(x[1]-x[0]);
        for(int i=1;i<n;i++){
            double mul =1;
            double val = a[n-i-1][i];
            for(int j=0;j<i;j++){
                mul*=(p+j)/(j+1);
            }
            ans+=val*mul;
        }
        return ans;
    }
};


int main(){
    vector<double>x = {1891,1901,1911,1921,1931};
    vector<double>y = {46,66,81,93,101};
    NewtonInterpolation np = NewtonInterpolation(x,y);
    cout<<np.forwordRoot(1920)<<endl;
    cout<<np.backwordRoot(1895)<<endl;
}
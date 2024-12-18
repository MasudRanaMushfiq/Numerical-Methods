#include<bits/stdc++.h>
using namespace std;

class newtonInterpolation{
private:
    vector<double>x,y;
    vector<vector<double>>tab;
    int n;
    void createTable(){
        tab.resize(n,vector<double>(n,0.0));
        for(int i=0;i<n;i++)tab[i][0] = y[i];
        for(int j=1;j<n;j++){
            for(int i=0;i<n-j;i++){
                tab[i][j] = tab[i+1][j-1]-tab[i][j-1];
            }
        }
    }
    double calProduct(double u,int order){
        double p = 1;
        for(int i=0;i<order;i++){
            p*=(u-i)/(i+1);
        }
        return p;
    }
public:
    newtonInterpolation(vector<double>xval,vector<double>yval){
        x = xval;
        y = yval;
        n = x.size();
        createTable();
    }

    double forwardInterPol(double val){
        double ans = y[0];
        double h = x[1]-x[0];
        double p = (val-x[0])/h;
        for(int i=1;i<n;i++){
            double v=calProduct(p,i)*tab[0][i];
            // cout<<v<<" ";
            ans+=v;
        }
        return ans;
    }
    double backwardInterPol(double val){
        double ans = y[n-1];
        double h = x[1]-x[0];
        double p = (val-x[n-1])/h;
        for(int i=1;i<n;i++){
            double pd = 1;
            for(int j=0;j<i;j++){
                pd*=(p+j)/(j+1);
            }
            
            double v=pd*tab[n-1-i][i];
            // cout<<v<<" ";
            ans+=v;
        }
        return ans;
    }
};

int main(){
    // vector<double>x = {0,1,2,3}; val = 4 ans = 33
    // vector<double>y = {1,0,1,10};
    vector<double>x = {1891,1901,1911,1921,1931};
    vector<double>y = {46,66,81,93,101};
    newtonInterpolation ni= newtonInterpolation(x,y);
    cout<<ni.forwardInterPol(1895)<<endl;
    cout<<ni.backwardInterPol(1895);
}
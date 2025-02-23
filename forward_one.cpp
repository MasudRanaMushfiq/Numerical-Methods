#include<bits/stdc++.h>
using namespace std;

class Forward{
    private:
    vector<double> x, y;
    double n;
    vector<vector<double>> tab;
public:
    Forward(vector<double>x, vector<double>y){
        this->x = x;
        this->y = y;
        n = x.size();
        tab.resize(n,vector<double>(n, 0.0));
        makeTable();
    }
    void makeTable(){
        for(int i = 0; i<n; i++){
            tab[i][0] = y[i];
        }
        for(int j=1; j<n; j++){
            for(int i = 0; i<n-j; i++){
                tab[i][j] = tab[i+1][j-1] - tab[i][j-1];
            }
        }
        for(int j=0; j<n; j++){
            for(int i = 0; i<n-j; i++)
            cout<<tab[j][i]<<" ";
            cout<<endl;
        }
    }
        double forword(double xx){
        double ans = tab[0][0];
        double p = (xx-x[0])/(x[1]-x[0]);
        for(int i=1;i<n;i++){
            double mul =1;
            double val = tab[0][i];
            for(int j=0;j<i;j++){
                mul*=(p-j)/(j+1);
            }
            ans+=val*mul;
        }
        return ans;
        }
        double backward(double give){
            double ans = y[n-1];
            double p = (give-x[n-1])/(x[1]-x[0]);
            for(int i = 1; i<n; i++){
                double multi = 1;
                for(int j = 0; j<i; j++){
                    multi *= (p+j)/(j+1);
                }
                double valu = tab[n-i-1][i];
                ans += multi * valu;
            }
            return ans;
        }



};

int main(){
    vector<double> x = {1891,1901,1911,1921,1931};
    vector<double> y = {46,66,81,93,101};
    Forward ford = Forward(x,y);
    cout<<ford.forword(1895)<<endl;
    cout<<ford.backward(1895)<<endl;
}
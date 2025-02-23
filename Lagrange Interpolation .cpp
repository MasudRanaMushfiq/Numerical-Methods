#include <bits/stdc++.h>
using namespace std;

class Lagrange {
public:

    void solve(){
        double x[100], y[100], xp, yp = 0.0, p;

        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin >> x[i];
            cin >> y[i];
        }

        cin>>xp;
        for(int i=0; i<n; i++){
            p = 1;
            for(int j=0; j<n; j++){
                if(j != i){
                    p = p * (xp - x[j])/(x[i] - x[j]);
                }
            
            }
            yp += (y[i]*p);
        }
        cout<<yp<<endl;
    }
};

int main(){

    Lagrange lagrange;
    lagrange.solve();

    return 0;
}

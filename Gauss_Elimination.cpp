#include <bits/stdc++.h>
using namespace std;

class GaussElimination {
    public:
    void solve() {
        int n;
        cin >> n;

        double a[100][101];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n+1; j++) {
                cin >> a[i][j];
            } 
        }

        for(int i = 0; i < n-1; i++) {

            if(a[i][i] == 0) {
                cout << "Invalid" << endl;
                return;
            }

            for(int j = i+1; j < n; j++) {
                double ratio = a[j][i] / a[i][i];
                for(int k = 0; k < n+1; k++) {
                    a[j][k] -= (ratio*a[i][k]);
                }
            }
        }
        double x[100];

        x[n-1] = a[n-1][n] / a[n-1][n-1];

        for(int i = n-2; i >= 0; i--) {
            x[i] = a[i][n];
            for(int j = i+1; j < n; j++) {
                x[i] -= (a[i][j] * x[j]);
            }
            x[i] = x[i] / a[i][i];
        }
        for(int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }

};

int main() {

    GaussElimination ge;
    ge.solve();
}

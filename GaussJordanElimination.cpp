#include <bits/stdc++.h>
using namespace std;

class GaussJordan {
    public:
        int n;
        double a[10][10], x[10];

        GaussJordan() {
            cin >> n;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= n; j++) {
                    cin >> a[i][j];
                }
            }
        }
        void solve() {
            for(int i = 0; i < n; i++) {
                if(a[i][i] == 0.0) {
                    cout << "Error !" << endl;
                    cout << "The problem has infinite solutions" << endl;
                }

                for(int j = 0; j < n; j++) {
                    if(i != j) {
                        double r = a[j][i] / a[i][i];
                        for(int k = 0; k <= n; k++) {
                            a[j][k] -= (a[i][k] * r);
                        }
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= n; j++) {
                    cout << a[i][j] << " ";
                } cout << endl;
            }

            for(int i = 0; i < n; i++)
                x[i] = a[i][n] / a[i][i];

            cout << endl << endl;
            for(int i = 0; i < n; i++) {
                cout << "x[" << i+1 << "] = " << x[i] << endl;
            }
        }

};

int main() {

    GaussJordan gj;
    gj.solve();
    return 0;
}

// 3
// 1 1 -1 7
// 1 -1 2 3
// 2 1 1 9

// x[1] = 6
// x[2] = -1
// x[3] = -1

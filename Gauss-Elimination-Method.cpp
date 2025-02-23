#include <bits/stdc++.h>
using namespace std;

class GaussElimination {
public:
    int n;
    double augmented_matrix[10][10], x[10];

    GaussElimination() {
        cin>>n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                cin>>augmented_matrix[i][j];
            }
        }
    }

    void solve() {
        // Gauss Elimination Formmula
        for(int i = 0; i < n - 1; i++) {
            if(augmented_matrix[i][i] == 0.0) {
                cout<<"Can't be solved using Gauss Elimination Method\n";
                exit(0);
            }
            for(int j = i + 1; j < n; j++) {
                double ratio = augmented_matrix[j][i] / augmented_matrix[i][i];
                for(int k = 0; k <= n; k++) {
                    augmented_matrix[j][k] -= augmented_matrix[i][k] * ratio;
                }
            }
        }
        // Back Substitution
        x[n-1] = augmented_matrix[n-1][n] / augmented_matrix[n-1][n-1];
        for(int i = n - 2; i >= 0; i--) {
            x[i] = augmented_matrix[i][n];
            for(int j = i + 1; j < n; j++) {
                x[i] -= augmented_matrix[i][j] * x[j];
            }
            x[i] = x[i] / augmented_matrix[i][i];
        }
        // Display the values of x
        for(int i = 0; i < n; i++) {
            cout<<"x"<<i<<" = "<<x[i];
            cout<<"\n";
        }
    }
};

int main(){
    GaussElimination g = GaussElimination();
    g.solve();
}

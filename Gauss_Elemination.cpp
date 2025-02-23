#include <bits/stdc++.h>
using namespace std;

class GaussElimination {
private:
    int n;
    double** matrix;

public:
    GaussElimination(int n) {
        this->n = n;
        matrix = new double*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new double[n + 1];
        }
    }

    void inputMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void printMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void eliminate(){
        for(int i=0;i<n;i++){ //for every column
            for(int j=i+1;j<n;j++){     //for every row
                double c = -matrix[j][i]/matrix[i][i];
                for(int k=i;k<=n;k++)   //for every element in a row
                    matrix[j][k] += c*matrix[i][k] ;
            }
        }
    }

    void solve() {
        double* x = new double[n];
        for (int i = n - 1; i >= 0; i--) {
            x[i] = matrix[i][n] / matrix[i][i];
            for(int j=i-1;j>=0;j--)
            matrix[j][n]-=x[i]*matrix[j][i];
           
        }

        cout << "Solution: ";
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;

    }

    
};

int main() {
    int n;
    cin >> n;
    /*
    n = 3
    2 1 1 10
    3 2 3 18
    1 4 9 16    x= 7,-9,5
    */

    GaussElimination ge(n);
    cout << "Input Matrix: " << endl;
    ge.printMatrix();
    cout << "After Elimination: " << endl;
    ge.printMatrix();
    ge.solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Least_Square_Curve_Fitting {
  public:
    void solve() {
        cout << "Enter number of data pairs: ";
        int n;
        cin >> n;
        double x[n], y[n];
        cout << "\nEnter the Data pairs-\n" << endl;

        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        cout << endl << endl;

        double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;

        for(int i = 0; i < n; i++) {
            sum_x += x[i];
            sum_y += y[i];

            sum_xx += (x[i]*x[i]);
            sum_xy += (x[i]*y[i]);
        }

        double b = (sum_xy - (sum_x*sum_y)/n) / (sum_xx - ((sum_x*sum_x) / n));
        double a = (sum_y / n) - b*(sum_x / n);

        cout << "a = " << a << "    " << "b = " << b << endl;

        cout << "\nEquation is : " << a << " + " << b  << "x" << endl;
    }
};

int main(){

    Least_Square_Curve_Fitting lscf;

    lscf.solve();

    return 0;
}

/*
4
50 12
70 15
100 21
120 25

a = 2.27586
b = 0.187931
*/

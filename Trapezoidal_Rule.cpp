#include <bits/stdc++.h>

using namespace std;

class Trapezoidal {

    public:

    // double function(double x) {
    //     return (1 / (1 + pow(x, 2)));
    // }

    double function(double x) {
        return (sqrt(x*x + 1));
    }
    
    double a, b, n, h;

    Trapezoidal() {

        cout << "Enter lower limit: ";
        cin >> a;
        cout << "Enter upper limit: ";
        cin >> b;

        cout << "Enter sub-interval: ";
        cin >> n;
    }

    void solve() {

    // step size
    h = (b-a) / n;

    // integrated value
    double i_val = function(a);
    for(int i = 1; i < n; i++) {
        double x = a + i*h;
        i_val += 2*function(x);
    }

    i_val += function(b);

    i_val = (i_val * h) / 2;

    cout<< endl << "Required value of integration is: " << i_val;

    }
        
};

int main() {

    Trapezoidal trapezoidal;
    trapezoidal.solve();

    return 0;

}

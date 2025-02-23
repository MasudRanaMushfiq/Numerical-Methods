#include <bits/stdc++.h>

using namespace std;

class Simpson {

    public:

    double a, b, n, h;

    Simpson() {

        cout << "Enter lower limit: ";
        cin >> a;
        cout << "Enter upper limit: ";
        cin >> b;
        cout << "Enter value of n: ";
        cin >> n; 
    }

    // double function(double x) {
    //     return (1 / (1 + pow(x, 2)));
    // }
    // double function(double x) {
    //     return (1 / (1 + x));
    // }
    double function(double x) {
        return (sqrt(x*x + 1));
    }

    void solve() {

        h = (b-a) / n;

        double i_val = function(a);

        for(int i = 1; i < n; i++) {
            double x = a + i*h;
            if(i % 2 == 0) {
                i_val += 2*function(x);
            } else {
                i_val += 4*function(x);
            }
        }

        i_val += function(b);

        i_val = (i_val * h) / 3;

        cout<< endl << "Required value of integration is: " << i_val << endl << endl;

    }
        
};

int main() {

    Simpson simpson;
    simpson.solve();

    return 0;

}

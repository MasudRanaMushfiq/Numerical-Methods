#include <bits/stdc++.h>
using namespace std;

class LagIntp {
    vector<double> x;
    vector<double> y;

public:
    LagIntp(const vector<double>& xPoints, const vector<double>& yPoints)
        : x(xPoints), y(yPoints) {}

    double interpolate(double xi) const {
        int n = x.size();
        double result = 0.0;

        for(int i = 0; i < n; i++){
            double term = y[i];
            for(int j = 0; j < n; j++) {
                if(j != i){
                    term *= (xi - x[j]) / (x[i] - x[j]);
                }
            }
            result += term;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }

    LagIntp intrpltr(x, y);

    double xi;
    cin >> xi;

    double yi = intrpltr.interpolate(xi);
    cout << "in " << xi << " y is = " << yi << endl;

    return 0;
}

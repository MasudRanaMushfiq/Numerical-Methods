#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class NewtonForward {
private:
    vector<double> x;
    vector<double> y;
    vector<vector<double>> differenceTable;
    int n;

public:
    void setSize(int size) {
        n = size;
        x.resize(n);
        y.resize(n);
        differenceTable.resize(n, vector<double>(n, 0));
    }


    void inputPoints() {
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            differenceTable[i][0] = y[i];
        }
    }

    void calculateDifferenceTable() {
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < n - j; ++i) {
                differenceTable[i][j] = differenceTable[i + 1][j - 1] - differenceTable[i][j - 1];
            }
        }
    }

    void displayDifferenceTable() {
        cout << "\nForward Difference Table:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << setw(4) << x[i];
            for (int j = 0; j < n - i; ++j) {
                cout << setw(4) << differenceTable[i][j];
            }
            cout << endl;
        }
    }
    double factorial(int num) {
        double fact = 1;
        for (int i = 1; i <= num; ++i) {
            fact *= i;
        }
        return fact;
    }

    double interpolate(double value) {
        double h = x[1] - x[0];
        double p = (value - x[0]) / h;
        double result = y[0];

        double p_term = 1.0;
        for (int i = 1; i < n; ++i) {
            p_term *= (p - (i - 1));
            result += (p_term * differenceTable[0][i]) / factorial(i);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    NewtonForward interpolator;

    interpolator.setSize(n);

    interpolator.inputPoints();
    interpolator.calculateDifferenceTable();
    interpolator.displayDifferenceTable();

    double value;
    cin >> value;

    double result = interpolator.interpolate(value);
    cout << "\nInterpolated value at x = " << value << " is " << result << endl;

    return 0;
}

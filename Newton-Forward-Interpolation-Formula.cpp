#include <bits/stdc++.h>
using namespace std;

class ForwardInterpolation
{
public:
    int n;
    double x[10], y[10][10];
    double ans = 0, given_x;

    ForwardInterpolation()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i][0];
        }
        cin >> given_x;
    }
    double factorial(int i)
    {
        if (i)
        {
            return i * factorial(i - 1);
        }
        else
        {
            return 1;
        }
    }
    double multiply(double p, int i)
    {
        double value = p;
        for (int j = 1; j < i; j++)
        {
            value = value * (p - j);
        }
        return value;
    }
    void solve()
    {
        for (int col = 1; col < n; col++)
        {
            for (int row = 0; row < n - col; row++)
            {
                y[row][col] = y[row + 1][col - 1] - y[row][col - 1];
            }
        }
        ans = y[0][0];
        double h = x[1] - x[0];
        double p = (given_x - x[0]) / h;
        for (int i = 1; i < n; i++)
        {
            ans = ans + (multiply(p, i) * y[0][i]) / factorial(i);
        }
        cout << "The value of " << given_x << " is " << ans << endl;
    }
};

int main()
{
    ForwardInterpolation f = ForwardInterpolation();
    f.solve();
    return 0;
}

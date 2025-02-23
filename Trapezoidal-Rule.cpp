#include <bits/stdc++.h>
using namespace std;

class Trapezoidal
{
public:
    int n;
    double x[10], y[10];
    double ans = 0, h, y0, yn;
    Trapezoidal()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        y0 = y[0];
        yn = y[n - 1];
        h = x[1] - x[0];
    }

    void solve()
    {
        ans = y0 + yn;
        for (int i = 1; i < n - 1; i++)
        {
            ans = ans + 2 * y[i];
        }
        ans = (ans * h) / 2;
        cout << "answer = " << ans << endl;
    }
};

int main()
{
    Trapezoidal t = Trapezoidal();
    t.solve();
    return 0;
}

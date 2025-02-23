#include <bits/stdc++.h>
using namespace std;

class SimpsonRule
{
public:
    int n;
    double ans = 0, y0, yn, h;
    double x[10], y[10];
    SimpsonRule()
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
            if (i % 2 == 1)
            {
                ans = ans + 4 * y[i];
            }
            else
            {
                ans = ans + 2 * y[i];
            }
        }
        ans = (ans * h) / 3;
        cout << "Answer = " << ans << endl;
    }
};

int main()
{
    SimpsonRule s = SimpsonRule();
    s.solve();
    return 0;
}

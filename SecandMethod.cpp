#include <bits/stdc++.h>
using namespace std;

class Secant
{
private:
    const double tolerence = 0.0001;

    double functional_value(double x)
    {
        return pow(x, 3) + pow(x, 2) - 1;
    }
    double secant(double a, double b)
    {
        return (b * functional_value(a) - a * functional_value(b)) / (functional_value(a) - functional_value(b));
    }

public:
    double a, b;
    void solve()
    {
        srand(time(0));
        int i = 0;
        while (1)
        {
            a = rand() % 10 - 9;
            b = rand() % 10;
            if (functional_value(a) * functional_value(b) < 0)
            {
                break;
            }
        }

        double root = secant(a, b);
        while (1)
        {
            printf("a = %10f   b = %10f     root = %9f\n", a, b, root);
            if (functional_value(root) == 0.0)
            {
                break;
            }
            if (abs(root - secant(root, a)) < tolerence)
            {
                break;
            }
            b = a;
            a = root;
            root = secant(a, b);
        }

        root = secant(root, a);
        printf("a = %10f   b = %10f     root = %9f\n", a, b, root);
        cout << "\nThe root is " << root << " (correct upto 3 decimal palces)\n";
    }
};

int main(void)
{
    Secant n = Secant();
    n.solve();
}

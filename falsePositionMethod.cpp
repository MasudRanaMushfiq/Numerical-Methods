#include <bits/stdc++.h>
using namespace std;

class FalsePositionMethod
{
private:
    float posi, neg, e;

    float function(float x)
    {
        return pow(x, 3) - 2 * x - 5;
    }

    void generateRandomValues()
    {
        srand(time(0));
        do
        {
            posi = static_cast<float>(rand()) / RAND_MAX * 20 - 10;
            neg = static_cast<float>(rand()) / RAND_MAX * 20 - 10;
        } while (function(posi) * function(neg) > 0);
        if (function(posi) < 0)
            swap(posi, neg);
        cout << "Positive: " << posi << ", Negative: " << neg << endl;
    }

public:
    FalsePositionMethod(float e) : e(e)
    {
        generateRandomValues();
    }

    float findRoot()
    {
        float x, f1;
        int i = 1;
        do
        {
            x = (posi * function(neg) - neg * function(posi)) / (function(neg) - function(posi));
            f1 = function(x);
            if (f1 == 0)
                break;
            else if (f1 * function(posi) < 0)
                neg = x;
            else
                posi = x;
            cout << i++ << ". iteration: " << x << endl;

        } while (abs(f1) > e);
        return x;
    }
};

int main()
{
    float e;
    cin >> e;

    FalsePositionMethod falsePosition(e);
    float root = falsePosition.findRoot();
    cout << "The root is: " << root << endl;

    return 0;
}

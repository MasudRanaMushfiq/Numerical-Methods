#include <bits/stdc++.h>
using namespace std;

class BisectionMethod
{
private:
    float left, right, toll;

    float function(float x){
        return pow(x, 3) - 2 * x - 5;
    }

    void generateRandomValues(){
        srand(time(0));
        do{
            left = static_cast<float>(rand()) / RAND_MAX * 20 - 10;
            right = static_cast<float>(rand()) / RAND_MAX * 20 - 10;
        } while (function(left) * function(right) >= 0);
        if (function(left) < 0)
            swap(left, right);

        cout << "Positive: " << left << ", Negative: " << right << endl;
    }

public:
    BisectionMethod(float e) : toll(e)
    {
        generateRandomValues();
    }  

    float findRoot(){
        float x, f1;
        int i = 1;
        do
        {
            x = (left + right) / 2;
            f1 = function(x);
            if (f1 > 0)
                left = x;
            else
                right = x;
            cout << i++ << ". iteration: " << x << endl;
        } while (abs(f1) > toll);
        return x;
    }
};

int main()
{
    float e;
    cin>>e;

    BisectionMethod bisection(e);
    float root = bisection.findRoot();
    cout << "The root is: " << root << endl;

    return 0;
}

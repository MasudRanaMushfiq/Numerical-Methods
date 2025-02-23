#include <bits/stdc++.h>
using namespace std;

class NewtonRaphsonMethod{
    float value, toll;

    float function(float x){
        return pow(x, 3) - 2 * x - 5;
    }

    float functionDerivative(float x){
        return 3 * pow(x, 2) - 2;
    }

    void generateRandomValues(){
        srand(static_cast<unsigned>(time(0)));
        value = static_cast<float>(rand()) / RAND_MAX * 2;
        cout << "Initial Value: " << value << endl;
    }

public:
    NewtonRaphsonMethod(float e) : toll(e){
        generateRandomValues();
    }

    float findRoot(){
        float x = value;
        float h;
        int i = 1;

        do{
            h = function(x) / functionDerivative(x);
            x = x - h;
            cout << "Iteration " << i << ", x = " << x << endl;
            i++;
        } while (abs(h) > toll);

        return x;
    }
};

int main(){

    NewtonRaphsonMethod newton(0.001);
    float root = newton.findRoot();
    
    return 0;
}

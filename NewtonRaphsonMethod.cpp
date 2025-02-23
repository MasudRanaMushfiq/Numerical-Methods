#include <bits/stdc++.h>

using namespace std;

#define tolerence 0.0001
#define N 100

class NewtonRaphson {

    private:

        double function(double x) {
            return (x*x*x + x*x - 1);
        }
        double derivative(double x) {
            return (3*x*x + 2*x);
        }

    public:

        void solve() {

            srand(int(time(0)));
            double prev_root;
            while(true) {
                prev_root = -9 + rand()%10;
                if(derivative(prev_root) != 0) 
                break;
            }

            double root, step = 0;

            cout << prev_root << endl;

            while(true) {

                double fx = function(prev_root);
                double dfx = derivative(prev_root);

                root = prev_root - (fx / dfx); 

                if(function(root) == 0.0) break;

                if(tolerence > abs((root - prev_root) / root)) break;

                cout << "Iteration-" << ++step << ":\t x = "<< setw(10) << root <<"    and f(x) = " << setw(10) << function(root) << endl;

                if(step > N) {
                    cout << "Non Convergent! " << endl;
                    return;
                }

                if(derivative(root) == 0.0) root++;
                prev_root = root;

            }

            cout << "\n\nThe value of root is: " << root << endl;

        }

};


int main() {

    NewtonRaphson nr;
    nr.solve();

    return 0;

}

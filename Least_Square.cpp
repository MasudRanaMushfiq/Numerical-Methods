#include <iostream>
#include <vector>
#include <cmath>

class LeastSquareMethod {
private:
    std::vector<double> x, y;

public:
    void addDataPoint(double x, double y) {
        this->x.push_back(x);
        this->y.push_back(y);
    }

    double calculateSlope() {
        double sX=0,sY=0,sXY=0,sX2=0;
        for(int i=0;i<x.size();i++){
            sX+=x[i];
            sY += y[i];
            sXY+=x[i]*y[i];
            sX2+=x[i]*x[i];
        }
        int n = x.size();
        double slope = (n*sXY - sX*sY)/(n*sX2 - sX*sX);
        return slope;
    }

    double calculateIntercept(double slope) {
        int n = x.size();
        double sX = 0,sY =0;
        for(int i=0;i<n;i++){
            sX += x[i];
            sY += y[i];
        }
        double intercept = (sY - slope * sX) / n;
        return intercept;
    }

    void printEquation() {
        double slope = calculateSlope();
        double intercept = calculateIntercept(slope);

        std::cout << "y = " << slope << "x + " << intercept << std::endl;
    }
};

int main() {
    LeastSquareMethod lsm;

    lsm.addDataPoint(20, 800.3);
    lsm.addDataPoint(30, 800.4);
    lsm.addDataPoint(40, 800.6);
    lsm.addDataPoint(50, 800.7);
    lsm.addDataPoint(60, 800.9);
    lsm.addDataPoint(70, 801.0);
    

    lsm.printEquation();

    return 0;
}

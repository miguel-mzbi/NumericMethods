// InterpolationLineal.cc: Miguel Montoya
// Description: Linear Interpolation

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
using namespace std;

double linearInterpolation(int l, double xAprox) {
    
    double xReal, yReal, xPrev, yPrev, x0, x1, y0, y1;
    xReal = yReal = xPrev = yPrev = 0;
    
    ifstream myX("x.txt");
    ifstream myY("y.txt");

    for(int i = 0; i < l && myX && myY; i++) {
        xPrev = xReal;
        yPrev = yReal;
        myX >> xReal;
        myY >> yReal;
        if(xReal == xAprox) {
            return yReal;
        }
        else if(xReal > xAprox) {
            if(i = 0) {
                // Can't get x0 because xAprox is smaller
                throw domain_error("The x to aproximate must be between the domain of given coordinates (x is too small!)");
            }
            x1 = xReal;
            x0 = xPrev;
            y1 = yReal;
            y0 = yPrev;
            break;
        }
        else if(i == l -1 && xReal < xAprox) {
            // Can't get x1 because xAprox is bigger
            throw domain_error("The x to aproximate must be between the domain of given coordinates (x is too big!)");
        }
    }
    
    myX.close();
    myY.close();
    
    double m = (y1-y0)/(x1-x0);
    return m*(xAprox-x1)+y1;
}

int main() {
    
    int l;
    double xAprox, yAprox;

    cout << "Write the number of coordinates: ";
    cin >> l;
    
    cout << "Write the x to aproximate y: ";
    cin >> xAprox;
    
    yAprox = linearInterpolation(l, xAprox);
    
    cout << "y = " << yAprox;
    
}
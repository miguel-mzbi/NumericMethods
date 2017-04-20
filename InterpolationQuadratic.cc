// InterpolationQuadratic.cc: Miguel Montoya
// Description: Quadratic Interpolation

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double x) {
    return log(x);
}

double quadraticInterpolation(double xAprox) {
    
    double xReal, yReal, yAprox, a0, a1, a2, b0, b1, b2, errorAbs, errorRel;
    double x[3];
    double y[3];
    xReal = yReal = 0;
    
    ifstream myX("x.txt");
    ifstream myY("y.txt");

    for(int i = 0; i < 3 && myX && myY; i++) {
        myX >> xReal;
        myY >> yReal;
        x[i] = xReal;
        y[i] = yReal;
    }
    
    myX.close();
    myY.close();
    
    b0 = y[0];
    b1 = (y[1]-y[0])/(x[1]-x[0]);
    b2 = ((y[2]-y[1])/(x[2]-x[1]) - (y[1]-y[0])/(x[1]-x[0]))/(x[2]-x[0]);
    
    a0 = b0 - b1*x[0] + b2*x[0]*x[1];
    a1 = b1 - b2*x[0] - b2*x[1];
    a2 = b2;
    
    cout << "f(x) = " << a0 << " " << a1 << "x " << a2 << "x^2" << endl;
    
    yAprox = a0 + a1*xAprox + a2*pow(xAprox, 2); 
    errorAbs = abs(yAprox - f(xAprox));
    errorRel = abs((yAprox - f(xAprox))/f(xAprox));
    
    cout << "Error Absoluto = " << errorAbs << endl;
    cout << "Error Relativo = " << errorRel << endl;
    
    return yAprox;
}

int main() {
    
    double xAprox, yAprox;
    
    cout << "Write the x to aproximate y: ";
    cin >> xAprox;
    
    yAprox = quadraticInterpolation(xAprox);
    
    cout << "f(x) = " << yAprox;
    
}
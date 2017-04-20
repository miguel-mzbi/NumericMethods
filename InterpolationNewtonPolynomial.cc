// InterpolationQuadratic.cc: Miguel Montoya
// Description: Quadratic Interpolation

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double x) {
    return log(x);
}

double diffDivFin(int i0, int i1, double* xAt, double* yAt) {
    
    if(i1-i0 == 0) {
        return yAt[i0];
    }
    else {
        return (diffDivFin(i0+1, i1, xAt, yAt) - diffDivFin(i0, i1-1, xAt, yAt))/(xAt[i1]-xAt[i0]);
    }
}

double quadraticInterpolation(double xAprox, int l) {
    
    double xReal, yReal, yAprox, a0, a1, a2, b0, b1, b2, errorAbs, errorRel;
    double x[l];
    double y[l];
    double diffsDivs[l];
    xReal = yReal = 0;
    
    ifstream myX("x.txt");
    ifstream myY("y.txt");

    for(int i = 0; i < 3 && myX && myY; i++) {
        myX >> x[i];
        myY >> y[i];
    }
    
    myX.close();
    myY.close();
    
    for(int i = 0; i < l; i++) {
        diffsDivs[i] = diffDivFin(0, i, x, y);
        cout << diffsDivs[i] << endl;
    }
    
    yAprox = 0;
    
    for(int i = 0; i < l; i++) {
        double aprox = diffsDivs[i];
        
        for(int j = 0; j < i; j++) {
            aprox *= (xAprox - x[j]);
        }
        
        yAprox += aprox;
    }
    
    return yAprox;
}

int main() {
    
    double xAprox, yAprox;
    int l;
    
    cout << "Write the number of coordinates ";
    cin >> l;
    
    cout << "Write the x to aproximate y: ";
    cin >> xAprox;
    
    yAprox = quadraticInterpolation(xAprox, l);
    
    cout << "f(x) = " << yAprox;
    
}
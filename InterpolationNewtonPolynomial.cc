// InterpolationNewtonPolynomial.cc: Miguel Montoya
// Description: Newton Polynomial Interpolation

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double diffDivFin(int i0, int i1, double* xAt, double* yAt) {
    
    if(i1-i0 == 0) {
        return yAt[i0];
    }
    else {
        return (diffDivFin(i0+1, i1, xAt, yAt) - diffDivFin(i0, i1-1, xAt, yAt))/(xAt[i1]-xAt[i0]);
    }
}

double NewtonInterpolation(double xAprox, int l, double* x, double* y) {
    
    double yAprox;
    double diffsDivs[l];
    
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

    double x[l];
    double y[l];
    
    ifstream myX("x.txt");
    ifstream myY("y.txt");

    for(int i = 0; i < l && myX && myY; i++) {
        myX >> x[i];
        myY >> y[i];
    }
    
    myX.close();
    myY.close();
    
    yAprox = NewtonInterpolation(xAprox, l, x, y);
    
    cout << "f(x) = " << yAprox;
    
}
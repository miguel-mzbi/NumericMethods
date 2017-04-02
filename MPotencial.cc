#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
    
    // x: accum of x
    // y: accum of y
    // xy: accum of x*y
    // xsq: accum of x^2
    // avy: average of y
    // sr: yMes - yPros
    // st: yMes - avy
    // n: number of coords
    double x, y, xy, xsq, avy, xReal, yMes, yReal, sr, st, n, i, a1, a0;
    x = y = xy = xsq = avy = xMes = yMes = yPros = i = 0;
    cout << "Write n: ";
    cin >> n;
    
    ifstream myX("x.txt");
    ifstream myY("y.txt");
    
    // Loop to get a0 and a1
    for(i; myX && myY && i < n; i++) {
        double tx, ty;
        myX >> tx;
        myY >> ty;
        cout << tx << " | " << ty << endl;
        x += log10(tx);
        y += log10(ty);
        xy += log10(tx)*log10(ty);
        xsq += pow(log(tx), 2);

    }
    
    myX.close();
    myY.close();
    
    // Get alpha (a0) and beta (a1)
    a1 = (n*xy - x*y)/(n*xsq - pow(x, 2));
    avy = y/n;
    a0 = pow(10, avy - a1*(x/n));
    
    ifstream myErrX("x.txt");
    ifstream myErrY("y.txt");
    
    // Loop to get errors
    for(int i = 0; i < n; i++) {
        myErrY >> yReal;
        myErrX >> xReal;
        yMes = a0*pow(xReal, a1);
        sr += pow(yReal - yMes, 2);
        st += pow(yReal - avy, 2);
    }
    
    myErrX.close();
    myErrY.close();

    // Get Std. Error, Determiantion Coeff (r2) Correlation Coef (r)
    double stdError = sqrt(sr/(n-2));
    double r2 = (st-sr)/st;
    double r = sqrt(r2);
    
    cout << "β = " << a1 << "\tα = " << a0 << endl;
    cout << "Std. Error = " << stdError << "\tDetermiantion Coefficient = " << r2 << "\tCorrelation Coefficient = " << r << endl;
}
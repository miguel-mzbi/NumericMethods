#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    
    double x, y, xy, xsq, n, i, a1, a0, avy, avx, st, sr, yMes, yReal, xReal;
    x = y = xy = xsq = i = 0;
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
        x += tx;
        y += ty;
        xy += tx*ty;
        xsq += pow(tx, 2);
    }
    
    myX.close();
    myY.close();
    
    // Calculate with given values
    a1 = (n*xy - x*y)/(n*xsq - pow(x, 2));
    avy = y/n;
    avx = x/n;
    a0 = avy - a1*avx;
    
    ifstream myErrX("x.txt");
    ifstream myErrY("y.txt");
    
    // Loop to get errors
    for(int i = 0; i < n; i++) {
        myErrY >> yReal;
        myErrX >> xReal;
        yMes = a0* + a1*xReal;
        sr += pow(yReal - yMes, 2);
        st += pow(yReal - avy, 2);
    }
    
    myErrX.close();
    myErrY.close();
    
    // Get Std. Error, Determiantion Coeff (r2) Correlation Coef (r)
    double stdError = sqrt(sr/(n-2));
    double r2 = (st-sr)/st;
    double r = sqrt(r2);
    
    cout << "a1 = " << a1 << "\ta0 = " << a0 << endl;
    cout << "Std. Error = " << stdError << "\tDetermiantion Coefficient = " << r2 << "\tCorrelation Coefficient = " << r << endl;
}
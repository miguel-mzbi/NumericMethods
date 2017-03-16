#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    
    double x, y, xy, xsq, n, i, a1, a0, avy, avx;
    x = y = xy = xsq = i = 0;
    cout << "Write n: ";
    cin >> n;
    ifstream myX("x.txt");
    ifstream myY("y.txt");
    
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
    
    a1 = (n*xy - x*y)/(n*xsq - pow(x, 2));
    avy = y/n;
    avx = x/n;
    a0 = avy - a1*avx;
    
    cout << "x = " << x << "\ty = " << y << "\txy = " << xy << endl;
    cout << "a1 = " << a1 << "\ta0 = " << a0 << endl;
    
}
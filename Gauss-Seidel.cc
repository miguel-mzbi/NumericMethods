#include <iostream>
#include <cmath>
using namespace std;

double fx(double y, double z) {
    
    return (3 + y + z)/6;
}

double fy(double x, double z) {
    
    return (40 - 6*x - z)/9;
}

double fz(double x, double y) {
    
    return (50 + 3*x- y)/-12;
}

int main() {
    
    double x, y, z;
    double error = 5;
    int i;
    x = y = z = 0.0;
    
    do {
        
        x = fx(y, z); // New value for x
        y = fy(x, z); // New value for y
        z = fz(x, y); // New value for z
        i++;
        cout << x << " | " << y << " | " << z << " | " << i << endl;
    }
    while(abs(-3*x+y-12*z-50)*100>error || abs(6*x-y-z-3)*100>error || abs(6*x+9*y+z-40)*100>error); //ERROR PARCIAL2
    
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "i = " << i << endl;

}
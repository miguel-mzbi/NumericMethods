//Newton-Raphson.cc: Miguel Montoya
//Description: Newton-Raphson Bisection

#include <iostream>
#include <cmath>
using namespace std;

#define FUNCTION exp(x)+x
#define DERIVATE exp(x)+1

double f(double x) {
    return (double) FUNCTION;
}

double fd(double x) {
    return (double) DERIVATE;
}

int main() {
    double x0, x1, p, i;
    cout << "x0: ";
    cin >> x0;
    
    do {
        p = f(x0)/fd(x0);
        x1 = x0 - p;
        x0 = x1;
        i++;
    } while (abs(p) > 0.0000001);
    
    cout <<"Root: " << x1 << " Iterations: " << i << endl;
}
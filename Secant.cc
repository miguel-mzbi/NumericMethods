//Secant.cc: Miguel Montoya
//Description: Secant Method

#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return 9*exp(-0.7*x)*cos(4*x)-3.5;
}

int main() {
    double xn, xp, xnt, i;
    cout << "Previous x: ";
    cin >> xp;
    cout << "New x: ";
    cin >> xn;

    do {
        double a = f(xn);
        double b = f(xp);
        xnt = xn - (f(xn) * (xp - xn)) / (f(xp) - f(xn)); // x-origin of secant
        xp = xn;
        xn = xnt;
        i++;
        cout << "Iteration: " << i << " Aproximation: " << xn << endl;
    } while(abs(f(xn))*100 > 0.1); //ERROR PARCIAL 2
    // abs(xn - xp) Iterative

    cout << "Root: " << xn << "\t\tIterations: " << i << "\t\tf(xf):" << f(xn) << endl;
}
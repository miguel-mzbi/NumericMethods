//Secant.cc: Miguel Montoya
//Description: Secant Method

#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return log(x);
}

int main() {
    double xn, xp, xnt, x1, i, fxn;
    cout << "Previous x: ";
    cin >> xp;
    cout << "New x: ";
    cin >> xn;

    do {
        xnt = xn - (f(xn) * (xp - xn)) / (f(xp) - f(xn));
        xp = xn;
        xn = xnt;
        i++;
        cout << "Iteration: " << i << " Aproximation: " << xn << endl;
        fxn = f(xn);
    } while (abs(fxn) > pow(10, -12));

    cout << "Root: " << xn << "\t\tIterations: " << i << "\t\tf(xf):" << fxn << endl;
}
//Secant.cc: Miguel Montoya
//Description: Secant Method

#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return pow(x, 2);
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
        xnt = xn - (f(xn) * (xp - xn)) / (f(xp) - f(xn));
        xp = xn;
        xn = xnt;
        i++;
        cout << "Iteration: " << i << " Aproximation: " << xn << endl;
    } while (abs(f(xn)) > pow(10, -12));

    cout << "Root: " << xn << "\t\tIterations: " << i << "\t\tf(xf):" << f(xn) << endl;
}
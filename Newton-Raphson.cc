//Newton-Raphson.cc: Miguel Montoya
//Description: Newton-Raphson Bisection

#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return log(x - 1) + 1;
}

double fd(double x) {
    return 1 / (x-1);
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
        cout << "Iteration: " << i << " Aproximation: " << x1 << " P: " << p << endl;
    } while (abs(p) > pow(10, -15));

    cout << "Root: " << x1 << " Iterations: " << i << endl;
}
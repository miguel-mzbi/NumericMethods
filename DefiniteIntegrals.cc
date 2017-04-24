// DefiniteIntegrals.cc: Miguel Montoya
// Description: Definite Integrals methods (LRS, RRS, Trapezium Sum)

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {

    return 0.2 + 25*x - 200*pow(x, 2) + 675*pow(x, 3) - 900*pow(x, 4) + 400*pow(x, 5); 
}

double functionIntegral(double x) {
    return 0.2*x + 25*pow(x, 2)/2 - 200*pow(x, 3)/3 + 675*pow(x, 4)/4 - 900*pow(x, 5)/5 + 400*pow(x, 6)/6;
}

double integral(double a, double b) {

    return functionIntegral(b) - functionIntegral(a);
}

double LRS(int n, double a, double b) {

    double h = (b-a)/n;
    double _a = a;
    double integral = 0;
    for(int i = 0; i < n; i++) {
        integral += h*f(_a);
        _a += h;
    }
    return integral;
}

double RRS(int n, double a, double b) {
    
    double h = (b-a)/n;
    double _b = b;
    double integral = 0;
    for(int i = 0; i < n; i++) {
        integral += h*f(_b);
        _b -= h;
    }
    return integral;
}

double trapezium(int n, double a, double b) {
    
    double h = (b-a)/n;
    double _a = a;
    double integral = f(a) + f(b);
    double integralSum = 0;
    for(int i = 1; i < n-1; i++) {
        integralSum += f(_a);
        _a +=h;
    }
    return (integral+2*integralSum)*h/2;
}

int main() {

    int select;
    double n, a, b, defInt, realDefInt, percentualError;

    cout << "Select the number corresponding to the method:" << endl << "0\tLRS" << endl << "1\tRRS" << endl << "2\tTrapezium" << endl;
    cin >> select;
    cout << "Number of intervals: ";
    cin >> n;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    
    switch(select) {
        case 0:
            defInt = LRS(n, a, b);
            break;
        case 1:
            defInt = RRS(n, a, b);
            break;
        case 2:
            defInt = trapezium(n, a, b);
            break;
    }

    percentualError = abs((integral(a, b)-defInt)/integral(a, b))*100;

    cout << "Integral = " << defInt << endl;
    cout << "Percentual Error = " << percentualError << "%" << endl;

}
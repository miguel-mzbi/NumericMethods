// SimpsonIntegral1-3.cc: Miguel Montoya
// Description: Integral Simpson 1/3 Rule

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double simpsonIntegralOneThird(double *x, double *y, int intervals, int extraIntervals) {
    int index = intervals - extraIntervals;
    double coeff = (x[index] - x[0])/(3*index);
    double integral, preIntegral, extraIntegral;
    integral = preIntegral = extraIntegral = 0;

    for(int i = 1; i < index; i += 2) {
        preIntegral += 4*y[i];
    }
    
    for(int i = 2; i < index -1; i += 2) {
        preIntegral += 2*y[i];
    }

    if(extraIntervals > 0) {
        extraIntegral = (y[index]+y[index+1])*(x[index+1]-x[index])/2;
    }

    integral = coeff*(y[0] + preIntegral + y[index]) + extraIntegral;

    return integral;
}

int main() {

    int l, numberIntervals, numberSimpsonIntervals, extraIntervals;
    l = numberIntervals = numberSimpsonIntervals, extraIntervals = 0;
    double integral, realIntegral;
    integral = realIntegral = 0;
    
    cout << "Write the number of coordinates ";
    cin >> l;

    cout << "The coordinates are read from x.txt and y.txt" << endl;

    numberIntervals = l-1;
    numberSimpsonIntervals = numberIntervals/2;
    extraIntervals = numberIntervals%2;
    
    cout << "Number of regular intervals: " << numberIntervals << endl;
    cout << "Number of intervals to use Simpson 1/3: " << numberSimpsonIntervals << endl;
    cout << "Number of intervals where trapezoid integral will be used (Last): " << extraIntervals << endl;


    double x[l];
    double y[l];
    
    ifstream myX("x.txt");
    ifstream myY("y.txt");

    for(int i = 0; i < l && myX && myY; i++) {
        myX >> x[i];
        myY >> y[i];
    }

    myX.close();
    myY.close();

    integral = simpsonIntegralOneThird(x, y, numberIntervals, extraIntervals);
    
    cout << "Integral = " << integral << endl;

}
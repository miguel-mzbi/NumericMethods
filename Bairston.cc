//Bairston.cc: Miguel Montoya
//Description: Bairston Method

#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return log(x);
}

int main() {
    // 1.25, -3.875, 2.125, 2.75, -3.5, 1
    double r, s;
    int degree, currentDegree;
    cout << "r: ";
    cin >> r;
    cout << "s: ";
    cin >> s;
    cout << "Degree of polynomial: ";
    cin >> degree;
    double coefficients[degree+1];
    for(int i = degree, j = 0; i >= 0; i--, j++){
        cout << "Coefficient of degree " << i << ": ";
        cin >> coefficients[j];
    }
    
    double bs[degree+1];
    for(int i = degree, j = 0; i >= 0; i--, j++){
        double op1, op2;
        if(i == degree){
            bs[j] = coefficients[j];
        }
        else if(i == degree-1){
            bs[j] = coefficients[j] + bs[j-1]*r;
        }
        else {
            bs[j] = coefficients[j] + bs[j-1]*r + bs[j-2]*s;
        }
    }
    
    for(int i = 0; i < degree+1; i++){
        cout << bs[i] << " ";
    }
    cout << endl;
}
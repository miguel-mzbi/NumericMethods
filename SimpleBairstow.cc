//Bairstow.cc: Miguel Montoya
//Description: Bairstow Method

#include <iostream>
#include <cmath>
using namespace std;

double error = 0.001;

int main() {
    double r, s, dr, ds;
    int degree;
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
    int i = 0;
    double bs[degree+1];
    do {
        // Synthetic division bs
        for(int i = degree, j = 0; i >= 0; i--, j++){
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
        
        double cs[degree+1];
        // Synthethic division cs
        for(int i = degree, j = 0; i >= 0; i--, j++){
            if(i == degree){
                cs[j] = bs[j];
            }
            else if(i == degree-1){
                cs[j] = bs[j] + cs[j-1]*r;
            }
            else {
                cs[j] = bs[j] + cs[j-1]*r + cs[j-2]*s;
            }
        }
        
        // Cramer
        dr = ((-bs[degree-1])*cs[degree-2]-(-bs[degree])*(cs[degree-3]))/(cs[degree-2]*cs[degree-2]-cs[degree-1]*cs[degree-3]);
        ds = (cs[degree-2]*(-bs[degree])-cs[degree-1]*(-bs[degree-1]))/(cs[degree-2]*cs[degree-2]-cs[degree-1]*cs[degree-3]);
        
        // New r and s approximation
        r = r + dr;
        s = s + ds;
        i++;
    } while(abs(dr/r) > error || abs(ds/s) > error);//ERROR PARCIAL2
    
    double x1 = (r + sqrt(pow(r,2)+4*s))/2;
    double x2 = (r - sqrt(pow(r,2)+4*s))/2;
    
    cout << endl << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "Iterations: " << i << endl;
    cout << "Remaining coefficients: ";
        for(int i = 0; i < degree-1; i++){
            cout << bs[i] << " ";
        }
        cout << endl;
    
}
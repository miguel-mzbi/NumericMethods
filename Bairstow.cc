//Bairstow.cc: Miguel Montoya
//Description: Bairstow Method

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double error = 0.001;

// Struct to store solutions
struct solution {
    double a;
    double bi;
};

void synDiv(vector<double> &coeff, vector<double> &bs, vector<double> &cs, double r, double s) {
    int deg = coeff.size() - 1;
    int i, j;
    for(i = deg, j = 0; i >= 0; i--, j++) {
        if(i == deg){
            bs[j] = coeff[j];
        }
        else if(i == deg - 1) {
            bs[j] = coeff[j] + bs[j - 1] * r;
        }
        else {
            bs[j] = coeff[j] + bs[j - 1] * r + bs[j - 2] * s;
        }
    }
    for(i = deg, j = 0; i >= 0; i--, j++) {
        if(i == deg) {
            cs[j] = bs[j];
        }
        else if(i == deg - 1) {
            cs[j] = bs[j] + cs[j - 1] * r;
        }
        else {
            cs[j] = bs[j] + cs[j - 1] * r + cs[j - 2] * s;
        }
    }
}

void bairstow(vector<double> &coeff, vector<solution*> &roots, double ri, double si) {
    // Loop for degree bigger than 2 (At least 3 roots). Size is 3 because is considering x^0.
    while (coeff.size() > 3) {
        vector<double> bs(coeff.size(), 0.0);
        vector<double> cs(coeff.size(), 0.0);
    
        double r = ri;
        double s = si;
        double dr = 0.0;
        double ds = 0.0;
        
        // Get adequate r and s (Intents of roots)
        do {
            //Initialize vectors to zero.
            for (int i = 0; i < bs.size(); i++) {
                bs[i] = 0;
                cs[i] = 0;
            }
            
            synDiv(coeff, bs, cs, r, s);
            
            int deg = coeff.size() - 1;
            double d = cs[deg - 2] * cs[deg - 2] - cs[deg - 1] * cs[deg - 3];
            dr = (-bs[deg - 1] * cs[deg - 2] + bs[deg] * cs[deg - 3]) / d;
            ds = (-cs[deg - 2] * bs[deg] + cs[deg - 1] * bs[deg - 1]) / d;
            
            r += dr;
            s += ds;
        } while(abs(dr / r) > error && abs(ds / s) > error); //ERROR PARCIAL2
        
        // Get determinant to set real or complex roots (2 roots)
        double det = pow(r, 2) + 4 * s;
        solution *r1 = new solution;
        solution *r2 = new solution;
        
        // Complex solution
        if (det < 0) {
            r1->a = r / 2;
            r1->bi = sqrt(-det) / 2;
            r2->a = r / 2;
            r2->bi = -sqrt(-det) / 2;
        }
        //Real solution
        else {
            r1->a = (r + sqrt(det)) / 2;
            r1->bi = 0;
            r2->a = (r - sqrt(det)) / 2;
            r2->bi = 0;
        }
        
        // Store both
        roots.push_back(r1);
        roots.push_back(r2);
        
        // Reset vectors
        bs = vector<double>(coeff.size(), 0.0);
        cs = vector<double>(coeff.size(), 0.0);
        
        // Lower degree of polynomial for new iteration
        synDiv(coeff, bs, cs, r, s);
        for(int i = 0; i < coeff.size() - 2; i++) {
            coeff[i] = bs[i];
        }
        coeff.pop_back();
        coeff.pop_back();
    }
    
    // If degree equals 2 (Size is 3, because ax^2 + bx + c)
    if (coeff.size() == 3) {
        // x^2 - rx - s
        int r = -coeff[1];
        int s = -coeff[2];
        double det = pow(r, 2) + 4 * s;
        
        solution* r1 = new solution;
        solution* r2 = new solution;
        if (det < 0) {
            r1->a = r / 2;
            r1->bi = sqrt(-det) / 2;
            r2->a = r / 2;
            r2->bi = -sqrt(-det) / 2;
        }
        else {
            r1->a = (r + sqrt(det)) / 2;
            r1->bi = 0;
            r2->a = (r - sqrt(det)) / 2;
            r2->bi = 0;
        }
        roots.push_back(r1);
        roots.push_back(r2);
    }
    // If degree equals 1 (Size is 2, because ax + b)
    else if (coeff.size() == 2) {
        cout << "Entro" << endl;
        cout << coeff[0] << endl;
        cout << coeff[1] << endl;
        solution *r = new solution;
        r->a = -coeff[1] / coeff[0];
        r->bi = 0;
        roots.push_back(r);
    }
}

int main(){
    double ri, si;
    int initDegree;
    
    cout << "r: ";
    cin >> ri;
    cout << "s: ";
    cin >> si;
    cout << "Degree of polynomial: ";
    cin >> initDegree;
    
    vector<double> poly(initDegree + 1);
    vector<solution*> roots;
    
    // Get coefficients, stored from higher degree to lower
    for(int i = initDegree; i >= 0; i--){
        double t;
        cout << "Coefficient of degree " << i << ": ";
        cin >> t;
        poly.push_back(t);
    }
    
    // Start Bairstow
    bairstow(poly, roots, ri, si);
    
    // Print all roots
    cout << "Roots:" << endl;
    for(int i = 0; i < initDegree; i++) {
        // Complex root
        if(roots[i]->bi != 0){
            cout << "x" << i << " = " << roots[i]->a << " + " << roots[i]->bi << "i" << endl;
        }
        // Real root
        else{
            cout << "x" << i << " = " << roots[i]->a << endl;
        }
    }
}

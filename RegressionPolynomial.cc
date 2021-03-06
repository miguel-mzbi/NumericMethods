// Regression Polynomial.cc: Miguel Montoya
// Description Polynomial Regression

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    
    int n, l;

    cout << "Write the number of coordinates: ";
    cin >> l;
    
    cout << "Write the degree of aproximation: ";
    cin >> n;
    
    double yAccum;
    // Array for the summatories for x^n
    double summatoriesX[2*n];
    // Array for the summatories of x^n*y
    double summatoriesXY[n];
    
    ifstream myX("x.txt");
    ifstream myY("y.txt");
    
    // Loop to get all accumulatives
    for(int i = 0; myX && myY && i < l; i++) {
        double xReal, yReal;
        myX >> xReal;
        myY >> yReal;
        for(int j = 0; j < 2*n; j++) {
            summatoriesX[j] += pow(xReal, j+1);
        }
        yAccum += yReal;
        for(int j = 0; j < n; j++) {
            summatoriesXY[j] += yReal * pow(xReal, j+1);
        }
    }
    
    myX.close();
    myY.close();
    
    // Build matrix Ax=b
    double matrix[n+1][n+2];
    
    for(int i = 0; i < n+1; i++) {
        int k = i-1;
        if(i == 0) {
            k++;
        }
        for(int j = 0; j < n+2; j++) {
            if(i == 0 && j == 0) {
                matrix[i][j] = l;
                continue;
            }
            if(j != n+1) {
                matrix[i][j] = summatoriesX[k];
            }
            else {
                if(i == 0) {
                    matrix[i][j] = yAccum;    
                }
                else {
                    matrix[i][j] = summatoriesXY[i-1];
                }
            }
            k++;
        }
    }
    
    // Gauss-Jordan
    for(int p = 0; p < n; p++) {
        double pivot = matrix[p][p];
        for(int i = p+1; i < n+1; i++) {
            double firstLine = matrix[i][p];
            for(int j = 0; j < n+2; j++) {
                matrix[i][j] -= matrix[p][j]*firstLine/pivot;
            }
        }
    }
    
    for(int p = n; p >= 1; p--) {
        double pivot = matrix[p][p];
        for(int i = p-1; i >= 0; i--) {
            double firstLine = matrix[i][p];
            for(int j = 0; j < n+2; j++) {
                //cout << matrix[p][j]*firstLine/pivot << endl;
                matrix[i][j] -= matrix[p][j]*firstLine/pivot;
            }
        }
    }
    
    for(int i = 0; i < n+1; i++) {
        double f = matrix[i][i];
        for(int j = 0; j < n+2; j++) {
            matrix[i][j] /= f;
        }
    }
    
    double solution[n+1];
    cout << endl;
    
    // Get solution
    for(int i = 0; i < n+1; i++) {
        solution[i] = matrix[i][n+1];
        cout<< matrix[i][n+1] << " x^" << i << endl;
    }
    
    double sr, st, yAvg;
    yAvg = yAccum/l;
    
    ifstream myErrX("x.txt");
    ifstream myErrY("y.txt");
    
    // Loop to get errors
    for(int i = 0; i < l; i++) {
        double xReal, yReal, yMes;
        yMes = 0;
        myErrY >> yReal;
        myErrX >> xReal;
        for(int j = 0; j < n+1; j++) {
            yMes += solution[j]*pow(xReal, j);
        }
        sr += pow(yReal - yMes, 2);
        st += pow(yReal - yAvg, 2);
    }
    
    myErrX.close();
    myErrY.close();
    
    // Calculate error
    double stdError = sqrt(sr/(l - (n + 1)));
    double rSq = (st - sr)/st;
    double r = sqrt(rSq);
    
    // Print errors
    
    cout << endl << "Standard Error = " << stdError << "\tDetermiantion Coefficient = " << rSq << "\tCorrelation Coefficient = " << r << endl;
}
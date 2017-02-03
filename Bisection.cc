// Bisection.cc: Miguel Montoya
// Description: Bisection

#include <iostream>
#include <cmath>
using namespace std;

// 13x^3+5x^2-20
double f (double x){
    double result;
	return 13*pow(x,3)+5*pow(x,2)-20;
}

int main(){
    double x0, x1, xm, fx0, fx1, fxm;
    
    cout << "x0: ";
    cin >> x0;
    cout << "x1: ";
    cin >> x1;
    
    fx0 = f(x0);
    fx1 = f(x1);
    xm = (x0 + x1)/2;
    fxm = f(xm);
    // Only enter the loop if the results of the functions
	// are each in a difererent side of the x-axis.
    if(fx0 == 0){
        cout <<"Root: " << x0;
    }
    else if(fx1 == 0){
        cout <<"Root: " << x1;
    }
    // Only enter the loop if the results of the functions
	// are each in a difererent side of the x-axis.
    else if((fx0*fx1) < 0){
        int i = 0;
        do{
            if(fx0*fxm < 0){
                x1 = xm;
            }
            else if (fxm*fx1 < 0){
                x0 = xm;
            }
            
            fx0 = f(x0);
            fx1 = f(x1);
            // Get the value of x between x0 and x1
            xm = (x0 + x1)/2;
            fxm = f(xm);
            
            i++;
            
        }while(abs(fxm) > 0.0000001);
        cout <<"Root: " << xm << " Iterations: " << i;
    }
    else{
        cout << "Error. Out of bounds. It's possible f(x0) and f(x1) are the same side of the sign" << endl;
        cout << "f(x0) = " << fx0 << endl;
        cout << "f(x1) = " << fx1 << endl;
    }
    return 0;
}

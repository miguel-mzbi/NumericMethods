// Bisection.cc: Miguel Montoya
// Description: Bisection

#include <iostream>
#include <cmath>
using namespace std;

double f (double x){
	return pow(x,7)-0.9;
}

int main(){
    double x0, x1, xm, fx0, fx1, fxm;

    cout << "x0: ";
    cin >> x0;
    cout << "x1: ";
    cin >> x1;

    fx0 = f(x0);
    fx1 = f(x1);

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
            // Get the value of x between x0 and x1
            xm = (x0 + x1)/2;
            fxm = f(xm);
            if(fx0*fxm < 0){
                x1 = xm;
            }
            else if (fxm*fx1 < 0){
                x0 = xm;
            }

            fx0 = f(x0);
            fx1 = f(x1);

            i++;
            cout << "Iteration: " << i << " Aproximation: " << xm << endl;

        }while(abs(fxm) > pow(10, -5));
        cout << "Root: " << xm << " Iterations: " << i;
    }
    else{
        cout << "Error. Out of bounds. It's possible f(x0) and f(x1) are the same side of the sign" << endl;
        cout << "f(x0) = " << fx0 << endl;
        cout << "f(x1) = " << fx1 << endl;
    }
    return 0;
}

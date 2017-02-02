//CosX.cc: Miguel Montoya
//Description: CosX
#include <iostream>
#include <cmath>
#define ITERACIONES 1
using namespace std;

double factorial(double n){
    double f = 1;
    for(int c = 2; c <= n; c++){
        f = f*c;
    }
    return f;
}

int main(){
    double x, e_rel, coseno = 0;
    int i = 0;
    cout << "Dame el angulo en radianes ";
    cin >> x; cin.clear();
    do{
        coseno = coseno + (pow(-1, i) * pow(x, 2*i))/factorial(2*i);
        double e_abs = cos(x) - coseno;
        e_rel = abs(e_abs/cos(x));
        i++;
    }while(e_rel > 1E-10);
    cout << "Coseno aprox: " << coseno << endl;
    cout << "Coseno real: " << cos(x) << endl;
    cout << "Iteraciones: " << i << endl;
    cout << "Error relativo: " << e_rel << endl;
    return 0;
}
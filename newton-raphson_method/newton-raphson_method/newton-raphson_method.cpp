// Adam Majchrzak s176708
//

#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

double f(double x) {
    return (cos(x) - x);
}

double f_prim(double x) {
    return (-1.0*sin(x) - 1.0);
}

double f_prim_prim(double x) {
    return (-1.0*cos(x));
}

int main()
{
    double xNew, xOld, Tol, Error;
    int i;
    xOld = 0.0;
   
    Tol = pow(10, -8);
    i = 0;
    do {
        xNew = xOld - (f(xOld) / f_prim(xOld)) * pow((1.0 - (f(xOld)/f_prim(xOld) * (f_prim_prim(xOld)/f_prim(xOld)))), -1);
        Error = fabs((xNew - xOld) / xNew);
        i++;
        cout << "i= " << i << " x0= " << setprecision(8) << xNew << endl;
        xOld = xNew;
    } while (Error >= Tol);

    cout << "Root found at " << setprecision(8) << xNew << endl;
    cout << "Number of iterations: " << i << endl;

    return 0;
}

//bisection method!

#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
	return cos(x) - x;
}

int main() {
	double xl, xr, tol, Error, xm;

	std::cout << "xl value: ";
	std::cin >> xl;
	std::cout << "xr value: ";
	std::cin >> xr;
	std::cout << "Tol value: ";
	std::cin >> tol;
	if (f(xl) * f(xr) > 0.0) {
		std::cout << "error";
		return -1;
	}
	int i = 0;
	do {
		xm = (xr + xl) / 2.0;
		if (f(xl)*f(xm)>0.0) {
			xl = xm;
		}
		else {
			xr = xm;
		}
		Error = fabs((xr - xl) / xm);
		i++;
	}while(Error > tol);
	std::cout << "iteration: " << i  << ". " << xm;
	
}
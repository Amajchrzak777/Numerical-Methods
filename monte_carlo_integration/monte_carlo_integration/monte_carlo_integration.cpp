// Adam Majchrzak 13.05.2020
// monte_carlo_integration.cpp

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

double f(double x)
{
	return exp(x);
}

double f2(double y)
{
	return exp(sqrt(1.0 + 2.0 * y) - 1.0) / sqrt(1.0 + 2.0 * y);
}

int main(int argc, char** argv) {
	int D[200];
	double I, a, b, xi, I2, fxi, SN, IR, IL;
	fstream fout;

	a = 0.0;
	b = 1.0;
	for (int N = 10; N <= 10000000; N = N * 10)
	{
		I = 0.0;
		I2 = 0.0;
		for (int i = 1; i <= N; i++)
		{
			xi = ((double)rand()) / RAND_MAX; //values between 0 and 1
			fxi = f(xi);
			I = I + fxi;
			I2 = I2 + (fxi * fxi);
		}
		I = I / N;
		I2 = I2 / N;
		SN = sqrt((I2 - I * I) / (N - 1));
		I = I * (b - a);
		cout << "I= " << setprecision(8) << I << " ; SN= " << setprecision(8) << SN << endl;
	}
	cout << "Exact= " << setprecision(8) << exp(1.0) - 1.0 << endl << endl;


	cout << "Importance sampling:" << endl;
	a = 0.0;
	b = 1.5;
	for (int N = 10; N <= 10000000; N = N * 10)
	{
		I = 0.0;
		I2 = 0.0;
		for (int i = 1; i <= N; i++)
		{
			xi = (((double)rand()) / RAND_MAX) * 1.5; //values between 0 and 1.5
			fxi = f2(xi);
			I = I + fxi;
			I2 = I2 + (fxi * fxi);
		}
		I = I / N;
		I2 = I2 / N;
		SN = sqrt((I2 - I * I) / (N - 1));
		I = I * (b - a);
		cout << "I= " << setprecision(8) << I << " ; SN= " << setprecision(8) << SN << endl;
	}
	cout << "Exact= " << setprecision(8) << exp(1.0) - 1.0 << endl;


	//Initial values for distribution of 200 intervals of size 0.002
	for (int j = 0; j < 200; j++)
	{
		D[j] = 0;
	}

	//Generate distribution
	int N = 1000;
	a = 0.0;
	b = 1.0;
	for (int e = 1; e <= 10000; e++) //10000 integrals to calculate
	{
		I = 0.0;
		for (int i = 1; i <= N; i++)
		{
			xi = ((double)rand()) / RAND_MAX; //values between 0 and 1
			fxi = f(xi);
			I = I + fxi;
		}
		I = (b - a) * I / N;
		if ((I < 1.5) || (I > 1.9))
		{
			//Do nothing, some integral values might be out of range 
			cout << I << endl;
		}
		else
		{
			IR = 1.502;
			for (int j = 0; j < 200; j++)
			{
				if (I <= IR) //Look for interval
				{
					D[j] += 1;
					break; //go out from "for" loop
				}
				IR = IR + 0.002;
			}
		}
	}

	//Write in File
	fout.open("Distribution.txt", ios::out);
	IL = 1.5;
	for (int j = 0; j < 200; j++)
	{
		fout << IL << "  " << D[j] << endl;
		IL = IL + 0.002;
	}
	fout.close();

	return 0;
}
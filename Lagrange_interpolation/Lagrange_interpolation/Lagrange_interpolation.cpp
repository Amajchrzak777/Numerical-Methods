//// Lagrange_interpolation.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
////
//
//#include <iostream>
//#include <math.h>
//#include <vector>
//
//using namespace std;
//
//double f(double x) 
//{
//    return exp(x);
//}
//
//
//
//int main()
//{
//    std::vector<double> vx;
//    std::cout << "How much x do you want to enter ?\n";
//    double x;
//    int how_much;
//    std::cin >> how_much;
//    for (int i = 0; i < how_much; ++i) {
//        std::cin >> x;
//        vx.push_back(x);
//    }
//    std::cout << "x: \n";
//    for (int i = 0; i < vx.size(); ++i) {
//        std::cout << "x" << i + 1 << ": " << vx[i] <<'\n';
//    }
//    std::vector<double> yx;
//    for (int i = 0; i < vx.size(); ++i) {
//        double y = f(vx[i]);
//        yx.push_back(y);
//    }
//
//    std::cout << "y: \n";
//    for (int i = 0; i < yx.size(); ++i) {
//        std::cout << "y" << i + 1 << ": " << yx[i] << '\n';
//    }
//    int zmienna = 5;
//    double Lx;
//    double score = 0.0;
//    int j = 1;
//    for (int i = 0; i < 3; ++i) {
//        Lx = (zmienna - vx[i]) / (vx[j] - vx[i]);
//        score += Lx;
//        j++;
//    }
//    std::cout << score;
//}

#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
	return exp(x);
}

double fp(double x)
{
	return exp(x);
}

int main(int argc, char** argv) {
	double xT[4] = { -1.0,0.5,1.5,2.0 };
	double x, p, l_jn, l_jnP, h_jn, hBar_jn;
	int NbStep, n;

	x = -5.0; //initial value of x
	n = 4; //number of points
	NbStep = int(10.000001 / 0.1); //number of steps


	cout << "Lagrange p(x):" << endl;
	for (int step = 0; step <= NbStep; step++) //loop over x
	{
		p = 0.0;
		for (int j = 0; j < n; j++) //index in xT[] from 0 to n-1
		{
			l_jn = 1.0;
			for (int i = 0; i < n; i++)
			{
				if (i != j) l_jn = l_jn * ((x - xT[i]) / (xT[j] - xT[i])); //calculate l_jn
			}
			p = p + l_jn * f(xT[j]);
		}
		cout << "x= " << x << " p(x)= " << p << endl;
		x = x + 0.1;
	}

	//cout << endl << "Hermite p(x):" << endl;
	//x = -5.0;
	//for (int step = 0; step <= NbStep; step++)
	//{
	//	p = 0.0;
	//	for (int j = 0; j < n; j++) //index in xT[] from 0 to n-1
	//	{
	//		l_jn = 1.0;
	//		l_jnP = 0.0;
	//		for (int i = 0; i < n; i++)
	//		{
	//			if (i != j)
	//			{
	//				l_jn = l_jn * ((x - xT[i]) / (xT[j] - xT[i])); //calculate l_jn
	//				l_jnP = l_jnP + (1.0 / (xT[j] - xT[i])); //calculate l_jn'(x_j)
	//			}
	//		}
	//		h_jn = (1.0 - 2.0 * (x - xT[j]) * l_jnP) * l_jn * l_jn;
	//		hBar_jn = (x - xT[j]) * l_jn * l_jn;
	//		p = p + h_jn * f(xT[j]) + hBar_jn * fp(xT[j]);
	//	}
	//	cout << "x= " << x << " p(x)= " << p << endl;
	//	x = x + 0.1;
	//}

	return 0;
}
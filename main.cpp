#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x, int b)
{
	double sum1 = cos(x) + 1.0 / b * cos(9 * x + 1);
	double sum2 = 1 / pow(b, 2) * cos(81 * x + 2);
	double sum3 = 1 / pow(b, 3) * cos(729 * x + 3);
	double sum4 = 1 / pow(b, 4) * cos(6561 * x + 4);
	return (sum1 + sum2 + sum3 + sum4);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	double x0, xn, y0, yn, alpha, c;
	double alphaMin = 0.000001;
	int b;
	pair<double, double> result;

	cout << "Введите начальную точку x0: ";
	cin >> x0;
	cout << "\nВведите значение шага: ";
	cin >> alpha;
	cout << "\nВведите параметр с (от 0.75 до 0.999): ";
	cin >> c;
	cout << "\nВведите параметр b (от 2 до 10): ";
	cin >> b;

	y0 = f(x0, b);
	result = make_pair(x0, y0);
	cout << "Начальное значение функции: ";
	cout << "x0=" << setprecision(15) << result.first << ", f(x0)=" << setprecision(15) << result.second << endl << endl;

	while (alpha>alphaMin)
	{
		double rand_num = -1.0 + static_cast<double>(rand()) / RAND_MAX * 2.0;
		xn = x0 + alpha * rand_num;
		yn = f(xn, b);
			
		if (yn < y0)
		{
			y0 = yn;
			x0 = xn;
		}
		
		alpha *= c;
		result = make_pair(xn, yn);
		cout << "x0=" <<setprecision(15) << result.first << ", f(x0)=" << setprecision(15) << result.second << endl;
	}

	return 0;
}

#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

double f(double x) {
	
	// wielomian: f(x) = x^2 - 4x +2

	return x * (x - 4) + 2;
}

double polowieniePrzedzialow(double a, double b, double epsilion) {
	if (f(a) == 0.0)return a;
	if (f(b) == 0.0)return b;

	double srodek;

	while (b - a > epsilion) {
		srodek = (a + b) / 2;

		if (f(srodek) == 0.0) return srodek;
		if (f(a) * f(srodek) == 0.0) {
			return b = srodek;
		}
		else {
			a = srodek;
		}
	}

	return (a + b) / 2;
}

//int main() {
//	setlocale(LC_ALL, "");
//
//	double a = -10, b = 10, epsilion = 0.00001;
//
//
//	cout << "Znalezione miejsce zerowe wynosi: ";
//	cout << fixed << setprecision(5) << polowieniePrzedzialow(a, b, epsilion);
//
//	return 0;
//	
//}
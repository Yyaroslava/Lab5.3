#include <iostream> 
#include <iomanip> 
#include <cmath> 

using namespace std;

double y(const double x);
double inner_sum(const double x);
double result(const double f);

int main() {
	double fp, fk, z;
	int n;

	cout << "fp = "; cin >> fp;
	cout << "fk = "; cin >> fk;
	cout << "n  = "; cin >> n;

	cout << fixed;
	cout << (char)0xda << string(10, (char)0xc4) << (char)0xc4 << string(10, (char)0xc4) << (char)0xbf << endl;
	cout << (char)0xb3 <<"        Table        "<<(char) 0xb3 << endl;
	cout << (char)0xc3 << string(10, (char)0xc4) << (char)0xc2 << string(10, (char)0xc4) << (char)0xb4 << endl;
	cout << (char)0xb3 << setw(6) << "f" << setw(5) << (char)0xb3 << setw(6) << "z" << setw(5) << (char)0xb3 <<  endl;
	cout << (char)0xc3 << string(10, (char)0xc4) << (char)0xc5 << string(10, (char)0xc4) << (char)0xb4 << endl;

	double df = (fk - fp) / n;
	double f = fp;

	while (f <= fk) {
		z = result(f);
		cout << (char)0xb3 << setw(10) << f << (char)0xb3 << setw(10) << z << (char)0xb3 << endl;
		f += df;
	}
	cout << (char)0xc0 << string(10, (char)0xc4) << (char)0xc1 << string(10, (char)0xc4) << (char)0xd9 << endl;

	return 0; 
}

double result(const double f) {
	double gg = y(f / 2.) + pow(y(f + 1.), 2) + y(2. * f);
	gg = round(gg * 100000) / 100000;
	return gg;
}
double y(const double x) {
	if (abs(x) >= 1) return (exp(x))/(1+exp(x)+sin(x));
	return inner_sum(x);
}
double inner_sum(const double x) {
	double a = 1;
	double s = a;
	for (int j = 1; j < 9; j++) {
		a *= (-1.) * x * x / (2. * j) / (2. * j - 1);
		s += a;
	}
	return s;
}
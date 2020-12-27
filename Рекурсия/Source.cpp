#include <iostream>

using namespace std;

double Pow(double x, int n) {
	if (n == 0) return 1;

	return x * pow(x, n - 1);
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "14 вариант" << endl
		 << "Ќаписать программу использу¤ рекурсии и не использу¤ циклы" << endl
		 << "¬ычислить величину e с регулируемой точностью" << endl;

	double n = 0;
	while (n <= 0) {
		cout << "¬ведите точность: ";
		cin >> n;
	}
	cout << Pow(1.0f + 1.0f / n, n) << endl;
	return 0;
}
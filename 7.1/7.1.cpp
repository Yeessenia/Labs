#include <iostream>

using namespace std;

double loga(double x)
{
	return log(x);
}

double loga(int x)
{
	return log10(x);
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Вариант 14" << endl
		 << "Написать перегруженные функции и основную программу, которая их вызывает. " << endl
		 << "а) для вычисления натурального логарифма" << endl
		 << "б) для вычисления десятичного логарифма." << "\n\n\n";

	double x = 0;
	while (x <= 0) {
		cout << "Введите число, которое больше нуля: ";
		cin >> x;
	}

	if ((int)x == x) {
		cout << "Десятичный логарифм от " << x << " равен " << loga((int)x);
	}
	else {
		cout << "Натуральный логарифм от " << x << " равен " << loga(x);
	}

	return 0;
}
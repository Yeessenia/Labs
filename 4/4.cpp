#include <iostream>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    cout << "Вариант 14" << endl;
    cout << "1) Сформировать одномерный массив целых чисел, используя датчик случайных чисел." << endl
         << "2) Распечатать полученный массив." << endl
         << "3) Перевернуть массив и, если число элементов массива нечетное, удалить его средний элемент." << endl
         << "4) Добавить в начало массива 3 элемента с значением M[I + 10] - 2." << endl
         << "5) Распечатать полученный массив." << endl;
    int n = 0;
    while (n <= 13) {
        cout << "Введите количество чисел в массиве (должно быть больше 13): ";
        cin >> n;
    }

    cout << "Сгенерированный массив: " << endl;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < n / 2; i++) {
        int val = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = val;
    }

    if (n % 2 == 1) {
        cout << "Число элементов в массиве нечётное: мы должны удалить его средний элемент" << endl;
        for (int i = n / 2; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n -= 1;
    }

    cout << "Массив после переворота его элементов: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    int* b = new int[n + 3];
    for (int i = 0; i < n + 3; i++) {
        if (i < 3)
            b[i] = arr[i + 10] - 2;
        else
            b[i] = arr[i - 3];
    }

    cout << "Результат:" << endl;
    for (int i = 0; i < n + 3; i++) {
        cout << b[i] << "\t";
    }
    return 0;
}
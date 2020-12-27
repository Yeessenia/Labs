#include <iostream>
#include <time.h>

using namespace std;

int** InitMatrix(int size)
{
    int** matrix = new int* [size];
    cout << "Сгенерированный двумерный массив: " << endl;
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10 + 1;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return matrix;
}


void calc(int** m, int size)
{
    int result = 1;
    bool exist = false;
    for (int i = 0; i < size; i++) {
        int val = m[0][i];
        int f = 1;
        for (int j = 0; j < size; j++) {
            if (val < m[j][j]) f = 0;
            if (val < m[j][size - j - 1]) f = 0;
        }
        if (f == 1) {
            exist = true;
            cout << i << " столбец больше всех элементов на главной и побочной диагоналях" << endl;
            for (int j = 0; j < size; j++) {
                result *= m[j][i];
            }
        }
    }
    if (exist == false) {
        cout << "В данной матрице нет элементов, удовлетворяющих условию" << endl;
    }
    else {
        cout << "Произведение равно " << result;
    }
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));

    cout << "Вариант 14" << endl;
    cout << "Вычислить произведение всех столбцов массива, у" << endl
         << "которых первый элемент больше элементов расположенных" << endl
         << "на главной и побочной диагонали." << endl;

    int n = 0;
    while (n <= 1) {
        cout << "Введите размер двумерного массива: ";
        cin >> n;
    }
    
    int** m = InitMatrix(n);
    calc(m, n);
    return 0;
}
#include <iostream>
#include <time.h>

using namespace std;

int* create(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}
	cout << endl;
	return arr;
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void obmen(int* arr, int size) {
	cout << endl << "—ортировка обменом" << endl;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	print(arr, size);
}

void selection(int* arr, int size) {
	cout << endl << "—ортировка вставками" << endl;
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] > arr[min])
				min = j;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	print(arr, size);
}

void vstavka(int* arr, int size) {
	cout << endl << "—ортировка вставками" << endl;
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
	print(arr, size);
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	int n = 0;
	while (n <= 0) {
		cout << "¬ведите размер массива: ";
		cin >> n;
	}
	cout << "»сходный массив: " << endl;
	int* arr = create(n);
	int* arr2 = new int[n];
	int* arr3 = new int[n];
	for (int i = 0; i < n; i++) {
		arr2[i] = arr[i];
		arr3[i] = arr[i];
	}
	obmen(arr, n);
	selection(arr2, n);
	vstavka(arr3, n);
	return 0;
}
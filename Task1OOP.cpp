// task1 Иванов Д.И. 4 вариант
#include <iostream>
#include <vector>
using namespace std;

void printMatrix(double** M, unsigned int n, unsigned int m) {
	cout << "\n";
	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < m; ++j) {
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	unsigned int n, m;
	// Считываем размеры матриц.
	cin >> n >> m;

	// Выделение памяти
	double** A = new double* [n];
	double** C = new double* [n];
	double** B = new double* [n];
	for (unsigned int i = 0; i < n; ++i) {
		A[i] = new double[m];
		C[i] = new double[m];
		B[i] = new double[m];
	}

	// Заполняем матрицу А с консоли
	for (unsigned int i = 0; i < n; ++i)
		for (unsigned int j = 0; j < m; ++j)
			cin >> A[i][j];


	// Заполняем матрицу С с консоли
	for (unsigned int i = 0; i < n; ++i)
		for (unsigned int j = 0; j < m; ++j)
			cin >> C[i][j];

	// Первое задание
	{
		double res = 0;
		for (unsigned int i = 0; i < n; ++i)
			for (unsigned int j = 0; j < m; ++j)
				res += A[i][j];

		cout << "result 1: " << res << "\n";
	}

	//Второе задание
	{
		double res = 1;
		for (unsigned int i = 0; i < n; ++i) {
			for (unsigned int j = 0; j < m; ++j) {
				if (A[i][j] != 0) {
					res *= A[i][j];
				}
			}
		}

		cout << "result 2: " << res << "\n";
	}

	// Третье задание
	{
		double max1 = A[0][0], max2 = A[0][0];
		for (unsigned int i = 0; i < n; ++i) {
			for (unsigned int j = 0; j < m; ++j) {
				if (max1 < A[i][j]) {
					max2 = max1;
					max1 = A[i][j];
				}
			}
		}

		cout << "result 3: " << max1 << "  " << max2 << "\n";
	}

	// Четвертое задание
	{
		// Показывает матрицы 
		printMatrix(A, n, m);
		printMatrix(C, n, m);

		for (unsigned int i = 0; i < n; ++i) {
			for (unsigned int j = 0; j < m; ++j) {
				B[i][j] = 2 * A[i][j] + C[i][j] / 3;
			}
		}

		// Для просмотра результата
		printMatrix(B, n, m);
	}


	// Освобождение памяти
	for (unsigned int i = 0; i < n; ++i) {
		delete[] A[i];
		delete[] C[i];
		delete[] B[i];
	}
	delete[] A;
	delete[] C;
	delete[] B;

	return 0;
}
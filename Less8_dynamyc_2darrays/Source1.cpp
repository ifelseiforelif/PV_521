#include <iostream>
using namespace std;

size_t** create_array(size_t rows, int cols)
{
	size_t** arr = new size_t* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new size_t[cols];
	}
	return arr;
}

template <typename T>
void delete_array(T** arr, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void fill_array(size_t** arr, int rows, int cols)
{
	size_t k = 2;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr[i][j] = k;
			k*=2;
		}
	}
}

void show_array(int** arr, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
#pragma region Означення
/*
змінна
константа
вираз
перетворення типів
типи даних
масиви (індекс)
функції
покажчики (аріфметика покажчиків)
посилання
*/
#pragma endregion


int main()
{
	int rows, cols;
	cout << "Rows: ";
	cin >> rows;
	int** arr = new int* [rows];
	int* arr_cols = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		cout << "cols for [" << i << "] : ";
		cin >> cols;
		arr_cols[i] = cols;
;		arr[i] = new int[cols];
	}
	srand(time(0));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < arr_cols[i]; j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	delete_array(arr, rows);
	return 0;
}
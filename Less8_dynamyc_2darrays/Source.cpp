#include <iostream>
using namespace std;


int main()
{
	int rows;
	cin >> rows;
	int cols;
	cin >> cols;
	int** array2d = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		array2d[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array2d[i][j] = 3;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array2d[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < rows; i++)
	{
		delete array2d[i];
	}
	delete[] array2d;
	return 0;
}
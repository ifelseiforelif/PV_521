#include <iostream>
using namespace std;

int main()
{
	//const unsigned int SIZE = 10;
	//int arr[SIZE]{};
	//srand(time(0));
	//int a = 0, b = 100;
	//for (size_t i = 0; i < SIZE; i++)
	//{
	//	arr[i]= rand()%(b-a)+a;
	//}
	//for (size_t i = 0; i < SIZE; i++)
	//{
	//	cout << arr[i] << ' ';
	//}
	//
	////cout << sizeof(arr);

	//const unsigned int SIZE = 12;
	//int arr[SIZE]{};
	//
	//int min_ind = 0;
	//int max_ind = 0;

	//for (int i = 0; i < SIZE; i++) {
	//	cin >> arr[i];
	//}
	//int max = arr[0];
	//int min = arr[0];
	//for (int i = 0; i < SIZE; i++) {
	//	if (arr[i] > max) {
	//		max = arr[i];
	//		max_ind = i;
	//	}
	//	if (arr[i] < min)
	//	{
	//		min = arr[i];
	//		min_ind = i;
	//	}
	//}
	//cout << "\nMax ind is: " << max_ind << endl;
	//cout << "Min ind is: " << min_ind << endl;


	//double a, b;
	//cin >> a >> b;
	//double res = 1;
	//if (b < 0)
	//{
	//	for (int i = 0; i < abs(b); i++)
	//	{
	//		res *= a;
	//	}
	//	res = 1 / res;
	//}
	//else
	//{
	//	for (int i = 0; i < b; i++)
	//	{
	//		res *= a;
	//	}
	//}
	//
	//cout << res;

	/*int arr[5] = { true,3.5,4.6f,5l,6ll };
	arr[2] = 45;
	cout << arr << endl;
	cout << arr + 1 << endl;*/

	//const int ROWS = 4; //
	//const int COLS = 3;
	//int arr2d[ROWS][COLS] = {4,3,4,6,7,8,9,2,4,5,6,7};
	/*for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << "Enter element [" << i << "][" << j << "] : ";
			cin >> arr2d[i][j];
		}
	}*/
	/*int arr2d[ROWS][COLS] = {
		{1,3,7},
		{4,2,5},
		{16,-3,21},
		{11,0,15}
	};*/
	/*for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr2d[i][j] << ' ';
		}
		cout << endl;
	}*/


	// Бінарний пошук

	/*const int N = 15;
	int arr[N] = { -10,-3,4,7,9,9,12,14,17,29,34,36,37,39,45};
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	int search;
	cout << "Enter value: ";
	cin >> search;
	int left = 0, right = N - 1;
	bool isSuccess = false;
	while (left <= right)
	{
		int indexMiddle = (left + right) / 2;
		if (arr[indexMiddle] == search)
		{
			cout << indexMiddle;
			isSuccess = true;
			break;
		}
		else if (arr[indexMiddle] < search)
		{
			left = indexMiddle + 1;
		}
		else
		{
			right = indexMiddle - 1;
		}
	}
	if (isSuccess == false)
	{
		cout << "Not found!";
	}*/
//const int ROWS = 3;
//const int COLS = 4;
//int arr2d[ROWS][COLS] = {
//	{10, 12, 13, 16},
//	{14, 15, 16, 18},
//	{17, 18, 10, 13},
//};
//
//int arr2dSum[ROWS][COLS]{};
//
//int sumRows = 0;
//int sumCols;
//
//for (int i = 0; i < ROWS; i++) {
//	for (int j = 0; j < COLS; j++) {
//		sumRows += arr2d[i][j];
//		cout << arr2d[i][j] << ' ';
//		if (j == COLS - 1) {
//			cout << "|" << ' ' << sumRows << endl;
//			sumRows = 0;
//		}
//		if (i == ROWS - 1 && j == COLS - 1) {
//			cout << "------------" << endl;
//		}
		/*if (arr2d[j][i] > 0) {
			sumCols += arr2d[j][i];
		}*/
//	}
//	
//	cout << endl;
//}
//
//
//for (int i = 0; i < COLS; i++)
//{
//	sumCols = 0;
//	for (int j = 0; j < ROWS; j++)
//	{
//		sumCols += arr2d[j][i];
//	}
//	cout << sumCols << ' ';
//	}
//cout << "| ";
	
	
	return 0;
}
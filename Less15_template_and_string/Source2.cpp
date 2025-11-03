#include <iostream>
using namespace std;
#include "Point.h"
#include "MyArray.h"

int main()
{
	const size_t SIZE = 5;
	int arr[SIZE] = { 5,7,3,5,2 };
	MyArray<int> myarr {arr,SIZE};
	cout << myarr;
	Point parr[SIZE] = { {4,5}, {6,4},{7,2},{-1,0}, {5,8} };
	MyArray<Point> myarr2{ parr, SIZE };
	cout << myarr2;

	return 0;
}
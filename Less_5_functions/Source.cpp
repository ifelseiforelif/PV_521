#include <iostream>
#include "Func.h";
using namespace std;


/*void mysum(int a, int b);

void change(int arr[])
{
	arr[0] = 8;
}

int get_cube(int n)
{
	return pow(n, 3);
}*/

//int get_max(int a, int b)
//{
//	/*return a > b ? a : b;*/
//	if (a > b)
//		return a;
//	return b;
//
//}
/*
* Написати функцію, яка приймає масив,
* та повертає кількість 0 елементів в даному 
* масиві
*/

//Перевантаження функцій (поліморфізм)

//int get_sum(int a, int b)
//{
//	return a + b;
//}

//int get_sum(int a, int b, int c)
//{
//	return a + b + c;
//}
//double get_sum(double a, double b)
//{
//	return a + b;
//}	

//void sum(int a, int b)
//{
//	cout << a + b << endl;
//}
//void sum(double a, double b)
//{
//	cout << a + b << endl;
//}
//void sum(short a, short b)
//{
//	cout << a + b << endl;
//}



//Статичні змінні
//void increment()
//{
//	static int i = 0;
//	i++;
//	cout << i << endl;
//}


void change(int& n)
{
	++n;
}

int main()
{
	int n = 9;
	int& refN = n;
	int n2 = 8;
	refN = n2;



	change(refN);
	cout << n << endl;



	//cout << factorial(3);
	/*increment();
	increment();
	increment();*/


	/*const int N = 5;
	int arr[N] = { 5,3,9,2,6 };
	double arr_d[N] = { 5.6,3.7,9.3,2.2,6.1 };
	show_array(arr, N);
	show_array(arr_d, N);*/



	/*cout << get_sum(2, 3) << endl;
	cout << get_sum(2.4, 3) << endl;*/
	/*cout << get_sum(2.5, 3.5) << endl;
	cout << get_sum(2, 3, 4) << endl;*/
	
	
	
	return 0;
}


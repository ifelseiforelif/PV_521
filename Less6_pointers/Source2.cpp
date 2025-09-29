#include <iostream>
using namespace std;

int get_sum_array(const  int* const arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

void show_elements_by_3(const int* const arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 3 == 0)
		{
			cout << arr[i] << ' ';
		}
	}
}
int main()
{
	/*
	Створіть функцію, яка виводить у консоль всі
	елементи масива, які кратні 3
	*/
	int n = 5;
	int* arr = new int[n] {8,6,8,9,12};
	show_elements_by_3(arr, n);
	//cout << get_sum_array(arr, n);
	delete[] arr;
	arr = nullptr;
	//Покажчик на константу,
	//Константний покажчик
	//Константний покажчик на константу
	//int n = 20;
	//int* const ptrN = &n; //Константний покажчик
	//cout << *ptrN;
	//int n2 = 30;
	//ptrN = &n2; //Error

	//int n = 20;
	//const int* ptr; //покажчик на константу
	//ptr = &n;
	//cout << ptr;
	//int n = 30;
	//const int* const ptrN = &n;
	//*ptrN = 20; //Error
	//ptrN = nullptr; //Error

	
	/*int n2 = 30;
	ptr = &n2;*/




	return 0;
}
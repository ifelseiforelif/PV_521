#include <iostream>
using namespace std;
//Покажчики (pointers)
/*
1) Написати функцію, яка створює масив у heap на n елементів
(create_array)
2) Написати функцію, яка очищує heap
(clear_array)
3) Написати функцію,яка заповнює масив (init_array)
4) Написати функцію, яка виводить масив (приймає покажчик
на масив та розмір) (show_array)
5) Написати функцію, яка додає елемент у кінець масива
(push_item)
6) Написати функцію, яка додає елемент на задану позицію(index)
(insert_item)
7) Написати функцію, яка видаляє елемент з кінця масива
(remove_item)
*/

//int* create_array(const int n)
//{
//	if (n > 0) 
//	{
//		return new int[n];
//	}
//	return nullptr;
//}
//void clear_array(int* arr)
//{
//	if (arr != nullptr)
//		delete[] arr;
//}

void create_array(int*& arr, int size)
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
	if (size > 0)
	{
		arr = new int[size] {};
	}

}

//Написати функцію, яка додає елемент у кінець масива
void push_item(int*& arr, int* n, int value)
{
	int* new_arr = new int[*n + 1];
	for (int i = 0; i < *n; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[*n] = value;
	(*n)++;
	delete[] arr;
	arr = new_arr;
}

void change(int* arr, int size, int& sum, int& mul)
{
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		mul *= arr[i];
	}
}
int main()
{
	int n = 4;
	int* arr = new int[n] {5, 3, 9, 1};
	int* address1 = &arr[0];
	int* address2 = &arr[n];
	cout << address2 - address1;
	delete[] arr;


	//Посилання (reference )
	//int* ptr = new int(10);
	//ptr++;
	//cout << ptr << endl;
	////ptr--;

	//int n = 10;
	//int& refN = n;
	//refN/=10;
	/*ptr += 2;
	ptr -= 3;*/


	/*delete ptr;*/


	/*const int N = 5;
	int arr[N] = { 5,3,2,5,2 };
	int s = 0, m = 1;
	change(arr, N, s, m);
	cout << "S: " << s << endl;
	cout << "M: " << m << endl;*/
	/*int n = 10;
	int& refN = n;
	int t = 20;
	refN = t;
	cout << n;
	n = 2;
	refN = 9;*/




	/*int n = 5;
	int* arr = new int[n] {6,8,9,3,5};
	push_item(arr, &n, 15);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}*/



	/*int* arr =nullptr;
	int size;
	cin >> size;
	arr = create_array(size);

	clear_array(arr);*/

	return 0;
}


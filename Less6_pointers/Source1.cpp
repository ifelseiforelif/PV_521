#include <iostream>
using namespace std;
//DRY 
//Покажчики на функції

void func1()
{
	cout << "I am func1()...\n";
}
int func2(int a)
{
	return a * a;
}
void show_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void fill_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void bubble_sort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void stupid_sort(int* arr, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
			i = 0;
		}
		else
		{
			i++;
		}
	}
}



void sorting(int* arr, int size, void(*algorithm)(int*, int))
{
	algorithm(arr, size);
}

int main()
{
	srand(time(0));
		const int N = 4;
		int* numbers = nullptr;
		void (*arr[N])(int*, int) = { 
			fill_array, show_array, bubble_sort, show_array 
		};
		for (int i = 0; i < N; i++)
		{
			arr[i](numbers, 10);
		}


	/*const int N = 5;
	int arr[N]{ 3,1,5,2,-90 };
	cout << "1 - bubble_sort, 2 - stupid_sort : ";
	int choice;
	cin >> choice;
	void (*ptr)(int*, int) = nullptr;
	switch (choice)
	{
	case 1:
		ptr = bubble_sort;
		break;
	case 2:
		ptr = stupid_sort;
		break;
	default:
		cout << "Error";
	}
	if (ptr != nullptr)
	{
		sorting(arr, N, ptr);
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << ' ';
		}
	}
	*/

	//cout << func1; //address
	/*void (*ptrFunc1)() = func1;
	int (*ptrFunc2)(int) = func2;
	ptrFunc1();
	cout << ptrFunc2(19);*/
	return 0;
}
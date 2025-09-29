#include <iostream>
#include <cmath>

using namespace std;
int main()
{
#pragma region Switch

	//int n;
	//int n2 = 19.5;
	////ун≥версальна ≥н≥ц≥ал≥зац≥€
	//int n3{ 12 };
	//int n4 = { 13 };

	//const double PI = 3.14;

	//int a = 11.4f;
	////cout << a % 2;

	///*
	//bool - 1 байт
	//short - 2 байт
	//long long - 8 байт
	//float - 4 байта
	//char - 1 байт
	//long - 4 байта
	//int - 2 or 4
	//*/



	///*ќператор switch*/
	//short day;
	//cout << "Enter day: (1-7): ";
	//cin >> day;
	//switch (day)
	//{
	//case 1:
	//	cout << "Monday\n";
	//	break;


	//case 2:
	//	cout << "Tuesday\n";

	//	break;
	//case 3:
	//	cout << "Wednesday\n";
	//	break;
	//case 4:
	//	cout << "Thursday\n";
	//	break;
	//case 5:
	//	cout << "Friday\n";
	//case 6:
	//	cout << "Saturday\n";
	//case 7:
	//	cout << "Sunday\n";
	//	break;
	//default:
	//	cout << "Error";
	//}
	//«апитати у користувача номер м≥с€ц€ та 
	// вивести назву м≥с€ца (використати switch)
	//також вивести пору року

#pragma endregion

	//÷икли
	/*1) ÷икл з предумовою while

	int i = 10;
	while (i != -1)
	{
		cout << i << ' ';
		if (i == 5)
		{
			break;
		}
	i--;
}*/

/*2) ÷икл з постумовою do while
* int n;
do
{
	cin >> n;
	cout << n * n << endl;
}
while (n!=0);
3) ÷икл з параметрами for
*/

//double x = 25.0;
//double y = (1 + 0.5 * sqrt(x)) / (pow(x, 3) + 10);
//cout << y;
//int n1, n2; //2 10  10 2
//cout << "Enter n1: ";
//cin >> n1;
//cout << "Enter n2: ";
//cin >> n2;
//if (n1 > n2)
//{
//	int temp = n1;
//	n1 = n2;
//	n2 = temp;
//}
//int i = n1;
//while (i <= n2)
//{
//	if (i % 2 == 0)
//	{
//		cout << i << " ";
//	}
//	i++;
//}
//int i;
//for (i=0;i<=10;i++)
//{
//	cout << i << " ";
//	//т≥ло цикла
//}
//cout << i;

//int k = 1, n=2, m=4;
//for (size_t i = 0; i < n; i++)
//{
//	for (size_t j = 0; j < m; j++)
//	{
//		cout << k << " ";
//		k++;
//	}
//	cout << endl;
//}
//for (char i = 'A'; i <= 'Z'; ++i)
//{
//	cout << i << " ";
//	}
//enum - тип даних
enum Menu
{
	EXIT,
	ADD=3,
	REMOVE,
	SHOW
};
int choice;
cin >> choice;
switch (choice)
{
case EXIT:
	break;
case ADD:
	break;
}
	system("pause");
	return 0;
}

/*
enum
loops
*/
/*
підключили бібліотеку ввода/вивода
діректива препроцесора
*/
#include <iostream>
using namespace std; //підключаємо простір імен std - standart

//описали функцію main - крапка входа у програму
int main()
{
#pragma region lesson
	//type name;
	//type name=value;
	// int (2 or 4 byte) 
	// short (2 byte)
	// long (4 byte)
	//long long (8 byte)
	//char (1 byte) 'A'

	//float - (4 byte)
	//double - (8 byte)

	//bool - (1 byte) true/false
	/*
	ctrl K C
	ctrl K U
	*/
	//unsigned short age = 10;
	//bool isSuccess = true;
	//float price = 9.5f;
	//double count = 10.0;
	//char val = 'A';
	//cout << "\"Hello World\"";
	// + - = == > < >= <= != % += -= /= *=
	//or || , and &&


	//cout << "Hello World!! " << "Bye..."; //cout - console out

#pragma endregion

	const int DAYS_OF_WEEK = 7;
	double const PI = 3.14;
	short age;
	cout << "Enter age: ";
	cin >> age; //cin - console input
	cout << "Your age is " << age;
	cout << endl;
	system("pause");
	return 0;
}
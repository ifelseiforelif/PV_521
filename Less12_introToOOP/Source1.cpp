#include <iostream>
using namespace std;
#include "Rectangle.h";
#include "Human.h";

//Деструктор, статичні поля, робота з heap
//TODO: const_cast

int main()
{
	int size;
	cout << "Enter size: ";
	cin >> size;
	Human* listOfHuman = new Human[size];
	for (int i = 0; i < size; i++)
	{
		char name[30];
		cout << "Enter name: ";
		cin >> name;
		unsigned short age;
		cout << "Enter age: ";
		cin >> age;
		cout << "Enter INN: ";
		unsigned int inn;
		cin >> inn;
		listOfHuman[i].setName(name);
		listOfHuman[i].setAge(age);
	}
	for (int i = 0; i < size; i++)
	{
		listOfHuman[i].print();
	}
	delete[] listOfHuman;
	listOfHuman = nullptr;
	
	return 0;
}
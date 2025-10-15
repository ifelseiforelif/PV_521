#include <iostream>
using namespace std;
#include "Rectangle.h";
#include "Human.h";

//Деструктор, статичні поля, робота з heap


int main()
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
	Human h1{ name, age, inn };
	cout << h1.getName() << endl;
	cout << h1.getAge() << endl;
	cout << h1.getINN() << endl;
	h1.~Human();

	Human* h2 = new Human(name, age, inn);
	delete h2;

	
	return 0;
}
#include <iostream>
using namespace std;
#include "Rectangle.h";
#include "Human.h";

//TODO: const_cast
//Статичні поля та методи


class Point
{
private:
	int x;
	int y;
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
		cout << "THIS from contructor: " << this << endl;
		this->show();
	}
	void show()
	{
		cout << (*this).x <<endl<< this->y<< endl;
	}
};


class Square
{
private:
	int x;
	int y;
	int size;
public:
	Square(int x1, int y1, int size1)
	{
		this->x = x1;
		this->y = y1;
		this->size = size1;
	}
	void showSquare()
	{
		cout << "Address: " << this << endl;
		cout << sizeof(this) << endl;
		cout << (*this).x << ' ' << this->y << endl;
	}
	
};

int main()
{

	/*Point p{ 3,4 };
	cout << "Address p: " << &p << endl;
	p.show();
	Point p2{7,8};
	cout << "Address p2: " << &p2 << endl;
	p2.show();*/

	/*Human h1;
	Human h2;
	Human h3;
	Human h4;
	Human* h5 = new Human();
	Human::getCounter();
	cout << Human::getCounter() << endl;
	h3.getCounter();
	return 0;
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
	*/
	return 0;
}
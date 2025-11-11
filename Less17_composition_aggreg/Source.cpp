#include <iostream>
using namespace std;

class Hat
{
private:
	string color;
public:
	friend class Human;
	Hat() = default;
	Hat(string c) : color{ c } {}
	string getColor() const { return color; }
};
class Head
{
private:
	string hairColor;
public:
	Head() : hairColor{ "Black" } {}
	Head(string hc) : hairColor{ hc } {}
};
class Human
{
private:
	string name;
	Head head; //композиція
	Hat* hat; //агрегація
public:
	friend class Hat;
	Human() : name{ "NoName" }, hat{ nullptr } {}
	Human(string n, Hat* h, string color) : head{color}, name { n }, hat{ h } {}
	void show() const
	{
		cout << typeid(this).name() << endl;
		cout << "Name: " << name << endl;
		if (hat)
			cout << "Has a hat." << hat->getColor() << endl;
		else
			cout << "No hat." << endl;
	}


};
class A
{
	class B {
	};
};

int main()
{
	//Взаємодія між класами
	/*
	1) inner classes (вкладені класи)
	2) friend classes (дружні класи)
	3) composition
	4) aggregation
	5) inheritance (успадкування) 
	*/

	Hat hat1("Red"); //агрегація
	Human* human1 = new Human("Bob", &hat1);
	human1->show();
	delete human1;
	Human* human2 = new Human("Alex", &hat1);
	human2->show();
	delete human2;

	return 0;
}
// Room Wall Firniture реалізувати ці класи і 
// продемонструвати композицію і агрегацію між ними
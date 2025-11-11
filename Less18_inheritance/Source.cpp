#include <iostream>
using namespace std;

/*
Реалізуйте клас Animal (name, weight) makeSound(){"Some sound"}
та похідний від нього клас Dog (breed, age)
та похідний класс Cat (color).
Додайте метод makeSound() для кожного класу,
*/

class Human //Base class
{
protected:
	string name;
	unsigned short age;
public:
	Human() : name("NoName"), age(0) {}
	Human(string n, unsigned short a) : name(n), age(a) {}
	void displayInfo()
	{
		cout << "Name: " << name << ", Age: " << age << endl;
	}
	~Human() 
	{
		cout << "I am destructor of Human class" << endl;
	}
};
class Student : public Human //Derived class
{
private:
	string group;
	float averageMark;
public:
	Student(string n, unsigned short a, string gr, float average) :Human(n, a)
	{
		this->group = gr;
		this->averageMark = average;
	}
	void displayInfo()
	{
		Human::displayInfo(); //Accessing base class method
		cout << "Group: " << group << ", Average Mark: " << averageMark << endl;
	}
	~Student()
			{
		cout << "I am destructor of Student class" << endl;
	}
};

int main()
{
	Student person1{"Alex", 23, "PV521", 10.7}; //Default constructor
	person1.displayInfo(); //Accessing base class method
	return 0;
}
#include <iostream>
using namespace std;

class Transport //abstract class
{
protected:
	string color;
	string model;
public:
	Transport(string c, string m) : color(c), model(m) {}
	virtual void move() = 0;
	virtual ~Transport() {};
};

class Car : public Transport
{
public:
	Car(string c, string m) : Transport(c, m) {}
	void move() override 
	{
		cout << "Car is moving" << endl;
	}
	~Car() { cout << "I am destruct Car\n"; }
};
class Bike : public Transport
{
public:
	Bike(string c, string m) : Transport(c, m) {}
	void move() override
	{
		cout << "Bike is moving" << endl;
	}
};

class Player
{
	string name;
public: 
	Player(string n) : name(n) {}
	void drive(Transport* tr)
	{
		tr->move();
	}
};


class Product
{
	int counter;
public: 
	Product(int c) : counter(c) {}
	int getCounter() { return counter; }	
	void setCounter(int c) { counter = c; }	
};


int main()
{

	Transport* t1 = new Car("Red", "Toyota");
	delete t1;

	/*Transport t = Transport("Blue", "Generic");
	Player p1("Bob");
	p1.drive(&t);
	Car c = Car("Red", "Toyota");
	p1.drive(&c);
	Bike b = Bike("Green", "Yamaha");
	p1.drive(&b);*/
	return 0;
}



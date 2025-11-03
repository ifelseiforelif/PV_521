#include <iostream>
using namespace std;
//Шаблонні класи

template <typename T>
class Number
{
private:
	T number1;
public:
	Number() = default;
	Number(T number) :number{ number } {}
	T getNumber() { return number; }
	void setNumber(T number) { this->number = number; }
};

int main()
{
	Number<int> n1;
	n1.setNumber(10);
	cout << n1.getNumber();
	cout << endl;
	Number<double> n2;
	n2.setNumber(10.5);
	cout << n2.getNumber();

	return 0;
}

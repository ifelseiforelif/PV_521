//Механіз Перевантаження операторів
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point() = default;
	explicit Point(int x1)
	{
		this->x = x1;
		this->y = 0;
	}
	Point(int x, int y) :x{ x }, y{ y } {}
	int getX() const
	{
		return this->x;
	}
	int getY() const
	{
		return this->y;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void showPoint() const
	{
		cout << this->getX() << endl << this->getY() << endl;
	}
	Point& operator!=(Point& obj)
	{
		Point p{ this->x + obj.x, this->y + obj.y };
		return p;
	}
	bool operator>(Point& obj)
	{
		if (this->x > obj.x && this->y > obj.y)
			return true;
		return false;
	}
	Point& operator+(int n)
	{
		Point p{ this->x + n, this->y + n };
		return p;
	}
	operator int()
	{
		return this->x + this->y;
	}
	operator bool()
	{
		return (this->x != 0 && this->y != 0) ? true : false;
	}
	Point& operator-()
	{
		Point p{ -this->x, -this->y };
		return p;
	}

	Point& operator++() 
	{
		this->x++;
		this->y++;
		return *this;
	}//префіксна форма
	Point& operator++(int) 
	{ 
		Point p = *this;
		this->x++;
		this->y++;
		return p;
	}//постфіксна

	Point& operator=(const Point& obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		return *this;
	}
};


Point& operator+(int n, Point& obj)
{
	Point p{ obj.getX() + n, obj.getY() + n };
	return p;
}
//++ --, перетворення типів

class MyArray
{
private:
	int* arr=nullptr;
	size_t size = 0;
public:
	MyArray(int* arr, size_t size)
	{
		if (size > 0 && arr != nullptr)
		{
			this->size = size;
			this->arr = new int[size];
			for (int i = 0; i < size; i++)
			{
				this->arr[i] = arr[i];
			}
		}
	}
	MyArray(const MyArray& obj) = delete;
	~MyArray()
	{
		if (arr != nullptr)
			delete[] arr;
	}
	int operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return arr[index];
		}
		return -1;
	}
};


ostream& operator<<(ostream& out, const Point& obj)
{
	out << "X: " << obj.getX() << " Y: " << obj.getY();
	return out;
}
istream& operator>>(istream& in, Point& obj)
{
	int x, y;
	cout << "Enter x: ";
	in >> x;
	obj.setX(x);
	cout << "Enter y: ";
	in >> y;
	obj.setY(y);
	return in;
}

//Point& operator-(const Point& p)
//{
//	Point p1{ -p.getX(), -p.getY() };
//	return p1;
//}

/*
створіть клас Number
в ньому поле типа int
зробіть перевантаження операторів
++, --, cout , cin, Number + число, число - Number
*/
int main()
{
	//деструктор, КК, оператор =

	Point p{ 3,4 };
	Point p2{ 6,8 };
	//Point p2 = p;
	p = p2;
	cout << p;
	

	
	//Point p{ 14,10 };
	//cout << ++p; //14 10
	//cout << p; //15 11
	/*
	cin >> p;
	cout << p;
	cout << static_cast<int>(p);*/
	/*int arr[] = { 4,5,6,9 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	MyArray marr1 = { arr, size };
	for (int i = 0; i < size; i++)
	{
		cout << marr1[i] << " ";
	}*/
//	Point p1{ 12,15 };
//	Point p2{ 7,8 };
//	Point p4 = p1 + 10; //Point+int
//	Point p5 = 10 + p1;
//	p4.showPoint();
//
//	if (p1 > p2)
//	{
//		cout << "p1>p2\n";
//	}
//	Point p3 = p1 + p2;
//	//Point p3 = p1.operator+(p2);
//	p3.showPoint();
	return 0;
}
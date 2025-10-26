#include <iostream>
using namespace std;


class Point
{
private:
	int x;
	int y;
public:
	Point() = default;
	explicit Point(int x)
	{
		this->x = x;
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
	Point& operator+(Point& obj)
	{
		Point p{this->x + obj.x, this->y+obj.y };
		return p;
	}
};
int main()
{
	Point p1{ 4,5 };
	Point p2{ 7,8 };
	Point p3 = p1 + p2;
	p3.showPoint();
	return 0;
}
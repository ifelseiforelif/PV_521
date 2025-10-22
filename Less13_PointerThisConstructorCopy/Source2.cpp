#include <iostream>
using namespace std;



/*
����������� ��������� (��):
����� ���� �� ��.
³� ������ ���������� ������� ���������(����� � �����).
���� �������� ClassName(const ClassName& obj);
���� ����� ���� ����� ���� ���������, �� ��� ��������
���������� �� � �� ���� ��� �� ��������.

���� ����� ���� ����� � ��������� �����
���������� �� ����, � ������� � ����� ������� ���������
(��������� ���, �� ����������� � HEAP)
������ ���� ������� ��� ������ �����������,
���� ������� ��'���� ����� ���� �����, ��� �������� �� 
1 ������ ������ ���'��.
��������� ������ - ������ �����, � ���� ����������
�������� ���� ��'���� (����� �������� ���� ����)
implicit - �� ����
����: explicit(����) ������������

*/

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
	void setX(int x)
	{
		this->x = x;
	}
	void showPoint() const
	{
		cout << this->x << endl << this->y << endl;
	}
};

void change(Point p , int value)
{
	p.setX(value);
	p.showPoint();
}
Point createPoint(int value)
{
	//Point p{ value + 2 };
	return value + 2;
}

int main()
{
	Point p{ 3,4 };
	//change(10, 20);
	change(p, 20); //int -> Point

	return 0;
}
#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:
	Point() = default;
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
};

inline std::ostream& operator<<(std::ostream& out, const Point& obj)
{
	out << "x: " << obj.getX() << " y: " << obj.getY() << std::endl;
	return out;
}



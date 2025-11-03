#include "Point.h"
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}
int Point::getX() const
{
	return this->x;
}
int Point::getY() const
{
	return this->y;
}

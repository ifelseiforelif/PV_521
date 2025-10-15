#include <iostream>
using namespace std;
#include "Rectangle.h"

Rectangle::Rectangle() :name{'A'}
{
    x = 0;
    y = 0;
    height = 0;
    width = 0;
}

Rectangle::Rectangle(int x1, int y1, int h, int w, char n) :name{n}
{
    x = x1;
    y = y1;
    height = (h > 0) ? h : 0;
    width = (w > 0) ? w : 0;
}

Rectangle::Rectangle(int x1, int y1, int h, int w) :name{'A'}
{
    x = x1;
    y = y1;
    height = (h > 0) ? h : 0;
    width = (w > 0) ? w:0;
}
   

int Rectangle::getX()
{
    return x;
}

int Rectangle::getY()
{
    return y;
}

int Rectangle::getHeight()
{
    return height;
}

int Rectangle::getWidth()
{
    return width;
}

void Rectangle::setX(int x1)
{
    x = x1;
}

void Rectangle::setY(int y1)
{
    y = y1;
}

void Rectangle::setHeight(int h)
{
    if (h > 0)
    {
        height = h;
    }
}

void Rectangle::setWidth(int w)
{
    if (w > 0)
    {
        width = w;
    }
}

void Rectangle::showRectangle()
{
    cout << "=========================\n";
    cout << "x: " << getX() << endl;
    cout << "y: " << getY() << endl;
    cout << "width: " << getWidth() << endl;
    cout << "height: " << getHeight() << endl;
    cout << "=========================\n";
}

#include <iostream>
using namespace std;
#include "Rectangle.h";

int main()
{
	Rectangle rect;
	Rectangle rect2{ 3,4,20,30 };
	rect.setHeight(30);
	rect.setWidth(50);
	rect.showRectangle();
	rect2.showRectangle();
	return 0;
}
#pragma once
class Rectangle
{
private:
	const char name;
	int x;
	int y;
	int height;
	int width;

public:
	Rectangle();
	Rectangle(int x1, int y1, int h, int w, char n);
	Rectangle(int x1, int y1, int h, int w);
	//геттери(акссесори) та сеттери(модіфікатори)
	int getX();
	int getY();
	int getHeight();
	int getWidth();
	void setX(int x1);
	void setY(int y1);
	void setHeight(int h);
	void setWidth(int w);
	void showRectangle();


};


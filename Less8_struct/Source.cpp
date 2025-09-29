#include <iostream>
using namespace std;

/*
Тема: Структури
*/

struct User //Pascal case
{
	char login[10];
	char name[20];
	unsigned short age;
	bool isActive;
};

struct Point
{
	int x; //поля структури
	int y;
};

void show_point(Point& p)
{
	cout << "Point. x:" << p.x << " y: " << p.y << endl;
}
void fill_point(Point& p)
{
	cout << "Enter x:";
	cin >> p.x;
	cout << "Enter y:";
	cin >> p.y;
}
Point& create_point(int x1, int y1)
{
	Point p = { x1,y1 };
	return p;
}

int main()
{
	/*
	Створити динамічний масив типа Fraction
	Розмір масива запитати у користувача.
	Заповнити дробі та вивести їх у консоль.

	*/
	int size;
	cout << "Enter size: ";
	cin >> size;
	Point* points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		fill_point(points[i]);
	}

	for (size_t i = 0; i < size; i++)
	{
		show_point(points[i]);
	}
	delete[] points;

	/*Point* obj = new Point();
	obj->x = 10;
	obj->y = 20;
	cout << "X:" << obj->x << " " << obj->y;
	delete obj;*/
	//cout << (*obj).x;



	/*Point p = create_point(5, 6);
	show_point(p);

	const int N = 3;
	Point points[N]{};
	for (int i = 0; i < N; i++)
	{
		fill_point(points[i]);
		show_point(points[i]);
	}*/

	//Point p1 = {}; // створення об'єкта структури
	//fill_point(p1);
	//show_point(p1);
	//Point p2 = {}; // створення об'єкта структури
	//fill_point(p2);
	//show_point(p2);
	//Point p3 = {}; // створення об'єкта структури
	//fill_point(p3);
	//show_point(p3);
	

	return 0;
}
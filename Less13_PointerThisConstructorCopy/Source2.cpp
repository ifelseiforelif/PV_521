#include <iostream>
using namespace std;



/*
Конструктор копіювання (КК):
Кожен клас має КК.
Він виконує поверхневе побітове копіювання(даних в стеке).
Його прототип ClassName(const ClassName& obj);
Якщо серед полів класа немає покажчики, то нас влаштовує
вбудований КК і ми його самі не реалізуємо.

Якщо серед полів класа Є покажчики треба
реалізувати КК явно, і зробити в ньому глибоке копіювання
(скопіювати дані, які зберігаються у HEAP)
інакше буде помилка при викликі деструктора,
коли декілька об'єктів мають поле класа, яке дивиться на 
1 спільну ділянку пам'яті.
Константні методи - методи класа, в яких заборонено
змінювати стан об'єкта (тобто значення його полів)
implicit - не явне
Тема: explicit(явне) конструктора

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
	change(10.5, 20);
	change(p, 20); //int -> Point

	return 0;
}
#include <iostream>
using namespace std;
//ООП - Об'єктно орієнтовне програмування
//Об'єктна декомпозиція
/*
Кіти ООП:
0) Абстрагування - це кіт проявляється у всіх кітах.
Це механізм виділення головних частин об'єкта і ігнорування неважливих
1) Інкапсуляція
2) Успадкування
3) Поліморфізм
Об'єкти - це екземпляри класа (instance)
Кожен клас складається з полів (властивості) та методів
Методи - це функції, які описуються в середині класа та описують
функціонал майбутнього об'єкта
public, private, protected
*/
class Car
{
	private:
		char* model;
		char* color;
		double price;
	public:
		//конструктор - це метод для створення об'єкта
		//Конструктор викликається автоматично
		//при створенні об`єкта класа
		//Вони ніколи нічого не повертають і мають назва
		//таку саму як і клас
		Car() //default - за замовчуванням
		{
			price = 1000;
			color = nullptr;
			model = nullptr;
		}
		Car(double pr)
		{
			if (pr > 1000)
			{
				price = pr;
			}
			else
			{
				price = 1000;
			}
			color = nullptr;
			model = nullptr;
		}
		Car(const char* m, const char* c, double pr)
		{
			if (pr > 1000)
			{
				price = pr;
			}
			else
			{
				price = 1000;
			}
			int sizeM = strlen(m);
			int sizeC = strlen(c);
			model = new char[sizeM+1 + 1];
			color = new char[sizeC + 1];
			strcpy_s(model, sizeM + 1, m);
			strcpy_s(color, sizeC + 1, c);

		}
		void showCar()
		{
			cout << model <<" " << color << " " << price << endl;
		}
};

int main()
{
	const char* model = "audi";
	const char* color = "white";
	double price = 3000;
	Car audi{model, color, price};
	audi.showCar();
	return 0;
}
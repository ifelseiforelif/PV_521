#include <iostream>
using namespace std;


class Student
{
private:
	char* name=nullptr;
	int inn;
	short age;
public:
	Student(char* name, int inn, short age) :inn{ inn }, age{ age }
	{
		if (name != nullptr)
		{
			int size = strlen(name);
			this->name = new char[size + 1];
			strcpy_s(this->name, size + 1, name);
		}
	}
	Student() :Student(nullptr,0,18) {}
	Student(const Student& obj) //конструктор копіювання
	{
		this->inn = obj.inn;
		this->age = obj.age;
		int size = strlen(obj.name);
		this->name = new char[size + 1];
		strcpy_s(this->name, size + 1, obj.name); //ГЛИБОКЕ КОПІЮВАННЯ
	}

	void print()
	{
		cout << "Student. inn: " << this->inn
			<< " age: " << this->age << endl;
	}
	Student& operator=(const Student& obj)
	{
		this->inn = obj.inn;
		this->age = obj.age;
		if (this->name != nullptr)
			delete[] name;
		int size = strlen(obj.name);
		this->name = new char[size + 1];
		strcpy_s(this->name, size + 1, obj.name);
		return *this;
	}
	~Student()
	{
		if (this->name != nullptr)
			delete[] this->name;
	}

};

int main()
{
	char name[20];
	cin >> name;
	Student st1{name, 344, 18 };
	st1.print();
	cin >> name;
	Student st2{ name, 120, 30 };
	st1.print();
	st1 = st2; //operator=
	Student st3 = st1; //КК
	st3.print();
	//Student st2 = st1; //копія
	//st2.print();
	

	return 0;
}
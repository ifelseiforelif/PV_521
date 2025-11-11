//#include <iostream>
//using namespace std;
//
//
//class Student
//{
//	char* name{ nullptr };
//public:
//	Student() = default;
//	Student(const char* name)
//	{
//		setName(name);
//	}
//	void setName(const char* name)
//	{
//		if (this->name)
//		{
//			delete[] this->name;
//			this->name = nullptr;
//		}
//		if (name)
//		{
//			unsigned int len = strlen(name);
//			this->name = new char[len + 1];
//			strcpy_s(this->name, len + 1, name);
//		}
//
//
//	}
//	~Student()
//	{
//		if (name)
//			delete[] name;
//	}
//
//};
//int main()
//{
//	const unsigned int N = 30;
//	char* name = new char[N];
//	cout << "Enter student name: ";
//	cin.getline(name, N);
//	{
//		Student st(name);
//	}
//	cout << name;
//	delete[] name;
//
//	return 0;
//}
//================================================== =
//EXAMPLE 4
//#include <iostream>
//using namespace std;
//
//
//class Student
//{
//	char* name{ nullptr };
//public:
//	Student() = default;
//	Student(const char* name)
//	{
//		setName(name);
//	}
//	Student(const Student& other)
//	{
//		setName(other.name);
//	}
//	Student& operator=(const Student& other)
//	{
//		if (this != &other)
//		{
//			setName(other.name);
//		}
//		return *this;
//	}
//	void setName(const char* name)
//	{
//		if (this->name)
//		{
//			this->~Student();
//			this->name = nullptr;
//		}
//		if (name)
//		{
//			unsigned int len = strlen(name);
//			this->name = new char[len + 1];
//			strcpy_s(this->name, len + 1, name);
//		}
//	}
//	~Student()
//	{
//		if (name)
//			delete[] name;
//	}
//
//};
//int main()
//{
//	const unsigned int N = 30;
//	char* name = new char[N];
//	cout << "Enter student name: ";
//	cin.getline(name, N);
//	{
//		Student st(name);
//		Student st2{ st };
//		Student st3;
//		st3 = st2;
//	}
//	cout << name;
//	delete[] name;
//
//	return 0;
//}
//====================================================
//EXAMPLE 5
#include <iostream>
using namespace std;


class Student
{
	char* name{ nullptr };
public:
	Student() = default;
	Student(const char* name)
	{
		setName(name);
	}
	Student(const Student& other)
	{
		setName(other.name);
	}
	Student(Student&& obj) noexcept //C++11
	{

		this->name = obj.name; //відчуження ресурса
		obj.name = nullptr;

	}
	
	Student& operator= (Student&& obj) noexcept //C++11
	{
		if(this->name )
		{
			delete[] this->name;
			this->name = nullptr;
		}
		this->name = obj.name; //відчуження ресурса
		obj.name = nullptr;
		return *this;
	}
	Student& operator=(const Student& other)
	{

		if (this != &other)
		{
			setName(other.name);
		}
		return *this;
	}
	void setName(const char* name)
	{
		if (this->name)
		{
			delete[] this->name;
			this->name = nullptr;
		}
		if (name)
		{
			unsigned int len = strlen(name);
			this->name = new char[len + 1];
			strcpy_s(this->name, len + 1, name);
		}
	}

	~Student()
	{
		if (name)
			delete[] name;
	}

};



void printName(const Student& stObj)
{
	cout << "Student name printed from function." << endl;
}

Student createStudent()
{
	bool flag = true;
	Student s1("Bob");
	Student s2("Alice");
	if (flag) return s1;  // NRVO(Named Return Value Optimization) не спрацює, потому что есть несколько объектов
	else return s2;
}

int main()
{
	Student st5("John");
	Student st6 = move(st5);
	Student st7("Alex");
	
	st6 = move(st7);

	/*Student s1("Kate");
	s1 = s1;*/
	/*
	Student st7 = st6;*/
	Student st4{ createStudent() };

	const unsigned int N = 30;
	char* name = new char[N];
	cout << "Enter student name: ";
	cin.getline(name, N);
	{
		Student st(name);
		printName(st);
		Student st2{ st };
		Student st3;
		st3 = st2;
	}
	cout << name;
	delete[] name;

	return 0;
}

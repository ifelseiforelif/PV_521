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
	Student(const Student& obj) //����������� ���������
	{
		this->inn = obj.inn;
		this->age = obj.age;
		int size = strlen(obj.name);
		this->name = new char[size + 1];
		strcpy_s(this->name, size + 1, obj.name); //������� ��ϲ������
	}

	void print()
	{
		cout << "Student. inn: " << this->inn
			<< " age: " << this->age << endl;
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
	Student st2 = st1; //����
	st2.print();
	

	return 0;
}
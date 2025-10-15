#include <iostream>
#include "Human.h"


Human::Human(char* n, unsigned short a, unsigned int inn) :INN{inn}
{
	setName(n);
	setAge(a);
}

Human::Human():Human::Human(nullptr,0,0)
{
}

char* Human::getName()
{
	return name;
}

unsigned short Human::getAge()
{
	return age;
}

unsigned int Human::getINN()
{
	return INN;
}

void Human::setName(char* n)
{
	if (n != nullptr && strlen(n)>0)
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		int size = strlen(n);
		name = new char[size + 1];
		strcpy_s(name, size + 1, n);
	}
}

void Human::setAge(unsigned short a)
{
	age = a;
}

Human::~Human()
{
	if (name != nullptr)
		delete[] name;
}

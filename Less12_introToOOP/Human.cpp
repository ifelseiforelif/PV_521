#include <iostream>
#include "Human.h"


Human::Human(char* n, unsigned short a, unsigned int inn) :INN{inn}
{
	++counter;
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

void Human::print()
{
	std::cout << "Human: \n";
	std::cout << getName() << std::endl;
	std::cout << getAge() << std::endl;
	std::cout << getINN() << std::endl;
	std::cout << "=========================\n\n";
}

int Human::getCounter()
{
	return counter;
}

int Human::counter = 0;

Human::~Human()
{
	if (name != nullptr)
		delete[] name;
}

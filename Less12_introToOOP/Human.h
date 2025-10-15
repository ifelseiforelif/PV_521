#pragma once
class Human
{
private:
	char* name = nullptr;
	unsigned short age;
	const unsigned int INN;

public:
	Human(char* n, unsigned short a, unsigned int inn);
	Human();
	char* getName();
	unsigned short getAge();
	unsigned int getINN();
	void setName(char* n);
	void setAge(unsigned short a);
	~Human(); //ÄÅÑÒĞÓÊÒÎĞ

};


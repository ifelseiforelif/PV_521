#include <iostream>
#include <string>
using namespace std;
#include "Point.h"

//template<typename T>
//class Printer
//{
//private: 
//	T obj;
//public:
//	Printer() = default;
//	Printer(T obj) {
//		this->obj = obj;
//	}
//	void print()
//	{
//		cout << obj << endl;
//	}
//};
//class Cat
//{
//
//};
//ostream& operator<<(ostream& out, Cat& cat)
//{
//	out << "Meow\n";
//	return out;
//}
int main() 
{
	std::string str(100, 'x');
	std::cout << "1. capacity of str: " << str.capacity() << '\n';

	str.resize(10);
	std::cout << "2. capacity of str: " << str.capacity() << '\n';

	str.shrink_to_fit();
	std::cout << "3. capacity of str: " << str.capacity() << '\n';
	/*string str1="";
	cout << str1.capacity()<< endl;
	str1.shrink_to_fit();
	cout << str1.capacity();*/
	//string s = str1.substr(2, 5); //Hello World
	//cout << s;
	/*int index = 10;
	try
	{
		cout << str1.at(10);
	}
	catch (const exception& ex)
	{
		cout << "error";
	}*/
	/*if (index >= 0 && index < str1.size())
	{
		cout << str1[index];
	}*/
	
	//
	//
	//str1.clear();
	/*if (str1.empty())
	{
		cout << "Empty";
	}
	cout << str1;*/
	//getline(cin, str1, ';');
	//cin >> str1;
	/*for (const char& k : str1)
	{
		cout << k << ' ';
	}*/
	/*cout << str1;
	int i = 0;
	while (i < str1.length())
	{
		cout << str1[i] << ' ';
		++i;
	}*/
	//string str = "Hello World!"; //HEAP
	//string str2{ "Hello World!" };
	//cout << str.size() << endl;
	//cout << str.length() << endl;
	//cout << str.capacity() << endl;


	/*Printer<int> myprint1{ 10 };
	myprint1.print();
	Point p{ 4,5 };
	Printer<Point> myprint2(p);
	myprint2.print();
	Printer<Cat> mypr3;
	mypr3.print();*/

	//Основна ідея перевантаження операторів
	//це інтеграція нашого власного типа даних у шаблон
	return 0;
}
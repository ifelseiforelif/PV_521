#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	/*short a;
	cout << sizeof(a);*/
	/*
	++ ���������
	-- ���������
	
	*/
	//int a = 10;
	//cout << --a + --a << endl; //8 + 8
	//cout << a; //8
	//a++; // ���������� ����� ����������
	//++a; // ��������� ����� ���������� *
	/*cout << ++a;
	cout << endl;
	cout << a;*/
	/*����/�� ����*/ 
	/*cout << bool(2 + 4);*/
	/*cout << typeid('A'+'B'+true).name();*/
	/*long l1 = 10l;
	long l2 = 10ll;
	cout << sizeof(long long);*/
	/*int n = 15.6;
	double n2 = 12;*/

	//int a = 10, b = -4;
	//cout << ((a > 5) && (b < -9));
	//cout << endl;
	//cout << ((a == 10) || (b !=-4));
	cout << "Enter number: ";
	int num;
	cin >> num;
	num > 0 ? cout << "+" : (num==0)? cout<< "0" : cout <<"-";

	// ����� ? true : false  //��������� ��������
	/*if (�����)
	{

	}
	else
	{

	}*/

	char ch;
	cin >> ch;
	cout << int(ch);
	if (ch >= 65 && ch <= 90)
	{

	}
	return 0;
}
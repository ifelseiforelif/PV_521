#include <iostream>
#include "Header.h"
#include "./admin/functions.h";
#define plusTen(a) a+10
#define multi(m) m*m*m
using namespace std;

int main() {
	Document d;
	Point p{ 2,3 };
	int num;
	cin >> num;

	cout << plusTen(num) << endl;
	cout << multi(num);
	return 0;
}
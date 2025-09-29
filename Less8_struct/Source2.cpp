#include <iostream>
using namespace std;


struct Test
{
	char n1; //1b 1b _ _ 4b 1b _ _ _
	char n2;
	char n4;
	int n3;
	bool b;
	long long n;
	
};

void print(Test& t)
{

}

int main()
{
	cout << sizeof(Test) << endl;



	
	return 0;
}
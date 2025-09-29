#include <iostream>
#include <stdlib.h>
using namespace std;

int my_strlen(const char* str)
{
	int k = 0;
	while (str[k] != '\0')
	{
		++k;
	}
	return k;
}

void change_space(char* const str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == ' ')
		{
			*(str + i) = '\t';
		}
		++i;
	}
}

int main()
{


	return 0;
	char row[] = "Hello, W o r l d !!!";
	char tab = '\t';
	for (int i = 0; i < strlen(row); i++) {
		if (row[i] == ' ') {
			row[i] = tab;
		}
	}
	cout << row;

	return 0;
	const int N1 = 20;
	char text[N1];
	cout << "Enter text: ";
	cin.getline(text, N1 -1);
	change_space(text);
	cout << text;
	return 0;
	//Рядки
	//cout << "Hello";
	/*char ch = '\0';
	cout << static_cast<int>(ch);*/
	//char arr[6]{ 'h','e','\0','l','o','\0'};
	//cout << arr;
	const int N = 30;
	char name[N];
	cout << "Enter name: ";
	//cin >> name;
	cin.getline(name, N-1);
	cout << "Welcome " << name << endl;
	int size =  my_strlen(name);
	char* real_name = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		real_name[i] = name[i];
	}
	real_name[size] = '\0';
	cout << real_name;
	delete[] real_name;
	return 0;
}
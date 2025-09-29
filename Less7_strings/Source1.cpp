#include <iostream>
//#pragma warning(disable : 4996)
using namespace std;

void my_strcpy(char* dest, int size, const char* source)
{
	for (int i = 0; i < size; i++)
	{
		dest[i] = source[i];
	}
}

void my_strcat(char* dest, int size, const char* source)
{
	char* total = new char[size];
	int i = 0;
	while (dest[i] != '\0')
	{
		total[i] = dest[i];
		++i;
	}
	int j = 0;
	while (source[j] != '\0')
	{
		total[i] = source[j];
		++i;
		++j;
	}
	total[size - 1] = '\0';
	cout << total;
}

bool is_palindrome(const char* str)
{ 
	int i = 0, j=strlen(str)-1;
	while (i < j)
	{
		if (str[i] == str[j])
		{
			++i;
			--j;
		}
		else
		{
			return false;
		}
	}
	return true;
}



int main()
{
	cout << is_palindrome("taatw");
	//strcmp = string compare - порівняння рядків
	// 0 - коли рядки дорівнюють один одному   Bob == Bob  => 0
	// 1 - коли перший рядок більше другого  
	// -1 - коли перший рядок меньше другого 

	//const char* str1 = "Boris";
	//const char* str2 = "Bocis";
	//cout << strcmp(str1, str2);
  
	/*int size = 100;
	char* str1 = new char[size];
	char* str2 = new char[size];
	cout << "str1: ";
	cin.getline(str1, size - 1);
	cout << "str2: ";
	cin.getline(str2, size - 1);
	char* real_str1 = new char[strlen(str1) + 1];
	char* real_str2 = new char[strlen(str2) + 1];
	strcpy_s(real_str1, strlen(str1) + 1, str1);
	strcpy_s(real_str2, strlen(str2) + 1, str2);
	delete[] str1;
	delete[] str2;
	my_strcat(real_str1, strlen(real_str1) + strlen(real_str2) + 1, real_str2);*/
	

	/*const int N = 20;
	char str1[N];
	cout << "Enter str1: ";
	cin.getline(str1, N - 1);
	char str2[N / 2];
	cout << "Enter str2: ";
	cin.getline(str2, N/2 - 1);
	strcat_s(str1, N, str2);
	cout << str1;*/


	//cout << "Enter string: ";
	//int size = 100;
	//char* str1 = new char[size];
	//cin.getline(str1, size - 1);
	//cout << str1;
	////copy
	//int len = strlen(str1) + 1;
	//char* copy_str = new char[len];

	////copy_str = str1;
	////strcpy(copy_str, str1);
	//strcpy_s(copy_str, len, str1);
	////my_strcpy(copy_str, len, str1);
	










	/*delete[] copy_str;
	delete[] str1;*/
	return 0;
}
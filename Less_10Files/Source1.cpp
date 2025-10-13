#include <iostream>
using namespace std;

/*
�������� ��������� Fraction (��� ���� ��������� �� ���������)
�������� ����� ��'���� ���� Fraction
�������� �� � ���� �� ���� ������� �� � ����� �� 
������� � �������
*/
struct Point
{
	int x;
	int y;
};

void show_points(Point* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "x:" << list[i].x << " y:" << list[i].y << endl;
	}
}
int main()
{
	const int N = 3;
	Point points[N];
	FILE* file;
	if (fopen_s(&file, "points.bin", "rb+") == 0)
	{
		cout << "File openning successfully" << endl;
		fread(points, sizeof(Point), N, file);
		show_points(points, N);
		fclose(file);
	}
	else
	{
		cout << "Error opening file" << endl;
	}
	return 0;
}
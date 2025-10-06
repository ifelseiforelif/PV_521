#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

int main()
{
	//Point p1 = { 10, 20 };
	FILE* file;
	if (fopen_s(&file, "point.bin", "rb") == 0)
	{
		int n;
		double n2 ;
		
		fread(&n, sizeof(int), 1, file);
		fread(&n2, sizeof(double), 1, file);
		cout << n << " " << n2 << endl;
		fclose(file);
	}


	//if (fopen_s(&file, "point.bin", "rb") == 0) //відкриття бінарного файлу для запису
	//{
	//	cout << "File openning successfully" << endl;
	//	Point p2;
	//	fread(&p2, sizeof(Point), 1, file); //запись структуры в бінарний файл
	//	cout << p2.x << " " << p2.y << endl;
	//	fclose(file);
	//}
	//if (fopen_s(&file, "point.bin", "wb") == 0) //відкриття бінарного файлу для запису
	//{
	//	cout << "File openning successfully" << endl;
	//	fwrite(&p1, sizeof(Point), 1, file); //запись структуры в бінарний файл
	//	fclose(file);
	//}
	else
	{
		cout << "Error opening file" << endl;
	}

	return 0;
}
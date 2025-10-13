#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};
Point& create_point();
void show_points(Point* list, int size);
void write_point_to_file(FILE* file, Point* points, int size);
void read_point_from_file(FILE* file, Point*& points);
enum Menu
{
	EXIT,
	CREATE_POINT,
	WRITE_POINT,
	READ_POINT
};
int main()
{
	Point* points = nullptr;
	FILE* file = nullptr;
	const char* path = "points.bin";
	errno_t code = fopen_s(&file, path, "ab+");
	int size = 0;
	int choice;
	do
	{
		cout << CREATE_POINT << "-create point \n"
			<< WRITE_POINT << "-write point to file \n"
			<< READ_POINT << "-read from file\n"
			<< EXIT << "-exit\n";
		cin >> choice;
		switch (choice)
		{
		case CREATE_POINT:
		{
			if (points != nullptr)
			{
				delete[] points;
				points = nullptr;
			}
			cout << "Enter size: ";
			cin >> size;
			points = new Point[size];
			for (int i = 0; i < size; i++)
			{
				points[i] = create_point();
			}
		}
		break;
		case WRITE_POINT:
		{
			if (code == 0)
			{
				fwrite(points, sizeof(Point), size, file);
				if (points != nullptr)
				{
					delete[] points;
					points = nullptr;
				}
			}
		}
		break;
		case READ_POINT:
		{
			read_point_from_file(file, points);
		}
		break;
		}

		
	} while (choice != 0);
	if (points != nullptr)
		delete[] points;
	if (file != nullptr)
	{
		fclose(file);
	}
	return 0;
}

Point& create_point()
{
	Point p;
	cout << "Enter x: ";
	cin >> p.x;
	cout << "Enter y: ";
	cin >> p.y;
	return p;
}
void show_points(Point* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "x:" << list[i].x << " y:" << list[i].y << endl;
	}
}
void write_point_to_file(FILE* file, Point* points, int size)
{
	//
}
void read_point_from_file(FILE* file, Point*& points) 
{
	fseek(file, 0, SEEK_END);
	int total = ftell(file) > 0 ? ftell(file) : 0;
	int count = total / sizeof(Point);
	if (points != nullptr)
	{
		delete[] points;
		points = nullptr;
	}
	points = new Point[count];
	if (file != nullptr)
	{
		fseek(file, 0, SEEK_SET);
		fread(points, sizeof(Point), count, file);
		for (int i = 0; i < count; i++)
		{
			show_points(points, count);
		}
	}
	if (points != nullptr)
	{
		delete[] points;
		points = nullptr;
	}
}


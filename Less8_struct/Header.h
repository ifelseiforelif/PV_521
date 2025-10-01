#pragma once
struct Car
{
	int id;
	char brand[50];
	int year;
	float price;
};
enum Menu {
	EXIT,
	SHOW_ALL,
	SHOW_BY_ID,
	ADD,
	UPDATE,
	DELETE,
	SORT,
	SEARCH
};
void show_menu()
{
	cout << EXIT << ". Exit" << endl;
	cout << SHOW_ALL << ". Show all cars" << endl;
	cout << SHOW_BY_ID << ". Show car by ID" << endl;
	cout << ADD << ". Add car" << endl;
	cout << UPDATE << ". Update car" << endl;
	cout << DELETE << ". Delete car" << endl;
	cout << SORT << ". Sort cars by price" << endl;
	cout << SEARCH << ". Search cars by brand" << endl;
}

void delete_cars(Car*& cars, unsigned int& size)
{
	if (cars != nullptr)
	{
		delete[] cars;
		cars = nullptr;
		size = 0;
	}
}

void show_car(const Car& car)
{
	cout << "ID: " << car.id << endl;
	cout << "Brand: " << car.brand << endl;
	cout << "Year: " << car.year << endl;
	cout << "Price: " << car.price << endl;
}

void show_cars(const Car* cars, unsigned int size)
{
	if (size == 0)
	{
		cout << "List is empty.\n";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		show_car(cars[i]);
		cout << "------------------------\n";
	}
}
void delete_car_by_id(Car*& cars, unsigned int& size, int id)
{
	int index = -1; //тут будет индекс удаляемого элемента, залишиться -1 якщо не знайдено
	for (int i = 0; i < size; i++)
	{
		if (cars[i].id == id)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		cout << "Car with ID " << id << " not found.\n";
		return;
	}
	Car* temp = new Car[size - 1]; //новий масив на 1 елемент менший
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != index)
		{
			temp[j++] = cars[i];
		}
	}
	size--;
	delete[] cars; //видаляємо старий масив
	cars = temp; //перенаправляємо пока на новий масив
	cout << "Car with ID " << id << " deleted.\n";
}
void add_car(Car*& cars, unsigned int& size)
{
	static int id = 101;
	Car car;
	car.id = id++;
	cout << "Enter brand: ";
	cin >> car.brand;
	cout << "Enter year: ";
	cin >> car.year;
	cout << "Enter price: ";
	cin >> car.price;
	Car* temp = new Car[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = cars[i];
	}
	temp[size] = car;
	size++;
	delete[] cars;
	cars = temp;
}
void run(Car*& cars, unsigned int& size)
{
	int choice;
	do {
		show_menu();
		cin >> choice;
		switch (choice)
		{
		case EXIT:
			delete_cars(cars, size);
			exit(0);
		case SHOW_ALL:
			show_cars(cars, size);
			break;
		case SHOW_BY_ID:
			break;
		case ADD:
			add_car(cars, size);
			break;
		case UPDATE:
			break;
		case DELETE:
		{
			int id;
			cout << "Enter car ID to delete: ";
			cin >> id;
			delete_car_by_id(cars, size, id);
		}
			break;
		case SORT:
			break;
		case SEARCH:
			break;
		default:
			cout << "Incorrect choice. Try again." << endl;
			break;
		}
	} while (choice != EXIT);
}


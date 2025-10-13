#define _CRT_SECURE_NO_WARNINGS
#include "Warehouse_functions.h"
#include <iostream>
#include <cstring>
#include "Windows.h"
using namespace std;

int next_product_id = 1;

void initialize_warehouse(Warehouse* warehouse)
{
	(*warehouse).head = NULL;
	(*warehouse).last = NULL;
	(*warehouse).productCount = 0;
	(*warehouse).totalValue = 0;
}
Date create_data(int year, int month, int day)
{
	Date newDate;
	newDate.year = year;
	newDate.month = month;
	newDate.day = day;

	return newDate;
}
int valid_data(const Date* date)
{
	if ((*date).year < 1900 || (*date).year > 2100) return 0;
	if ((*date).month < 1 || (*date).month > 12) return 0;
	if ((*date).day < 1 || (*date).day > 31) return 0;
	return 1;
}
Product* create_product(const char* name, const char* manufacturer,
	double price, const char* category, const Date* reciptDate,
	const Date* expiryDate, int quantity)
{
	Product* newProduct = new Product;

	size_t nameLen = strlen(name) + 1;
	(*newProduct).name = new char[nameLen];
	strcpy((*newProduct).name, name);

	size_t manufacturerLen = strlen(manufacturer) + 1;
	(*newProduct).manufacturer = new char[manufacturerLen];
	strcpy((*newProduct).manufacturer, manufacturer);

	size_t categoryLen = strlen(category) + 1;
	(*newProduct).category = new char[categoryLen];
	strcpy((*newProduct).category, category);

	(*newProduct).id = -1;
	(*newProduct).price = price;
	(*newProduct).quantity = quantity;
	// копіювання структур Date
	(*newProduct).reciptDate = *reciptDate;
	(*newProduct).expiryDate = *expiryDate;
	(*newProduct).next = NULL;

	return newProduct;
}
void clean_product(Product* product)
{
	if (product == NULL)
	{
		return;
	}
	if ((*product).name != NULL)
	{
		delete[](*product).name;
		(*product).name = NULL;
	}
	if ((*product).manufacturer != NULL)
	{
		delete[](*product).manufacturer;
		(*product).manufacturer = NULL;
	}
	if ((*product).category != NULL)
	{
		delete[](*product).category;
		(*product).category = NULL;
	}
	delete product;
}
Date input_date(const char* prompt) {
	Date date;
	int success = 0;

	cout << prompt;

	while (success == 0) {
		cout << "Введіть рік: ";
		if (!(cin >> date.year)) {
			cout << "Некоректне введення року. Спробуйте ще раз.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "Введіть місяць: ";
		if (!(cin >> date.month)) {
			cout << "Некоректне введення місяця. Спробуйте ще раз.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "Введіть день: ";
		if (!(cin >> date.day)) {
			cout << "Некоректне введення дня. Спробуйте ще раз.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		if (valid_data(&date)) {
			success = 1;
		}
		else {
			cout << "Некоректне значення дати. Спробуйте ще раз.\n";
		}
	}
	cin.ignore(10000, '\n');
	return date;
}
Product* input_product()
{
	char temp_name[50], temp_manufacturer[50], temp_category[50];
	double temp_price;
	int temp_quantity;

	cout << "\n Введення даних про товар \n";

	cout << "Введіть назву товару: ";
	cin.getline(temp_name, sizeof(temp_name));

	cout << "Введіть виробника: ";
	cin.getline(temp_manufacturer, sizeof(temp_manufacturer));

	cout << "Введіть категорію: ";
	cin.getline(temp_category, sizeof(temp_category));

	cout << "Введіть ціну: ";
	while (!(cin >> temp_price) || temp_price <= 0) {
		cout << "Некоректна ціна. Введіть позитивне число: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	cout << "Введіть кількість: ";
	while (!(cin >> temp_quantity) || temp_quantity < 0) {
		cout << "Некоректна кількість. Введіть невід'ємне число: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	Date recipt = input_date(" Введення дати надходження \n");
	Date expiry = input_date(" Введення терміну придатності \n");

	return create_product(temp_name, temp_manufacturer, temp_price, temp_category,
		&recipt, &expiry, temp_quantity);
}
void add_product(Warehouse* warehouse) {
	Product* newProduct = input_product();

	if (newProduct == NULL) {
		cout << "Помилка: не вдалося створити товар.\n";
		return;
	}

	(*newProduct).id = next_product_id;
	next_product_id = next_product_id + 1;

	if ((*warehouse).head == NULL)
	{
		(*warehouse).head = newProduct;
		(*warehouse).last = newProduct;
	}
	else
	{
		(*(*warehouse).last).next = newProduct;
		(*warehouse).last = newProduct;
	}

	(*newProduct).next = NULL;

	(*warehouse).productCount = (*warehouse).productCount + 1;
	(*warehouse).totalValue = (*warehouse).totalValue + ((*newProduct).price * (*newProduct).quantity);

	cout << "Товар (ID: " << (*newProduct).id << ", " << (*newProduct).name << ") успішно додано до складу.\n";
}
void remove_product(Warehouse* warehouse) {
	if ((*warehouse).head == NULL) {
		cout << "Склад порожній.\n";
		return;
	}

	int id_to_remove;
	cout << "\nВведіть ID товару, який потрібно видалити: ";
	if (!(cin >> id_to_remove)) {
		cout << "Некоректний ID. Скасування.\n";
		cin.clear();
		cin.ignore(10000, '\n');
		return;
	}
	cin.ignore(10000, '\n');

	Product* current = (*warehouse).head;
	Product* previous = NULL;
	int found = 0;

	while (current != NULL)
	{
		if ((*current).id == id_to_remove)
		{
			found = 1;
			break;
		}
		previous = current;
		current = (*current).next;
	}

	if (found == 0) {
		cout << "Товар з ID " << id_to_remove << " не знайдено.\n";
		return;
	}
	(*warehouse).productCount = (*warehouse).productCount - 1;
	(*warehouse).totalValue = (*warehouse).totalValue - ((*current).price * (*current).quantity);

	if (previous == NULL)
	{
		(*warehouse).head = (*current).next;
	}
	else
	{
		(*previous).next = (*current).next;
	}

	if ((*current).next == NULL)
	{
		(*warehouse).last = previous;
	}

	cout << "Товар (ID: " << (*current).id << ", " << (*current).name << ") успішно видалено.\n";
	clean_product(current);
}
void edit_product(Warehouse* warehouse)
{
	if ((*warehouse).head == NULL)
	{
		cout << "Склад порожній.Нічого редагувати.\n";
		return;
	}
	int id_edit;
	cout << "Введіть ID товару, який потрібно редагувати: ";
	if (!(cin >> id_edit))
	{
		cout << "Некоректний ID.Скасування редагування.\n";
		cin.clear();
		cin.ignore(10000, '\n');
		return;
	}
	cin.ignore(10000, '\n');

	Product* current = (*warehouse).head;
	Product* product_edit = NULL;

	while (current != NULL)
	{
		if ((*current).id == id_edit)
		{
			product_edit = current;
			break;
		}
		current = (*current).next;
	}
	if (product_edit == NULL)
	{
		cout << "Товар з ID" << id_edit << " не знайдено.\n";
		return;
	}
	cout << "\nЗнайден товар для редагування:\n";
	show_product(product_edit);

	char temp_name[50], temp_manufacturer[50], temp_category[50];
	double temp_price;
	int temp_quantity;

	cout << "\nВведіть нові дані (або повторіть старі)\n";

	cout << "Введіть нову назву товару (Поточна: " << (*product_edit).name << "): ";
	cin.getline(temp_name, sizeof(temp_name));

	cout << "Введіть нового виробника (Поточний: " << (*product_edit).manufacturer << "): ";
	cin.getline(temp_manufacturer, sizeof(temp_manufacturer));

	cout << "Введіть нову категорію (Поточна: " << (*product_edit).category << "): ";
	cin.getline(temp_category, sizeof(temp_category));

	cout << "Введіть нову ціну (Поточна: " << (*product_edit).price << "): ";
	while (!(cin >> temp_price) || temp_price <= 0)
	{
		cout << "Некоректна ціна. Введіть позитивне число: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Введіть нову кількість (Поточна: " << (*product_edit).quantity << "): ";
	while (!(cin >> temp_quantity) || temp_quantity < 0) {
		cout << "Некоректна кількість. Введіть невід'ємне число: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cin.ignore(10000, '\n');

	(*warehouse).totalValue = (*warehouse).totalValue - ((*product_edit).price * (*product_edit).quantity);

	update_product(product_edit, temp_name, temp_manufacturer, temp_price, temp_category, temp_quantity);

	(*warehouse).totalValue = (*warehouse).totalValue + (temp_price * temp_quantity);
	cout << "Редагування товару (ID: " << id_edit << ") завершено.\n";
}
void update_product(Product* product, const char* name,
	const char* manufacturer, double price, const char* category, int quantity)
{
	if (product == NULL)
	{
		cout << "Помилка. Вказівник на товар для оновлення.\n";
		return;
	}
	if ((*product).name != NULL)
	{
		delete[](*product).name;
	}
	size_t nameLen = strlen(name) + 1;
	(*product).name = new char[nameLen];
	strcpy((*product).name, name);

	if ((*product).manufacturer != NULL)
	{
		delete[](*product).manufacturer;
	}
	size_t manufacturerLen = strlen(manufacturer) + 1;
	(*product).manufacturer = new char[manufacturerLen];
	strcpy((*product).manufacturer, manufacturer);

	if ((*product).category != NULL)
	{
		delete[](*product).category;
	}
	size_t categoryLen = strlen(category) + 1;
	(*product).category = new char[categoryLen];
	strcpy((*product).category, category);

	(*product).price = price;
	(*product).quantity = quantity;
	cout << "Поля товару (ID: " << (*product).id << ") оновлені.\n";
}
void display_all_products(const Warehouse* warehouse)
{
	if ((*warehouse).head == NULL)
	{
		cout << "Склад порожній.Немає товарів.\n";
		return;
	}
	Product* current = (*warehouse).head;
	int index = 1;

	cout << "Всі товари на складі (Всього: " << (*warehouse).productCount << ")";
	cout << "Загальна вартість: " << (*warehouse).totalValue << "грн\n";

	while (current != NULL)
	{
		cout << "Товар " << index << "\n";
		show_product(current);
		current = (*current).next;
		index++;
	}
}
void show_product(const Product* product)
{
	if (product == NULL)
	{
		cout << "Товар не знайдено\n";
		return;
	}
	cout << "ID: " << (*product).id << "\n";
	cout << "Назва: " << (*product).name << "\n";
	cout << "Виробник: " << (*product).manufacturer << "\n";
	cout << "Ціна: " << (*product).price << " грн\n";
	cout << "Група: " << (*product).category << "\n";
	cout << "Кількість: " << (*product).quantity << " од.\n";
	cout << "Надходження на склад: " << (*product).reciptDate.day << "."
		<< (*product).reciptDate.month << "."
		<< (*product).reciptDate.year << "\n";
	cout << "Придатний до: " << (*product).expiryDate.day << "."
		<< (*product).expiryDate.month << "."
		<< (*product).expiryDate.year << "\n";
}
int compare_dates(const Date* date1, const Date* date2)
{
	if ((*date1).year != (*date2).year)
	{
		return (*date1).year - (*date2).year;
	}
	if ((*date1).month != (*date2).month)
	{
		return (*date1).month - (*date2).month;
	}
	return (*date1).day - (*date2).day;
}
SearchResult initialize_search_result(int initial_capacity)
{
	SearchResult results;
	results.count = 0;

	if (initial_capacity <= 0)
	{
		results.capacity = 10;
	}
	else
	{
		results.capacity = initial_capacity;
	}
	results.products = new Product * [results.capacity];

	return results;
}
void add_search_result(SearchResult* results, Product* product)
{
	if ((*results).count >= (*results).capacity)
	{

		int newCapacity = (*results).capacity * 2;
		Product** newProducts = new Product * [newCapacity];

		memcpy(newProducts, (*results).products, (*results).count * sizeof(Product*));

		delete[](*results).products;

		(*results).products = newProducts;
		(*results).capacity = newCapacity;
	}
	(*results).products[(*results).count] = product;
	(*results).count = (*results).count + 1;
}
SearchResult search_name(const Warehouse* warehouse, const char* name)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;
	while (current != NULL)
	{
		if (strcmp((*current).name, name) == 0)
		{
			add_search_result(&results, current);
		}
		current = (*current).next;
	}
	cout << "Пошук \"" << name << "\" завершено. Знайдено: " << results.count << " товарів.\n";
	return results;
}
SearchResult search_manufacturer(const Warehouse* warehouse, const char* manufacturer)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;

	while (current != NULL)
	{
		if (strcmp((*current).manufacturer, manufacturer) == 0)
		{
			add_search_result(&results, current);
		}
		current = (*current).next;
	}

	cout << "Пошук за виробником \"" << manufacturer << "\" завершено. Знайдено: " << results.count << " товарів.\n";
	return results;
}
SearchResult search_category(const Warehouse* warehouse, const char* category)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;

	while (current != NULL)
	{
		if (strcmp((*current).category, category) == 0)
		{
			add_search_result(&results, current);
		}
		current = (*current).next;
	}

	cout << "Пошук за групою \"" << category << "\" завершено. Знайдено: " << results.count << " товарів.\n";
	return results;
}

SearchResult search_price(const Warehouse* warehouse, double minPrice, double maxPrice)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;
	if (minPrice > maxPrice)
	{
		cout << "Помилка.Мінімальна ціна " << minPrice << " не може бути більшою за максимальну " << maxPrice << ".\n";
		return results;
	}
	while (current != NULL)
	{
		if ((*current).price >= minPrice && (*current).price <= maxPrice) //перевірка діапазону
		{
			add_search_result(&results, current);
		}
		current = (*current).next;
	}
	cout << "Пошук за ціною від " << minPrice << " до " << maxPrice << " грн завершено. Знайдено: " << results.count << " товарів.\n"; // Виправлено
	return results;
}
SearchResult search_recipt_date(const Warehouse* warehouse, const Date* startDate,
	const Date* endDate)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;

	if (compare_dates(startDate, endDate) > 0)
	{
		cout << "Помилка.Початкова дата не може бути пізнішою за кінцеву.\n";
		return results;
	}
	while (current != NULL)
	{
		if (compare_dates(&(*current).reciptDate, startDate) >= 0)
		{
			if (compare_dates(&(*current).reciptDate, endDate) <= 0)
			{
				add_search_result(&results, current);
			}
		}
		current = (*current).next;
	}
	cout << "Пошук за датою надходження завершено. Знайдено: " << results.count << " товарів.\n";
	return results;
}
SearchResult search_expiry_date(const Warehouse* warehouse, const Date* expiryDate)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;
	while (current != NULL)
	{
		if (compare_dates(&(*current).expiryDate, expiryDate) <= 0)// пошук товарівтермін придатності яких спливає раніше або в зазначену дату <= 0
		{
			add_search_result(&results, current);
		}
		current = (*current).next;
	}
	cout << "Пошук товарів, термін придатності яких спливає до "
		<< (*expiryDate).day << "." << (*expiryDate).month << "." << (*expiryDate).year
		<< " завершено. Знайдено: " << results.count << " товарів.\n";
	return results;
}
SearchResult search_requirement(const Warehouse* warehouse,
	const SearchRequirement requirement)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;

	if (current == NULL)
	{
		cout << "Склад порожній.Комбінований пошук неможливий.\n";
		return results;
	}

	while (current != NULL)
	{

		int matches = 1; // 1 відповідає 0 не відповідає

		if (matches == 1 && requirement.name != NULL && strcmp(requirement.name, "") != 0)
		{
			if (strcmp((*current).name, requirement.name) != 0)
			{
				matches = 0;
			}
		}
		if (matches == 1 && requirement.manufacturer != NULL && strcmp(requirement.manufacturer, "") != 0)
		{
			if (strcmp((*current).manufacturer, requirement.manufacturer) != 0)
			{
				matches = 0;
			}
		}
		if (matches == 1 && requirement.category != NULL && strcmp(requirement.category, "") != 0)
		{
			if (strcmp((*current).category, requirement.category) != 0)
			{
				matches = 0;
			}
		}
		if (matches == 1 && (requirement.minPrice > 0 || requirement.maxPrice > 0))
		{
			if (requirement.minPrice > 0 && (*current).price < requirement.minPrice)
			{
				matches = 0;
			}
			if (matches == 1 && requirement.maxPrice > 0 && (*current).price > requirement.maxPrice)
			{
				matches = 0;
			}
		}
		if (matches == 1 && requirement.startDate.year > 0 && requirement.endDate.year > 0)
		{
			if (compare_dates(&(*current).reciptDate, &requirement.startDate) < 0)
			{
				matches = 0;
			}
			if (matches == 1 && compare_dates(&(*current).reciptDate, &requirement.endDate) > 0)
			{
				matches = 0;
			}
		}
		if (matches == 1 && requirement.expiryBefore.year > 0)
		{
			// expiryDate повинна бути <= expiryBefore /термін придатності спливає раніше або в зазначену дату
			if (compare_dates(&(*current).expiryDate, &requirement.expiryBefore) > 0)
			{
				matches = 0;
			}
		}
		if (matches == 1)
		{
			add_search_result(&results, current);
		}

		current = (*current).next;
	}
	cout << "Комбінований пошук завершено.Знайдено: " << results.count << " товарів.\n";
	return results;
}
void display_search_results(const SearchResult* results)
{
	if ((*results).count == 0)
	{
		cout << "\nТоварів не знайдено.\n";
		return;
	}
	cout << "\nРезультат пошуку (Знайдено: " << (*results).count << ")\n";
	for (int i = 0; i < (*results).count; i++) {
		cout << "Знайдений товар " << i + 1 << "\n";
		show_product((*results).products[i]);
	}
	delete[](*results).products;
}
void search_menu(const Warehouse* warehouse)
{
	int search_choice;
	SearchResult results = { NULL, 0, 0 };

	cout << "\nПІДМЕНЮ ПОШУКУ\n";
	cout << "1. Пошук за назвою\n";
	cout << "2. Пошук за виробником\n";
	cout << "3. Пошук за категорією\n";
	cout << "4. Пошук за ціновим діапазоном\n";
	cout << "5. Пошук за датою надходження\n";
	cout << "6. Пошук за терміном придатності (прострочення)\n";
	cout << "7. Комбінований пошук\n";
	cout << "0. Повернутися до головного меню\n";
	cout << "Ваш вибір: ";

	if (!(cin >> search_choice))
	{
		cout << "Некоректний ввід. Повернення до меню.\n";
		cin.clear();
		cin.ignore(10000, '\n');
		return;
	}
	cin.ignore(10000, '\n');

	if (search_choice == 1)
	{
		char name_query[50];
		cout << "Введіть назву для пошуку: ";
		cin.getline(name_query, 50);
		results = search_name(warehouse, name_query);
		display_search_results(&results);

	}
	else if (search_choice == 2)
	{
		char manufacturer_query[50];
		cout << "Введіть виробника для пошуку: ";
		cin.getline(manufacturer_query, 50);
		results = search_manufacturer(warehouse, manufacturer_query);
		display_search_results(&results);
	}
	else if (search_choice == 3) {
		char category_query[50];
		cout << "Введіть категорію (групу) для пошуку: ";
		cin.getline(category_query, 50);
		results = search_category(warehouse, category_query);
		display_search_results(&results);
	}
	else if (search_choice == 4)
	{
		double min_p, max_p;
		cout << "Введіть мінімальну ціну: ";
		while (!(cin >> min_p) || min_p < 0)
		{
			cout << "Некоректна ціна. Введіть невід'ємне число: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "Введіть максимальну ціну: ";
		while (!(cin >> max_p) || max_p < min_p)
		{
			cout << "Некоректна ціна (має бути >= мінімальної). Введіть число: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cin.ignore(10000, '\n');
		results = search_price(warehouse, min_p, max_p);
		display_search_results(&results);

	}
	else if (search_choice == 5)
	{
		cout << "\n Введення початкової дати надходження \n";
		Date start_date = input_date("Введіть початкову дату діапазону: ");

		cout << "\n Введення кінцевої дати надходження \n";
		Date end_date = input_date("Введіть кінцеву дату діапазону: ");

		results = search_recipt_date(warehouse, &start_date, &end_date);
		display_search_results(&results);

	}
	else if (search_choice == 6)
	{
		cout << "\n Введення граничної дати придатності \n";
		Date expiry_limit = input_date("Введіть дату, до якої термін придатності має спливати (включно): ");

		results = search_expiry_date(warehouse, &expiry_limit);
		display_search_results(&results);

	}
	else if (search_choice == 7)
	{
		SearchRequirement req = {};
		char temp_str[50];

		cout << "\n Комбінований пошук (Залиште поле порожнім або 0 для ігнорування) \n";

		cout << "Введіть назву: ";
		cin.getline(temp_str, 50);
		if (strlen(temp_str) > 0)
		{
			size_t len = strlen(temp_str);
			req.name = new char[len + 1];
			strcpy(req.name, temp_str);
		}
		else {
			req.name = NULL;
		}
		cout << "Введіть виробника: ";
		cin.getline(temp_str, 50);
		if (strlen(temp_str) > 0) {
			size_t len = strlen(temp_str);
			req.manufacturer = new char[len + 1];
			strcpy(req.manufacturer, temp_str);
		}
		else {
			req.manufacturer = NULL;
		}
		cout << "Введіть категорію: ";
		cin.getline(temp_str, 50);
		if (strlen(temp_str) > 0) {
			size_t len = strlen(temp_str);
			req.category = new char[len + 1];
			strcpy(req.category, temp_str);
		}
		else {
			req.category = NULL;
		}
		cout << "Введіть мінімальну ціну (0 для ігнорування): ";
		if (!(cin >> req.minPrice)) req.minPrice = 0;

		cout << "Введіть максимальну ціну (0 для ігнорування): ";
		if (!(cin >> req.maxPrice)) req.maxPrice = 0;
		cin.ignore(10000, '\n');

		char date_choice;
		cout << "Шукати за діапазоном надходження? (Y/N): ";
		cin >> date_choice;
		cin.ignore(10000, '\n');
		if (date_choice == 'Y' || date_choice == 'y') {
			cout << "\nВведіть початкову дату надходження:\n";
			req.startDate = input_date("");
			cout << "\nВведіть кінцеву дату надходження:\n";
			req.endDate = input_date("");
		}
		cout << "Шукати за простроченням (термін до)? (Y/N): ";
		cin >> date_choice;
		cin.ignore(10000, '\n');
		if (date_choice == 'Y' || date_choice == 'y') {
			cout << "\nВведіть граничну дату придатності (до якої спливає):\n";
			req.expiryBefore = input_date("");
		}
		results = search_requirement(warehouse, req);
		display_search_results(&results);

		delete[] req.name;
		delete[] req.manufacturer;
		delete[] req.category;

	}
	else if (search_choice == 0)
	{
		cout << "Повернення до головного меню.\n";
	}
	else {
		cout << "Функція пошуку (" << search_choice << ") ще не реалізована.\n";
	}
}
void show_menu() {
	cout << "\n Меню складу \n";
	cout << "1. Додати товар\n";
	cout << "2. Видалити товар (за ID)\n";
	cout << "3. Редагувати товар (оновлення)\n";
	cout << "4. Пошук товару (за критеріями)\n";
	cout << "5. Вивести всі товари\n";
	cout << "6. Перевірка прострочених товарів\n";
	cout << "7. Сортування товарів\n";
	cout << "0. Вихід\n";
	cout << "Ваш вибір: ";
}
int main() {
	setlocale(LC_ALL, "");
	Warehouse inventory;
	initialize_warehouse(&inventory);

	int choice;
	int success_read;

	do {
		show_menu();

		success_read = 0;
		if (cin >> choice)
		{
			success_read = 1;
		}
		if (success_read == 0)
		{
			cout << "Некоректний ввід! Будь ласка, введіть число.\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		else if (choice == 1)
		{
			add_product(&inventory);
		}
		else if (choice == 2)
		{
			remove_product(&inventory);
		}
		else if (choice == 3)
		{
			edit_product(&inventory);
		}
		else if (choice == 4)
		{
			search_menu(&inventory);
		}
		else if (choice == 5)
		{
			display_all_products(&inventory);
		}

	} while (choice != 0);
	return 0;
}
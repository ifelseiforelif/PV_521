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
	// ��������� �������� Date
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
		cout << "������ ��: ";
		if (!(cin >> date.year)) {
			cout << "���������� �������� ����. ��������� �� ���.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "������ �����: ";
		if (!(cin >> date.month)) {
			cout << "���������� �������� �����. ��������� �� ���.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "������ ����: ";
		if (!(cin >> date.day)) {
			cout << "���������� �������� ���. ��������� �� ���.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		if (valid_data(&date)) {
			success = 1;
		}
		else {
			cout << "���������� �������� ����. ��������� �� ���.\n";
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

	cout << "\n �������� ����� ��� ����� \n";

	cout << "������ ����� ������: ";
	cin.getline(temp_name, sizeof(temp_name));

	cout << "������ ���������: ";
	cin.getline(temp_manufacturer, sizeof(temp_manufacturer));

	cout << "������ ��������: ";
	cin.getline(temp_category, sizeof(temp_category));

	cout << "������ ����: ";
	while (!(cin >> temp_price) || temp_price <= 0) {
		cout << "���������� ����. ������ ��������� �����: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	cout << "������ �������: ";
	while (!(cin >> temp_quantity) || temp_quantity < 0) {
		cout << "���������� �������. ������ ����'���� �����: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	Date recipt = input_date(" �������� ���� ����������� \n");
	Date expiry = input_date(" �������� ������ ���������� \n");

	return create_product(temp_name, temp_manufacturer, temp_price, temp_category,
		&recipt, &expiry, temp_quantity);
}
void add_product(Warehouse* warehouse) {
	Product* newProduct = input_product();

	if (newProduct == NULL) {
		cout << "�������: �� ������� �������� �����.\n";
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

	cout << "����� (ID: " << (*newProduct).id << ", " << (*newProduct).name << ") ������ ������ �� ������.\n";
}
void remove_product(Warehouse* warehouse) {
	if ((*warehouse).head == NULL) {
		cout << "����� �������.\n";
		return;
	}

	int id_to_remove;
	cout << "\n������ ID ������, ���� ������� ��������: ";
	if (!(cin >> id_to_remove)) {
		cout << "����������� ID. ����������.\n";
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
		cout << "����� � ID " << id_to_remove << " �� ��������.\n";
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

	cout << "����� (ID: " << (*current).id << ", " << (*current).name << ") ������ ��������.\n";
	clean_product(current);
}
void edit_product(Warehouse* warehouse)
{
	if ((*warehouse).head == NULL)
	{
		cout << "����� �������.ͳ���� ����������.\n";
		return;
	}
	int id_edit;
	cout << "������ ID ������, ���� ������� ����������: ";
	if (!(cin >> id_edit))
	{
		cout << "����������� ID.���������� �����������.\n";
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
		cout << "����� � ID" << id_edit << " �� ��������.\n";
		return;
	}
	cout << "\n������� ����� ��� �����������:\n";
	show_product(product_edit);

	char temp_name[50], temp_manufacturer[50], temp_category[50];
	double temp_price;
	int temp_quantity;

	cout << "\n������ ��� ��� (��� �������� ����)\n";

	cout << "������ ���� ����� ������ (�������: " << (*product_edit).name << "): ";
	cin.getline(temp_name, sizeof(temp_name));

	cout << "������ ������ ��������� (��������: " << (*product_edit).manufacturer << "): ";
	cin.getline(temp_manufacturer, sizeof(temp_manufacturer));

	cout << "������ ���� �������� (�������: " << (*product_edit).category << "): ";
	cin.getline(temp_category, sizeof(temp_category));

	cout << "������ ���� ���� (�������: " << (*product_edit).price << "): ";
	while (!(cin >> temp_price) || temp_price <= 0)
	{
		cout << "���������� ����. ������ ��������� �����: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "������ ���� ������� (�������: " << (*product_edit).quantity << "): ";
	while (!(cin >> temp_quantity) || temp_quantity < 0) {
		cout << "���������� �������. ������ ����'���� �����: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cin.ignore(10000, '\n');

	(*warehouse).totalValue = (*warehouse).totalValue - ((*product_edit).price * (*product_edit).quantity);

	update_product(product_edit, temp_name, temp_manufacturer, temp_price, temp_category, temp_quantity);

	(*warehouse).totalValue = (*warehouse).totalValue + (temp_price * temp_quantity);
	cout << "����������� ������ (ID: " << id_edit << ") ���������.\n";
}
void update_product(Product* product, const char* name,
	const char* manufacturer, double price, const char* category, int quantity)
{
	if (product == NULL)
	{
		cout << "�������. �������� �� ����� ��� ���������.\n";
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
	cout << "���� ������ (ID: " << (*product).id << ") �������.\n";
}
void display_all_products(const Warehouse* warehouse)
{
	if ((*warehouse).head == NULL)
	{
		cout << "����� �������.���� ������.\n";
		return;
	}
	Product* current = (*warehouse).head;
	int index = 1;

	cout << "�� ������ �� ����� (������: " << (*warehouse).productCount << ")";
	cout << "�������� �������: " << (*warehouse).totalValue << "���\n";

	while (current != NULL)
	{
		cout << "����� " << index << "\n";
		show_product(current);
		current = (*current).next;
		index++;
	}
}
void show_product(const Product* product)
{
	if (product == NULL)
	{
		cout << "����� �� ��������\n";
		return;
	}
	cout << "ID: " << (*product).id << "\n";
	cout << "�����: " << (*product).name << "\n";
	cout << "��������: " << (*product).manufacturer << "\n";
	cout << "ֳ��: " << (*product).price << " ���\n";
	cout << "�����: " << (*product).category << "\n";
	cout << "ʳ������: " << (*product).quantity << " ��.\n";
	cout << "����������� �� �����: " << (*product).reciptDate.day << "."
		<< (*product).reciptDate.month << "."
		<< (*product).reciptDate.year << "\n";
	cout << "��������� ��: " << (*product).expiryDate.day << "."
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
	cout << "����� \"" << name << "\" ���������. ��������: " << results.count << " ������.\n";
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

	cout << "����� �� ���������� \"" << manufacturer << "\" ���������. ��������: " << results.count << " ������.\n";
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

	cout << "����� �� ������ \"" << category << "\" ���������. ��������: " << results.count << " ������.\n";
	return results;
}

SearchResult search_price(const Warehouse* warehouse, double minPrice, double maxPrice)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;
	if (minPrice > maxPrice)
	{
		cout << "�������.̳������� ���� " << minPrice << " �� ���� ���� ������ �� ����������� " << maxPrice << ".\n";
		return results;
	}
	while (current != NULL)
	{
		if ((*current).price >= minPrice && (*current).price <= maxPrice) //�������� ��������
		{
			add_search_result(&results, current);
		}
		current = (*current).next;
	}
	cout << "����� �� ����� �� " << minPrice << " �� " << maxPrice << " ��� ���������. ��������: " << results.count << " ������.\n"; // ����������
	return results;
}
SearchResult search_recipt_date(const Warehouse* warehouse, const Date* startDate,
	const Date* endDate)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;

	if (compare_dates(startDate, endDate) > 0)
	{
		cout << "�������.��������� ���� �� ���� ���� ������ �� ������.\n";
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
	cout << "����� �� ����� ����������� ���������. ��������: " << results.count << " ������.\n";
	return results;
}
SearchResult search_expiry_date(const Warehouse* warehouse, const Date* expiryDate)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;
	while (current != NULL)
	{
		if (compare_dates(&(*current).expiryDate, expiryDate) <= 0)// ����� ����������� ���������� ���� ������ ����� ��� � ��������� ���� <= 0
		{
			add_search_result(&results, current);
		}
		current = (*current).next;
	}
	cout << "����� ������, ����� ���������� ���� ������ �� "
		<< (*expiryDate).day << "." << (*expiryDate).month << "." << (*expiryDate).year
		<< " ���������. ��������: " << results.count << " ������.\n";
	return results;
}
SearchResult search_requirement(const Warehouse* warehouse,
	const SearchRequirement requirement)
{
	SearchResult results = initialize_search_result(10);
	Product* current = (*warehouse).head;

	if (current == NULL)
	{
		cout << "����� �������.����������� ����� ����������.\n";
		return results;
	}

	while (current != NULL)
	{

		int matches = 1; // 1 ������� 0 �� �������

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
			// expiryDate ������� ���� <= expiryBefore /����� ���������� ������ ����� ��� � ��������� ����
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
	cout << "����������� ����� ���������.��������: " << results.count << " ������.\n";
	return results;
}
void display_search_results(const SearchResult* results)
{
	if ((*results).count == 0)
	{
		cout << "\n������ �� ��������.\n";
		return;
	}
	cout << "\n��������� ������ (��������: " << (*results).count << ")\n";
	for (int i = 0; i < (*results).count; i++) {
		cout << "��������� ����� " << i + 1 << "\n";
		show_product((*results).products[i]);
	}
	delete[](*results).products;
}
void search_menu(const Warehouse* warehouse)
{
	int search_choice;
	SearchResult results = { NULL, 0, 0 };

	cout << "\nϲ����� ������\n";
	cout << "1. ����� �� ������\n";
	cout << "2. ����� �� ����������\n";
	cout << "3. ����� �� ��������\n";
	cout << "4. ����� �� ������� ���������\n";
	cout << "5. ����� �� ����� �����������\n";
	cout << "6. ����� �� ������� ���������� (������������)\n";
	cout << "7. ����������� �����\n";
	cout << "0. ����������� �� ��������� ����\n";
	cout << "��� ����: ";

	if (!(cin >> search_choice))
	{
		cout << "����������� ���. ���������� �� ����.\n";
		cin.clear();
		cin.ignore(10000, '\n');
		return;
	}
	cin.ignore(10000, '\n');

	if (search_choice == 1)
	{
		char name_query[50];
		cout << "������ ����� ��� ������: ";
		cin.getline(name_query, 50);
		results = search_name(warehouse, name_query);
		display_search_results(&results);

	}
	else if (search_choice == 2)
	{
		char manufacturer_query[50];
		cout << "������ ��������� ��� ������: ";
		cin.getline(manufacturer_query, 50);
		results = search_manufacturer(warehouse, manufacturer_query);
		display_search_results(&results);
	}
	else if (search_choice == 3) {
		char category_query[50];
		cout << "������ �������� (�����) ��� ������: ";
		cin.getline(category_query, 50);
		results = search_category(warehouse, category_query);
		display_search_results(&results);
	}
	else if (search_choice == 4)
	{
		double min_p, max_p;
		cout << "������ �������� ����: ";
		while (!(cin >> min_p) || min_p < 0)
		{
			cout << "���������� ����. ������ ����'���� �����: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "������ ����������� ����: ";
		while (!(cin >> max_p) || max_p < min_p)
		{
			cout << "���������� ���� (�� ���� >= ��������). ������ �����: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cin.ignore(10000, '\n');
		results = search_price(warehouse, min_p, max_p);
		display_search_results(&results);

	}
	else if (search_choice == 5)
	{
		cout << "\n �������� ��������� ���� ����������� \n";
		Date start_date = input_date("������ ��������� ���� ��������: ");

		cout << "\n �������� ������ ���� ����������� \n";
		Date end_date = input_date("������ ������ ���� ��������: ");

		results = search_recipt_date(warehouse, &start_date, &end_date);
		display_search_results(&results);

	}
	else if (search_choice == 6)
	{
		cout << "\n �������� �������� ���� ���������� \n";
		Date expiry_limit = input_date("������ ����, �� ��� ����� ���������� �� �������� (�������): ");

		results = search_expiry_date(warehouse, &expiry_limit);
		display_search_results(&results);

	}
	else if (search_choice == 7)
	{
		SearchRequirement req = {};
		char temp_str[50];

		cout << "\n ����������� ����� (������� ���� ������� ��� 0 ��� �����������) \n";

		cout << "������ �����: ";
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
		cout << "������ ���������: ";
		cin.getline(temp_str, 50);
		if (strlen(temp_str) > 0) {
			size_t len = strlen(temp_str);
			req.manufacturer = new char[len + 1];
			strcpy(req.manufacturer, temp_str);
		}
		else {
			req.manufacturer = NULL;
		}
		cout << "������ ��������: ";
		cin.getline(temp_str, 50);
		if (strlen(temp_str) > 0) {
			size_t len = strlen(temp_str);
			req.category = new char[len + 1];
			strcpy(req.category, temp_str);
		}
		else {
			req.category = NULL;
		}
		cout << "������ �������� ���� (0 ��� �����������): ";
		if (!(cin >> req.minPrice)) req.minPrice = 0;

		cout << "������ ����������� ���� (0 ��� �����������): ";
		if (!(cin >> req.maxPrice)) req.maxPrice = 0;
		cin.ignore(10000, '\n');

		char date_choice;
		cout << "������ �� ��������� �����������? (Y/N): ";
		cin >> date_choice;
		cin.ignore(10000, '\n');
		if (date_choice == 'Y' || date_choice == 'y') {
			cout << "\n������ ��������� ���� �����������:\n";
			req.startDate = input_date("");
			cout << "\n������ ������ ���� �����������:\n";
			req.endDate = input_date("");
		}
		cout << "������ �� ������������� (����� ��)? (Y/N): ";
		cin >> date_choice;
		cin.ignore(10000, '\n');
		if (date_choice == 'Y' || date_choice == 'y') {
			cout << "\n������ �������� ���� ���������� (�� ��� ������):\n";
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
		cout << "���������� �� ��������� ����.\n";
	}
	else {
		cout << "������� ������ (" << search_choice << ") �� �� ����������.\n";
	}
}
void show_menu() {
	cout << "\n ���� ������ \n";
	cout << "1. ������ �����\n";
	cout << "2. �������� ����� (�� ID)\n";
	cout << "3. ���������� ����� (���������)\n";
	cout << "4. ����� ������ (�� ���������)\n";
	cout << "5. ������� �� ������\n";
	cout << "6. �������� ������������ ������\n";
	cout << "7. ���������� ������\n";
	cout << "0. �����\n";
	cout << "��� ����: ";
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
			cout << "����������� ���! ���� �����, ������ �����.\n";
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
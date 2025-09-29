#include <iostream>
using namespace std;
const int SIZE_NAME = 30;

struct Product
{
	bool isExist;
	float price;
	double weight;
	char name[SIZE_NAME];
};


void fill_product(Product& prod)
{
	static int i = 0;
	if(i!=0)
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter name: ";
	cin.getline(prod.name, SIZE_NAME - 1);
	cout << "Enter price: ";
	cin >> prod.price;
	cout << "Enter weight: ";
	cin >> prod.weight;
	cout << "isExist (0 or 1): ";
	cin >> prod.isExist;
	++i;
}
void show_product(Product& prod)
{
	cout << "Pr. Name: " << prod.name << " Price: " << prod.price << " Weight: " << prod.weight << " ";
	(prod.isExist) ? cout << "On" : cout << "Off";
	cout << endl;
}

void sorting_product_by_price(Product* pr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (pr[i].price > pr[i + 1].price)
			{
				swap(pr[i], pr[i + 1]);
			}
		}
	}
}

void sorting_product_by_name(Product* pr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strcmp(pr[i].name,pr[i+1].name)==1)
			{
				swap(pr[i], pr[i + 1]);
			}
		}
	}
}

int main()
{
	const int N = 3;
	Product products[N];
	for (int i = 0; i < N; i++)
	{
		fill_product(products[i]);
	}
	for (int i = 0; i < N; i++)
	{
		show_product(products[i]);
	}
	cout << "=====================\n\n";
	//sorting_product_by_price(products, N);
	sorting_product_by_name(products, N);
	for (int i = 0; i < N; i++)
	{
		show_product(products[i]);
	}
	return 0;
}

/*

Alexander
Bond

*/
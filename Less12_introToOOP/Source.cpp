#include <iostream>
using namespace std;
//��� - ��'����� �������� �������������
//��'����� ������������
/*
ʳ�� ���:
0) ������������� - �� �� ������������ � ��� ����.
�� ������� �������� �������� ������ ��'���� � ����������� ����������
1) ������������
2) ������������
3) ����������
��'���� - �� ���������� ����� (instance)
����� ���� ���������� � ���� (����������) �� ������
������ - �� �������, �� ���������� � ������� ����� �� ��������
���������� ����������� ��'����
public, private, protected
*/
class Car
{
	private:
		char* model;
		char* color;
		double price;
	public:
		//����������� - �� ����� ��� ��������� ��'����
		//����������� ����������� �����������
		//��� �������� ��`���� �����
		//���� ����� ����� �� ���������� � ����� �����
		//���� ���� �� � ����
		Car() //default - �� �������������
		{
			price = 1000;
			color = nullptr;
			model = nullptr;
		}
		Car(double pr)
		{
			if (pr > 1000)
			{
				price = pr;
			}
			else
			{
				price = 1000;
			}
			color = nullptr;
			model = nullptr;
		}
		Car(const char* m, const char* c, double pr)
		{
			if (pr > 1000)
			{
				price = pr;
			}
			else
			{
				price = 1000;
			}
			int sizeM = strlen(m);
			int sizeC = strlen(c);
			model = new char[sizeM+1 + 1];
			color = new char[sizeC + 1];
			strcpy_s(model, sizeM + 1, m);
			strcpy_s(color, sizeC + 1, c);

		}
		void showCar()
		{
			cout << model <<" " << color << " " << price << endl;
		}
};

int main()
{
	const char* model = "audi";
	const char* color = "white";
	double price = 3000;
	Car audi{model, color, price};
	audi.showCar();
	return 0;
}
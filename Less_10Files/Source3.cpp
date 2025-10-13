#include <iostream>
using namespace std;

int main()
{
	const char* path = "test.dat";
	FILE* file;
	if (fopen_s(&file, path, "wb+") == 0)
	{
		long long n;
		cout << "Enter n: ";
		cin >> n;
		fwrite(&n, sizeof(long long), 1, file);
		cout << "Size: " << ftell(file) << endl;
		fseek(file, 0, SEEK_SET);
		long long m;
		fread(&m, sizeof(long long), 1, file);
		cout << "m: " << m;
		fclose(file);
	}
	return 0;
}
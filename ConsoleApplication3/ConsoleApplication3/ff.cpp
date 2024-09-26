
#include <iostream>
using namespace std;
struct student {
	long ID;
	char* name;
	int no;
	int* g;
};
double* printStudentAvg(student a[], int sz)
{
	double* av = new double[sz];
	for (int i = 0; i < sz; i++)
	{
		int sum = 0;
		for (int j = 0; j < a[i].no; ++j)
			sum += a[i].g[j];
		av[i] = sum / a[i].no;
	}
	return av;
}
void readArray(student st[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		st[i].name = new char[50];
		cout << "Enter ID for student " << i + 1 << ": ";
		cin >> st[i].ID;
		cout << "Enter name for student " << i + 1 << ": ";
		cin >> st[i].name;
		cout << "Enter number of grades for student " << i + 1 << ": ";
		cin >> st[i].no;
		st[i].g = new int[st[i].no];
		cout << "Enter grades for student " << i + 1 << ": ";
		for (int j = 0; j < st[i].no; j++)
		{
			cin >> st[i].g[j];
		}
	}
}
int main() {
	student st[10];
	readArray(st, 10);
	double* avg = printStudentAvg(st, 10);
	for (int i = 0; i < 10; i++)
		cout << avg[i] << " ";
	delete[]avg;
	for (int i = 0; i < 10; i++)
	{
		delete[]st[i].name;
		delete[]st[i].g;
	}
}
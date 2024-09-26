#include <iostream>
using namespace std;
void f(int arr[][5], int r) {
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < r; j++)
		{
			cin >> arr[i][j];
		}
	}
}
int main() {
	cout << f << endl;
}


#include <iostream>
using namespace std;

int main()
{
	int a[2][3] = { { 16,12,23 }, {10, 25, 26} };
	cout << *a[0] << "    " << *(a[0] + 4) << "   " << endl;
}

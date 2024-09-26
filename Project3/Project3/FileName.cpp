#include<iostream>
using namespace std;
int main() {
	int x=5;
	int* y = &x;
	cout << y++; //increases y by 4
	cout << y; //increases y by 20
}
#include<iostream>
using namespace std;
class rectangle {
private:
	double len, width;
public:
	double area() { return len * width; }
	//double perim() { return z * len + z * width; }
	void setlength(double n) {
		len = n;

	}
	void setwid(double w) {
		width = w;

	}
	double getlength() { return len; }
	double getwid() { return width; }
};
int main()
{
	rectangle a, b;
	//a = b; 
	cout << a.area();
	double x, y;
	cin >> x >> y;
	a.setlength(x);
	a.setwid(y);
	cout << a.getlength() << a.getwid();
	cout << a.area();
	
}
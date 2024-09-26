#include <iostream>
using namespace std;
class circle {
private:
	float radions;
public:
	circle()
	{
		radions = { 0 };
	}
	circle(float r) {
		radions = r;
	}
	void setr(float r) {
		radions = r;
	}
	float getr() { return radions; }
	float area() { return radions * 22 / 7; }
};
int main() {
	circle a;
	circle c(5.5);
	circle d = { 5 };
	c.setr(5);
	c.getr();
	cout << c.getr() << endl;
	cout << c.area();

		c.area();
}
#include<iostream>
#include<cstdlib>
#include<string.h>


using namespace std;
class Complex {
private:
	int real, image;
public:
	char* toString() {
		char* output = new char[1000];

		char* st1 = itoa(real);
		char* st2 = itoa(image);

		strcpy(output, st1);
		strcpy(output, "+");
		strcpy(output, st2);
		strcpy(output, "i\n");
		return output;
	}
	Complex(int r = 0, int i = 0) {
		real = r;
		image = i;
		cout << "constructor with 2 parameters is called \n";
	}
	Complex(const Complex& obj) {
		cout << "copy";
		real = obj.real;
		image = obj.image;
	}
	~Complex(){
		cout << "destructor";
	}
	
	void setReal(int r)
	{
		real = r;
	}
	void setImage(int i) 
	{
		image = i;
	}
	int getReal() {
		return real;
	} 
	int  getImage(){

		return image;
	}
	
	

};
int main() {
	Complex c;
	Complex d(2);
	Complex a(4, 3);
	int x, y;
	cin >> x >> y;
	c.setReal(x);
	c.setImage(y);
	cout << a.toString()<< ""<< d.toString()<<endl;
	//a + d;
	//ut << c.tostring();

}
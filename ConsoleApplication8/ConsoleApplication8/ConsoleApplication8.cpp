#include <iostream>
#include <string>

struct Complex {
    float real;
    float imaginary;
};

void toString(const Complex& c, std::string& str) {
    str = std::to_string(c.real);
    if (c.imaginary > 0) {
        str += "+";
    }
    str += std::to_string(c.imaginary) + "i";
}

Complex subComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    return result;
}

int main() {
    Complex a = { 3, 4 };
    Complex d = { 2, 0 };
    Complex c;

    std::string st;
    toString(a, st);
    std::cout << st << std::endl; 
    toString(d, st);
    std::cout << st << std::endl;

    c = subComplex(a, d);

    toString(c, st);
    std::cout << st << std::endl; 

    return 0;
}
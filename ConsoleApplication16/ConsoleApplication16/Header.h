#include <iostream>
#include <cstring> // For strlen and strcpy
using namespace std;

class String {
private:
    char* str;
    size_t length;

public:
    // Default constructor
    String() {
        str = nullptr;
        length = 0;
    }

    // Parameterized constructor
    String(const char* input) {
        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
    }

    // Copy constructor
    String(const String& other) 
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Overloaded assignment operator
    String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }

        delete[] str;

        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);

        return *this;
    }

    // Function to get the length of the string
    size_t getLength() const {
        return length;
    }

    // Function to get the string as a C-string
    const char* c_str() const {
        return str;
    }

    // Function to set the string
    void setString(const char* input) {
        delete[] str;

        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
    }

    // Function to check if the string is empty
    bool isEmpty() const {
        return length == 0;
    }

    // Overloaded insertion operator for output
    friend ostream& operator<<(ostream& os, const MyString& myStr) {
        if (myStr.str) {
            os << myStr.str;
        }
        return os;
    }

    // Overloaded extraction operator for input
    friend istream& operator>>(istream& is, String& myStr) {
        char buffer[1000];
        is.getline(buffer, 1000);
        myStr.setString(buffer);
        return is;
    }
};



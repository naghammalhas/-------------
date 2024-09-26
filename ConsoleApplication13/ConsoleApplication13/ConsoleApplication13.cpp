#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int MAXSIZE = 100;

struct Car {
    char* id;
    char* make;
    char* model;
    int year;
    char* color;
    int engine;
    int price;
};

void menu() {
    cout << "Please enter your choice (1-10):" << endl;
    cout << "1) Add a car record" << endl;
    cout << "2) Delete a car record" << endl;
    cout << "3) Update a car record" << endl;
    cout << "4) View all car records" << endl;
    cout << "5) View cars with price less than value" << endl;
    cout << "6) View cars by car make" << endl;
    cout << "7) View all cars sorted by price" << endl;
    cout << "8) View all cars sorted by year" << endl;
    cout << "9) Save" << endl;
    cout << "10) Quit" << endl;
}
int main() {
    Car cars[MAXSIZE];
    int size = 0;
    int choice;
    ifstream CARS;
    CARS.open("cars.txt");
    if (!CARS.is_open()) { cout << "error in opening file"; return 0; }
    int x;
    CARS >> x;
    cout << x << endl;
    CARS.close();

    while (true) {
      

        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            addRecord(cars, size);
            break;
        case 2:
            deleteRecord(cars, size);
            break;
        case 3:
            updateRecord(cars, size);
            break;
        case 4:
            display(cars, size);
            break;
        case 5:
            displayByPrice(cars, size);
            break;
        case 6:
            displayByMake(cars, size);
            break;
        case 7:
            displaySortedPrice(cars, size);
            break;
        case 8:
            displayByYear(cars, size);
            break;
        case 9:
            save(cars, size, "cars.txt");
            break;
        case 10:
            cout << "Quitting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 10." << endl;
        }
    }

    return 0;
}
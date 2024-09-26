#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXSIZE = 100;
const char FILE_PATH[] = "nagham8.txt";

struct Car {
    int id;
    char make[50];
    char model[50];
    int year;
    char color[20];
    int engine;
    int price;
};

void displayMenu();
void addRecord(Car cars[], int& size);
void updateRecord(Car cars[], int size);
void deleteRecord(Car cars[], int& size);
void displayAll(const Car cars[], int size);
void displayByPrice(const Car cars[], int size);
void displayByModel(const Car cars[], int size);
void displayByYear(const Car cars[], int size);
void displaySortedByPrice(Car cars[], int size);
void swap(Car& a, Car& b);
void loadFromFile(Car cars[], int& size);
void saveToFile(const Car cars[], int size);

int main() {
    Car cars[MAXSIZE];
    int size = 0;

    loadFromFile(cars, size);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addRecord(cars, size);
            saveToFile(cars, size);
            break;
        case 2:
            updateRecord(cars, size);
            saveToFile(cars, size);
            break;
        case 3:
            deleteRecord(cars, size);
            saveToFile(cars, size);
            break;
        case 4:
            displayAll(cars, size);
            break;
        case 5:
            displayByPrice(cars, size);
            break;
        case 6:
            displayByModel(cars, size);
            break;
        case 7:
            displayByYear(cars, size);
            break;
        case 8:
            displaySortedByPrice(cars, size);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    cout << "\nCar Dealership Management System\n";
    cout << "1. Add a new car record\n";
    cout << "2. Update an existing car record\n";
    cout << "3. Delete a car record\n";
    cout << "4. Display all car records\n";
    cout << "5. Display cars by price\n";
    cout << "6. Display cars by make\n";
    cout << "7. Display cars by year\n";
    cout << "8. Display cars sorted by price\n";
    cout << "0. Exit\n";
}

void addRecord(Car cars[], int& size) {
    if (size >= MAXSIZE) {
        cout << "Cannot add more records. The database is full.\n";
        return;
    }

    Car temp;
    ifstream inFile(FILE_PATH);
    if (!inFile) {
        cout << "Unable to open file " << FILE_PATH << "\n";
        return;
    }

    inFile >> temp.id >> temp.make >> temp.model >> temp.year >> temp.color >> temp.engine >> temp.price;
    inFile.close();

    cout << "New Car Record:\n";
    cout << temp.id << ' ' << temp.make << ' ' << temp.model << ' ' << temp.year << ' ' << temp.color << ' ' << temp.engine << ' ' << temp.price << '\n';
    cout << "Do you want to add this record? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        cars[size++] = temp;
        cout << "Car record added successfully.\n";
    }
    else {
        cout << "Car record not added.\n";
    }
}


void updateRecord(Car cars[], int size) {
    int id;
    cout << "Enter the car ID to update: ";
    cin >> id;

    for (int i = 0; i < size; ++i) {
        if (cars[i].id == id) {
            cout << "Enter new make (current: " << cars[i].make << "): ";
            cin >> cars[i].make;
            cout << "Enter new model (current: " << cars[i].model << "): ";
            cin >> cars[i].model;
            cout << "Enter new year (current: " << cars[i].year << "): ";
            cin >> cars[i].year;
            cout << "Enter new color (current: " << cars[i].color << "): ";
            cin >> cars[i].color;
            cout << "Enter new engine capacity (current: " << cars[i].engine << "): ";
            cin >> cars[i].engine;
            cout << "Enter new price (current: " << cars[i].price << "): ";
            cin >> cars[i].price;

            cout << "Car record updated successfully.\n";
            return;
        }
    }
    cout << "Car ID not found.\n";
}

void deleteRecord(Car cars[], int& size) {
    int id;
    cout << "Enter the car ID to delete: ";
    cin >> id;

    for (int i = 0; i < size; ++i) {
        if (cars[i].id == id) {
            cout << "Car Record to be deleted:\n";
            cout << cars[i].id << ' ' << cars[i].make << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].color << ' ' << cars[i].engine << ' ' << cars[i].price << '\n';
            cout << "Do you want to delete this record? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                cars[i] = cars[size - 1];
                --size;
                cout << "Car record deleted successfully.\n";
            }
            else {
                cout << "Car record not deleted.\n";
            }
            return;
        }
    }
    cout << "Car ID not found.\n";
}

void displayAll(const Car cars[], int size) {
    if (size == 0) {
        cout << "No car records available.\n";
        return;
    }

    cout << "ID Make Model Year Color Engine Price\n";
    for (int i = 0; i < size; ++i) {
        cout << cars[i].id << ' ' << cars[i].make << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].color << ' ' << cars[i].engine << ' ' << cars[i].price << '\n';
    }
}

void displayByPrice(const Car cars[], int size) {
    int price;
    cout << "Enter maximum price: ";
    cin >> price;

    cout << "Cars with price less than or equal to " << price << ":\n";
    for (int i = 0; i < size; ++i) {
        if (cars[i].price <= price) {
            cout << cars[i].id << ' ' << cars[i].make << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].color << ' ' << cars[i].engine << ' ' << cars[i].price << '\n';
        }
    }
}

void displayByModel(const Car cars[], int size) {
    char make[50];
    cout << "Enter make: ";
    cin >> make;

    cout << "Cars with make " << make << ":\n";
    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].make, make) == 0) {
            cout << cars[i].id << ' ' << cars[i].make << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].color << ' ' << cars[i].engine << ' ' << cars[i].price << '\n';
        }
    }
}

void displayByYear(const Car cars[], int size) {
    int year;
    cout << "Enter year: ";
    cin >> year;

    cout << "Cars with year " << year << ":\n";
    for (int i = 0; i < size; ++i) {
        if (cars[i].year == year) {
            cout << cars[i].id << ' ' << cars[i].make << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].color << ' ' << cars[i].engine << ' ' << cars[i].price << '\n';
        }
    }
}

void displaySortedByPrice(Car cars[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (cars[j].price > cars[j + 1].price) {
                swap(cars[j], cars[j + 1]);
            }
        }
    }

    displayAll(cars, size);
}

void swap(Car& a, Car& b) {
    Car temp = a;
    a = b;
    b = temp;
}

void loadFromFile(Car cars[], int& size) {
    ifstream inFile(FILE_PATH);
    if (!inFile) {
        cout << "Unable to open file " << FILE_PATH << "\n";
        return;
    }

    size = 0;
    while (inFile >> cars[size].id) {
        inFile >> cars[size].make >> cars[size].model >> cars[size].year >> cars[size].color >> cars[size].engine >> cars[size].price;
        ++size;
        if (size >= MAXSIZE) break;
    }

    inFile.close();
}

void saveToFile(const Car cars[], int size) {
    ofstream outFile(FILE_PATH);
    if (!outFile) {
        cout << "Unable to open file " << FILE_PATH << "\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        outFile << cars[i].id << ' ' << cars[i].make << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].color << ' ' << cars[i].engine << ' ' << cars[i].price << '\n';
    }

    outFile.close();
}
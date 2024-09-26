
#include <iostream>
#include<string.h>
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

    Car() {
        id = new char[100];
        make = new char[100];
        model = new char[100];
        color = new char[100];
    }

    ~Car() {
        delete[] id;
        delete[] make;
        delete[] model;
        delete[] color;
    }
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

void addRecord(Car cars[], int& size) {
    if (size >= MAXSIZE) {
        cout << "Cannot add more records. The storage is full." << endl;
        return;
    }

    Car temp;
    cout << "Enter car ID: ";
    cin >> temp.id;
    cout << "Enter car make: ";
    cin >> temp.make;
    cout << "Enter car model: ";
    cin >> temp.model;
    cout << "Enter car year: ";
    cin >> temp.year;
    cout << "Enter car color: ";
    cin >> temp.color;
    cout << "Enter car engine: ";
    cin >> temp.engine;
    cout << "Enter car price: ";
    cin >> temp.price;

    cout << "You entered:" << endl;
    cout << temp.id << " " << temp.make << " " << temp.model << " " << temp.year << " " << temp.color << " " << temp.engine << " " << temp.price << endl;
    cout << "Confirm addition (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        cars[size] = temp;
        size++;
        cout << "Record added." << endl;
    }
    else {
        cout << "Addition cancelled." << endl;
    }
}

void deleteRecord(Car cars[], int& size) {
    if (size == 0) {
        cout << "No records to delete." << endl;
       
    }

    char id[20];
    cout << "Enter car ID to delete: ";
    cin >> id;

    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].id, id) == 0) {
            cout << "You are about to delete the following record:" << endl;
            cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
            cout << "Confirm deletion (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                cars[i] = cars[size - 1];
                size--;
                cout << "Record deleted." << endl;
            }
            else {
                cout << "Deletion cancelled." << endl;
            }
            
        }
    }
    cout << "Record not found." << endl;
}

void updateRecord(Car cars[], int size) {
    if (size == 0) {
        cout << "No records to update." << endl;
        
    }

    char id[20];
    cout << "Enter car ID to update: ";
    cin >> id;

    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].id, id) == 0) {
            Car temp;
            cout << "Enter new car make: ";
            cin >> temp.make;
            cout << "Enter new car model: ";
            cin >> temp.model;
            cout << "Enter new car year: ";
            cin >> temp.year;
            cout << "Enter new car color: ";
            cin >> temp.color;
            cout << "Enter new car engine: ";
            cin >> temp.engine;
            cout << "Enter new car price: ";
            cin >> temp.price;

            cout << "You entered:" << endl;
            cout << id << " " << temp.make << " " << temp.model << " " << temp.year << " " << temp.color << " " << temp.engine << " " << temp.price << endl;
            cout << "Confirm update (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                strcpy_s(cars[i].make, sizeof(cars[i].make), temp.make);
                strcpy_s(cars[i].model, sizeof(cars[i].model), temp.model);
                cars[i].year = temp.year;
                strcpy_s(cars[i].color, sizeof(cars[i].color), temp.color);
                cars[i].engine = temp.engine;
                cars[i].price = temp.price;
                cout << "Record updated." << endl;
            }
            else {
                cout << "Update cancelled." << endl;
            }
          
        }
    }
    cout << "Record not found." << endl;
}

void display(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        
    }
    for (int i = 0; i < size; ++i) {
        cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
    }
}

void displayByPrice(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        
    }

    int price;
    cout << "Enter maximum price: ";
    cin >> price;

    for (int i = 0; i < size; ++i) {
        if (cars[i].price < price) {
            cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
        }
    }
}

void displayByMake(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
       
    }

    char make[20];
    cout << "Enter car make: ";
    cin >> make;

    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].make, make) == 0) {
            cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
        }
    }
}

void displayByYear(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        return;
    }

    int year;
    cout << "Enter car year: ";
    cin >> year;

    for (int i = 0; i < size; ++i) {
        if (cars[i].year == year) {
            cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
        }
    }
}

void displaySortedPrice(Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (cars[j].price > cars[j + 1].price) {
                Car temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }

    display(cars, size);
}

void save(const Car cars[], int size, const char* filename) {
    ofstream CARS("cars.txt");

    if (!CARS.is_open()) {
        cout << "error in opening file" << endl;
        return;
    }

    CARS << size << endl;
    for (int i = 0; i < size; ++i) {

        CARS << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
    }
    CARS.close();
    cout << "Records saved to " << "cars.txt" << endl;
}

int main() {
    Car cars[MAXSIZE];
    int size = 0;
    int choice;

    ifstream CARS;
    CARS.open("cars.txt");
    if (!CARS.is_open()) { cout << "error in opening file"; return 0; }
    
 
    else {
        CARS >> size;
        CARS.ignore();
        for (int i = 0; i < size; ++i) {
            CARS.getline(cars[i].id, 20);
            CARS.getline(cars[i].make, 20);
            CARS.getline(cars[i].model, 20);
            CARS >> cars[i].year;
            CARS.ignore();  
            CARS.getline(cars[i].color, 20);
            CARS >> cars[i].engine;
            CARS >> cars[i].price;
            CARS.ignore();  
        }
         CARS.close();
    }

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
            save(cars, size,"cars.txt" );
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

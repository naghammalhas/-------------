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

void addRecord(Car cars[], int& size) {
    if (size >= MAXSIZE) {
        cout << "Cannot add more records, the array is full." << endl;
        return;
    }

    Car newCar;
    newCar.id = new char[20];
    newCar.make = new char[20];
    newCar.model = new char[20];
    newCar.color = new char[20];

    cout << "Enter car ID: ";
    cin >> newCar.id;
    cout << "Enter car make: ";
    cin >> newCar.make;
    cout << "Enter car model: ";
    cin >> newCar.model;
    cout << "Enter car year: ";
    cin >> newCar.year;
    cout << "Enter car color: ";
    cin >> newCar.color;
    cout << "Enter car engine: ";
    cin >> newCar.engine;
    cout << "Enter car price: ";
    cin >> newCar.price;

    cout << "New Car Record: " << endl;
    cout << "ID: " << newCar.id << ", Make: " << newCar.make << ", Model: " << newCar.model << ", Year: " << newCar.year << ", Color: " << newCar.color << ", Engine: " << newCar.engine << ", Price: " << newCar.price << endl;
    cout << "Confirm addition (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        cars[size] = newCar;
        size++;
        cout << "Car added successfully!" << endl;
    }
    else {
        cout << "Addition cancelled." << endl;
    }
}

void deleteRecord(Car cars[], int& size) {
    if (size == 0) {
        cout << "No records to delete." << endl;
        return;
    }

    char id[20];
    cout << "Enter the ID of the car to delete: ";
    cin >> id;

    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].id, id) == 0) {
            cout << "Car Record to Delete: " << endl;
            cout << "ID: " << cars[i].id << ", Make: " << cars[i].make << ", Model: " << cars[i].model << ", Year: " << cars[i].year << ", Color: " << cars[i].color << ", Engine: " << cars[i].engine << ", Price: " << cars[i].price << endl;
            cout << "Confirm deletion (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                delete[] cars[i].id;
                delete[] cars[i].make;
                delete[] cars[i].model;
                delete[] cars[i].color;

                cars[i] = cars[size - 1];
                size--;
                cout << "Car deleted successfully!" << endl;
            }
            else {
                cout << "Deletion cancelled." << endl;
            }
            return;
        }
    }

    cout << "Car not found!" << endl;
}

void updateRecord(Car cars[], int size) {
    if (size == 0) {
        cout << "No records to update." << endl;
        return;
    }

    char id[20];
    cout << "Enter the ID of the car to update: ";
    cin >> id;

    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].id, id) == 0) {
            Car updatedCar;
            updatedCar.id = new char[20];
            updatedCar.make = new char[20];
            updatedCar.model = new char[20];
            updatedCar.color = new char[20];

            cout << "Enter new car make: ";
            cin >> updatedCar.make;
            cout << "Enter new car model: ";
            cin >> updatedCar.model;
            cout << "Enter new car year: ";
            cin >> updatedCar.year;
            cout << "Enter new car color: ";
            cin >> updatedCar.color;
            cout << "Enter new car engine: ";
            cin >> updatedCar.engine;
            cout << "Enter new car price: ";
            cin >> updatedCar.price;
            //strcpy(updatedCar.id, id);

            cout << "Updated Car Record: " << endl;
            cout << "ID: " << updatedCar.id << ", Make: " << updatedCar.make << ", Model: " << updatedCar.model << ", Year: " << updatedCar.year << ", Color: " << updatedCar.color << ", Engine: " << updatedCar.engine << ", Price: " << updatedCar.price << endl;
            cout << "Confirm update (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                delete[] cars[i].make;
                delete[] cars[i].model;
                delete[] cars[i].color;

                cars[i] = updatedCar;
                cout << "Car updated successfully!" << endl;
            }
            else {
                cout << "Update cancelled." << endl;
                delete[] updatedCar.id;
                delete[] updatedCar.make;
                delete[] updatedCar.model;
                delete[] updatedCar.color;
            }
            return;
        }
    }

    cout << "Car not found!" << endl;
}

void display(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        cout << "ID: " << cars[i].id << ", Make: " << cars[i].make << ", Model: " << cars[i].model << ", Year: " << cars[i].year << ", Color: " << cars[i].color << ", Engine: " << cars[i].engine << ", Price: " << cars[i].price << endl;
    }
}

void displayByPrice(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        return;
    }

    int maxPrice;
    cout << "Enter the maximum price: ";
    cin >> maxPrice;

    for (int i = 0; i < size; ++i) {
        if (cars[i].price < maxPrice) {
            cout << "ID: " << cars[i].id << ", Make: " << cars[i].make << ", Model: " << cars[i].model << ", Year: " << cars[i].year << ", Color: " << cars[i].color << ", Engine: " << cars[i].engine << ", Price: " << cars[i].price << endl;
        }
    }
}

void displayByMake(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        return;
    }

    char make[20];
    cout << "Enter the car make: ";
    cin >> make;

    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].make, make) == 0) {
            cout << "ID: " << cars[i].id << ", Make: " << cars[i].make << ", Model: " << cars[i].model << ", Year: " << cars[i].year << ", Color: " << cars[i].color << ", Engine: " << cars[i].engine << ", Price: " << cars[i].price << endl;
        }
    }
}

void displayByYear(const Car cars[], int size) {
    if (size == 0) {
        cout << "No records to display." << endl;
        return;
    }

    int year;
    cout << "Enter the year: ";
    cin >> year;

    for (int i = 0; i < size; ++i) {
        if (cars[i].year == year) {
            cout << "ID: " << cars[i].id << ", Make: " << cars[i].make << ", Model: " << cars[i].model << ", Year: " << cars[i].year << ", Color: " << cars[i].color << ", Engine: " << cars[i].engine << ", Price: " << cars[i].price << endl;
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
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    file << size << endl;
    for (int i = 0; i < size; ++i) {
        file << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
    }

    file.close();
    cout << "Records saved to " << filename << " successfully!" << endl;
}

int main() {
    Car cars[MAXSIZE];
    int size = 0;
    int choice;

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

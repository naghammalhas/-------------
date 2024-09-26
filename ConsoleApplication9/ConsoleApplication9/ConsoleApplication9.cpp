#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_CARS = 100;

struct Car {
    int id;
    char make[100];
    char model[100];
    int year;
    char color[100];
    int engine;
    int price;
};
void displayMenu() {
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

void loadCars(Car cars[], int* size, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Could not open file " << filename << endl;
        return;
    }

    file >> *size;
    for (int i = 0; i < *size; i++) {
        file >> cars[i].id >> cars[i].make >> cars[i].model >> cars[i].year >> cars[i].color >> cars[i].engine >> cars[i].price;
    }

    file.close();
}

void saveCars(const Car cars[], int size, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Could not open file " << filename << endl;
        return;
    }

    file << size << endl;
    for (int i = 0; i < size; i++) {
        file << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " " << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
    }

    file.close();
}

void addCar(Car cars[], int* size) {
    if (*size == MAX_CARS) {
        cout << "No more space to add cars." << endl;
        return;
    }

    cout << "Enter car ID: ";
    cin >> cars[*size].id;
    cout << "Enter car make: ";
    cin >> cars[*size].make;
    cout << "Enter car model: ";
    cin >> cars[*size].model;
    cout << "Enter car year: ";
    cin >> cars[*size].year;
    cout << "Enter car color: ";
    cin >> cars[*size].color;
}

int main() {
    Car cars[MAX_CARS];
    int size = 0;
    string filename = "cars.txt";

    loadCars(cars, &size, filename);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCar(cars, &size);
            break;
        case 2:
            deleteCar(cars, &size);
            break;
        case 3:
            updateCar(cars, size);
            break;
        case 4:
            viewAllCars(cars, size);
            break;
        case 5:
            viewCarsByPrice(cars, size);
            break;
        case 6:
            viewCarsByMake(cars, size);
            break;
        case 7:
            viewCarsByPriceSorted(cars, size);
            break;
        case 8:
            viewCarsByYearSorted(cars, size);
            break;
        case 9:
            saveCars(cars, size, filename);
            break;
        case 10:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}


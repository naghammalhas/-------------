#include <iostream>
using namespace std;

const int NUM_ROWS = 9;
const int NUM_COLS = 4;

int seats[NUM_ROWS][NUM_COLS] = { 0 };

bool isValid(int row, int col) {
    return (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS);
}

bool isSeatEmpty(int row, int col) {
    return seats[row][col] == 0;
}

void reserveSeat(int row, int col) {
    seats[row][col] = 1;
}

void deleteReservation(int row, int col) {
    seats[row][col] = 0;
}

void deleteAllReservations() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            seats[i][j] = 0;
        }
    }
}

void printSeatMap() {
    cout << "Flight Seat Map:" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            cout << "Seat " << i << j;
            if (seats[i][j] == 1) {
                cout << " Reserved" << endl;
            }
            else {
                cout << " Empty" << endl;
            }
        }
    }
}

int main() {
  
    while (true) {
        cout << "Please enter your choice (1-5):" << endl;
        cout << "1. Reserve a newly empty seat." << endl;
        cout << "2. Delete a reserved seat." << endl;
        cout << "3. Delete all reserved seats." << endl;
        cout << "4. Print out flight seat map." << endl;
        cout << "5. Quit." << endl;

        int choice;
        cin >> choice;
   
        switch (choice) {
        case 1:
            int row, col;
            do {
                cout << "Enter row number (0-8): ";
                cin >> row;
                cout << "Enter column number (0-3): ";
                cin >> col;

            } while (!isValid(row, col) || !isSeatEmpty(row, col));

            reserveSeat(row, col);
            cout << "Seat " << row << col << " has been reserved." << endl;
            break;
        case 2:
            do {
                cout << "Enter row number (0-8): ";
                cin >> row;
                cout << "Enter column number (0-3): ";
                cin >> col;
            } while (!isValid(row, col) || isSeatEmpty(row, col));

            deleteReservation(row, col);
            cout << "Reservation for seat " << row << col << " has been canceled." << endl;
            break;
        case 3:
            deleteAllReservations();
            cout << "All reservations have been canceled." << endl;
            break;
        case 4:
            printSeatMap();
            break;
        case 5:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

class Seat {
private:
    string seat_number;
    bool reserved;

public:
    Seat() {
        seat_number = "";
        reserved = false;
    }

    Seat(string num) {
        seat_number = num;
        reserved = false;
    }

    string get_seat_number() {
        return seat_number;
    }

    bool is_reserved() {
        return reserved;
    }

    void reserve() {
        reserved = true;
    }

    void cancel_reservation() {
        reserved = false;
    }

    void printInfo() {
        cout << "Seat " << seat_number;
        if (reserved) {
            cout << " Reserved" << endl;
        }
        else {
            cout << " Empty" << endl;
        }
    }
};

class Flight {
private:
    Seat seats[13][4];

public:
    Flight() {
        string seat_labels[13][4] = {
            {"A1", "B1", "C1", "D1"},
            {"A2", "B2", "C2", "D2"},
            {"A3", "B3", "C3", "D3"},
            {"A4", "B4", "C4", "D4"},
            {"A5", "B5", "C5", "D5"},
            {"A6", "B6", "C6", "D6"},
            {"A7", "B7", "C7", "D7"},
            {"A8", "B8", "C8", "D8"},
            {"A9", "B9", "C9", "D9"},
            {"A10", "B10", "C10", "D10"},
            {"A11", "B11", "C11", "D11"},
            {"A12", "B12", "C12", "D12"},
            {"A13", "B13", "C13", "D13"}
        };

        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                seats[i][j] = Seat(seat_labels[i][j]);
            }
        }
    }

    bool is_Valid(int row, int col) {
        return (row >= 0 && row < 13 && col >= 0 && col < 4);
    }

    bool is_Seat_Empty(int row, int col) {
        return !seats[row][col].is_reserved();
    }

    void reserve_Seat(int row, int col) {
        seats[row][col].reserve();
    }

    void Delete_Reservation(int row, int col) {
        seats[row][col].cancel_reservation();
    }

    void Delete_All_Reservations() {
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                seats[i][j].cancel_reservation();
            }
        }
    }

    void print_Seat_Map() {
        cout << "Flight Seat Map:" << endl;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                seats[i][j].printInfo();
            }
        }
    }
};

int main() {
    Flight flight;

    while (true) {
        cout << " please Enter your choice (1-5):" << endl;
        cout << "1. Reserve a newly empty seat." << endl;
        cout << "2. Delete a reserved seat." << endl;
        cout << "3. Delete all reserved seats." << endl;
        cout << "4. Print out flight seats map." << endl;
        cout << "5. Quit." << endl;


        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            int row, col;
            do {
                cout << "Enter row number (0-12): ";
                cin >> row;
                cout << "Enter column number (0-3): ";
                cin >> col;
            } while (!flight.is_Valid(row, col) || !flight.is_Seat_Empty(row, col));

            flight.reserve_Seat(row, col); flight.reserve_Seat(row, col);
            cout << "Seat " << row << col << " has been reserved." << endl;
           
            break;
        case 2:
            do {
                cout << "Enter row number (0-12): ";
                cin >> row;
                cout << "Enter column number (0-3): ";
                cin >> col;
            } while (!flight.is_Valid(row, col) || flight.is_Seat_Empty(row, col));

            flight.Delete_Reservation(row, col);
            cout << "Reservation for seat " << row << col << " has been canceled." << endl;
            break;
        case 3:
            flight.Delete_All_Reservations();
            cout << "All reservations have been canceled." << endl;
            break;
        case 4:
            flight.print_Seat_Map();
            break;
        case 5:
            cout << "Exiting the program " << endl;
            return 0;
        default:
            cout << "Invalid choice,Please enter a valid option (1-5) " << endl;
        }
    }

    return 0;
}

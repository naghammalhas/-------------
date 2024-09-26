#include <iostream>
using namespace std;

class Seat {
private:
    int seat_number;
    bool reserved;

public:
    Seat() {
        seat_number = 0;
        reserved = false;
    }

    Seat(int num) {
        seat_number = num;
        reserved = false;
    }

    int get_seat_number() {
        return seat_number;
    }

    bool is_reserved() {
        return reserved;
    }

    void reserve() {
        reserved = true;
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
    Seat seats[9][4];

public:
    Flight() {
        int seat_number = 11;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 4; j++) {
                seats[i][j] = Seat(seat_number);
                seat_number++;
                if (j == 1) {
                    seat_number++;
                }
            }
        }
    }

    bool is_Valid(int row, int col) {
        return (row >= 0 && row < 9 && col >= 0 && col < 4);
    }

    bool is_Seat_Empty(int row, int col) {
        return !seats[row][col].is_reserved();
    }

    void reserve_Seat(int row, int col) {
        seats[row][col].reserve();
    }


    void Delete_Reservation(int row, int col) {
        seats[row][col].reserve();
    }

    void Delete_All_Reservations() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 4; j++) {
                seats[i][j].reserve();
            }
        }
    }

    void print_Seat_Map() {
        cout << "Flight Seat Map:" << endl;
        for (int i = 0; i < 9; i++) {
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
                cout << "Enter row number (1-13): ";
                cin >> row;
                cout << "Enter column number (A-D): ";
                cin >> col;
            } while (!flight.is_Valid(row, col) || !flight.is_Seat_Empty(row, col));

            flight.reserve_Seat(row, col);
            cout << "Seat " << row << col << " has been reserved." << endl;
            break;
        case 2:
            do {
                cout << "Enter row number (1-13): ";
                cin >> row;
                cout << "Enter column number (A-D): ";
                cin >> col;
            } while (!flight.is_Valid(row, col) || !flight.is_Seat_Empty(row, col));

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

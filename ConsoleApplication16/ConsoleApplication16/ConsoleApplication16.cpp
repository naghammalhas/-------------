#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Seat {
private:
    string seat_number;
    string passenger_name;

public:
    Seat() {
        seat_number = "";
        passenger_name = "";
    }

    Seat(string num) {
        seat_number = num;
        passenger_name = "";
    }

    string get_seat_number() {
        return seat_number;
    }

    void set_seat_number(string num) {
        seat_number = num;
    }

    string get_passenger_name() {
        return passenger_name;
    }

    void set_passenger_name(string name) {
        passenger_name = name;
    }

    bool isEmpty() {
        return passenger_name.empty();
    }

    void reserve(string name) {
        passenger_name = name;
    }

    void cancel_reservation() {
        passenger_name = "";
    }

    void print_info() {
        cout << "Seat " << seat_number;
        if (!isEmpty()) {
            cout << " Reserved for " << passenger_name << endl;
        }
        else {
            cout << " Empty" << endl;
        }
    }

    static bool isValid(string seatNumber) {
        if (seatNumber.length() < 2 || seatNumber.length() > 3) {
            return false;
        }
        char rowChar = seatNumber[0];
        int row = stoi(seatNumber.substr(1));
        return (row >= 1 && row <= 13 && (rowChar == 'A' || rowChar == 'B' || rowChar == 'C' || rowChar == 'D'));
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

    bool is_valid_seat(int row, int col) {
        return (row >= 0 && row < 13 && col >= 0 && col < 4);
    }

    bool is_seat_empty(int row, int col) {
        return seats[row][col].isEmpty();
    }

    void reserve_seat(int row, int col, string passengerName) {
        seats[row][col].reserve(passengerName);
    }

    void delete_reservation(int row, int col) {
        seats[row][col].cancel_reservation();
    }

    void delete_all_reservations() {
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                seats[i][j].cancel_reservation();
            }
        }
    }

    Seat get_seat(int row, int col) {
        return seats[row][col];
    }

    void print_seat_map() {
        cout << "Flight Seat Map:" << endl;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                seats[i][j].print_info();
            }
        }
    }

    void read_passengers_file() {
        ifstream infile("passengers.txt");
        if (!infile) {
            cout << "Unable to open passengers.txt. File might not exist yet." << endl;
            return;
        }

        string line;
        while (getline(infile, line)) {
            size_t pos = line.find(":");
            if (pos != string::npos) {
                string seat_num = line.substr(0, pos);
                string passenger_name = line.substr(pos + 2); 

                if (Seat::isValid(seat_num)) {
                   
                    for (int i = 0; i < 13; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (seats[i][j].get_seat_number() == seat_num) {
                                seats[i][j].reserve(passenger_name);
                                break;
                            }
                        }
                    }
                }
            }
        }

        infile.close();
    }

    void update_passengers_file() {
        ofstream outfile("passengers.txt");
        if (!outfile) {
            cout << "Unable to open passengers.txt for writing." << endl;
            return;
        }

        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                if (!seats[i][j].isEmpty()) {
                    outfile << seats[i][j].get_seat_number() << ": " << seats[i][j].get_passenger_name() << endl;
                }
            }
        }

        outfile.close();
    }
};

int main() {
    Flight flight;

    while (true) {
        cout << "Please Enter your choice (1-6):" << endl;
        cout << "1. Read passengers' file." << endl;
        cout << "2. Reserve a new empty seat." << endl;
        cout << "3. Delete a reserved seat." << endl;
        cout << "4. Delete all reserved seats." << endl;
        cout << "5. Update passengers' file." << endl;
        cout << "6. Quit." << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            flight.read_passengers_file();
            cout << "Passengers' file has been read." << endl;
            break;
        case 2: {
            int row, col;
            cout << "Enter row number (0-12): ";
            cin >> row;
            cout << "Enter column number (0-3): ";
            cin >> col;

            if (!flight.is_valid_seat(row, col)) {
                cout << "Invalid seat position. Try again." << endl;
                break;
            }

            if (!flight.is_seat_empty(row, col)) {
                cout << "Seat is already reserved. Try another seat." << endl;
                break;
            }

            string passengerName;
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, passengerName);
            flight.reserve_seat(row, col, passengerName);
            cout << "Seat " << flight.get_seat(row, col).get_seat_number() << " has been reserved for " << passengerName << "." << endl;
            break;
        }
        case 3: {
            int row, col;
            cout << "Enter row number (0-12): ";
            cin >> row;
            cout << "Enter column number (0-3): ";
            cin >> col;

            if (!flight.is_valid_seat(row, col)) {
                cout << "Invalid seat position. Try again." << endl;
                break;
            }

            if (flight.is_seat_empty(row, col)) {
                cout << "Seat is already empty. Try another seat." << endl;
                break;
            }

            flight.delete_reservation(row, col);
            cout << "Reservation for seat " << flight.get_seat(row, col).get_seat_number() << " has been canceled." << endl;
            break;
        }
        case 4:
            flight.delete_all_reservations();
            cout << "All reservations have been canceled." << endl;
            break;
        case 5:
            flight.update_passengers_file();
            cout << "Passengers' file has been updated." << endl;
            break;
        case 6:
            cout << "Exiting the program" << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
    return 0;
}


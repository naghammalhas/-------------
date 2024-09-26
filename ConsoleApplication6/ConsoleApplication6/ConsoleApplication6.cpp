#include <iostream>
using namespace std;

void abbreviateMiddleName(char s[]) {
    int i = 0;
    char result[100]; // Assuming the result will not exceed 100 characters
    int resultIndex = 0;
    int namePart = 0; // 0: first name, 1: middle name, 2: last name

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            if (namePart == 0) {
                // First space encountered, indicating end of first name
                namePart = 1;
            }
            else if (namePart == 1) {
                // Second space encountered, indicating end of middle name
                namePart = 2;
            }
        }

        if (namePart == 1 && s[i] != ' ') {
            // Skip the full middle name, add only the first letter and a dot
            result[resultIndex++] = s[i];
            result[resultIndex++] = '.';
            result[resultIndex++] = ' ';
            namePart = 2;

            // Skip the rest of the middle name
            while (s[i] != ' ' && s[i] != '\0') {
                i++;
            }
            continue;
        }

        if (namePart != 1) {
            result[resultIndex++] = s[i];
        }

        i++;
    }
    result[resultIndex] = '\0';

    // Copy the result back to the original string
    i = 0;
    while (result[i] != '\0') {
        s[i] = result[i];
        i++;
    }
    s[i] = '\0';
}

int main() {
    char name1[100] = "Rami Yusuf Daraghma";
    char name2[100] = "John Michael Smith";

    cout << "Original Name 1: " << name1 << endl;
    abbreviateMiddleName(name1);
    cout << "Modified Name 1: " << name1 << endl;

    cout << "Original Name 2: " << name2 << endl;
    abbreviateMiddleName(name2);
    cout << "Modified Name 2: " << name2 << endl;

    return 0;
}

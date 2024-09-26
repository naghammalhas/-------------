#include <iostream>
using namespace std;

struct student {
    long ID;
    char* name;
    int no;
    int* g;
};

double* printStudentAvg(student a[], int sz) {
    double* av = new double[sz];
    for (int i = 0; i < sz; i++) {
        int sum = 0;
        for (int j = 0; j < a[i].no; ++j)
            sum += a[i].g[j];
        av[i] = sum / a[i].no;
    }
    return av;
}

double ClassAvg(double av[], int sz) {
    double totalSum = 0;
    for (int i = 0; i < sz; i++) {
        totalSum += av[i];
    }
    return totalSum / sz;
}

int countAboveClassAvg(double av[], int sz, double classAvg) {
    int count = 0;
    for (int i = 0; i < sz; i++) {
        if (av[i] > classAvg) {
            count++;
        }
    }
    return count;
}

void readArray(student st[], int sz) {
    for (int i = 0; i < sz; i++) {
        st[i].name = new char[50];
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> st[i].ID;
        cout << "Enter name for student " << i + 1 << ": ";
        cin >> st[i].name;
        cout << "Enter number of grades for student " << i + 1 << ": ";
        cin >> st[i].no;
        st[i].g = new int[st[i].no];
        cout << "Enter grades for student " << i + 1 << ": ";
        for (int j = 0; j < st[i].no; j++) {
            cin >> st[i].g[j];
        }
    }
}

int main() {
    const int numStudents = 3;
    student st[numStudents];

    readArray(st, numStudents);

    double* avg = printStudentAvg(st, numStudents);

    cout << "Individual Averages: " << endl;
    for (int i = 0; i < numStudents; i++)
        cout << avg[i] << " ";
    cout << endl;

    double classAvg = ClassAvg(avg, numStudents);
    cout << "Class Average: " << classAvg << endl;

    int countAboveAvg = countAboveClassAvg(avg, numStudents, classAvg);
    cout << "Number of students above class average: " << countAboveAvg << endl;

    delete[] avg;
    for (int i = 0; i < numStudents; i++) {
        delete[] st[i].name;
        delete[] st[i].g;
    }

    return 0;
}

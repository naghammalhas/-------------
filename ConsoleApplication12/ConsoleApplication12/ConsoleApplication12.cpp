#include <iostream>
using namespace std;
class Time {
private:
    int hours, minutes, seconds;
public:
    Time(int a = 0, int s = 0, int b = 0) {
        hours = a;
        minutes = s;
        seconds = b;
    }
    Time(const Time& t) {
        hours = t.hours;
        minutes = t.minutes;
        seconds=t.seconds;
    }
    void setHours(int a) { hours = a; }
    void setMinutes(int s) { minutes = s; }
    void setSeconds(int b) { seconds = b; }
    int getHours() { return hours; }
    int getMinutes() { return minutes; }
    int getSeconds() { return seconds; }
    void printTime() {
        cout << hours<< hours << ":" << minutes<< minutes << ":" << seconds<< seconds << "." << endl;
    }

    bool isValidTime (int a, int s, int b) {
        hours = a;
        minutes = s;
        seconds = b;
        if (hours > 0 && hours < 23) {
            if (minutes > 0 && minutes < 59) {
                if (seconds > 0 && seconds < 59) {
                    return 1;
                }


            }
        }
        else
           
        return 0;
    }
    ~Time() {}
};
 char* toString() {

    char* output = new char[1000];
    char st1[10], st2, st3;


    strcpy(output, st1);
    strcat(output, ":");
    strcat(output, st2);
    strcat(output, "PM");

    return output;

}


int main()
{
    Time t;
    int a, b, c;
    cout << "Enter hour \n";
    cin >> a;
    cout << "Enter minutes \n";
    cin >> b;
    cout << "Enter seconds \n";
    cin >> c;
    t.setHours(a);
    t.setMinutes(b);
    t.setSeconds(c);
    t.getHours();
    t.getMinutes();
    t.getSeconds();
    
    
    if (t.isValidTime(a, b, c))
    {
       t.printTime();
        cout << toString();
    }
    else
    {
        cout << "You Entered an invalid time\n";
    }
    return 0;

}


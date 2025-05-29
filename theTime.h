// Header för klassen time
//

#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int hour, minute, seconds;

public:
    // Konstruktor
    Time();
    Time(int pHour, int pMinute, int pSeconds);
    ~Time();

    // Sätt-funktioner
    void setHour(int pHour);
    void setMinute(int pMinute);
    void setSeconds(int pSeconds);
    void setNormalTime(int totalAeconds); // Konvertera sekunder till hour, min, sec

    // Get-funktioner
    int getHour() const {return hour;}
    int getMinute() const {return minute;}
    int getSeconds() const {return seconds;}
    int getTotalSeconds() const {return hour*60*60 + minute*60 + seconds;}

    // Operatorer
    Time operator+(const Time &time) const;
    bool operator<(const Time &time) const;
    bool operator==(const Time &time) const;
};
// In- och utskrift
ostream &operator<<(ostream &os, const Time &time);
istream &operator>>(istream &is, Time &time);
#endif //PROJECT_PROJECT_H

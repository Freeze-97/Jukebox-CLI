//
// Created by Admin on 2019-03-11.
// Definitionsfil

#include "theTime.h"

// Funktions-definitioner för klassen Time
Time::Time() {
    hour = minute = seconds = 0;
}
Time::Time(int pHour, int pMinute, int pSeconds) {
    setHour(pHour);
    setMinute(pMinute);
    setSeconds(pSeconds);
}
Time::~Time() = default;

void Time::setHour(int pHour) {
    if(pHour >= 0){
        hour = pHour;
    }
    else {
        hour = -1;
    }
}
void Time::setMinute(int pMinute) {
    if(pMinute >= 0& pMinute < 60){
        minute = pMinute;
    }
    else {
        minute = -1;
    }
}
void Time::setSeconds(int pSeconds) {
    if(pSeconds >= 0 && pSeconds < 60) {
        seconds = pSeconds;
    }
    else {
        seconds = -1;
    }
}
void Time::setNormalTime(int totalAeconds) {
    int second, minutes, hours;
    minutes = totalAeconds/60;
    second = totalAeconds%60;
    hours = minutes/60;
    minutes = minutes%60;
    hour = hours;
    minute = minutes;
    seconds = second;
}
Time Time::operator+(const Time &time) const {
    Time sum;
    sum.seconds = seconds + time.seconds;
    if (sum.seconds > 59) {
        sum.minute++;
        sum.seconds -= 60;
    }
    sum.minute += minute + time.minute;
    if (sum.minute > 59) {
        sum.hour++;
        sum.minute -= 60;
    }
    sum.hour += hour + time.hour;
    return sum;
}
bool Time::operator<(const Time &time) const {
    // Omvandlas till sekunder
    return (hour*60*60 + minute*60 + seconds) < (time.hour*60*60 + time.minute*60 + seconds);
}
bool Time::operator==(const Time &time) const {
    return seconds == time.seconds && minute == time.minute && hour == time.hour;
}
ostream &operator<<(ostream &os, const Time &time) {
    return os << time.getTotalSeconds();
}
istream &operator>>(istream &is, Time &time) {
    int allSeconds;
    is >> allSeconds;
    is.get();
    time.setNormalTime(allSeconds);
    return is;
}
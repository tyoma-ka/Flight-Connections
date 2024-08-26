#include <iostream>
#include <set>
#include <list>

#pragma once


class Duration {
    int hour;
    int minute;

public:
    Duration();
    Duration(int hour, int minute);
    bool setDuration(std::string duration);
    bool setDuration(int hours, int minutes);
    std::string getDuration() const;
    int getDurationInMinutes() const {return (hour * 60) + minute; }; //for sorting
    Duration operator+(const Duration &second) const;
};

class DateTime {
    int year;
    int month;
    int day;

    int hour;
    int minute;

public:
    DateTime();
    bool setDateTime(std::string datetime);
    bool putDateTime(int year0, int month0, int day0, int hour0, int minute0);
    std::string getDateTimeString() const;
    std::string getDateString() const;
    Duration operator-(const DateTime &second);

};

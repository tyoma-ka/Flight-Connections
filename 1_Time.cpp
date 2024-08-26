#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "1_Time.h"

bool check_interval(int cislo, int start, int end) {
    if (cislo < start || cislo > end) {
        return false;
    } return true;
}

Duration::Duration() {
    hour = -1;
    minute = -1;
}

Duration::Duration(int hour, int minute) {
    if (check_interval(hour, 0, 72) && check_interval(minute, 0, 59)) {
        this->hour = hour;
        this->minute = minute;
    }
}

DateTime::DateTime() {
    year = -1;
    month = -1;
    day = -1;
    hour = -1;
    minute = -1;
}

int getDaysByMonth(int month0, int year0) {
    switch (month0){
        case 1:
            return 31;
        case 2:
            if (year0 % 4 == 0) {
                return 29;
            } else {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;

    }
}

bool check_date(int year, int month,  int day) {
    if (day <= 0 || month <= 0) {
        return false;
    }
    if (day <= getDaysByMonth(month, year)) {
        return true;
    } return false;
}

bool DateTime::putDateTime(int year0, int month0, int day0, int hour0, int minute0) {
    year = -1;
    month = -1;
    day = -1;
    hour = -1;
    minute = -1;
    if (not check_interval(year0, 2023, 2124)) return false; // potom cez rok zmenim na 2025 - 2125
    if (not check_date(year0, month0, day0)) return false;
    if (not check_interval(hour0, 0, 23)) return false;
    if (not check_interval(minute0, 0, 59)) return false;
    year = year0;
    month = month0;
    day = day0;
    hour = hour0;
    minute = minute0;
    return true;
}


bool DateTime::setDateTime(std::string datetime) {
    if (datetime.empty()) return false;

    bool check = false;
    std::istringstream is(datetime);
    char dash;
    int year0;
    int month0;
    int day0;
    int hour0;
    int minute0;
    std::string datet;
    std::string timet;


    if (is >> year0 >> dash) {
        if (dash != '-') {
            return false;
        }
        if (is >> month0 >> dash) {
            if (dash != '-') {
                return false;
            }
            if (is >> day0 >> dash) {
                if (dash != ';') {
                    return false;
                }
                if (is >> hour0 >> dash) {
                    if (dash != ':') {
                        return false;
                    }
                    if (is >> minute0) {
                        check = true;
                    }
                }
            }
        }
    }
    if (not check) return false;
    if (not this->putDateTime(year0, month0, day0, hour0, minute0)) return false;
    return true;
}

Duration Duration::operator+(const Duration &second) const {
    Duration final;

    final.hour = hour + second.hour;
    final.minute = minute + second.minute;

    if (final.minute >= 60) {
        final.hour += final.minute / 60;
        final.minute %= 60;
    }
    return final;
}

std::string addZerosAtTheBegin(int cas, int size) {
    std::string formatted_cas = std::to_string(cas);
    std::string prefix;
    int offset = 0;
    while (formatted_cas.size() + offset < size) {
        prefix += "0";
        offset++;
    }
    formatted_cas = prefix + formatted_cas;
    return formatted_cas;
}

std::string DateTime::getDateTimeString() const {
    std::string final;
    //2023-01-01 12:00
    std::string formatted_month = addZerosAtTheBegin(month, 2);
    std::string formatted_day = addZerosAtTheBegin(day, 2);
    std::string formatted_hour = addZerosAtTheBegin(hour, 2);
    std::string formatted_minute = addZerosAtTheBegin(minute, 2);
    final = std::to_string(year) + "-"
            + formatted_month + "-"
            + formatted_day + ";"
            + formatted_hour + ":"
            + formatted_minute;
    return final;
}

std::string DateTime::getDateString() const {
    std::string final;
    std::string formatted_month = addZerosAtTheBegin(month, 2);
    std::string formatted_day = addZerosAtTheBegin(day, 2);
    final = std::to_string(year) + "-"
            + formatted_month + "-"
            + formatted_day;
    return final;
}

bool Duration::setDuration(int hour0, int minute0) {
    hour = -1;
    minute = -1;
    if (not check_interval(hour0, 0, 72)) return false;
    if (not check_interval(minute0, 0, 59)) return false;
    hour = hour0;
    minute = minute0;
    return true;
}

bool Duration::setDuration(std::string duration) {
    if (duration.empty()) return false;

    bool check = false;
    std::istringstream is(duration);
    char dash;
    int hour0;
    int minute0;

    if (is >> hour0 >> dash) {
        if (dash != ':') {
            return false;
        }
        if (is >> minute0) {
            check = true;
        }
    }
    if (not check) return false;
    if (not this->setDuration(hour0, minute0)) return false;
    return true;
}

std::string Duration::getDuration() const {
    std::string final;
    std::string formatted_hour = addZerosAtTheBegin(hour, 2);
    std::string formatted_minute = addZerosAtTheBegin(minute, 2);

    final = formatted_hour + ":" + formatted_minute;
    return final;
}

Duration DateTime::operator-(const DateTime &second) {
    Duration finalDuration;
    int year0;
    int month0;
    int day0;
    int hour0;
    int minute0;
    int diff = 0;
    minute0 = minute - second.minute;
    if (minute0 < 0) {
        diff = 1;
        minute0 = 60 + minute0;
    }
    hour0 = hour - second.hour - diff;
    diff = 0;
    if (hour0 < 0) {
        diff = 1;
        hour0 = 24 + hour0;
    }
    day0 = day - second.day - diff;
    diff = 0;
    if (day0 < 0) {
        diff = 1;
        hour0 += (24 * (day0 + getDaysByMonth(second.month, second.year)));
    } else {
        hour0 += (24 * day0);
    }
    month0 = month - second.month - diff;
    diff = 0;
    if (month0 < 0) {
        diff = 1;
        hour0 += ((24 * 30) * (month0 + 12));  //budeme aproximovat, ze v kazdom mesiace 30 dni. Aj tak to je uz dost dlhy duration
    } else {
        hour0 += (24 * month0);
    }
    year0 = year - second.year - diff;
    diff = 0;
    if (year0 < 0) {
        return finalDuration;
    } else {
        hour0 += ((24 * 365) * year0); //takze aproximujem ako z mesiacami
    }


    finalDuration.setDuration(hour0, minute0);
    return finalDuration;
}
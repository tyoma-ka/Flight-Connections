#include <iostream>

#pragma once

enum AircraftStatus {OK, WRONG_REGISTRATION = -1, WRONG_COUNTRY = -2, EMPTY_AIRCRAFT = -3};

class Aircraft {
    std::string registration;
    std::string type;
    std::string country;
    AircraftStatus status = EMPTY_AIRCRAFT;

public:
    Aircraft();
    bool setRegistration(const std::string &registration);
    void setType(const std::string &type);
    bool setCountry(const std::string &country);

    std::string getRegistration() const {return registration; };
    std::string getType() const {return type; };
    std::string getCountry() const {return country; };

    inline void setStatus(const AircraftStatus status0) { status = status0; };
    inline AircraftStatus getStatus() const { return status; };
};
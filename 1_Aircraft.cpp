#include <iostream>


#include "1_Aircraft.h"

Aircraft::Aircraft() {
    registration = "";
    type = "";
    country = "";
    status = EMPTY_AIRCRAFT;
}
bool checkSymbol(const char &symbol) {
    if ((symbol >= '0' && symbol <= '9') ||
        (symbol >= 'a' && symbol <= 'z') ||
        (symbol >= 'A' && symbol <= 'Z') ||
         symbol == '-') {
        return true;
    } return false;
}

bool checkRegistration(const std::string &registration) {
    size_t position_of_dash = registration.find('-');
    if (registration[0] == 'N') {
        if (position_of_dash != std::string::npos) {
            return false;
        }
    }
    else {
        if (position_of_dash == std::string::npos) {
            return false;
        }
        if (position_of_dash < 1 || position_of_dash > 4) {
            return false;
        }
    }

    for (size_t i = 0; i < registration.size(); ++i) {
        if (not checkSymbol(registration[i])) {
            return false;
        }
    } return true;
}

bool Aircraft::setRegistration(const std::string &registration) {
    if (registration.size() < 5 || registration.size() > 10 || not checkRegistration(registration)) {
        this->setStatus(WRONG_REGISTRATION);
        return false;
    }
    this->setStatus(OK);
    this->registration = registration;
    return true;
}

void Aircraft::setType(const std::string &type)  {
    this->type = type;
}

bool Aircraft::setCountry(const std::string &country) {
    if (country.size() != 2) {
        this->setStatus(WRONG_COUNTRY);
        return false;
    }
    this->setStatus(OK);
    this->country = country;
    return true;
}




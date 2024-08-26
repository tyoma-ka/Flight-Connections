#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "1_Flight.h"


bool Flight::setTime(const std::string &departure_time, const std::string &arrival_time) {
    if (not this->departure_time.setDateTime(departure_time) || not this->arrival_time.setDateTime(arrival_time)) {
        setStatus(WRONG_TIME);
        return false;
    }
    this->duration = this->arrival_time - this->departure_time;
    if (this->duration.getDuration() == "-1:-1") {
        setStatus(WRONG_TIME);
        return false;
    } return true;
}

std::string Flight::getDepartureTime() const {
    return departure_time.getDateTimeString();
}

std::string Flight::getArrivalTime() const {
    return arrival_time.getDateTimeString();
}

std::string Flight::getDuration() const {
    return duration.getDuration();
}
int checkAirportSymbol(const char &symbol) {
    if (symbol >= 'A' && symbol <= 'Z') return 1; //na buduce spravim upper funkciu aby aj a-z fungovalo
    return 0;
}

bool Airport::setAirport(const std::string &airport) {
    this->airportName = "";
    if (airport.size() != 3) {
        return false;
    }
    for (size_t i = 0; i < airport.size(); ++i) {
        if (not checkAirportSymbol(std::toupper(airport[i]))) {
            this->airportName = "";
            return false;
        } this->airportName += std::toupper(airport[i]);
    }
    return true;

}

bool Flight::setDepartureAirport(const std::string &airport) {
    if (not departureAirport.setAirport(airport)) {
        this->setStatus(WRONG_AIRPORT);
        return false;
    } return true;
}

bool Flight::setArrivalAirport(const std::string &airport) {
    if (not arrivalAirport.setAirport(airport)) {
        this->setStatus(WRONG_AIRPORT);
        return false;
    } return true;
}

bool Airline::setAirline(const std::string &airline) {
    if (airline.empty()) return false;
    this->airlineName = airline;
    return true;
}

void Flight::setAirline(const std::string &airline) {
    this->airline.setAirline(airline);
}

bool Flight::setAircraft(const std::string &registration, const std::string &type, const std::string &country) {
    if (not aircraft.setRegistration(registration) || not aircraft.setCountry(country)) {
        return false;
    }
    aircraft.setType(type);
    return true;
}

bool FlightNumber::setFlightNumber(const std::string &flight_number) {
    if (flight_number.size() < 3) return false;
    this->flightNumberName = flight_number;
    return true;
}

bool Flight::setFlightNumber(const std::string &flight_number) {
    if (not this->flightNumber.setFlightNumber(flight_number)) {
        setStatus(WRONG_FLIGHT_NUMBER);
        return false;
    }
    return true;
}

bool Flight::setPrice(int price) {
    if (price < 0) {
        setStatus(WRONG_PRICE);
        return false;
    }
    this->price = price;
    return true;
}

//departure_time&arrival_time&departureAirport&arrivalAirport&airline&flightNumber&price&registration&type&country&
bool Flight::readFromString(const std::string &flight_details) {
    if (flight_details.empty()) return false;

    int number = 0;
    std::string departure_time0;
    std::string arrival_time0;
    std::string departureAirport0;
    std::string arrivalAirport0;
    std::string airline0;
    std::string flightNumber0;
    int price0;
    std::string registration0;
    std::string type0;
    std::string country0;
    std::string current;
    for (size_t i = 0; i < flight_details.size(); ++i) {
        if (flight_details[i] == '&') {
            switch (number) {
                case 0:
                    departure_time0 = current;
                    break;
                case 1:
                    arrival_time0 = current;
                    break;
                case 2:
                    departureAirport0 = current;
                    break;
                case 3:
                    arrivalAirport0 = current;
                    break;
                case 4:
                    airline0 = current;
                    break;
                case 5:
                    flightNumber0 = current;
                    break;
                case 6:
                    price0 = std::stoi(current);
                    break;
                case 7:
                    registration0 = current;
                    break;
                case 8:
                    type0 = current;
                    break;
                case 9:
                    country0 = current;
                    break;
                default:
                    return false;
            } current = "";
            ++number;
        } else {
            current += flight_details[i];
        }
    }
    if (number != 10) return false;

    if (not this->setTime(departure_time0, arrival_time0)) return false;
    if (not this->setDepartureAirport(departureAirport0)) return false;
    if (not this->setArrivalAirport(arrivalAirport0)) return false;
    if (not this->setFlightNumber(flightNumber0)) return false;
    this->setAirline(airline0);
    if (not this->setPrice(price0)) return false;
    if (not this->setAircraft(registration0, type0, country0)) return false;
    return true;
}

void Flight::operator=(const Flight &input) {
    this->setTime(input.getDepartureTime(), input.getArrivalTime());
    this->setDepartureAirport(input.getDepartureAirport());
    this->setArrivalAirport(input.getArrivalAirport());
    this->setFlightNumber(input.getFlightNumber());
    this->setPrice(input.getPrice());
    this->setAirline(input.getAirline());
    this->setAircraft(input.getAircraft().getRegistration(), input.getAircraft().getType(), input.getAircraft().getCountry());
}


#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "2_Flights.h"

Flights::Flights() {
    numberOfFlights = 0;
    status = NO_FLIGHTS;
}


bool Flights::readFromFile(const std::string &fileName) {
    std::string row;
    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        return false;
    }
    while (std::getline(inFile, row)) {
        size_t oddelovac = row.find_first_of("\n\r\v\0");
        if (oddelovac != std::string::npos) {
            row.resize(oddelovac);
        }
        if (this->addFlight(row)) {
            numberOfFlights++;
        }
    }
    return true;

}

bool Flights::addFlight(const std::string &flightInfo) {
    Flight current_flight;
    current_flight.readFromString(flightInfo);
    if (flights.find(std::make_pair(current_flight.getDepartureTime(), current_flight.getFlightNumber())) != flights.end()) {
        return false;
    } else {
        flights[std::make_pair(current_flight.getDepartureTime(), current_flight.getFlightNumber())] = current_flight;
    } return true;
}

bool
Flights::saveToFile(const std::string &fileName, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) {
    std::ofstream current_file(fileName);
    if (not current_file) {
        return false;
    }
    current_file << getChosenFlightsStringFormatted(chosenFlights);
    current_file.close();
    return true;
}


std::string Flights::getChosenFlightsStringFormatted(std::map<std::pair<std::string, std::string>, Flight> chosenFlights) {
    std::string allFlights;
    std::string currentInfo;
    bool first = true;
    for (auto &[key, value] : chosenFlights) {
        if (first) {
            first = false;
        } else {
            allFlights += "\n";
        }
        currentInfo =   value.getDepartureTime() + '&' +
                        value.getArrivalTime() + '&' +
                        value.getDepartureAirport() + '&' +
                        value.getArrivalAirport() + '&' +
                        value.getAirline() + '&' +
                        value.getFlightNumber() + '&' +
                        std::to_string(value.getPrice()) + '&' +
                        value.getAircraft().getRegistration() + '&' +
                        value.getAircraft().getType() + '&' +
                        value.getAircraft().getCountry() + '&';
        allFlights += currentInfo;
    }
    return allFlights;
}

std::string Flights::getChosenFlightsString(std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::string allFlights;
    std::string currentInfo;
    std::ostringstream oss1;
    oss1 << "       " << "Departure"
        << std::setw(18) << "Arrival"
        << std::setw(6) << "from"
        << std::setw(4) << "to"
        << std::setw(25) << "Airline"
        << std::setw(11) << "FlightNo."
        << std::setw(6) << "Price"
        << std::setw(10) << "Reg."
        << std::setw(21) << "Type"
        << std::setw(6) << "Co"; //country of registration
    currentInfo = oss1.str();
    allFlights += currentInfo;
    allFlights += "\n";
    for (size_t i = 0; i < 123; ++i) allFlights += "-";
    for (auto &[key, value] : chosenFlights) {
        allFlights += "\n";
        std::ostringstream oss;
        oss << value.getDepartureTime()
            << std::setw(18) << value.getArrivalTime()
            << std::setw(5) << value.getDepartureAirport()
            << std::setw(5) << value.getArrivalAirport()
            << std::setw(25) << value.getAirline()
            << std::setw(10) << value.getFlightNumber()
            << std::setw(7) << std::to_string(value.getPrice())
            << std::setw(10) << value.getAircraft().getRegistration()
            << std::setw(21) << value.getAircraft().getType()
            << std::setw(6) << value.getAircraft().getCountry();
        currentInfo = oss.str();
        allFlights += currentInfo;
    } return allFlights;
}

std::string Flights::getChosenFlightsString(std::vector<Flight> chosenFlights) const {
    std::string allFlights;
    std::string currentInfo;
    std::ostringstream oss1;
    oss1 << "       " << "Departure"
         << std::setw(18) << "Arrival"
         << std::setw(6) << "from"
         << std::setw(4) << "to"
         << std::setw(25) << "Airline"
         << std::setw(11) << "FlightNo."
         << std::setw(6) << "Price"
         << std::setw(10) << "Reg."
         << std::setw(21) << "Type"
         << std::setw(6) << "Co"; //country of registration
    currentInfo = oss1.str();
    allFlights += currentInfo;
    allFlights += "\n";
    for (size_t i = 0; i < 123; ++i) allFlights += "-";
    Flight value;
    for (size_t i = 0; i < chosenFlights.size(); ++i) {
        value = chosenFlights[i];
        allFlights += "\n";
        std::ostringstream oss;
        oss << value.getDepartureTime()
            << std::setw(18) << value.getArrivalTime()
            << std::setw(5) << value.getDepartureAirport()
            << std::setw(5) << value.getArrivalAirport()
            << std::setw(25) << value.getAirline()
            << std::setw(10) << value.getFlightNumber()
            << std::setw(7) << std::to_string(value.getPrice())
            << std::setw(10) << value.getAircraft().getRegistration()
            << std::setw(21) << value.getAircraft().getType()
            << std::setw(6) << value.getAircraft().getCountry();
        currentInfo = oss.str();
        allFlights += currentInfo;
    } return allFlights;
}

std::map<std::pair<std::string, std::string>, Flight> Flights::getFlightsByFlightNumber(const std::string &flightNumber, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::map<std::pair<std::string, std::string>, Flight> newChosenFlights;
    for (auto &[key, value] : chosenFlights) {
        if (value.getFlightNumber() == flightNumber) {
            if (newChosenFlights.find(std::make_pair(value.getDepartureTime(), value.getFlightNumber())) == newChosenFlights.end()) {
                newChosenFlights[std::make_pair(value.getDepartureTime(), value.getFlightNumber())] = value;
            }
        }
    } return newChosenFlights;
}

std::map<std::pair<std::string, std::string>, Flight>
Flights::getFlightsByDateOfDeparture(const std::string &departureDate,
                                     std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::map<std::pair<std::string, std::string>, Flight> newChosenFlights;
    for (auto &[key, value] : chosenFlights) {
        if (value.getDepartureTimeT().getDateString() == departureDate) {
            if (newChosenFlights.find(std::make_pair(value.getDepartureTime(), value.getFlightNumber())) == newChosenFlights.end()) {
                newChosenFlights[std::make_pair(value.getDepartureTime(), value.getFlightNumber())] = value;
            }
        }
    } return newChosenFlights;
}

std::map<std::pair<std::string, std::string>, Flight>
Flights::getFlightsByDateOfArrival(const std::string &arrivalDate,
                                   std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::map<std::pair<std::string, std::string>, Flight> newChosenFlights;
    for (auto &[key, value] : chosenFlights) {
        if (value.getArrivalTimeT().getDateString() == arrivalDate) {
            if (newChosenFlights.find(std::make_pair(value.getDepartureTime(), value.getFlightNumber())) == newChosenFlights.end()) {
                newChosenFlights[std::make_pair(value.getDepartureTime(), value.getFlightNumber())] = value;
            }
        }
    } return newChosenFlights;
}

std::map<std::pair<std::string, std::string>, Flight>
Flights::getFlightsByAirportOfDeparture(const std::string &departureAirport,
                                        std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::map<std::pair<std::string, std::string>, Flight> newChosenFlights;
    for (auto &[key, value] : chosenFlights) {
        if (value.getDepartureAirport() == departureAirport) {
            if (newChosenFlights.find(std::make_pair(value.getDepartureTime(), value.getFlightNumber())) == newChosenFlights.end()) {
                newChosenFlights[std::make_pair(value.getDepartureTime(), value.getFlightNumber())] = value;
            }
        }
    } return newChosenFlights;
}

std::map<std::pair<std::string, std::string>, Flight>
Flights::getFlightsByAirportOfArrival(const std::string &arrivalAirport,
                                      std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::map<std::pair<std::string, std::string>, Flight> newChosenFlights;
    for (auto &[key, value] : chosenFlights) {
        if (value.getArrivalAirport() == arrivalAirport) {
            if (newChosenFlights.find(std::make_pair(value.getDepartureTime(), value.getFlightNumber())) == newChosenFlights.end()) {
                newChosenFlights[std::make_pair(value.getDepartureTime(), value.getFlightNumber())] = value;
            }
        }
    } return newChosenFlights;
}

std::map<std::pair<std::string, std::string>, Flight>
Flights::getFlightsByPrice(int from, int to,
                           std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::map<std::pair<std::string, std::string>, Flight> newChosenFlights;
    for (auto &[key, value] : chosenFlights) {
        if (value.getPrice() >= from && value.getPrice() <= to) {
            if (newChosenFlights.find(std::make_pair(value.getDepartureTime(), value.getFlightNumber())) == newChosenFlights.end()) {
                newChosenFlights[std::make_pair(value.getDepartureTime(), value.getFlightNumber())] = value;
            }
        }
    } return newChosenFlights;
}

std::map<std::pair<std::string, std::string>, Flight>
Flights::getFlightsByAirline(const std::string &airlineName,
                             std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const {
    std::map<std::pair<std::string, std::string>, Flight> newChosenFlights;
    for (auto &[key, value] : chosenFlights) {
        if (value.getAirline() == airlineName) {
            if (newChosenFlights.find(std::make_pair(value.getDepartureTime(), value.getFlightNumber())) == newChosenFlights.end()) {
                newChosenFlights[std::make_pair(value.getDepartureTime(), value.getFlightNumber())] = value;
            }
        }
    } return newChosenFlights;
}
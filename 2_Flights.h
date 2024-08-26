#include <iostream>
#include <map>

#pragma once

#include "1_Flight.h"

enum FlightsStatus  {NO_FLIGHTS = -2};

class Flights {
    std::map<std::pair<std::string, std::string>, Flight> flights;
    int numberOfFlights;
    FlightsStatus status;
public:
    Flights();
    bool readFromFile(const std::string &fileName);
    bool saveToFile(const std::string &fileName, std::map<std::pair<std::string, std::string>, Flight> chosenFlights);
    bool addFlight(const std::string &flightInfo);
    std::string getChosenFlightsStringFormatted(std::map<std::pair<std::string, std::string>, Flight> chosenFlights);

    //this function is made only for testing, it won't be used in CLI
    std::string getChosenFlightsString(std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;
    std::string getChosenFlightsString(std::vector<Flight> chosenFlights) const;
    std::map<std::pair<std::string, std::string>, Flight> getAllFlights() const {return flights; };


    std::map<std::pair<std::string, std::string>, Flight> getFlightsByAirline(const std::string &airlineName, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;
    std::map<std::pair<std::string, std::string>, Flight> getFlightsByFlightNumber(const std::string &flightNumber, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;
    std::map<std::pair<std::string, std::string>, Flight> getFlightsByDateOfDeparture(const std::string &departureDate, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;
    std::map<std::pair<std::string, std::string>, Flight> getFlightsByDateOfArrival(const std::string &arrivalDate, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;
    std::map<std::pair<std::string, std::string>, Flight> getFlightsByAirportOfDeparture(const std::string &departureAirport, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;
    std::map<std::pair<std::string, std::string>, Flight> getFlightsByAirportOfArrival(const std::string &arrivalAirport, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;
    std::map<std::pair<std::string, std::string>, Flight> getFlightsByPrice(int from, int to, std::map<std::pair<std::string, std::string>, Flight> chosenFlights) const;

    inline void setStatus(const FlightsStatus status0) { status = status0; };
    inline FlightsStatus getStatus() const { return status; };
};


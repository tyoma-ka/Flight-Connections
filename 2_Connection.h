#include <iostream>
#include <map>
#include <set>
#include <vector>

#pragma once

#include "1_Flight.h"


class Connection {
    int numberOfTransfers;
    std::vector<Airport> listOfAirports;
    std::vector<FlightNumber> listOfFlightNumbers;
    std::set<Airline> setOfAirlines;
    std::string allTimesOfDepartures; //is used for identification in Connections
    DateTime firstDeparture;
    DateTime lastArrival;
    Duration totalDuration;
    int totalPrice;

public:
    Connection();
    void addNumberOfTransfers();
    bool addAirport(const Airport& airport);
    void addFlightNumber(const FlightNumber& flightNumber);
    void addAirline(const Airline& airline);
    void addDuration(DateTime lastDeparture0, DateTime lastArrival0);
    void addPrice(int price);
    bool appendConnection(Flight &flight);

    int getNumberOfTransfers() const {return numberOfTransfers; };
    std::string getListOfAirports() const;
    std::string getListOfFlightNumbers() const;
    std::string getSetOfAirlines() const;
    std::string getAllDatesOfDepartures() const {return allTimesOfDepartures; };
    Duration getTotalDuration() const;
    int getTotalDurationInMinutes() const {return totalDuration.getDurationInMinutes(); };
    int getTotalPrice() const;
    DateTime getFirstDeparture() const {return firstDeparture; };

};
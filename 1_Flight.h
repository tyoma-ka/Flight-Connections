#include <iostream>

#pragma once

#include "1_Aircraft.h"
#include "1_Time.h"

enum FlightStatus {WRONG_TIME = -1, WRONG_AIRPORT = -2, WRONG_PRICE = -3, WRONG_FLIGHT_NUMBER = -4};

class Airport {
    std::string airportName;
public:
    bool setAirport(const std::string &airport);
    std::string getAirport() const {return airportName; };
};

class Airline {
    std::string airlineName;
public:
    bool setAirline(const std::string &airline);
    std::string getAirline() const {return airlineName; };
    bool operator<(const Airline& other) const {
        return airlineName < other.airlineName;
    }
};

class FlightNumber {
    std::string flightNumberName;
public:
    bool setFlightNumber(const std::string &flight_number);
    std::string getFlightNumber() const {return flightNumberName; };
};

class Flight {
    DateTime departure_time;
    DateTime arrival_time;
    Duration duration;
    Airport departureAirport;
    Airport arrivalAirport;
    Airline airline;
    FlightNumber flightNumber;
    int price;
    Aircraft aircraft;
    FlightStatus status;

public:
    bool setTime(const std::string &departure_time, const std::string &arrival_time);
    bool setDepartureAirport(const std::string &airport);
    bool setArrivalAirport(const std::string &airport);
    void setAirline(const std::string &airline);
    bool setAircraft(const std::string &registration, const std::string &type, const std::string &country);
    bool setPrice(int price);
    bool setFlightNumber(const std::string &flight_number);
    bool readFromString(const std::string &flight_details);

    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    DateTime getDepartureTimeT() const {return departure_time; };
    DateTime getArrivalTimeT() const {return arrival_time; };
    std::string getDuration() const;
    int getDurationInMinutes() const {return duration.getDurationInMinutes(); };
    int getPrice() const {return price; }

    std::string getDepartureAirport() const {return departureAirport.getAirport(); };
    std::string getArrivalAirport() const {return arrivalAirport.getAirport(); };
    std::string getAirline() const {return airline.getAirline(); };
    std::string getFlightNumber() const {return flightNumber.getFlightNumber(); };
    Aircraft getAircraft() const {return aircraft; };
    Airport getDepartureAirportT() const {return departureAirport; };
    Airport getArrivalAirportT() const {return arrivalAirport; };
    FlightNumber getFlightNumberT() const {return flightNumber; };
    Airline getAirlineT() const {return airline; };
    Duration getDurationT() const {return duration; };


    inline void setStatus(const FlightStatus status0) { status = status0; };
    inline FlightStatus getStatus() const { return status; };

    void operator=(const Flight &input);
};

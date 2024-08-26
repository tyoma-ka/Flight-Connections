#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "2_Connection.h"

Connection::Connection() {
    numberOfTransfers = -1;
    totalDuration = *new Duration(0, 0);
    totalPrice = 0;
}

void Connection::addNumberOfTransfers() {
    numberOfTransfers += 1;
}

bool Connection::addAirport(const Airport& airport) {
    for (size_t i = 0; i < listOfAirports.size(); ++i) {
        if (listOfAirports[i].getAirport() == airport.getAirport()) { //this airport already exists in connection
            return false;                                             //example: DXB -> BTS -> DXB
        }
    } listOfAirports.push_back(airport);
    return true;
}

void Connection::addFlightNumber(const FlightNumber& flightNumber) {
    listOfFlightNumbers.push_back(flightNumber);
}

void Connection::addAirline(const Airline& airline) {
    setOfAirlines.insert(airline);
}

void Connection::addDuration(DateTime lastDeparture0, DateTime lastArrival0) {
    if (firstDeparture.getDateString() == "-1--1--1") {
        firstDeparture = lastDeparture0;
    }
    allTimesOfDepartures += lastDeparture0.getDateTimeString();
    totalDuration = lastArrival0 - firstDeparture;
    lastArrival = lastArrival0;
}

void Connection::addPrice(int price) {
    totalPrice += price;
}

std::string Connection::getListOfAirports() const {
    std::string final;
    bool first = true;
    for (size_t i = 0; i < listOfAirports.size(); ++i) {
        if (first) first = false;
        else final += " -> ";
        final += listOfAirports[i].getAirport();
    } return final;
}

std::string Connection::getListOfFlightNumbers() const {
    std::string final;
    bool first = true;
    for (size_t i = 0; i < listOfFlightNumbers.size(); ++i) {
        if (first) first = false;
        else final += " -> ";
        final += listOfFlightNumbers[i].getFlightNumber();
    } return final;
}

std::string Connection::getSetOfAirlines() const {
    std::string final;
    bool first = true;
    for (auto &airline : setOfAirlines) {
        if (first) first = false;
        else final += ", ";
        final += airline.getAirline();
    } return final;
}

Duration Connection::getTotalDuration() const {
    return totalDuration;
}

int Connection::getTotalPrice() const {
    return totalPrice;
}

bool Connection::appendConnection(Flight &flight) {
    if (numberOfTransfers == -1) {
        this->addAirport(flight.getDepartureAirportT());
        this->addAirport(flight.getArrivalAirportT());
        this->addNumberOfTransfers();
        this->addFlightNumber(flight.getFlightNumberT());
        this->addAirline(flight.getAirlineT());
        this->addDuration(flight.getDepartureTimeT(), flight.getArrivalTimeT());
        this->addPrice(flight.getPrice());
        return true;
    }
    if (flight.getDepartureAirport() != listOfAirports[numberOfTransfers + 1].getAirport()) {
        return false;
    } if ((flight.getDepartureTimeT() - lastArrival).getDurationInMinutes() < Duration(1, 0).getDurationInMinutes()) {
        return false;
    }
    this->addAirport(flight.getArrivalAirportT());
    this->addNumberOfTransfers();
    this->addFlightNumber(flight.getFlightNumberT());
    this->addAirline(flight.getAirlineT());
    this->addDuration(flight.getDepartureTimeT(), flight.getArrivalTimeT());
    this->addPrice(flight.getPrice());
    return true;
}
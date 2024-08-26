#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "3_Connections.h"


Connections::Connections(std::map<std::pair<std::string, std::string>, Flight> allFlights) {
    this->addConnectionsFromFlights(allFlights);
}
bool Connections::addConnection(Connection &con) {
    if (con.getNumberOfTransfers() == -1) return false;
    if (connections.find(std::make_pair(con.getAllDatesOfDepartures(), con.getListOfFlightNumbers())) != connections.end()) {
        return false;
    } else {
        connections[std::make_pair(con.getAllDatesOfDepartures(), con.getListOfFlightNumbers())] = con;
    }
    return true;
}

void Connections::addConnectionsFromFlights(std::map<std::pair<std::string, std::string>, Flight> flights0) {
    for (auto &[key, value] : flights0) {
        Connection con;
        con.appendConnection(value);
        this->addConnection(con);
    }
}


std::string
Connections::getChosenConnections(std::map<std::pair<std::string, std::string>, Connection> chosenConnections) const {
    std::string allConnections;
    std::string currentInfo;
    std::ostringstream oss1;
    oss1 << "From"
        << std::setw(15) << "To"
        << std::setw(40) << "Airlines"
        << std::setw(35) << "Flight Numbers"
        << std::setw(27) << "Total Price";

    currentInfo = oss1.str();
    allConnections += currentInfo;
    allConnections += "\n";
    for (size_t i = 0; i < 123; ++i) allConnections += "-";
    for (auto &[key, value] : chosenConnections) {
        allConnections += "\n";
        std::ostringstream oss;
        oss << value.getListOfAirports()
            << std::setw(50) << value.getSetOfAirlines()
            << std::setw(30) << value.getListOfFlightNumbers()
            << std::setw(25) << std::to_string(value.getTotalPrice());
        currentInfo = oss.str();
        allConnections += currentInfo;
    } return allConnections;
}

std::string Connections::getChosenConnections(std::vector<Connection> chosenConnections) const {
    std::string allConnections;
    std::string currentInfo;
    std::ostringstream oss1;
    oss1 << "From"
         << std::setw(15) << "To"
         << std::setw(40) << "Airlines"
         << std::setw(35) << "Flight Numbers"
         << std::setw(27) << "Total Price";

    currentInfo = oss1.str();
    allConnections += currentInfo;
    allConnections += "\n";
    for (size_t i = 0; i < 123; ++i) allConnections += "-";
    Connection value;
    for (size_t i = 0; i < chosenConnections.size(); ++i) {
        value = chosenConnections[i];
        allConnections += "\n";
        std::ostringstream oss;
        oss << value.getListOfAirports()
            << std::setw(50) << value.getSetOfAirlines()
            << std::setw(30) << value.getListOfFlightNumbers()
            << std::setw(25) << std::to_string(value.getTotalPrice());
        currentInfo = oss.str();
        allConnections += currentInfo;
    } return allConnections;
}
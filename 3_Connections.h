#include <iostream>
#include <map>
#include <set>
#include <vector>

#pragma once

#include "2_Connection.h"

struct AirportComparator {
    bool operator()(const Airport& a1, const Airport& a2) const {
        return a1.getAirport() < a2.getAirport();
    }
};

struct ConnectionComparator {
    bool operator()(const Connection& c1, const Connection& c2) const {
        return c1.getListOfFlightNumbers() < c2.getListOfFlightNumbers();
    }
};

class Connections {
    std::map<std::pair<std::string, std::string>, Connection> connections;
    std::map<Airport, std::set<Airport, AirportComparator>, AirportComparator> graph;
    std::map<Airport, std::set<Connection, ConnectionComparator>, AirportComparator> setOfConnectionsPerAirport;


public:
    Connections() = default;
    Connections(std::map<std::pair<std::string, std::string>, Flight> allFlights);
    bool createGrafOfConnections(std::map<std::pair<std::string, std::string>, Flight> &flights, Airport from);
    bool findConnection(Airport to, int maxNumberOfTransfers);
    bool addConnection(Connection &con);
    void addConnectionsFromFlights(std::map<std::pair<std::string, std::string>, Flight> flights0);

    std::map<std::pair<std::string, std::string>, Connection> getAllConnections() const {return connections; };
    std::string getChosenConnections(std::map<std::pair<std::string, std::string>, Connection> chosenConnections) const;
    std::string getChosenConnections(std::vector<Connection> chosenConnections) const;
};
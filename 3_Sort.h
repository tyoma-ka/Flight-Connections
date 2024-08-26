#include <iostream>
#include <map>
#include <vector>

#pragma once

#include "2_Flights.h"
#include "3_Connections.h"


class Sort {
    std::map<std::pair<std::string, std::string>, Flight> flights;
public:
    static std::vector<Flight> orderByPriceAsc(std::map<std::pair<std::string, std::string>, Flight> &flights);
    static std::vector<Connection> orderByPriceAsc(std::map<std::pair<std::string, std::string>, Connection> &&connections);
    static std::vector<Flight> orderByPriceDesc(std::map<std::pair<std::string, std::string>, Flight> &flights);
    static std::vector<Connection> orderByPriceDesc(std::map<std::pair<std::string, std::string>, Connection> &&connections);
    static std::vector<Flight> orderByDuration(std::map<std::pair<std::string, std::string>, Flight> &flights);
    static std::vector<Connection> orderByDuration(std::map<std::pair<std::string, std::string>, Connection> &&connections);
};
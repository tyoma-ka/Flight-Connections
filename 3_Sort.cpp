#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "3_Sort.h"

template<typename T>
int partition(std::vector<T>& arr, int low, int high, int (T::*getAttr)() const) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if ((arr[j].*getAttr)() < (pivot.*getAttr)()) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<typename T>
void quickSort(std::vector<T>& arr, int low, int high, int (T::*getAttr)() const) {
    if (low < high) {
        int pi = partition(arr, low, high, getAttr);
        quickSort(arr, low, pi - 1, getAttr);
        quickSort(arr, pi + 1, high, getAttr);
    }
}

std::vector<Flight> Sort::orderByPriceAsc(std::map<std::pair<std::string, std::string>, Flight> &flights) {
    std::vector<Flight> SortedList;
    for (auto &[key, value] : flights) {
        SortedList.push_back(value);
    }
    quickSort(SortedList, 0, SortedList.size() - 1, &Flight::getPrice);
    return SortedList;
}

std::vector<Connection> Sort::orderByPriceAsc(std::map<std::pair<std::string, std::string>, Connection> &&connections) {
    std::vector<Connection> SortedList;
    for (auto &[key, value] : connections) {
        SortedList.push_back(value);
    }
    quickSort(SortedList, 0, SortedList.size() - 1, &Connection::getTotalPrice);
    return SortedList;
}

std::vector<Flight> Sort::orderByPriceDesc(std::map<std::pair<std::string, std::string>, Flight> &flights) {
    std::vector<Flight> SortedList = Sort::orderByPriceAsc(flights);
    std::reverse(SortedList.begin(), SortedList.end());
    return SortedList;
}

std::vector<Connection>
Sort::orderByPriceDesc(std::map<std::pair<std::string, std::string>, Connection> &&connections) {
    std::vector<Connection> SortedList = Sort::orderByPriceAsc(std::move(connections));
    std::reverse(SortedList.begin(), SortedList.end());
    return SortedList;
}

std::vector<Flight> Sort::orderByDuration(std::map<std::pair<std::string, std::string>, Flight> &flights) {
    std::vector<Flight> SortedList;
    for (auto &[key, value] : flights) {
        SortedList.push_back(value);
    }
    quickSort(SortedList, 0, SortedList.size() - 1, &Flight::getDurationInMinutes);
    return SortedList;
}

std::vector<Connection> Sort::orderByDuration(std::map<std::pair<std::string, std::string>, Connection> &&connections) {
    std::vector<Connection> SortedList;
    for (auto &[key, value] : connections) {
        SortedList.push_back(value);
    }
    quickSort(SortedList, 0, SortedList.size() - 1, &Connection::getTotalDurationInMinutes);
    return SortedList;
}
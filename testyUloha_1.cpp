// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_Time.h"
#include "1_Aircraft.h"
#include "1_Flight.h"

using namespace ::testing;

// 1.uloha
TEST(TestFirstTask, TimeTest) {
    DateTime timeTest;
    ASSERT_EQ(1, timeTest.setDateTime("2023-01-01;15:00"));
    ASSERT_EQ("2023-01-01;15:00", timeTest.getDateTimeString());
    ASSERT_EQ("2023-01-01", timeTest.getDateString());
    Duration durTest;
    ASSERT_EQ(1, durTest.setDuration("23:09"));
    ASSERT_EQ("23:09", durTest.getDuration());

    DateTime timeTest2;
    ASSERT_EQ(1, timeTest2.setDateTime("2023-01-01;14:01"));
    Duration dur = timeTest - timeTest2;
    ASSERT_EQ("00:59", dur.getDuration());
}

TEST(TestFirstTask, TimeDifferences) {
    DateTime departure;
    DateTime arrival;
    ASSERT_EQ(1, departure.setDateTime("2023-12-31;01:00"));
    ASSERT_EQ(1, arrival.setDateTime("2024-01-01;02:00"));
    Duration dur = arrival - departure;
    ASSERT_EQ("25:00", dur.getDuration());
}

TEST(TestFirstTask, PrilisVelkeDuration) {
    DateTime departure;
    DateTime arrival;
    ASSERT_EQ(1, departure.setDateTime("2023-12-31;01:00"));
    ASSERT_EQ(1, arrival.setDateTime("2025-01-01;02:00"));
    Duration dur = arrival - departure;
    ASSERT_EQ("-1:-1", dur.getDuration());
}

TEST(TestFirstTask, MinutesTest) {
    DateTime departure;
    DateTime arrival;
    ASSERT_EQ(1, departure.setDateTime("2023-12-31;01:59"));
    ASSERT_EQ(1, arrival.setDateTime("2024-01-01;02:00"));
    Duration dur = arrival - departure;
    ASSERT_EQ("24:01", dur.getDuration());
}

TEST(TestFirstTask, NewYearFlight) {
    DateTime departure;
    DateTime arrival;
    ASSERT_EQ(1, departure.setDateTime("2023-12-31;23:59"));
    ASSERT_EQ(1, arrival.setDateTime("2024-01-01;00:00"));
    Duration dur = arrival - departure;
    ASSERT_EQ("00:01", dur.getDuration());
}

TEST(TestFirstTask, LongFlight) {
    DateTime departure;
    DateTime arrival;
    ASSERT_EQ(1, departure.setDateTime("2024-01-01;23:00"));
    ASSERT_EQ(1, arrival.setDateTime("2024-01-04;01:00"));
    Duration dur = arrival - departure;
    ASSERT_EQ("50:00", dur.getDuration());
}

TEST(TestFirstTask, TimeMachineFlight) {
    DateTime departure;
    DateTime arrival;
    ASSERT_EQ(1, departure.setDateTime("2024-01-02;23:00"));
    ASSERT_EQ(1, arrival.setDateTime("2024-01-01;01:00"));
    Duration dur = arrival - departure;
    ASSERT_EQ("-1:-1", dur.getDuration());
}

TEST(TestFirstTask, SpravnyRegistration) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("TC-JJE"));
}

TEST(TestFirstTask, NepovolenySymbol) {
    Aircraft aircraft;
    ASSERT_EQ(0, aircraft.setRegistration("TC-=RK"));
}

TEST(TestFirstTask, ViacSymbolovAkoJeDovolene) {
    Aircraft aircraft;
    ASSERT_EQ(0, aircraft.setRegistration("A6-EQQKLKHE9"));
}

TEST(TestFirstTask, MenejSymbolovAkoJeDovolene) {
    Aircraft aircraft;
    ASSERT_EQ(0, aircraft.setRegistration("B-LI"));
}

TEST(TestFirstTask, NeexistujeDash) {
    Aircraft aircraft;
    ASSERT_EQ(0, aircraft.setRegistration("DFUNC"));
}

TEST(TestFirstTask, WrongDashPosition) {
    Aircraft aircraft;
    ASSERT_EQ(0, aircraft.setRegistration("-DFUNC"));
    ASSERT_EQ(WRONG_REGISTRATION, aircraft.getStatus());
}

TEST(TestFirstTask, CorrectReg1) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("SP-RSR"));
}

TEST(TestFirstTask, BelaviaWorldofTanksLivery) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("EW-254PA"));
    ASSERT_EQ(OK, aircraft.getStatus());
}

TEST(TestFirstTask, BillGatesBusinessJet) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("N887WM"));
    ASSERT_EQ(OK, aircraft.getStatus());
}

TEST(TestFirstTask, WrongAmerican) {
    Aircraft aircraft;
    ASSERT_EQ(0, aircraft.setRegistration("N-887WM"));
    ASSERT_EQ(WRONG_REGISTRATION, aircraft.getStatus());
    ASSERT_EQ("", aircraft.getRegistration());
}

TEST(TestFirstTask, MichaelJordanJet) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("N236MJ"));
    ASSERT_EQ(OK, aircraft.getStatus());
}

TEST(TestFirstTask, SomeRyanairAircraft) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("SP-RSP"));
    ASSERT_EQ(OK, aircraft.getStatus());
    ASSERT_EQ("SP-RSP", aircraft.getRegistration());
}

TEST(TestFirstTask, CorrectReg2) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("G-JZHA"));
    ASSERT_EQ(OK, aircraft.getStatus());
}

TEST(TestFirstTask, CorrectLaos) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("RDPL-34022"));
    ASSERT_EQ(OK, aircraft.getStatus());
    aircraft.setType("Boeing 737-82R");
    ASSERT_EQ("Boeing 737-82R", aircraft.getType());
    aircraft.setCountry("LA");
    ASSERT_EQ(OK, aircraft.getStatus());
    ASSERT_EQ("LA", aircraft.getCountry());
}

TEST(TestFirstTask, IncorrectCountry) {
    Aircraft aircraft;
    ASSERT_EQ(1, aircraft.setRegistration("A6-EOK"));
    ASSERT_EQ(OK, aircraft.getStatus());
    aircraft.setType("Airbus A380-861");
    ASSERT_EQ(0, aircraft.setCountry("UAE"));
    ASSERT_EQ(WRONG_COUNTRY, aircraft.getStatus());
    ASSERT_EQ("", aircraft.getCountry());
}

TEST(TestFirstTask, InsertTime) {
    Flight flight;
    ASSERT_EQ(1, flight.setTime("2023-01-01;12:00", "2023-01-01;14:01"));
    ASSERT_EQ("2023-01-01;12:00", flight.getDepartureTime());
    ASSERT_EQ("2023-01-01;14:01", flight.getArrivalTime());
    ASSERT_EQ("02:01", flight.getDuration());
    ASSERT_EQ(1, flight.setDepartureAirport("BTS"));
    ASSERT_EQ(1, flight.setAircraft("G-DHLX", "Boeing 777-F", "GB"));
}

TEST(TestFirstTask, WrongAircraft) {
    Flight flight;
    ASSERT_EQ(0, flight.setAircraft("%G-DHLX", "Boeing 777-F", "GB"));
}

TEST(TestFirstTask, ArrivalBeforeDeparture) {
    Flight flight;
    ASSERT_EQ(0, flight.setTime("2023-01-01;15:00", "2023-01-01;14:01"));
}

TEST(TestFirstTask, Airports) {
    Flight flight;
    ASSERT_EQ(1, flight.setDepartureAirport("DXB"));
    ASSERT_EQ(1, flight.setArrivalAirport("LED"));
}

TEST(TestFirstTask, Price) {
    Flight flight;
    ASSERT_EQ(1, flight.setPrice(299));
    ASSERT_EQ(0, flight.setPrice(-20));
    ASSERT_EQ(1, flight.setPrice(0));
    ASSERT_EQ(1, flight.setPrice(19));
}
TEST(TestFirstTask, WrongFlightNumber) {
    Flight flight;
    ASSERT_EQ(1, flight.setFlightNumber("RYR2HR"));
    ASSERT_EQ(0, flight.setFlightNumber("RY"));
}

TEST(TestFirstTask, Airline) {
    Flight flight;
    flight.setAirline("Ryanair");
    ASSERT_EQ("Ryanair", flight.getAirline());
}

TEST(TestFirstTask, Flight1) {
    Flight flight;
    flight.setAirline("British Airways");
    ASSERT_EQ(1, flight.setPrice(399));
    ASSERT_EQ(1, flight.setDepartureAirport("KEF"));
    ASSERT_EQ(1, flight.setArrivalAirport("LHR"));
    ASSERT_EQ(1, flight.setAircraft("G-XWBB", "Airbus A350-1041", "GB"));
    ASSERT_EQ(1, flight.setTime("2023-12-17;18:45", "2023-12-17;21:20"));

    ASSERT_EQ("British Airways", flight.getAirline());
    ASSERT_EQ("KEF", flight.getDepartureAirport());
    ASSERT_EQ("LHR", flight.getArrivalAirport());
    ASSERT_EQ("Airbus A350-1041", flight.getAircraft().getType());
    ASSERT_EQ("G-XWBB", flight.getAircraft().getRegistration());
    ASSERT_EQ("GB", flight.getAircraft().getCountry());
    ASSERT_EQ("2023-12-17;18:45", flight.getDepartureTime());
    ASSERT_EQ("2023-12-17;21:20", flight.getArrivalTime());
    ASSERT_EQ("02:35", flight.getDuration());
}

TEST(TestFirstTask, Flight2) {
    Flight flight;
    flight.setAirline("Turkish Airlines");
    ASSERT_EQ(1, flight.setPrice(1090));
    ASSERT_EQ(1, flight.setDepartureAirport("IST"));
    ASSERT_EQ(1, flight.setArrivalAirport("ICN"));
    ASSERT_EQ(1, flight.setAircraft("TC-JJL", "Boeing 777-3F2(ER)", "TR"));
    ASSERT_EQ(1, flight.setTime("2023-12-17;17:10", "2023-12-18;08:55"));

    ASSERT_EQ("Turkish Airlines", flight.getAirline());
    ASSERT_EQ("IST", flight.getDepartureAirport());
    ASSERT_EQ("ICN", flight.getArrivalAirport());
    ASSERT_EQ("Boeing 777-3F2(ER)", flight.getAircraft().getType());
    ASSERT_EQ("TC-JJL", flight.getAircraft().getRegistration());
    ASSERT_EQ("TR", flight.getAircraft().getCountry());
    ASSERT_EQ("2023-12-17;17:10", flight.getDepartureTime());
    ASSERT_EQ("2023-12-18;08:55", flight.getArrivalTime());
    ASSERT_EQ("15:45", flight.getDuration());
}

TEST(TestFirstTask, WrongFlight3) {
    Flight flight;
    flight.setAirline("DHL");
    ASSERT_EQ(0, flight.setPrice(-20));
    ASSERT_EQ(1, flight.setDepartureAirport("SYD"));
    ASSERT_EQ(1, flight.setArrivalAirport("SIN"));
    ASSERT_EQ(1, flight.setAircraft("9V-DHA", "Boeing 777-F", "SG"));
    ASSERT_EQ(1, flight.setTime("2023-12-18;06:05", "2023-12-18;10:47"));

    ASSERT_EQ(WRONG_PRICE, flight.getStatus());
    ASSERT_EQ("DHL", flight.getAirline());
    ASSERT_EQ("SYD", flight.getDepartureAirport());
    ASSERT_EQ("SIN", flight.getArrivalAirport());
    ASSERT_EQ("Boeing 777-F", flight.getAircraft().getType());
    ASSERT_EQ("9V-DHA", flight.getAircraft().getRegistration());
    ASSERT_EQ("SG", flight.getAircraft().getCountry());
    ASSERT_EQ("2023-12-18;06:05", flight.getDepartureTime());
    ASSERT_EQ("2023-12-18;10:47", flight.getArrivalTime());
    ASSERT_EQ("04:42", flight.getDuration());
}

// departure_time&arrival_time&departureAirport&arrivalAirport&airline&flightNumber&price&registration&type&country
TEST(TestFirstTask, AddEverythingFromString) {
    Flight flight;
    ASSERT_EQ(1, flight.readFromString("2024-01-24;16:15&2024-01-24;17:45&BTS&LTN&Wizz Air&W94482&90&G-WUNB&Airbus A321-271NX&GB&"));
    ASSERT_EQ("01:30", flight.getDuration());
}

TEST(TestFirstTask, NotFullStringFlight) {
    Flight flight;
    ASSERT_EQ(0, flight.readFromString("2024-01-24;16:15&2024-01-24;17:45&BTS&LTN&WizzAir&W94482&90&G-WUNB&AirbusA321-271NX&"));
}

TEST(TestFirstTask, WrongDates) {
    Flight flight;
    ASSERT_EQ(0, flight.readFromString("2024-01-24;16:15&2024-01-23;17:45&BTS&LTN&Wizz Air&W94482&90&G-WUNB&Airbus A321-271NX&GB&"));
    ASSERT_EQ(WRONG_TIME, flight.getStatus());
    ASSERT_EQ("-1:-1", flight.getDuration());
}


// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_Flights.h"
#include "2_Connection.h"

using namespace ::testing;

// 1.uloha
TEST(TestSecondTask, ReadFromFile) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test1.txt"));
    ASSERT_EQ("2024-01-24;14:05&2024-01-24;18:25&DXB&BRU&Emirates&EK181&200&A6-EQM&Boeing 777-21H(ER)&AE&\n"
              "2024-01-24;16:15&2024-01-24;17:45&BTS&LTN&Wizz Air&W94482&90&G-WUNB&Airbus A321-271NX&GB&\n"
              "2024-01-24;19:55&2024-01-25;08:25&DXB&MNL&Philippine Airlines&PR659&250&R-C8781&Airbus A330-343&PH&\n"
              "2024-01-28;19:55&2024-01-30;08:25&DXB&MNL&Philippine Airlines&PR659&250&R-C8781&Airbus A330-343&PH&", fl.getChosenFlightsStringFormatted(fl.getAllFlights()));
}

TEST(TestSecondTask, ReadFromFileAndPrint) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test1.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getAllFlights();
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;14:05  2024-01-24;18:25  DXB  BRU                 Emirates     EK181    200    A6-EQM   Boeing 777-21H(ER)    AE\n"
              "2024-01-24;16:15  2024-01-24;17:45  BTS  LTN                 Wizz Air    W94482     90    G-WUNB    Airbus A321-271NX    GB\n"
              "2024-01-24;19:55  2024-01-25;08:25  DXB  MNL      Philippine Airlines     PR659    250   R-C8781      Airbus A330-343    PH\n"
              "2024-01-28;19:55  2024-01-30;08:25  DXB  MNL      Philippine Airlines     PR659    250   R-C8781      Airbus A330-343    PH", read);
}

TEST(TestSecondTask, ReadFromFileByNumber) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test1.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getFlightsByFlightNumber("PR659", fl.getAllFlights());
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;19:55  2024-01-25;08:25  DXB  MNL      Philippine Airlines     PR659    250   R-C8781      Airbus A330-343    PH\n"
              "2024-01-28;19:55  2024-01-30;08:25  DXB  MNL      Philippine Airlines     PR659    250   R-C8781      Airbus A330-343    PH", read);
}

TEST(TestSecondTask, GetByDate) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test1.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getFlightsByDateOfDeparture("2024-01-24", fl.getAllFlights());
    chosenFlights = fl.getFlightsByDateOfArrival("2024-01-25", chosenFlights);
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;19:55  2024-01-25;08:25  DXB  MNL      Philippine Airlines     PR659    250   R-C8781      Airbus A330-343    PH", read);
}

TEST(TestSecondTask, GetByAirport) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test1.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getFlightsByAirportOfDeparture("DXB", fl.getAllFlights());
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;14:05  2024-01-24;18:25  DXB  BRU                 Emirates     EK181    200    A6-EQM   Boeing 777-21H(ER)    AE\n"
              "2024-01-24;19:55  2024-01-25;08:25  DXB  MNL      Philippine Airlines     PR659    250   R-C8781      Airbus A330-343    PH\n"
              "2024-01-28;19:55  2024-01-30;08:25  DXB  MNL      Philippine Airlines     PR659    250   R-C8781      Airbus A330-343    PH", read);

    chosenFlights = fl.getFlightsByAirportOfArrival("BRU", chosenFlights);
    read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;14:05  2024-01-24;18:25  DXB  BRU                 Emirates     EK181    200    A6-EQM   Boeing 777-21H(ER)    AE", read);
}

TEST(TestSecondTask, GetByPrice) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test1.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getFlightsByPrice(80, 210, fl.getAllFlights());
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;14:05  2024-01-24;18:25  DXB  BRU                 Emirates     EK181    200    A6-EQM   Boeing 777-21H(ER)    AE\n"
              "2024-01-24;16:15  2024-01-24;17:45  BTS  LTN                 Wizz Air    W94482     90    G-WUNB    Airbus A321-271NX    GB", read);
}

TEST(TestSecondTask, ReadFromFile2) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getAllFlights();
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;16:15  2024-01-24;17:45  BTS  LTN                 Wizz Air    W94482     90    G-WUNB    Airbus A321-271NX    GB\n"
              "2024-01-25;08:15  2024-01-25;13:10  DOH  CPH                  Finnair    AY1986    490    OH-LTP      Airbus A330-302    FN\n"
              "2024-01-25;09:20  2024-01-25;10:25  BGY  STN                  Ryanair    FR2739    129    EI-DWO       Boeing 737-8AS    LA\n"
              "2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA\n"
              "2024-01-25;10:20  2024-01-25;12:40  BGY  MAD                  Ryanair    FR5494    124    EI-IFR     Boeing 737 MAX 8    LA\n"
              "2024-01-25;10:55  2024-01-25;12:35  BGY  EIN                  Ryanair    FR3460     95    9H-QAU       Boeing 737-8AS    LA\n"
              "2024-01-25;13:40  2024-01-25;22:20  WAW  DXB                 Emirates     EK180    799    A6-EPL   Boeing 777-31H(ER)    AE\n"
              "2024-01-25;14:10  2024-01-25;16:15  WAW  VNO                      LOT     LO779    120    SP-LMB      Embraer E190STD    PL\n"
              "2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH\n"
              "2024-01-25;14:35  2024-01-25;19:50  WAW  SSH                    SkyUp    U57347    375    UR-SQG       Boeing 737-8Z0    UA\n"
              "2024-01-25;15:05  2024-01-25;18:50  WAW  ALC                 Wizz Air    W61487    108    HA-LXC      Airbus A321-231    HU\n"
              "2024-01-25;15:55  2024-01-25;18:15  BGY  MAD                  Ryanair    FR5984    120    9H-VUX     Boeing 737 MAX 8    LA\n"
              "2024-01-25;16:25  2024-01-25;18:35  BGY  ALC                  Ryanair    FR3506    160    EI-IHK     Boeing 737 MAX 8    LA\n"
              "2024-01-25;16:50  2024-01-25;17:55  BGY  STN                 Wizz Air    FR3673    110    EI-HAW     Boeing 737 MAX 8    LA\n"
              "2024-01-25;17:00  2024-01-25;18:25  BGY  VIE             Lauda Europe    FR1533    100    9H-LOM      Airbus A320-232    AT\n"
              "2024-01-25;19:20  2024-01-25;23:55  WAW  IST         Turkish Airlines    TK1766    180    TC-JTL       Boeing 737-8F2    TR\n"
              "2024-01-25;20:35  2024-01-25;22:40  BGY  WAW                 Wizz Air    W61432    100    HA-LTF      Airbus A321-231    PL\n"
              "2024-01-25;23:00  2024-01-26;08:15  BGY  DXB                 flydubai    FZ1572    290    A6-FMG     Boeing 737 MAX 8    AE\n"
              "2024-01-25;23:05  2024-01-26;00:05  WAW  GDN                      LOT    LO3827    140    SP-LMF       Embraer E190AR    PL", read);
}

TEST(TestSecondTask, FindFlights1) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getFlightsByAirportOfDeparture("BGY", fl.getAllFlights());
    chosenFlights = fl.getFlightsByAirportOfArrival("MAD", chosenFlights);
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ(  "       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
                "---------------------------------------------------------------------------------------------------------------------------\n"
                "2024-01-25;10:20  2024-01-25;12:40  BGY  MAD                  Ryanair    FR5494    124    EI-IFR     Boeing 737 MAX 8    LA\n"
                "2024-01-25;15:55  2024-01-25;18:15  BGY  MAD                  Ryanair    FR5984    120    9H-VUX     Boeing 737 MAX 8    LA", read);

    chosenFlights = fl.getFlightsByPrice(0, 123, chosenFlights);
    read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ(  "       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
                "---------------------------------------------------------------------------------------------------------------------------\n"
                "2024-01-25;15:55  2024-01-25;18:15  BGY  MAD                  Ryanair    FR5984    120    9H-VUX     Boeing 737 MAX 8    LA", read);
}

TEST(TestSecondTask, FindFlights2) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getFlightsByAirportOfDeparture("BGY", fl.getAllFlights());
    chosenFlights = fl.getFlightsByAirportOfArrival("STN", chosenFlights);
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-25;09:20  2024-01-25;10:25  BGY  STN                  Ryanair    FR2739    129    EI-DWO       Boeing 737-8AS    LA\n"
              "2024-01-25;16:50  2024-01-25;17:55  BGY  STN                 Wizz Air    FR3673    110    EI-HAW     Boeing 737 MAX 8    LA", read);

    chosenFlights = fl.getFlightsByAirline("Wizz Air", chosenFlights);
    read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-25;16:50  2024-01-25;17:55  BGY  STN                 Wizz Air    FR3673    110    EI-HAW     Boeing 737 MAX 8    LA", read);
}

TEST(TestSecondTask, SaveToFile) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getFlightsByAirportOfDeparture("WAW", fl.getAllFlights());
    chosenFlights = fl.getFlightsByAirline("LOT", chosenFlights);
    std::string read = fl.getChosenFlightsString(chosenFlights);
    std::string checkString = "       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
                              "---------------------------------------------------------------------------------------------------------------------------\n"
                              "2024-01-25;14:10  2024-01-25;16:15  WAW  VNO                      LOT     LO779    120    SP-LMB      Embraer E190STD    PL\n"
                              "2024-01-25;23:05  2024-01-26;00:05  WAW  GDN                      LOT    LO3827    140    SP-LMF       Embraer E190AR    PL";

    ASSERT_EQ(checkString, read);
    ASSERT_EQ(1, fl.saveToFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/testFile.txt", chosenFlights));

    Flights fl2;
    ASSERT_EQ(1, fl2.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/testFile.txt"));
    chosenFlights = fl2.getAllFlights();
    read = fl2.getChosenFlightsString(chosenFlights);
    ASSERT_EQ(checkString, read);
}

TEST(TestSecondTask, ConnectionTest) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights1;
    chosenFlights1 = fl.getFlightsByAirportOfDeparture("BGY", fl.getAllFlights());
    chosenFlights1 = fl.getFlightsByAirportOfArrival("WAW", chosenFlights1);
    chosenFlights1 = fl.getFlightsByPrice(99, 99, chosenFlights1);

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights2;
    chosenFlights2 = fl.getFlightsByAirportOfDeparture("WAW", fl.getAllFlights());
    chosenFlights2 = fl.getFlightsByAirportOfArrival("ZRH", chosenFlights2);

    chosenFlights1.insert(chosenFlights2.begin(), chosenFlights2.end());
    std::string read = fl.getChosenFlightsString(chosenFlights1);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA\n"
              "2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH", read);


    Connection con;
    bool first = true;
    for (auto &[key, value] : chosenFlights1) {
        if (first) {
            first = false;
            con.addAirport(value.getDepartureAirportT());
        }
        ASSERT_EQ(1, con.addAirport(value.getArrivalAirportT()));
        con.addNumberOfTransfers();
        con.addFlightNumber(value.getFlightNumberT());
        con.addAirline(value.getAirlineT());
        con.addDuration(value.getDepartureTimeT(), value.getArrivalTimeT());
        con.addPrice(value.getPrice());
    }
    ASSERT_EQ(318, con.getTotalPrice());
    ASSERT_EQ(Duration(6, 30).getDurationInMinutes(), con.getTotalDuration().getDurationInMinutes());
    ASSERT_EQ("BGY -> WAW -> ZRH", con.getListOfAirports());
    ASSERT_EQ("Swiss, Wizz Air", con.getSetOfAirlines());
    ASSERT_EQ("W61434 -> LX1349", con.getListOfFlightNumbers());
    ASSERT_EQ(1, con.getNumberOfTransfers());

}

TEST(TestSecondTask, HugeConnection) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test3.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getAllFlights();
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA\n"
              "2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH\n"
              "2024-01-25;22:40  2024-01-26;17:40  ZRH  HKG                    Swiss     LX138    844    HB-JMI      Airbus A340-313    CH\n"
              "2024-01-26;19:20  2024-01-27;07:25  HKG  SYD           Cathay Pacific     CX111    600     B-LRD      Airbus A350-941    HK", read);

    Connection con;
    bool first = true;
    for (auto &[key, value] : chosenFlights) {
        if (first) {
            first = false;
            con.addAirport(value.getDepartureAirportT());
        }
        ASSERT_EQ(1, con.addAirport(value.getArrivalAirportT()));
        con.addNumberOfTransfers();
        con.addFlightNumber(value.getFlightNumberT());
        con.addAirline(value.getAirlineT());
        con.addDuration(value.getDepartureTimeT(), value.getArrivalTimeT());
        con.addPrice(value.getPrice());
    }

    ASSERT_EQ(1762, con.getTotalPrice());
    ASSERT_EQ(Duration(45, 20).getDurationInMinutes(), con.getTotalDuration().getDurationInMinutes());
    ASSERT_EQ("BGY -> WAW -> ZRH -> HKG -> SYD", con.getListOfAirports());
    ASSERT_EQ("Cathay Pacific, Swiss, Wizz Air", con.getSetOfAirlines());
    ASSERT_EQ("W61434 -> LX1349 -> LX138 -> CX111", con.getListOfFlightNumbers());
    ASSERT_EQ(3, con.getNumberOfTransfers());
}

TEST(TestSecondTask, AppendConnection) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test3.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights = fl.getAllFlights();
    std::string read = fl.getChosenFlightsString(chosenFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA\n"
              "2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH\n"
              "2024-01-25;22:40  2024-01-26;17:40  ZRH  HKG                    Swiss     LX138    844    HB-JMI      Airbus A340-313    CH\n"
              "2024-01-26;19:20  2024-01-27;07:25  HKG  SYD           Cathay Pacific     CX111    600     B-LRD      Airbus A350-941    HK", read);

    Connection con;

    for (auto &[key, value] : chosenFlights) {
        ASSERT_EQ(1, con.appendConnection(value));
    }

    ASSERT_EQ(1762, con.getTotalPrice());
    ASSERT_EQ(Duration(45, 20).getDurationInMinutes(), con.getTotalDuration().getDurationInMinutes());
    ASSERT_EQ("BGY -> WAW -> ZRH -> HKG -> SYD", con.getListOfAirports());
    ASSERT_EQ("Cathay Pacific, Swiss, Wizz Air", con.getSetOfAirlines());
    ASSERT_EQ("W61434 -> LX1349 -> LX138 -> CX111", con.getListOfFlightNumbers());
    ASSERT_EQ(3, con.getNumberOfTransfers());

    Connection con2;
    for (auto &[key, value] : chosenFlights) {
        ASSERT_EQ(1, con2.appendConnection(value));
        break;
    }
    ASSERT_EQ(99, con2.getTotalPrice());
    ASSERT_EQ(Duration(2, 5).getDurationInMinutes(), con2.getTotalDuration().getDurationInMinutes());
    ASSERT_EQ("BGY -> WAW", con2.getListOfAirports());
    ASSERT_EQ("Wizz Air", con2.getSetOfAirlines());
    ASSERT_EQ("W61434", con2.getListOfFlightNumbers());
    ASSERT_EQ(0, con2.getNumberOfTransfers());



}
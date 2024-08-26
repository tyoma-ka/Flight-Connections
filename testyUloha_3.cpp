// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_Sort.h"
#include "3_Connections.h"

using namespace ::testing;

// 1.uloha
TEST(TestThirdTask, SortByPrice) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getAllFlights();

    std::vector<Flight> SortedFlights;
    SortedFlights = Sort::orderByPriceAsc(chosenFlights);
    std::string read = fl.getChosenFlightsString(SortedFlights);


    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-24;16:15  2024-01-24;17:45  BTS  LTN                 Wizz Air    W94482     90    G-WUNB    Airbus A321-271NX    GB\n"
              "2024-01-25;10:55  2024-01-25;12:35  BGY  EIN                  Ryanair    FR3460     95    9H-QAU       Boeing 737-8AS    LA\n"
              "2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA\n"
              "2024-01-25;20:35  2024-01-25;22:40  BGY  WAW                 Wizz Air    W61432    100    HA-LTF      Airbus A321-231    PL\n"
              "2024-01-25;17:00  2024-01-25;18:25  BGY  VIE             Lauda Europe    FR1533    100    9H-LOM      Airbus A320-232    AT\n"
              "2024-01-25;15:05  2024-01-25;18:50  WAW  ALC                 Wizz Air    W61487    108    HA-LXC      Airbus A321-231    HU\n"
              "2024-01-25;16:50  2024-01-25;17:55  BGY  STN                 Wizz Air    FR3673    110    EI-HAW     Boeing 737 MAX 8    LA\n"
              "2024-01-25;14:10  2024-01-25;16:15  WAW  VNO                      LOT     LO779    120    SP-LMB      Embraer E190STD    PL\n"
              "2024-01-25;15:55  2024-01-25;18:15  BGY  MAD                  Ryanair    FR5984    120    9H-VUX     Boeing 737 MAX 8    LA\n"
              "2024-01-25;10:20  2024-01-25;12:40  BGY  MAD                  Ryanair    FR5494    124    EI-IFR     Boeing 737 MAX 8    LA\n"
              "2024-01-25;09:20  2024-01-25;10:25  BGY  STN                  Ryanair    FR2739    129    EI-DWO       Boeing 737-8AS    LA\n"
              "2024-01-25;23:05  2024-01-26;00:05  WAW  GDN                      LOT    LO3827    140    SP-LMF       Embraer E190AR    PL\n"
              "2024-01-25;16:25  2024-01-25;18:35  BGY  ALC                  Ryanair    FR3506    160    EI-IHK     Boeing 737 MAX 8    LA\n"
              "2024-01-25;19:20  2024-01-25;23:55  WAW  IST         Turkish Airlines    TK1766    180    TC-JTL       Boeing 737-8F2    TR\n"
              "2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH\n"
              "2024-01-25;23:00  2024-01-26;08:15  BGY  DXB                 flydubai    FZ1572    290    A6-FMG     Boeing 737 MAX 8    AE\n"
              "2024-01-25;14:35  2024-01-25;19:50  WAW  SSH                    SkyUp    U57347    375    UR-SQG       Boeing 737-8Z0    UA\n"
              "2024-01-25;08:15  2024-01-25;13:10  DOH  CPH                  Finnair    AY1986    490    OH-LTP      Airbus A330-302    FN\n"
              "2024-01-25;13:40  2024-01-25;22:20  WAW  DXB                 Emirates     EK180    799    A6-EPL   Boeing 777-31H(ER)    AE", read);

    SortedFlights = Sort::orderByPriceDesc(chosenFlights);
    read = fl.getChosenFlightsString(SortedFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-25;13:40  2024-01-25;22:20  WAW  DXB                 Emirates     EK180    799    A6-EPL   Boeing 777-31H(ER)    AE\n"
              "2024-01-25;08:15  2024-01-25;13:10  DOH  CPH                  Finnair    AY1986    490    OH-LTP      Airbus A330-302    FN\n"
              "2024-01-25;14:35  2024-01-25;19:50  WAW  SSH                    SkyUp    U57347    375    UR-SQG       Boeing 737-8Z0    UA\n"
              "2024-01-25;23:00  2024-01-26;08:15  BGY  DXB                 flydubai    FZ1572    290    A6-FMG     Boeing 737 MAX 8    AE\n"
              "2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH\n"
              "2024-01-25;19:20  2024-01-25;23:55  WAW  IST         Turkish Airlines    TK1766    180    TC-JTL       Boeing 737-8F2    TR\n"
              "2024-01-25;16:25  2024-01-25;18:35  BGY  ALC                  Ryanair    FR3506    160    EI-IHK     Boeing 737 MAX 8    LA\n"
              "2024-01-25;23:05  2024-01-26;00:05  WAW  GDN                      LOT    LO3827    140    SP-LMF       Embraer E190AR    PL\n"
              "2024-01-25;09:20  2024-01-25;10:25  BGY  STN                  Ryanair    FR2739    129    EI-DWO       Boeing 737-8AS    LA\n"
              "2024-01-25;10:20  2024-01-25;12:40  BGY  MAD                  Ryanair    FR5494    124    EI-IFR     Boeing 737 MAX 8    LA\n"
              "2024-01-25;15:55  2024-01-25;18:15  BGY  MAD                  Ryanair    FR5984    120    9H-VUX     Boeing 737 MAX 8    LA\n"
              "2024-01-25;14:10  2024-01-25;16:15  WAW  VNO                      LOT     LO779    120    SP-LMB      Embraer E190STD    PL\n"
              "2024-01-25;16:50  2024-01-25;17:55  BGY  STN                 Wizz Air    FR3673    110    EI-HAW     Boeing 737 MAX 8    LA\n"
              "2024-01-25;15:05  2024-01-25;18:50  WAW  ALC                 Wizz Air    W61487    108    HA-LXC      Airbus A321-231    HU\n"
              "2024-01-25;17:00  2024-01-25;18:25  BGY  VIE             Lauda Europe    FR1533    100    9H-LOM      Airbus A320-232    AT\n"
              "2024-01-25;20:35  2024-01-25;22:40  BGY  WAW                 Wizz Air    W61432    100    HA-LTF      Airbus A321-231    PL\n"
              "2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA\n"
              "2024-01-25;10:55  2024-01-25;12:35  BGY  EIN                  Ryanair    FR3460     95    9H-QAU       Boeing 737-8AS    LA\n"
              "2024-01-24;16:15  2024-01-24;17:45  BTS  LTN                 Wizz Air    W94482     90    G-WUNB    Airbus A321-271NX    GB", read);
}

TEST(TestThirdTask, SortByDuration) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getAllFlights();

    std::vector<Flight> SortedFlights;
    SortedFlights = Sort::orderByDuration(chosenFlights);
    std::string read = fl.getChosenFlightsString(SortedFlights);
    ASSERT_EQ("       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "2024-01-25;23:05  2024-01-26;00:05  WAW  GDN                      LOT    LO3827    140    SP-LMF       Embraer E190AR    PL\n"
              "2024-01-25;16:50  2024-01-25;17:55  BGY  STN                 Wizz Air    FR3673    110    EI-HAW     Boeing 737 MAX 8    LA\n"
              "2024-01-25;09:20  2024-01-25;10:25  BGY  STN                  Ryanair    FR2739    129    EI-DWO       Boeing 737-8AS    LA\n"
              "2024-01-25;17:00  2024-01-25;18:25  BGY  VIE             Lauda Europe    FR1533    100    9H-LOM      Airbus A320-232    AT\n"
              "2024-01-24;16:15  2024-01-24;17:45  BTS  LTN                 Wizz Air    W94482     90    G-WUNB    Airbus A321-271NX    GB\n"
              "2024-01-25;10:55  2024-01-25;12:35  BGY  EIN                  Ryanair    FR3460     95    9H-QAU       Boeing 737-8AS    LA\n"
              "2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH\n"
              "2024-01-25;20:35  2024-01-25;22:40  BGY  WAW                 Wizz Air    W61432    100    HA-LTF      Airbus A321-231    PL\n"
              "2024-01-25;14:10  2024-01-25;16:15  WAW  VNO                      LOT     LO779    120    SP-LMB      Embraer E190STD    PL\n"
              "2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA\n"
              "2024-01-25;16:25  2024-01-25;18:35  BGY  ALC                  Ryanair    FR3506    160    EI-IHK     Boeing 737 MAX 8    LA\n"
              "2024-01-25;10:20  2024-01-25;12:40  BGY  MAD                  Ryanair    FR5494    124    EI-IFR     Boeing 737 MAX 8    LA\n"
              "2024-01-25;15:55  2024-01-25;18:15  BGY  MAD                  Ryanair    FR5984    120    9H-VUX     Boeing 737 MAX 8    LA\n"
              "2024-01-25;15:05  2024-01-25;18:50  WAW  ALC                 Wizz Air    W61487    108    HA-LXC      Airbus A321-231    HU\n"
              "2024-01-25;19:20  2024-01-25;23:55  WAW  IST         Turkish Airlines    TK1766    180    TC-JTL       Boeing 737-8F2    TR\n"
              "2024-01-25;08:15  2024-01-25;13:10  DOH  CPH                  Finnair    AY1986    490    OH-LTP      Airbus A330-302    FN\n"
              "2024-01-25;14:35  2024-01-25;19:50  WAW  SSH                    SkyUp    U57347    375    UR-SQG       Boeing 737-8Z0    UA\n"
              "2024-01-25;13:40  2024-01-25;22:20  WAW  DXB                 Emirates     EK180    799    A6-EPL   Boeing 777-31H(ER)    AE\n"
              "2024-01-25;23:00  2024-01-26;08:15  BGY  DXB                 flydubai    FZ1572    290    A6-FMG     Boeing 737 MAX 8    AE", read);
}

TEST(TestThirdTask, MakeConnectionsFromFlights) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test2.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getAllFlights();

    Connections cons(chosenFlights);

    std::string readCon = cons.getChosenConnections(cons.getAllConnections());
    ASSERT_EQ("From             To                                Airlines                     Flight Numbers                Total Price\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "BTS -> LTN                                          Wizz Air                        W94482                       90\n"
              "DOH -> CPH                                           Finnair                        AY1986                      490\n"
              "BGY -> STN                                           Ryanair                        FR2739                      129\n"
              "BGY -> WAW                                          Wizz Air                        W61434                       99\n"
              "BGY -> MAD                                           Ryanair                        FR5494                      124\n"
              "BGY -> EIN                                           Ryanair                        FR3460                       95\n"
              "WAW -> DXB                                          Emirates                         EK180                      799\n"
              "WAW -> VNO                                               LOT                         LO779                      120\n"
              "WAW -> ZRH                                             Swiss                        LX1349                      219\n"
              "WAW -> SSH                                             SkyUp                        U57347                      375\n"
              "WAW -> ALC                                          Wizz Air                        W61487                      108\n"
              "BGY -> MAD                                           Ryanair                        FR5984                      120\n"
              "BGY -> ALC                                           Ryanair                        FR3506                      160\n"
              "BGY -> STN                                          Wizz Air                        FR3673                      110\n"
              "BGY -> VIE                                      Lauda Europe                        FR1533                      100\n"
              "WAW -> IST                                  Turkish Airlines                        TK1766                      180\n"
              "BGY -> WAW                                          Wizz Air                        W61432                      100\n"
              "BGY -> DXB                                          flydubai                        FZ1572                      290\n"
              "WAW -> GDN                                               LOT                        LO3827                      140", readCon);
}

TEST(TestThirdTask, PrintConnections1) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test3.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getAllFlights();

    Connections cons(chosenFlights);

    std::string readCon = cons.getChosenConnections(cons.getAllConnections());
    ASSERT_EQ("From             To                                Airlines                     Flight Numbers                Total Price\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "BGY -> WAW                                          Wizz Air                        W61434                       99\n"
              "WAW -> ZRH                                             Swiss                        LX1349                      219\n"
              "ZRH -> HKG                                             Swiss                         LX138                      844\n"
              "HKG -> SYD                                    Cathay Pacific                         CX111                      600", readCon);

    Connections cons1;
    Connection first;
    Connection second;
    std::map<std::pair<std::string, std::string>, Flight> chosenFlightsFirst;
    std::map<std::pair<std::string, std::string>, Flight> chosenFlightsSecond;
    chosenFlightsFirst = fl.getFlightsByPrice(98, 300, chosenFlights);
    chosenFlightsSecond = fl.getFlightsByPrice(400, 1000, chosenFlights);


    for (auto &[key, value] : chosenFlightsFirst) {
        first.appendConnection(value);
    }

    for (auto &[key, value] : chosenFlightsSecond) {
        second.appendConnection(value);
    }
    cons1.addConnection(first);
    cons1.addConnection(second);

    readCon = cons1.getChosenConnections(cons1.getAllConnections());
    ASSERT_EQ("From             To                                Airlines                     Flight Numbers                Total Price\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "BGY -> WAW -> ZRH                                   Swiss, Wizz Air              W61434 -> LX1349                      318\n"
              "ZRH -> HKG -> SYD                             Cathay Pacific, Swiss                LX138 -> CX111                     1444", readCon);


}

TEST(TestThirdTask, SortConnections) {
    Flights fl;
    ASSERT_EQ(1, fl.readFromFile("/Users/person/Documents/учеба/Programovanie/3 семестр/Проект/Проект/flights_test3.txt"));

    std::map<std::pair<std::string, std::string>, Flight> chosenFlights;
    chosenFlights = fl.getAllFlights();
    Connections cons1;
    Connection first;
    Connection second;
    std::map<std::pair<std::string, std::string>, Flight> chosenFlightsFirst;
    std::map<std::pair<std::string, std::string>, Flight> chosenFlightsSecond;
    chosenFlightsFirst = fl.getFlightsByPrice(98, 300, chosenFlights);
    chosenFlightsSecond = fl.getFlightsByPrice(400, 1000, chosenFlights);
    for (auto &[key, value] : chosenFlightsFirst) {
        first.appendConnection(value);
    }

    for (auto &[key, value] : chosenFlightsSecond) {
        second.appendConnection(value);
    }
    cons1.addConnection(second);
    cons1.addConnection(first);

    std::string readCon = cons1.getChosenConnections(cons1.getAllConnections());
    ASSERT_EQ("From             To                                Airlines                     Flight Numbers                Total Price\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "BGY -> WAW -> ZRH                                   Swiss, Wizz Air              W61434 -> LX1349                      318\n"
              "ZRH -> HKG -> SYD                             Cathay Pacific, Swiss                LX138 -> CX111                     1444", readCon);

    std::vector<Connection> sortedConnections = Sort::orderByPriceDesc(cons1.getAllConnections());
    readCon = cons1.getChosenConnections(sortedConnections);
    ASSERT_EQ("From             To                                Airlines                     Flight Numbers                Total Price\n"
              "---------------------------------------------------------------------------------------------------------------------------\n"
              "ZRH -> HKG -> SYD                             Cathay Pacific, Swiss                LX138 -> CX111                     1444\n"
              "BGY -> WAW -> ZRH                                   Swiss, Wizz Air              W61434 -> LX1349                      318", readCon);


}


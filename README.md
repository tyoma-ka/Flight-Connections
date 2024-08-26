# Flight Connections
 Flight connection API that reads and processes flight data from a file, performs validation, and provides functionality for sorting and selecting flights, creating connections, and outputting results in both Data Transfer Object (DTO) format and as formatted strings.

## Flight data example

2024-01-25;10:05&2024-01-25;12:10&BGY&WAW&Wizz Air&W61434&99&HA-LXJ&Airbus A321-231&LA&
2024-01-25;14:35&2024-01-25;16:35&WAW&ZRH&Swiss&LX1349&219&HB-JDC&Airbus A320-271N&CH&
2024-01-25;22:40&2024-01-26;17:40&ZRH&HKG&Swiss&LX138&844&HB-JMI&Airbus A340-313&CH&
2024-01-26;19:20&2024-01-27;07:25&HKG&SYD&Cathay Pacific&CX111&600&B-LRD&Airbus A350-941&HK&

## Added and validated flights
       Departure           Arrival  from  to                  Airline  FlightNo. Price      Reg.                 Type    Co
       ---------------------------------------------------------------------------------------------------------------------------
       2024-01-25;10:05  2024-01-25;12:10  BGY  WAW                 Wizz Air    W61434     99    HA-LXJ      Airbus A321-231    LA
       2024-01-25;14:35  2024-01-25;16:35  WAW  ZRH                    Swiss    LX1349    219    HB-JDC     Airbus A320-271N    CH
       2024-01-25;22:40  2024-01-26;17:40  ZRH  HKG                    Swiss     LX138    844    HB-JMI      Airbus A340-313    CH
       2024-01-26;19:20  2024-01-27;07:25  HKG  SYD           Cathay Pacific     CX111    600     B-LRD      Airbus A350-941    HK

## Made Connections
       From             To                                Airlines                     Flight Numbers                Total Price
       ---------------------------------------------------------------------------------------------------------------------------
       BGY -> WAW -> ZRH                                   Swiss, Wizz Air              W61434 -> LX1349                      318
       ZRH -> HKG -> SYD                             Cathay Pacific, Swiss                LX138 -> CX111                     1444


Check testyUloha_[1-3].cpp for more!

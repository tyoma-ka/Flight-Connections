cmake_minimum_required(VERSION 3.6.2)
project(cvicenie12)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

set(SOURCE_FILES
        1_Time.cpp
        1_Aircraft.cpp
        1_Flight.cpp
        2_Connection.cpp
        2_Flights.cpp
        3_Sort.cpp
        3_Connections.cpp

        testyUloha_1.cpp
        testyUloha_2.cpp
        testyUloha_3.cpp

        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)

include_directories(GoogleTest)
add_executable(cvicenie12 ${SOURCE_FILES})
target_link_libraries(cvicenie12 ${CMAKE_THREAD_LIBS_INIT})
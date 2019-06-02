cmake_minimum_required(VERSION 3.6)
project(Observer_DP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Subject.hpp Observer.hpp BoardingStatus.hpp BoardingStatus.cpp Passenger.hpp Passenger.cpp)
add_executable(Observer_DP ${SOURCE_FILES})
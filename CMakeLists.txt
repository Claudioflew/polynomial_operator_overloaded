cmake_minimum_required(VERSION 3.27)
project(Assignment8_PolynomialOverloadedOperators)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment8_PolynomialOverloadedOperators
        main.cpp
        Polynomial.cpp
        Polynomial.h)

cmake_minimum_required(VERSION 2.8)
project(cv-2016)
set(CMAKE_CXX_FLAGS "-pthread -std=c++11 ${CMAKE_CXX_FLAGS} -Wall -Og -g")
add_subdirectory(src)

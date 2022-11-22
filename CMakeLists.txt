cmake_minimum_required(VERSION 3.23)
project(CS250_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS250_project Main.cpp Course.cpp Course.h)

add_subdirectory(Google_tests)

cmake_minimum_required(VERSION 3.5)

project(module_4_6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(module_4_6 main.cpp)

install(TARGETS module_4_6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

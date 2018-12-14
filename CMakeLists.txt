cmake_minimum_required(VERSION 3.13)
project(Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulator main.cpp Interpreter.cpp Interpreter.h)
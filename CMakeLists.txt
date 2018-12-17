cmake_minimum_required(VERSION 3.13)
project(Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulator main.cpp Interpreter.cpp Interpreter.h BinaryExpression.cpp BinaryExpression.h Expression.h Plus.cpp Plus.h Number.cpp Number.h Minus.cpp Minus.h UnaryExpression.cpp UnaryExpression.h Neg.cpp Neg.h Data.cpp Data.h ShuntingYard.cpp ShuntingYard.h)
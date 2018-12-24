cmake_minimum_required(VERSION 3.13)
project(Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulator main.cpp Interpreter.cpp Interpreter.h BinaryExpression.cpp BinaryExpression.h Expression.h Plus.cpp Plus.h Number.cpp Number.h Minus.cpp Minus.h Mult.cpp Mult.h Div.cpp Div.h UnaryExpression.cpp UnaryExpression.h Neg.cpp Neg.h Data.cpp Data.h ShuntingYard.cpp ShuntingYard.h CommandExpression.cpp CommandExpression.h Command.h OpenDataServer.cpp OpenDataServer.h Connect.cpp Connect.h Sleep.cpp Sleep.h DefineVarCommand.cpp DefineVarCommand.h Assign.cpp Assign.h ConditionParser.cpp ConditionParser.h LoopCommand.cpp LoopCommand.h IfCommand.cpp IfCommand.h PrintCommand.cpp PrintCommand.h Condition.cpp Condition.h)
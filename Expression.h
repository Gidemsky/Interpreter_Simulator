//
// Created by benda on 14/12/18.
//

#ifndef SIMULATOR_EXPRESSION_H
#define SIMULATOR_EXPRESSION_H

class Expression {

    class BinaryExpression {
    public:
        virtual double calculate() = 0;
    };

    class UnaryExpression {
    public:
        virtual double calculate() = 0;
    };

    class Number {
    public:
        virtual double calculate() = 0;
    };

};

#endif //SIMULATOR_EXPRESSION_H

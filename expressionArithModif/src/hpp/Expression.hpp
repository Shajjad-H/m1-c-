#pragma once


class Expression {
    public:
        virtual Expression * clone() const = 0;
        virtual Expression * cloneTemp() = 0;
        virtual int eval() const = 0;
        virtual ~Expression() {};
};


#pragma once
#include "Expression.hpp"

class Const : public Expression {
    protected:
        long int val;
    public:
        Const() = delete;
        Const(long int val);
        Expression * clone() const;
        Expression * cloneTemp();
        int eval() const;
};
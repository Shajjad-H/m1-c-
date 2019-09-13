#pragma once

#include "Expression.hpp"

class ExpressionBinaire : public Expression {
    protected:
        Expression * exp1, * exp2;
    public:
        ExpressionBinaire() = delete;
        ExpressionBinaire(const ExpressionBinaire & e);
        ExpressionBinaire(const Expression &, const Expression &);
        ~ExpressionBinaire();

};


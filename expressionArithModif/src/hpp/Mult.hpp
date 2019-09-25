#pragma once

#include "ExpressionBinaire.hpp"

class Mult final : public ExpressionBinaire {
    public:
        using ExpressionBinaire::ExpressionBinaire;
        Mult(const Mult & p): ExpressionBinaire(p) {};
        Mult * clone() const;
        Mult * cloneTemp();
        int eval() const;
};
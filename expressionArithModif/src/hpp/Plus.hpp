#pragma once

#include "ExpressionBinaire.hpp"

class Plus final : public ExpressionBinaire {
    public:
        using ExpressionBinaire::ExpressionBinaire;
        Plus(const Plus & p): ExpressionBinaire(p) {};
        Plus * clone() const;
        Plus * cloneTemp();
        int eval() const;
};
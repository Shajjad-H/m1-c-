#pragma once
#include "ExpressionBinaire.hpp"


class Moins final : public ExpressionBinaire {
    public:
        using ExpressionBinaire::ExpressionBinaire;
        Moins(const Moins & p): ExpressionBinaire(p) {};
        Moins * clone() const;
        int eval() const;
};
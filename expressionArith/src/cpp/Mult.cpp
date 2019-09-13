#include "Mult.hpp"


Mult * Mult::clone() const {
    return new Mult(*this);
}

int Mult::eval() const {
    return this->exp1->eval() * this->exp2->eval();
}

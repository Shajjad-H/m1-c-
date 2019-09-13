#include "Moins.hpp"


Moins * Moins::clone() const {
    return new Moins(*this);
}

int Moins::eval() const {
    return this->exp1->eval() - this->exp2->eval();
}

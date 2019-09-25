#include "Mult.hpp"


Mult * Mult::clone() const {
    return new Mult(*this);
}

Mult * Mult::cloneTemp() {

    Mult * tmp = new Mult();
    tmp->exp1 = this->exp1;
    tmp->exp2 = this->exp2;
    this->exp1 = nullptr;
    this->exp2 = nullptr;
    
    return tmp;
}

int Mult::eval() const {
    return this->exp1->eval() * this->exp2->eval();
}

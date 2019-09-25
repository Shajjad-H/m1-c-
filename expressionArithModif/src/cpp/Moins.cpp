#include "Moins.hpp"


Moins * Moins::clone() const {
    return new Moins(*this);
}

Moins * Moins::cloneTemp() {

    Moins * tmp = new Moins();
    tmp->exp1 = this->exp1;
    tmp->exp2 = this->exp2;
    this->exp1 = nullptr;
    this->exp2 = nullptr;
    
    return tmp;
}

int Moins::eval() const {
    return this->exp1->eval() - this->exp2->eval();
}

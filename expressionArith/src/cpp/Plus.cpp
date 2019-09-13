#include "Plus.hpp"


Plus * Plus::clone() const {
    return new Plus(*this);
}

int Plus::eval() const {
    return this->exp1->eval() + this->exp2->eval();
}

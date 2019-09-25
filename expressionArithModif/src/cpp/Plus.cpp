#include "Plus.hpp"


Plus * Plus::clone() const {
    return new Plus(*this);
}

Plus * Plus::cloneTemp() {

    Plus * p = new Plus();
    p->exp1 = this->exp1;
    p->exp2 = this->exp2;
    this->exp1 = 0;
    this->exp2 = 0;
    
    return p;
}

int Plus::eval() const {
    return this->exp1->eval() + this->exp2->eval();
}

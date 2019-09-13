#include "Const.hpp"

Const::Const(long int val) {
    this->val = val;
}
Expression * Const::clone() const {

    Const * c = new Const(this->val); 
    return c;
}

int Const::eval() const {
    return this->val;
}
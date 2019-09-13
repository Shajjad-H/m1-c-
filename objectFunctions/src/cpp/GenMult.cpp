#include "GenMult.hpp"


GenMult::GenMult(int base) {
    this->lastVal = 0;
    this->base = base;
}

int GenMult::operator()() {
    this->lastVal += this->base;
    return this->lastVal;
}

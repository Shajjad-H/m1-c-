#include "ExpressionBinaire.hpp"

ExpressionBinaire::ExpressionBinaire(const Expression & exp1, const Expression & exp2) {
    this->exp1 = exp1.clone();
    this->exp2 = exp2.clone();
}

ExpressionBinaire::ExpressionBinaire(const ExpressionBinaire & e) {
    this->exp1 = e.exp1->clone();
    this->exp2 = e.exp2->clone();
}

ExpressionBinaire::~ExpressionBinaire() {
    
    delete this->exp1;
    delete this->exp2;

    this->exp1 = 0;
    this->exp2 = 0;
}





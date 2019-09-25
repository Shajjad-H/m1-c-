#include <cassert>
#include <iostream>

#include "Const.hpp"
#include "Plus.hpp"
#include "Moins.hpp"
#include "Mult.hpp"

using namespace std;

void testConst() {
    // Const cErr;
    Const c5 = 5;
    assert(c5.eval() == 5);
    cout << c5.eval() << endl;
    cout << "Passed Const(const int) et int eval() const" << endl;

    Expression * cpC5 = c5.clone();
    cout << cpC5->eval() << endl;
    assert(cpC5->eval() == 5);
    cout << "Passed Expression * clone()" << endl;

    cout << "Passed testConst()" << endl
         << endl;
}

void testPlus() {
    Const c5 = 5;
    Const c6 = 6;
    Plus p5_6(c5, c6);
    assert(p5_6.eval() == 11);
    cout << p5_6.eval() << endl;
    cout << "Plus(Const &, Const &)" << endl;

    Plus p(Const(5), Const(6));
    cout << p.eval() << endl;
    assert(p.eval() == 11);
    cout << "Plus(Const &&, Const &&)" << endl;

    Plus pp = Plus( Plus(Const(5), Const(6)), Plus(Const(5), Const(6)) );
    cout << pp.eval() << endl;
    assert(pp.eval() == 22);
    cout << "Plus(Plus &&, Plus &&)" << endl;


    Plus pp5_6(Plus(Const(5), Const(10)), Plus(Const(-5), Moins(Const(6), Const(20)) ));
    cout << pp5_6.eval() << endl;
    assert(pp5_6.eval() == -4);
    // Plus pmErr = Moins(Const(5), Const(4)); Ok
        cout << "Passed testPlus()" << endl
         << endl;
}

void testMoins() {
    Const c5 = 5, c6 = 6;
    Moins m1(c6, c5);
    assert(m1.eval() == 1);
    cout << "Moins(Const, Const)" << endl;

    Moins mm_56(Moins(c5, Moins(c6, Const(10))), Plus(Const(5), Const(10)));
    cout << mm_56.eval() << endl;
    assert(mm_56.eval() == -6);

    cout << "Passed testMoins()" << endl
         << endl;
}

void testMult() {
    // Const c5 = 5, c6 = 6;
    // Mult m30(Const(4), Const(2));
    Mult m30( Const(5), Const(6) );
    assert(m30.eval() == 30);
    cout<<"passed Mult(C, C)"<<endl;

    Mult m(Plus(Const(5), Const(6)), Const(10));
    assert(m.eval() == 110);
    cout<<"passed Mult(Exp, C)"<<endl;

    Mult m100(Moins(Const(5), Const(6)), Mult(Const(10), Const(10)) );
    // cout<<m100.eval()<<endl;
    assert(m100.eval() == -100);
    cout<<"passed Mult(Exp, Exp)"<<endl;

    cout<<endl<<endl;

}

void textMix() {
    // int a = 5;
    // const Expression& e = Mult( Plus(Const(a), Const(-2)), Plus(Const(1),Const(3)));

    // std::cout << e.eval() << std::endl;
}



int main() {
    testConst();
    testPlus();
    testMoins();
    testMult();
    // textMix();

    return 0;
}

#include <iostream>
#include "GenMult.hpp"


using namespace std;

int main() {

    GenMult gen5(5);

    for (size_t i = 0; i < 10; i++) {
        cout<<gen5()<<endl;
    }
    
    GenMult genM5(-5);
    for (size_t i = 0; i < 10; i++) {
        cout<<genM5()<<endl;
    }

    return 0;
}

#include "String.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testConstructors() {

    String s;
    assert(s.size() == 0);
    cout<<"passed default String()"<<endl;

    String s1 = "123";
    assert(s1.size() == 3);
    assert(s1.at(0) == '1');
    assert(s1.at(1) == '2');
    assert(s1.at(2) == '3');
    cout<<"passed String(const char *)"<<endl;

    String s2 = 'a';
    assert(s2.size() == 1);
    cout<<"passed String(const char &)"<<endl;

    String s3 = s1;
    assert(s3.size() == 3);
    cout<<"passed String(String)"<<endl;

}

int main(int argc, char const *argv[])
{

    testConstructors();
    cout<<"Ok"<<endl;
    return 0;
}

#include "String.hpp"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

bool assertForEgale(const String &s, const char * chrs) {
    for(size_s i = 0; i < s.size(); i++) {
        if(s.at(i) != chrs[i])
            return false;
    }
    return true;
}

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

void assertAffect() {
    String s1;
    s1 = "abc";
    assert(assertForEgale(s1, "abc"));
    s1 = "ce ci est un test et \0 c'est pas fini";
    assert(assertForEgale(s1, "ce ci est un test et \0 c'est pas fini"));
    cout<<s1<<endl;
    cout<<"passed operator="<<endl;

}

int main(int argc, char const *argv[]) {

    testConstructors();
    assertAffect();
    cout<<"Ok"<<endl;
    return 0;
}

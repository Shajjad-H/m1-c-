#include "String.hpp"

#include <stdexcept>
#include <ostream>

using namespace std;

String::String() : length(0), reservedLength(2) {

    this->str = new char[reservedLength];
}

String::String(const char & chr) {

    this->length = 1;
    this->reservedLength = 2;
    this->str = new char[this->reservedLength];
    this->str[0] = chr;
}


String::String(const char * chrs) {
    this->str = NULL;
    this->replace(chrs);

}


String::String(const String & s) {
    this->str = NULL;
    this->replace(s);
}


char String::at(size_s index) const {

    if( index < this->length)
        return this->str[index];

    throw invalid_argument( "out of range index in function at(size_s index);"  );
}

void String::replace(const String & s) {
    
    this->erase();
    this->length = s.length;
    this->reservedLength = s.reservedLength;

    this->str = new char[this->reservedLength];
    
    for(size_s i = 0; i < this->length; i++) {
        this->str[i] = s.at(i);
    }
}

void String::replace(const char * chrs) {
    this->erase();
    this->length = this->strLen(chrs);
    this->reservedLength = this->length;

    if(this->reservedLength == 0) {
        this->reservedLength = 2;
    }

    this->str = new char[this->reservedLength];
    
    for(size_s i = 0; i < this->length; i++) {
        this->str[i] = chrs[i];
    }
}

size_s String::size() const {
    return this->length;
}

ostream& operator<<(ostream& os, const String& s) {
    os<<s.str;
    return os;
}


char & String::operator[](size_s index) const {
    
    if( index < this->length)
        return this->str[index];

    throw invalid_argument( "out of range index in function [size_s index]"  );
}


String::~String() {
    this->erase();
}

void String::erase() {
    
    this->length = 0;
    this->reservedLength = 2;

    if(this->str)   delete[] this->str;
    this->str = nullptr;
}



size_s String::strLen(const char * chrs) const {
    size_s len = 0;
    
    while(chrs[len] != '\0') len++;
    
    return len;
}

char * String::c_str() const {
    char * retVal = new char[this->length + 1];
    for(size_s i = 0; i < this->length; i++) {
        retVal[i] = this->at(i);
    }
    retVal[this->length] = '\0';
    return retVal;
}


const String & String::operator=(const String & s) {
    this->replace(s);
    return *this;
}

const String & String::operator=(const char * chrs) {
    this->replace(chrs);
    return *this;
}

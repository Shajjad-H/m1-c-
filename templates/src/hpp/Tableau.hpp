#pragma once

#include <exception>

#include "Iterator.hpp"

typedef unsigned int size_tab;


template<typename T>
class Tableau {

    typedef Iterator<T> iterator;
    
    protected:
        T  * data;
        size_tab len;
        size_tab reservedLen;
        void copie(const T * source, T * dest, size_tab size);
    public:
        Tableau();
        Tableau(const Tableau<T> &);
        Tableau(const T * tab, size_tab size);
        ~Tableau();
        size_tab size() const;
        void push(const T &);
        T & operator[](size_tab index);
        const Tableau<T> & operator=(const Tableau<T> &);
        Tableau::iterator begin();
        Tableau::iterator end();


};

template<typename T>
typename Tableau<T>::iterator Tableau<T>::begin() {
    return iterator(*this, 0);
}

template<typename T>
typename Tableau<T>::iterator Tableau<T>::end() {

    return iterator(*this, this->len);

}


template<typename T>
Tableau<T>::Tableau(const Tableau<T> & tab) {

    this->len = tab.len;
    this->reservedLen = tab.reservedLen;
    this->data = new T[this->reservedLen];
    this->copie( tab.data, this->data, this->len );

}

template<typename T>
T & Tableau<T>::operator[](size_tab index) {

    if(index < this->len) {

        return this->data[index];
    }

    throw "depacement de la taille";
}

template<typename T>
const Tableau<T> & Tableau<T>::operator=(const Tableau<T> & tab) {

    if( tab.reservedLen < this->reservedLen) {

        this->len = tab.len;
        this->reservedLen = tab.reservedLen;
        this->copie(this->data, tab.data, this->len);
        return *this;

    }

    this->len = tab.len;
    this->reservedLen = tab.reservedLen;
    if (this->data)
        delete[] this->data;
    this->data = new T[this->reservedLen];

    this->copie(this->data, tab.data, this->len);

    return *this;

}


template<typename T>
Tableau<T>::~Tableau<T>() {
    this->len = 0;
    this->reservedLen = 0;
    delete[] this->data;
}

template<typename T>
Tableau<T>::Tableau() {
    this->len = 0;
    this->reservedLen = 2;
    this->data = new T[this->reservedLen];
}

template<typename T>
void Tableau<T>::push(const T & e) {

    if(this->len < this->reservedLen) {
        
        this->data[this->len] = e;
        this->len++;

    } else {

        this->reservedLen *= 2;
        T * newTab = new T[this->reservedLen];
        this->copie(this->data, newTab, this->len);
        newTab[this->len] = e;
        this->len++;

        delete[] this->data;
        this->data = newTab;

    }
}

template<typename T>
size_tab Tableau<T>::size() const {

    return this->len;
}


template<typename T>
void Tableau<T>::copie(const T * source, T * dest,  size_tab size) {

    for (size_tab i = 0; i < size; i++) {

        dest[i] = source[i];

    }
    

}

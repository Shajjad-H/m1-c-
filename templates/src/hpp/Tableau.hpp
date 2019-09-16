#pragma once

typedef unsigned int size_tab;

template<typename T>
class Tableau {

    protected:
        T  * data;
        size_tab len;
        size_tab reservedLen;
        void copie(const T * source, T * dest, size_tab size);
    public:
        Tableau<T>();
        Tableau<T>(const Tableau<T> &);
        Tableau<T>(const T * tab, size_tab size);
        ~Tableau<T>();
        size_tab size() const;
        void push(const T &);
        T & operator[](size_tab index);
        const Tableau<T> & operator=(const Tableau<T> &);
        

};

template<typename T>
Tableau<T>::Tableau<T>(const Tableau<T> & tab) {

    this->len = tab.len;
    this->reservedLen = tab.reservedLen;
    this->data = new T[this->reservedLen];
    this->copie( tab.data, this->data, this->len );

}

template<typename T>
Tableau<T>::~Tableau<T>() {
    this->len = 0;
    this->reservedLen = 0;
    delete[] this->data;
}

template<typename T>
Tableau<T>::Tableau<T>() {
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
void Tableau<T>::copie(const T * source, T * dest,  size_tab size) {

    for (size_tab i = 0; i < size; i++) {

        dest[i] = source[i];

    }
    

}

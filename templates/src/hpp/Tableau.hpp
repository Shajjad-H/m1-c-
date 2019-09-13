#pragma once

typedef unsigned int size_tab;

template<typename T>
class Tableau {

    protected:
        T data;
        size_tab len;
        size_tab reservedLen;
    public:
        Tableau<T>();
        Tableau<T>(const Tableau<T> &);
        Tableau<T>(const T *, unsigned int);
        ~Tableau<T>();
        size_tab size() const;
        void push();
        T & operator[](size_tab index);
        const Tableau<T> & operator=(const Tableau<T> &);


};
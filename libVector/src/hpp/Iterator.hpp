#pragma once

template <typename T>
class Tableau;


template<typename T>
class Iterator {

    protected:
        Tableau<T> * tab;
        unsigned int currentIndex;
    public:
        Iterator() = delete;

        Iterator(const Iterator<T> & itrator) : tab(itrator.tab), currentIndex(itrator.currentIndex) {}

        Iterator(const Tableau<T> & tab, unsigned int currentIndex): tab(&tab), currentIndex(currentIndex) {}

        Iterator<T> operator++(int);
        Iterator<T> operator--(int);
        // bool operator==(const Iterator<T> &);
        T & operator*();
        ~Iterator(){}
};


template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
    if(this->currentIndex <= this->tab->size()) {

        this->currentIndex++;

    }
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
    if(this->currentIndex > 0) {

        this->currentIndex--;

    }
    return *this;
}

template<typename T>
T & Iterator<T>::operator*() {

    return this->tab[this->currentIndex];

}
